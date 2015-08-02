////////////////////////////////////////////////////////////
//
// Copyright (c) 2013-2015 Brandon Haffen - bhaffen97@gmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <sfml/sfsqrat.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfTexture_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Texture* instance = new sf::Texture();
        Sqrat::DefaultAllocator<sf::Texture>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Texture&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Texture* instance = new sf::Texture(copy.value);
            Sqrat::DefaultAllocator<sf::Texture>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Loads the texture from a file on disk
////////////////////////////////////////////////////////////
static SQInteger sfTexture_loadFromFile(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        Sqrat::Var<const std::string&> filename(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromFile(filename.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        Sqrat::Var<const std::string&> filename(v, 2);
        Sqrat::Var<const sf::IntRect&> area(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromFile(filename.value, area.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Loads the texture from an image
////////////////////////////////////////////////////////////
static SQInteger sfTexture_loadFromImage(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        Sqrat::Var<const sf::Image&> image(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromImage(image.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        Sqrat::Var<const sf::Image&> image(v, 2);
        Sqrat::Var<const sf::IntRect&> area(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromImage(image.value, area.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Loads the texture from a file in memory
////////////////////////////////////////////////////////////
static SQInteger sfTexture_loadFromMemory(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        Sqrat::Var<const std::string&> data(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromMemory(data.value.c_str(), data.value.size()));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        Sqrat::Var<const std::string&> data(v, 2);
        Sqrat::Var<const sf::IntRect&> area(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromMemory(data.value.c_str(), data.value.size(), area.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Updates the texture from a source
////////////////////////////////////////////////////////////
static SQInteger sfTexture_update(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<Sqrat::Array> pixels(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                sq_pushobject(v, pixels.value.GetObject());
                sq_pushnull(v);
                sf::Uint8 data[sq_getsize(v, -2)];
                while (SQ_SUCCEEDED(sq_next(v, -2))) {
                    SQInteger key;
                    sq_getinteger(v, -2, &key);
                    Sqrat::Var<sf::Uint8> pixel(v, -1);
                    if (Sqrat::Error::Occurred(v)) {
                        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
                    }
                    sq_pop(v, 2);
                    data[key] = pixel.value;
                }
                sq_pop(v, 2);
                left.value.update(data);
                return 0;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const sf::Image&> image(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                left.value.update(image.value);
                return 0;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const sf::RenderWindow&> window(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                left.value.update(window.value);
                return 0;
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, _SC("array|") + Sqrat::ClassType<sf::Image>::ClassName() + _SC("|") + Sqrat::ClassType<sf::RenderWindow>::ClassName()).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<const sf::Image&> image(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::Var<unsigned int> x(v, 3);
                Sqrat::Var<unsigned int> y(v, 4);
                if (!Sqrat::Error::Occurred(v)) {
                    left.value.update(image.value, x.value, y.value);
                    return 0;
                }
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const sf::RenderWindow&> window(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::Var<unsigned int> x(v, 3);
                Sqrat::Var<unsigned int> y(v, 4);
                if (!Sqrat::Error::Occurred(v)) {
                    left.value.update(window.value, x.value, y.value);
                    return 0;
                }
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Image>::ClassName() + _SC("|") + Sqrat::ClassType<sf::RenderWindow>::ClassName()).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 6) {
        Sqrat::Var<sf::Texture&> left(v, 1);
        Sqrat::Var<Sqrat::Array> pixels(v, 2);
        Sqrat::Var<unsigned int> width(v, 3);
        Sqrat::Var<unsigned int> height(v, 4);
        Sqrat::Var<unsigned int> x(v, 5);
        Sqrat::Var<unsigned int> y(v, 6);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, pixels.value.GetObject());
            sq_pushnull(v);
            sf::Uint8 data[sq_getsize(v, -2)];
            while (SQ_SUCCEEDED(sq_next(v, -2))) {
                SQInteger key;
                sq_getinteger(v, -2, &key);
                Sqrat::Var<sf::Uint8> pixel(v, -1);
                if (Sqrat::Error::Occurred(v)) {
                    return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
                }
                sq_pop(v, 2);
                data[key] = pixel.value;
            }
            sq_pop(v, 2);
            left.value.update(data, width.value, height.value, x.value, y.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML texture library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlTextureLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Texture> sfTexture(v, _SC("sf.Texture"));
    sfTexture.SquirrelFunc(_SC("constructor"), &sfTexture_constructor);
    sfTexture.SquirrelFunc(_SC("loadFromFile"), &sfTexture_loadFromFile);
    sfTexture.SquirrelFunc(_SC("loadFromImage"), &sfTexture_loadFromImage);
    sfTexture.SquirrelFunc(_SC("loadFromMemory"), &sfTexture_loadFromMemory);
    sfTexture.SquirrelFunc(_SC("update"), &sfTexture_update);
    sfTexture.Func(_SC("copyToImage"), &sf::Texture::copyToImage);
    sfTexture.Func(_SC("create"), &sf::Texture::create);
    sfTexture.StaticFunc(_SC("getMaximumSize"), &sf::Texture::getMaximumSize);
    sfTexture.Func(_SC("getSize"), &sf::Texture::getSize);
    sfTexture.Func(_SC("isRepeated"), &sf::Texture::isRepeated);
    sfTexture.Func(_SC("isSmooth"), &sf::Texture::isSmooth);
    sfTexture.Func(_SC("setRepeated"), &sf::Texture::setRepeated);
    sfTexture.Func(_SC("setSmooth"), &sf::Texture::setSmooth);

    namespaceTable.Bind(_SC("Texture"), sfTexture);
}

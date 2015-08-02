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
#include <SFML/Graphics/Image.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfImage_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Image* instance = new sf::Image();
        Sqrat::DefaultAllocator<sf::Image>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Image&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Image* instance = new sf::Image(copy.value);
            Sqrat::DefaultAllocator<sf::Image>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Copies pixels from another image onto this one
////////////////////////////////////////////////////////////
static SQInteger sfImage_copy(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<const sf::Image&> source(v, 2);
        Sqrat::Var<unsigned int> destX(v, 3);
        Sqrat::Var<unsigned int> destY(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.copy(source.value, destX.value, destY.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<const sf::Image&> source(v, 2);
        Sqrat::Var<unsigned int> destX(v, 3);
        Sqrat::Var<unsigned int> destY(v, 4);
        Sqrat::Var<const sf::IntRect&> sourceRect(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.copy(source.value, destX.value, destY.value, sourceRect.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 6) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<const sf::Image&> source(v, 2);
        Sqrat::Var<unsigned int> destX(v, 3);
        Sqrat::Var<unsigned int> destY(v, 4);
        Sqrat::Var<const sf::IntRect&> sourceRect(v, 5);
        Sqrat::Var<bool> applyAlpha(v, 6);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.copy(source.value, destX.value, destY.value, sourceRect.value, applyAlpha.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Creates the image
////////////////////////////////////////////////////////////
static SQInteger sfImage_create(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<unsigned int> width(v, 2);
        Sqrat::Var<unsigned int> height(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.create(width.value, height.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<unsigned int> width(v, 2);
        Sqrat::Var<unsigned int> height(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<const sf::Color&> color(v, 4);
            if (!Sqrat::Error::Occurred(v)) {
                left.value.create(width.value, height.value, color.value);
                return 0;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<Sqrat::Array> pixels(v, 4);
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
                left.value.create(width.value, height.value, data);
                return 0;
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 4, Sqrat::ClassType<sf::Color>::ClassName() + _SC("|array")).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Creates a transparency mask from a specified color-key
////////////////////////////////////////////////////////////
static SQInteger sfImage_createMaskFromColor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<const sf::Color&> color(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.createMaskFromColor(color.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<const sf::Color&> color(v, 2);
        Sqrat::Var<sf::Uint8> alpha(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.createMaskFromColor(color.value, alpha.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Gets an array representing the image's pixels
////////////////////////////////////////////////////////////
static SQInteger sfImage_getPixels(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        Sqrat::Var<sf::Image&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            const sf::Uint8* data = left.value.getPixelsPtr();
            sq_newarray(v, left.value.getSize().x * left.value.getSize().y * 4);
            for (std::size_t i = 0; i < left.value.getSize().x * left.value.getSize().y * 4; ++i) {
                Sqrat::PushVar(v, i);
                Sqrat::PushVar(v, data[i]);
                sq_rawset(v, -3);
            }
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Loads the image from a file in memory
////////////////////////////////////////////////////////////
static SQInteger sfImage_loadFromMemory(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Image&> left(v, 1);
        Sqrat::Var<const std::string&> data(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromMemory(data.value.c_str(), data.value.size()));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML image library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlImageLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Image> sfImage(v, _SC("sf.Image"));
    sfImage.SquirrelFunc(_SC("constructor"), &sfImage_constructor);
    sfImage.SquirrelFunc(_SC("copy"), &sfImage_copy);
    sfImage.SquirrelFunc(_SC("create"), &sfImage_create);
    sfImage.SquirrelFunc(_SC("createMaskFromColor"), &sfImage_createMaskFromColor);
    sfImage.SquirrelFunc(_SC("getPixels"), &sfImage_getPixels);
    sfImage.SquirrelFunc(_SC("loadFromMemory"), &sfImage_loadFromMemory);
    sfImage.Func(_SC("flipHorizontally"), &sf::Image::flipHorizontally);
    sfImage.Func(_SC("flipVertically"), &sf::Image::flipVertically);
    sfImage.Func(_SC("getPixel"), &sf::Image::getPixel);
    sfImage.Func(_SC("getSize"), &sf::Image::getSize);
    sfImage.Func(_SC("loadFromFile"), &sf::Image::loadFromFile);
    sfImage.Func(_SC("saveToFile"), &sf::Image::saveToFile);
    sfImage.Func(_SC("setPixel"), &sf::Image::setPixel);

    namespaceTable.Bind(_SC("Image"), sfImage);
}

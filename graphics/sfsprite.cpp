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
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfSprite_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Sprite* instance = new sf::Sprite();
        Sqrat::DefaultAllocator<sf::Sprite>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Sprite&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Sprite* instance = new sf::Sprite(copy.value);
            Sqrat::DefaultAllocator<sf::Sprite>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Texture&> texture(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Sprite* instance = new sf::Sprite(texture.value);
            Sqrat::DefaultAllocator<sf::Sprite>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Sprite>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Texture>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<const sf::Texture&> texture(v, 2);
        Sqrat::Var<const sf::IntRect&> rectangle(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Sprite* instance = new sf::Sprite(texture.value, rectangle.value);
            Sqrat::DefaultAllocator<sf::Sprite>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Changes the source texture of the sprite
////////////////////////////////////////////////////////////
static SQInteger sfSprite_setTexture(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Sprite&> left(v, 1);
        Sqrat::Var<const sf::Texture&> texture(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setTexture(texture.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Sprite&> left(v, 1);
        Sqrat::Var<const sf::Texture&> texture(v, 2);
        Sqrat::Var<bool> resetRect(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setTexture(texture.value, resetRect.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML sprite library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlSpriteLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::DerivedClass<sf::Sprite, sf::Transformable> sfSprite(v, _SC("sf.Sprite"));
    sfSprite.SquirrelFunc(_SC("constructor"), &sfSprite_constructor);
    sfSprite.SquirrelFunc(_SC("setTexture"), &sfSprite_setTexture);
    sfSprite.Func(_SC("getColor"), &sf::Sprite::getColor);
    sfSprite.Func(_SC("getGlobalBounds"), &sf::Sprite::getGlobalBounds);
    sfSprite.Func(_SC("getLocalBounds"), &sf::Sprite::getLocalBounds);
    sfSprite.Func(_SC("getTexture"), &sf::Sprite::getTexture);
    sfSprite.Func(_SC("getTextureRect"), &sf::Sprite::getTextureRect);
    sfSprite.Func(_SC("setColor"), &sf::Sprite::setColor);
    sfSprite.Func(_SC("setTextureRect"), &sf::Sprite::setTextureRect);

    namespaceTable.Bind(_SC("Sprite"), sfSprite);
}

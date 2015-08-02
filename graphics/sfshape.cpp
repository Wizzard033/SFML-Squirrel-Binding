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
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfShape_constructor(HSQUIRRELVM v)
{
    return sq_throwerror(v, _SC("constructor is protected"));
}


////////////////////////////////////////////////////////////
// Changes the source texture of the shape
////////////////////////////////////////////////////////////
static SQInteger sfShape_setTexture(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Shape&> left(v, 1);
        Sqrat::Var<const sf::Texture*> texture(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setTexture(texture.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Shape&> left(v, 1);
        Sqrat::Var<const sf::Texture*> texture(v, 2);
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
// Initializes and registers the SFML shape library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlShapeLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::DerivedClass<sf::Shape, sf::Transformable, Sqrat::NoConstructor<sf::Shape> > sfShape(v, _SC("sf.Shape"));
    sfShape.SquirrelFunc(_SC("constructor"), &sfShape_constructor);
    sfShape.SquirrelFunc(_SC("setTexture"), &sfShape_setTexture);
    sfShape.Func(_SC("getFillColor"), &sf::Shape::getFillColor);
    sfShape.Func(_SC("getGlobalBounds"), &sf::Shape::getGlobalBounds);
    sfShape.Func(_SC("getLocalBounds"), &sf::Shape::getLocalBounds);
    sfShape.Func(_SC("getOutlineColor"), &sf::Shape::getOutlineColor);
    sfShape.Func(_SC("getOutlineThickness"), &sf::Shape::getOutlineThickness);
    sfShape.Func(_SC("getTexture"), &sf::Shape::getTexture);
    sfShape.Func(_SC("getTextureRect"), &sf::Shape::getTextureRect);
    sfShape.Func(_SC("setFillColor"), &sf::Shape::setFillColor);
    sfShape.Func(_SC("setOutlineColor"), &sf::Shape::setOutlineColor);
    sfShape.Func(_SC("setOutlineThickness"), &sf::Shape::setOutlineThickness);
    sfShape.Func(_SC("setTextureRect"), &sf::Shape::setTextureRect);

    namespaceTable.Bind(_SC("Shape"), sfShape);
}

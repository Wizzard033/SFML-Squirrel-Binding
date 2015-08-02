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
#include <SFML/Graphics/RectangleShape.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfRectangleShape_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::RectangleShape* instance = new sf::RectangleShape();
        Sqrat::DefaultAllocator<sf::RectangleShape>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::RectangleShape&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RectangleShape* instance = new sf::RectangleShape(copy.value);
            Sqrat::DefaultAllocator<sf::RectangleShape>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2f&> size(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RectangleShape* instance = new sf::RectangleShape(size.value);
            Sqrat::DefaultAllocator<sf::RectangleShape>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::RectangleShape>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML rectangle shape library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlRectangleShapeLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::DerivedClass<sf::RectangleShape, sf::Shape> sfRectangleShape(v, _SC("sf.RectangleShape"));
    sfRectangleShape.SquirrelFunc(_SC("constructor"), &sfRectangleShape_constructor);
    sfRectangleShape.Func(_SC("getPoint"), &sf::RectangleShape::getPoint);
    sfRectangleShape.Func(_SC("getPointCount"), &sf::RectangleShape::getPointCount);
    sfRectangleShape.Func(_SC("getSize"), &sf::RectangleShape::getSize);
    sfRectangleShape.Func(_SC("setSize"), &sf::RectangleShape::setSize);

    namespaceTable.Bind(_SC("RectangleShape"), sfRectangleShape);
}

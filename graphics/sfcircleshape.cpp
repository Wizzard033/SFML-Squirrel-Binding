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
#include <SFML/Graphics/CircleShape.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfCircleShape_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::CircleShape* instance = new sf::CircleShape();
        Sqrat::DefaultAllocator<sf::CircleShape>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::CircleShape&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::CircleShape* instance = new sf::CircleShape(copy.value);
            Sqrat::DefaultAllocator<sf::CircleShape>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<float> radius(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::CircleShape* instance = new sf::CircleShape(radius.value);
            Sqrat::DefaultAllocator<sf::CircleShape>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::CircleShape>::ClassName() + _SC("|float")).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<float> radius(v, 2);
        Sqrat::Var<unsigned int> pointCount(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::CircleShape* instance = new sf::CircleShape(radius.value, pointCount.value);
            Sqrat::DefaultAllocator<sf::CircleShape>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML circle shape library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlCircleShapeLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::DerivedClass<sf::CircleShape, sf::Shape> sfCircleShape(v, _SC("sf.CircleShape"));
    sfCircleShape.SquirrelFunc(_SC("constructor"), &sfCircleShape_constructor);
    sfCircleShape.Func(_SC("getPoint"), &sf::CircleShape::getPoint);
    sfCircleShape.Func(_SC("getPointCount"), &sf::CircleShape::getPointCount);
    sfCircleShape.Func(_SC("getRadius"), &sf::CircleShape::getRadius);
    sfCircleShape.Func(_SC("setPointCount"), &sf::CircleShape::setPointCount);
    sfCircleShape.Func(_SC("setRadius"), &sf::CircleShape::setRadius);

    namespaceTable.Bind(_SC("CircleShape"), sfCircleShape);
}

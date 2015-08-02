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
#include <SFML/Graphics/ConvexShape.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfConvexShape_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::ConvexShape* instance = new sf::ConvexShape();
        Sqrat::DefaultAllocator<sf::ConvexShape>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::ConvexShape&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::ConvexShape* instance = new sf::ConvexShape(copy.value);
            Sqrat::DefaultAllocator<sf::ConvexShape>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<unsigned int> pointCount(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::ConvexShape* instance = new sf::ConvexShape(pointCount.value);
            Sqrat::DefaultAllocator<sf::ConvexShape>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::ConvexShape>::ClassName() + _SC("|float")).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML convex shape library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlConvexShapeLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::DerivedClass<sf::ConvexShape, sf::Shape> sfConvexShape(v, _SC("sf.ConvexShape"));
    sfConvexShape.SquirrelFunc(_SC("constructor"), &sfConvexShape_constructor);
    sfConvexShape.Func(_SC("getPoint"), &sf::ConvexShape::getPoint);
    sfConvexShape.Func(_SC("getPointCount"), &sf::ConvexShape::getPointCount);
    sfConvexShape.Func(_SC("setPoint"), &sf::ConvexShape::setPoint);
    sfConvexShape.Func(_SC("setPointCount"), &sf::ConvexShape::setPointCount);

    namespaceTable.Bind(_SC("ConvexShape"), sfConvexShape);
}

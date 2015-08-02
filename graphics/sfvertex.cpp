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
#include <SFML/Graphics/Vertex.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVertex_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Vertex* instance = new sf::Vertex();
        Sqrat::DefaultAllocator<sf::Vertex>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Vertex&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vertex* instance = new sf::Vertex(copy.value);
            Sqrat::DefaultAllocator<sf::Vertex>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2f&> thePosition(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vertex* instance = new sf::Vertex(thePosition.value);
            Sqrat::DefaultAllocator<sf::Vertex>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Vertex>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<const sf::Vector2f&> thePosition(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<const sf::Color&> theColor(v, 3);
            if (!Sqrat::Error::Occurred(v)) {
                sf::Vertex* instance = new sf::Vertex(thePosition.value, theColor.value);
                Sqrat::DefaultAllocator<sf::Vertex>::SetInstance(v, 1, instance);
                return 0;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const sf::Vector2f&> theTexCoords(v, 3);
            if (!Sqrat::Error::Occurred(v)) {
                sf::Vertex* instance = new sf::Vertex(thePosition.value, theTexCoords.value);
                Sqrat::DefaultAllocator<sf::Vertex>::SetInstance(v, 1, instance);
                return 0;
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 3, Sqrat::ClassType<sf::Color>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<const sf::Vector2f&> thePosition(v, 2);
        Sqrat::Var<const sf::Color&> theColor(v, 3);
        Sqrat::Var<const sf::Vector2f&> theTexCoords(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vertex* instance = new sf::Vertex(thePosition.value, theColor.value, theTexCoords.value);
            Sqrat::DefaultAllocator<sf::Vertex>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML vertex library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlVertexLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Vertex> sfVertex(v, _SC("sf.Vertex"));
    sfVertex.SquirrelFunc(_SC("constructor"), &sfVertex_constructor);
    sfVertex.Var(_SC("position"), &sf::Vertex::position);
    sfVertex.Var(_SC("color"), &sf::Vertex::color);
    sfVertex.Var(_SC("texCoords"), &sf::Vertex::texCoords);

    namespaceTable.Bind(_SC("Vertex"), sfVertex);
}

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
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfRenderStates_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::RenderStates* instance = new sf::RenderStates();
        Sqrat::DefaultAllocator<sf::RenderStates>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::RenderStates&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderStates* instance = new sf::RenderStates(copy.value);
            Sqrat::DefaultAllocator<sf::RenderStates>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::BlendMode&> theBlendMode(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderStates* instance = new sf::RenderStates(theBlendMode.value);
            Sqrat::DefaultAllocator<sf::RenderStates>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Transform&> theTransform(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderStates* instance = new sf::RenderStates(theTransform.value);
            Sqrat::DefaultAllocator<sf::RenderStates>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Texture*> theTexture(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderStates* instance = new sf::RenderStates(theTexture.value);
            Sqrat::DefaultAllocator<sf::RenderStates>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::RenderStates>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Transform>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Texture>::ClassName()).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<const sf::BlendMode&> theBlendMode(v, 2);
        Sqrat::Var<const sf::Transform&> theTransform(v, 3);
        Sqrat::Var<const sf::Texture*> theTexture(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderStates* instance = new sf::RenderStates(theBlendMode.value, theTransform.value, theTexture.value, NULL);
            Sqrat::DefaultAllocator<sf::RenderStates>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML render states library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlRenderStatesLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::RenderStates> sfRenderStates(v, _SC("sf.RenderStates"));
    sfRenderStates.SquirrelFunc(_SC("constructor"), &sfRenderStates_constructor);
    sfRenderStates.Var(_SC("transform"), &sf::RenderStates::transform);
    sfRenderStates.Var(_SC("texture"), &sf::RenderStates::texture);
    sfRenderStates.SetStaticValue(_SC("Default"), sf::RenderStates::Default);

    namespaceTable.Bind(_SC("RenderStates"), sfRenderStates);
}

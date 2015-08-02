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
#include <SFML/System/Clock.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfClock_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Clock* instance = new sf::Clock();
        Sqrat::DefaultAllocator<sf::Clock>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Clock&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Clock* instance = new sf::Clock(copy.value);
            Sqrat::DefaultAllocator<sf::Clock>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML clock library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlClockLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Clock> sfClock(v, _SC("sf.Clock"));
    sfClock.SquirrelFunc(_SC("constructor"), &sfClock_constructor);
    sfClock.Func(_SC("getElapsedTime"), &sf::Clock::getElapsedTime);
    sfClock.Func(_SC("restart"), &sf::Clock::restart);

    namespaceTable.Bind(_SC("Clock"), sfClock);
}

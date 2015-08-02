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
#include <SFML/System/Time.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfTime_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Time* instance = new sf::Time();
        Sqrat::DefaultAllocator<sf::Time>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Time&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Time* instance = new sf::Time(copy.value);
            Sqrat::DefaultAllocator<sf::Time>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfTime_equals(const sf::Time& left, const sf::Time& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// The + operator
////////////////////////////////////////////////////////////
static sf::Time sfTime_add(const sf::Time& left, const sf::Time& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// The - operator
////////////////////////////////////////////////////////////
static sf::Time sfTime_sub(const sf::Time& left, const sf::Time& right)
{
    return left - right;
}


////////////////////////////////////////////////////////////
// The / operator
////////////////////////////////////////////////////////////
static float sfTime_div(const sf::Time& left, const sf::Time& right)
{
    return left / right;
}


////////////////////////////////////////////////////////////
// The % operator
////////////////////////////////////////////////////////////
static sf::Time sfTime_modulo(const sf::Time& left, const sf::Time& right)
{
    return left % right;
}


////////////////////////////////////////////////////////////
// The unary minus operator
////////////////////////////////////////////////////////////
static sf::Time sfTime_unm(const sf::Time& right)
{
    return -right;
}


////////////////////////////////////////////////////////////
// Invoked to emulate the < > <= >= operators
////////////////////////////////////////////////////////////
static int sfTime_cmp(const sf::Time& left, const sf::Time& right)
{
    if (left == right)
        return 0;
    if (left < right)
        return -1;
    return 1;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML time library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlTimeLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Time> sfTime(v, _SC("sf.Time"));
    sfTime.SquirrelFunc(_SC("constructor"), &sfTime_constructor);
    sfTime.GlobalFunc(_SC("equals"), &sfTime_equals);
    sfTime.Func(_SC("asSeconds"), &sf::Time::asSeconds);
    sfTime.Func(_SC("asMilliseconds"), &sf::Time::asMilliseconds);
    sfTime.Func(_SC("asMicroseconds"), &sf::Time::asMicroseconds);
    sfTime.SetStaticValue(_SC("Zero"), sf::Time::Zero);
    sfTime.GlobalFunc(_SC("_add"), &sfTime_add);
    sfTime.GlobalFunc(_SC("_sub"), &sfTime_sub);
    sfTime.GlobalFunc(_SC("_div"), &sfTime_div);
    sfTime.GlobalFunc(_SC("_modulo"), &sfTime_modulo);
    sfTime.GlobalFunc(_SC("_unm"), &sfTime_unm);
    sfTime.GlobalFunc(_SC("_cmp"), &sfTime_cmp);

    namespaceTable.Bind(_SC("Time"), sfTime);
    namespaceTable.Func(_SC("seconds"), &sf::seconds);
    namespaceTable.Func(_SC("milliseconds"), &sf::milliseconds);
    namespaceTable.Func(_SC("microseconds"), &sf::microseconds);
}

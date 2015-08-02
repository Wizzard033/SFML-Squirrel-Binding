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
#include <SFML/Graphics/Color.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfColor_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Color* instance = new sf::Color();
        Sqrat::DefaultAllocator<sf::Color>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Color&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Color* instance = new sf::Color(copy.value);
            Sqrat::DefaultAllocator<sf::Color>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::Uint8> red(v, 2);
        Sqrat::Var<sf::Uint8> green(v, 3);
        Sqrat::Var<sf::Uint8> blue(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Color* instance = new sf::Color(red.value, green.value, blue.value);
            Sqrat::DefaultAllocator<sf::Color>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<sf::Uint8> red(v, 2);
        Sqrat::Var<sf::Uint8> green(v, 3);
        Sqrat::Var<sf::Uint8> blue(v, 4);
        Sqrat::Var<sf::Uint8> alpha(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Color* instance = new sf::Color(red.value, green.value, blue.value, alpha.value);
            Sqrat::DefaultAllocator<sf::Color>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfColor_equals(const sf::Color& left, const sf::Color& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// The + operator
////////////////////////////////////////////////////////////
static sf::Color sfColor_add(const sf::Color& left, const sf::Color& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// The - operator
////////////////////////////////////////////////////////////
static sf::Color sfColor_sub(const sf::Color& left, const sf::Color& right)
{
    return left - right;
}


////////////////////////////////////////////////////////////
// The * operator
////////////////////////////////////////////////////////////
static sf::Color sfColor_mul(const sf::Color& left, const sf::Color& right)
{
    return left * right;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML color library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlColorLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Color> sfColor(v, _SC("sf.Color"));
    sfColor.SquirrelFunc(_SC("constructor"), &sfColor_constructor);
    sfColor.GlobalFunc(_SC("equals"), &sfColor_equals);
    sfColor.Var(_SC("r"), &sf::Color::r);
    sfColor.Var(_SC("g"), &sf::Color::g);
    sfColor.Var(_SC("b"), &sf::Color::b);
    sfColor.Var(_SC("a"), &sf::Color::a);
    sfColor.SetStaticValue(_SC("Black"), sf::Color::Black);
    sfColor.SetStaticValue(_SC("White"), sf::Color::White);
    sfColor.SetStaticValue(_SC("Red"), sf::Color::Red);
    sfColor.SetStaticValue(_SC("Green"), sf::Color::Green);
    sfColor.SetStaticValue(_SC("Blue"), sf::Color::Blue);
    sfColor.SetStaticValue(_SC("Yellow"), sf::Color::Yellow);
    sfColor.SetStaticValue(_SC("Magenta"), sf::Color::Magenta);
    sfColor.SetStaticValue(_SC("Cyan"), sf::Color::Cyan);
    sfColor.SetStaticValue(_SC("Transparent"), sf::Color::Transparent);
    sfColor.GlobalFunc(_SC("_add"), &sfColor_add);
    sfColor.GlobalFunc(_SC("_sub"), &sfColor_sub);
    sfColor.GlobalFunc(_SC("_mul"), &sfColor_mul);

    namespaceTable.Bind(_SC("Color"), sfColor);
}

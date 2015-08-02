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
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfMouse_constructor(HSQUIRRELVM v)
{
    return sq_throwerror(v, _SC("constructor is protected"));
}


////////////////////////////////////////////////////////////
// Gets the current position of the mouse
////////////////////////////////////////////////////////////
static SQInteger sfMouse_getPosition(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        Sqrat::PushVar(v, sf::Mouse::getPosition());
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::RenderWindow&> relativeTo(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, sf::Mouse::getPosition(relativeTo.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets the current position of the mouse
////////////////////////////////////////////////////////////
static SQInteger sfMouse_setPosition(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Vector2i&> position(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Mouse::setPosition(position.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<const sf::Vector2i&> position(v, 2);
        Sqrat::Var<const sf::RenderWindow&> relativeTo(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Mouse::setPosition(position.value, relativeTo.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML mouse library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlMouseLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::ConstTable constTable(v);
    constTable.Const(_SC("SF_MOUSE_LEFT"), static_cast<int>(sf::Mouse::Left));
    constTable.Const(_SC("SF_MOUSE_RIGHT"), static_cast<int>(sf::Mouse::Right));
    constTable.Const(_SC("SF_MOUSE_MIDDLE"), static_cast<int>(sf::Mouse::Middle));
    constTable.Const(_SC("SF_MOUSE_XBUTTON1"), static_cast<int>(sf::Mouse::XButton1));
    constTable.Const(_SC("SF_MOUSE_XBUTTON2"), static_cast<int>(sf::Mouse::XButton2));

    Sqrat::Class<sf::Mouse> sfMouse(v, _SC("sf.Mouse"));
    sfMouse.SquirrelFunc(_SC("constructor"), &sfMouse_constructor);
    sfMouse.SquirrelFunc(_SC("getPosition"), &sfMouse_getPosition);
    sfMouse.SquirrelFunc(_SC("setPosition"), &sfMouse_setPosition);
    sfMouse.StaticFunc(_SC("isButtonPressed"), &sf::Mouse::isButtonPressed);

    namespaceTable.Bind(_SC("Mouse"), sfMouse);
}

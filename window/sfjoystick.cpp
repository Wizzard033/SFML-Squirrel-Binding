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
#include <SFML/Window/Joystick.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfJoystickIdentification_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Joystick::Identification>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Joystick::Identification* instance = new sf::Joystick::Identification();
        Sqrat::DefaultAllocator<sf::Joystick::Identification>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Joystick::Identification&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Joystick::Identification>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Joystick::Identification* instance = new sf::Joystick::Identification(copy.value);
            Sqrat::DefaultAllocator<sf::Joystick::Identification>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfJoystick_constructor(HSQUIRRELVM v)
{
    return sq_throwerror(v, _SC("constructor is protected"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML joystick library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlJoystickLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::ConstTable constTable(v);
    constTable.Const(_SC("SF_JOYSTICK_COUNT"), static_cast<int>(sf::Joystick::Count));
    constTable.Const(_SC("SF_JOYSTICK_BUTTON_COUNT"), static_cast<int>(sf::Joystick::ButtonCount));
    constTable.Const(_SC("SF_JOYSTICK_AXIS_COUNT"), static_cast<int>(sf::Joystick::AxisCount));
    constTable.Const(_SC("SF_JOYSTICK_X"), static_cast<int>(sf::Joystick::X));
    constTable.Const(_SC("SF_JOYSTICK_Y"), static_cast<int>(sf::Joystick::Y));
    constTable.Const(_SC("SF_JOYSTICK_Z"), static_cast<int>(sf::Joystick::Z));
    constTable.Const(_SC("SF_JOYSTICK_R"), static_cast<int>(sf::Joystick::R));
    constTable.Const(_SC("SF_JOYSTICK_U"), static_cast<int>(sf::Joystick::U));
    constTable.Const(_SC("SF_JOYSTICK_V"), static_cast<int>(sf::Joystick::V));
    constTable.Const(_SC("SF_JOYSTICK_POVX"), static_cast<int>(sf::Joystick::PovX));
    constTable.Const(_SC("SF_JOYSTICK_POVY"), static_cast<int>(sf::Joystick::PovY));

    Sqrat::Class<sf::Joystick::Identification> sfJoystickIdentification(v, _SC("sf.Joystick.Identification"));
    sfJoystickIdentification.Var(_SC("name"), &sf::Joystick::Identification::name);
    sfJoystickIdentification.Var(_SC("vendorId"), &sf::Joystick::Identification::vendorId);
    sfJoystickIdentification.Var(_SC("productId"), &sf::Joystick::Identification::productId);

    Sqrat::Class<sf::Joystick> sfJoystick(v, _SC("sf.Joystick"));
    sfJoystick.SquirrelFunc(_SC("constructor"), &sfJoystick_constructor);
    sfJoystick.SquirrelFunc(_SC("Identification"), &sfJoystickIdentification_constructor);
    sfJoystick.StaticFunc(_SC("isConnected"), &sf::Joystick::isConnected);
    sfJoystick.StaticFunc(_SC("getButtonCount"), &sf::Joystick::getButtonCount);
    sfJoystick.StaticFunc(_SC("hasAxis"), &sf::Joystick::hasAxis);
    sfJoystick.StaticFunc(_SC("isButtonPressed"), &sf::Joystick::isButtonPressed);
    sfJoystick.StaticFunc(_SC("getAxisPosition"), &sf::Joystick::getAxisPosition);
    sfJoystick.StaticFunc(_SC("getIdentification"), &sf::Joystick::getIdentification);
    sfJoystick.StaticFunc(_SC("update"), &sf::Joystick::update);

    namespaceTable.Bind(_SC("Joystick"), sfJoystick);
}

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
#include <SFML/Window/Event.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventJoystickButtonEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::JoystickButtonEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::JoystickButtonEvent* instance = new sf::Event::JoystickButtonEvent();
        Sqrat::DefaultAllocator<sf::Event::JoystickButtonEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::JoystickButtonEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::JoystickButtonEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::JoystickButtonEvent* instance = new sf::Event::JoystickButtonEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::JoystickButtonEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventJoystickConnectEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::JoystickConnectEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::JoystickConnectEvent* instance = new sf::Event::JoystickConnectEvent();
        Sqrat::DefaultAllocator<sf::Event::JoystickConnectEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::JoystickConnectEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::JoystickConnectEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::JoystickConnectEvent* instance = new sf::Event::JoystickConnectEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::JoystickConnectEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventJoystickMoveEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::JoystickMoveEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::JoystickMoveEvent* instance = new sf::Event::JoystickMoveEvent();
        Sqrat::DefaultAllocator<sf::Event::JoystickMoveEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::JoystickMoveEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::JoystickMoveEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::JoystickMoveEvent* instance = new sf::Event::JoystickMoveEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::JoystickMoveEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventKeyEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::KeyEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::KeyEvent* instance = new sf::Event::KeyEvent();
        Sqrat::DefaultAllocator<sf::Event::KeyEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::KeyEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::KeyEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::KeyEvent* instance = new sf::Event::KeyEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::KeyEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventMouseButtonEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::MouseButtonEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::MouseButtonEvent* instance = new sf::Event::MouseButtonEvent();
        Sqrat::DefaultAllocator<sf::Event::MouseButtonEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::MouseButtonEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::MouseButtonEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::MouseButtonEvent* instance = new sf::Event::MouseButtonEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::MouseButtonEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventMouseMoveEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::MouseMoveEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::MouseMoveEvent* instance = new sf::Event::MouseMoveEvent();
        Sqrat::DefaultAllocator<sf::Event::MouseMoveEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::MouseMoveEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::MouseMoveEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::MouseMoveEvent* instance = new sf::Event::MouseMoveEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::MouseMoveEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventMouseWheelEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::MouseWheelEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::MouseWheelEvent* instance = new sf::Event::MouseWheelEvent();
        Sqrat::DefaultAllocator<sf::Event::MouseWheelEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::MouseWheelEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::MouseWheelEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::MouseWheelEvent* instance = new sf::Event::MouseWheelEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::MouseWheelEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventSizeEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::SizeEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::SizeEvent* instance = new sf::Event::SizeEvent();
        Sqrat::DefaultAllocator<sf::Event::SizeEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::SizeEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::SizeEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::SizeEvent* instance = new sf::Event::SizeEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::SizeEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEventTextEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Event::TextEvent>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Event::TextEvent* instance = new sf::Event::TextEvent();
        Sqrat::DefaultAllocator<sf::Event::TextEvent>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event::TextEvent&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Event::TextEvent>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Event::TextEvent* instance = new sf::Event::TextEvent(copy.value);
            Sqrat::DefaultAllocator<sf::Event::TextEvent>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfEvent_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Event* instance = new sf::Event();
        Sqrat::DefaultAllocator<sf::Event>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Event&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Event* instance = new sf::Event(copy.value);
            Sqrat::DefaultAllocator<sf::Event>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML event library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlEventLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Event::JoystickButtonEvent> sfEventJoystickButtonEvent(v, _SC("sf.Event.JoystickButtonEvent"));
    sfEventJoystickButtonEvent.Var(_SC("joystickId"), &sf::Event::JoystickButtonEvent::joystickId);
    sfEventJoystickButtonEvent.Var(_SC("button"), &sf::Event::JoystickButtonEvent::button);

    Sqrat::Class<sf::Event::JoystickConnectEvent> sfEventJoystickConnectEvent(v, _SC("sf.Event.JoystickConnectEvent"));
    sfEventJoystickConnectEvent.Var(_SC("joystickId"), &sf::Event::JoystickConnectEvent::joystickId);

    Sqrat::Class<sf::Event::JoystickMoveEvent> sfEventJoystickMoveEvent(v, _SC("sf.Event.JoystickMoveEvent"));
    sfEventJoystickMoveEvent.Var(_SC("axis"), &sf::Event::JoystickMoveEvent::axis);
    sfEventJoystickMoveEvent.Var(_SC("joystickId"), &sf::Event::JoystickMoveEvent::joystickId);
    sfEventJoystickMoveEvent.Var(_SC("position"), &sf::Event::JoystickMoveEvent::position);

    Sqrat::Class<sf::Event::KeyEvent> sfEventKeyEvent(v, _SC("sf.Event.KeyEvent"));
    sfEventKeyEvent.Var(_SC("code"), &sf::Event::KeyEvent::code);
    sfEventKeyEvent.Var(_SC("alt"), &sf::Event::KeyEvent::alt);
    sfEventKeyEvent.Var(_SC("control"), &sf::Event::KeyEvent::control);
    sfEventKeyEvent.Var(_SC("shift"), &sf::Event::KeyEvent::shift);
    sfEventKeyEvent.Var(_SC("control"), &sf::Event::KeyEvent::system);

    Sqrat::Class<sf::Event::MouseButtonEvent> sfEventMouseButtonEvent(v, _SC("sf.Event.MouseButtonEvent"));
    sfEventMouseButtonEvent.Var(_SC("button"), &sf::Event::MouseButtonEvent::button);
    sfEventMouseButtonEvent.Var(_SC("x"), &sf::Event::MouseButtonEvent::x);
    sfEventMouseButtonEvent.Var(_SC("y"), &sf::Event::MouseButtonEvent::y);

    Sqrat::Class<sf::Event::MouseMoveEvent> sfEventMouseMoveEvent(v, _SC("sf.Event.MouseMoveEvent"));
    sfEventMouseMoveEvent.Var(_SC("x"), &sf::Event::MouseMoveEvent::x);
    sfEventMouseMoveEvent.Var(_SC("y"), &sf::Event::MouseMoveEvent::y);

    Sqrat::Class<sf::Event::MouseWheelEvent> sfEventMouseWheelEvent(v, _SC("sf.Event.MouseWheelEvent"));
    sfEventMouseWheelEvent.Var(_SC("delta"), &sf::Event::MouseWheelEvent::delta);
    sfEventMouseWheelEvent.Var(_SC("x"), &sf::Event::MouseWheelEvent::x);
    sfEventMouseWheelEvent.Var(_SC("y"), &sf::Event::MouseWheelEvent::y);

    Sqrat::Class<sf::Event::SizeEvent> sfEventSizeEvent(v, _SC("sf.Event.SizeEvent"));
    sfEventSizeEvent.Var(_SC("width"), &sf::Event::SizeEvent::width);
    sfEventSizeEvent.Var(_SC("height"), &sf::Event::SizeEvent::height);

    Sqrat::Class<sf::Event::TextEvent> sfEventTextEvent(v, _SC("sf.Event.TextEvent"));
    sfEventTextEvent.Var(_SC("unicode"), &sf::Event::TextEvent::unicode);

    Sqrat::ConstTable constTable(v);
    constTable.Const(_SC("SF_EVENT_CLOSED"), static_cast<int>(sf::Event::Closed));
    constTable.Const(_SC("SF_EVENT_RESIZED"), static_cast<int>(sf::Event::Resized));
    constTable.Const(_SC("SF_EVENT_LOST_FOCUS"), static_cast<int>(sf::Event::LostFocus));
    constTable.Const(_SC("SF_EVENT_GAINED_FOCUS"), static_cast<int>(sf::Event::GainedFocus));
    constTable.Const(_SC("SF_EVENT_TEXT_ENTERED"), static_cast<int>(sf::Event::TextEntered));
    constTable.Const(_SC("SF_EVENT_KEY_PRESSED"), static_cast<int>(sf::Event::KeyPressed));
    constTable.Const(_SC("SF_EVENT_KEY_RELEASED"), static_cast<int>(sf::Event::KeyReleased));
    constTable.Const(_SC("SF_EVENT_MOUSE_WHEEL_MOVED"), static_cast<int>(sf::Event::MouseWheelMoved));
    constTable.Const(_SC("SF_EVENT_MOUSE_BUTTON_PRESSED"), static_cast<int>(sf::Event::MouseButtonPressed));
    constTable.Const(_SC("SF_EVENT_MOUSE_BUTTON_RELEASED"), static_cast<int>(sf::Event::MouseButtonReleased));
    constTable.Const(_SC("SF_EVENT_MOUSE_MOVED"), static_cast<int>(sf::Event::MouseMoved));
    constTable.Const(_SC("SF_EVENT_MOUSE_ENTERED"), static_cast<int>(sf::Event::MouseEntered));
    constTable.Const(_SC("SF_EVENT_MOUSE_LEFT"), static_cast<int>(sf::Event::MouseLeft));
    constTable.Const(_SC("SF_EVENT_JOYSTICK_BUTTON_PRESSED"), static_cast<int>(sf::Event::JoystickButtonPressed));
    constTable.Const(_SC("SF_EVENT_JOYSTICK_BUTTON_RELEASED"), static_cast<int>(sf::Event::JoystickButtonReleased));
    constTable.Const(_SC("SF_EVENT_JOYSTICK_MOVED"), static_cast<int>(sf::Event::JoystickMoved));
    constTable.Const(_SC("SF_EVENT_JOYSTICK_CONNECTED"), static_cast<int>(sf::Event::JoystickConnected));
    constTable.Const(_SC("SF_EVENT_JOYSTICK_DISCONNECTED"), static_cast<int>(sf::Event::JoystickDisconnected));

    Sqrat::Class<sf::Event> sfEvent(v, _SC("sf.Event"));
    sfEvent.SquirrelFunc(_SC("constructor"), &sfEvent_constructor);
    sfEvent.SquirrelFunc(_SC("JoystickButtonEvent"), &sfEventJoystickButtonEvent_constructor);
    sfEvent.SquirrelFunc(_SC("JoystickConnectEvent"), &sfEventJoystickConnectEvent_constructor);
    sfEvent.SquirrelFunc(_SC("JoystickMoveEvent"), &sfEventJoystickMoveEvent_constructor);
    sfEvent.SquirrelFunc(_SC("KeyEvent"), &sfEventKeyEvent_constructor);
    sfEvent.SquirrelFunc(_SC("MouseButtonEvent"), &sfEventMouseButtonEvent_constructor);
    sfEvent.SquirrelFunc(_SC("MouseMoveEvent"), &sfEventMouseMoveEvent_constructor);
    sfEvent.SquirrelFunc(_SC("MouseWheelEvent"), &sfEventMouseWheelEvent_constructor);
    sfEvent.SquirrelFunc(_SC("SizeEvent"), &sfEventSizeEvent_constructor);
    sfEvent.SquirrelFunc(_SC("TextEvent"), &sfEventTextEvent_constructor);
    sfEvent.Var(_SC("type"), &sf::Event::type);
    sfEvent.Var(_SC("size"), &sf::Event::size);
    sfEvent.Var(_SC("key"), &sf::Event::key);
    sfEvent.Var(_SC("text"), &sf::Event::text);
    sfEvent.Var(_SC("mouseMove"), &sf::Event::mouseMove);
    sfEvent.Var(_SC("mouseButton"), &sf::Event::mouseButton);
    sfEvent.Var(_SC("mouseWheel"), &sf::Event::mouseWheel);
    sfEvent.Var(_SC("joystickMove"), &sf::Event::joystickMove);
    sfEvent.Var(_SC("joystickButton"), &sf::Event::joystickButton);
    sfEvent.Var(_SC("joystickConnect"), &sf::Event::joystickConnect);

    namespaceTable.Bind(_SC("Event"), sfEvent);
}

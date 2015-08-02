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
#include <SFML/Window/Keyboard.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfKeyboard_constructor(HSQUIRRELVM v)
{
    return sq_throwerror(v, _SC("constructor is protected"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML keyboard library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlKeyboardLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::ConstTable constTable(v);
    constTable.Const(_SC("SF_KEYBOARD_UNKNOWN"), static_cast<int>(sf::Keyboard::Unknown));
    constTable.Const(_SC("SF_KEYBOARD_A"), static_cast<int>(sf::Keyboard::A));
    constTable.Const(_SC("SF_KEYBOARD_B"), static_cast<int>(sf::Keyboard::B));
    constTable.Const(_SC("SF_KEYBOARD_C"), static_cast<int>(sf::Keyboard::C));
    constTable.Const(_SC("SF_KEYBOARD_D"), static_cast<int>(sf::Keyboard::D));
    constTable.Const(_SC("SF_KEYBOARD_E"), static_cast<int>(sf::Keyboard::E));
    constTable.Const(_SC("SF_KEYBOARD_F"), static_cast<int>(sf::Keyboard::F));
    constTable.Const(_SC("SF_KEYBOARD_G"), static_cast<int>(sf::Keyboard::G));
    constTable.Const(_SC("SF_KEYBOARD_H"), static_cast<int>(sf::Keyboard::H));
    constTable.Const(_SC("SF_KEYBOARD_I"), static_cast<int>(sf::Keyboard::I));
    constTable.Const(_SC("SF_KEYBOARD_J"), static_cast<int>(sf::Keyboard::J));
    constTable.Const(_SC("SF_KEYBOARD_K"), static_cast<int>(sf::Keyboard::K));
    constTable.Const(_SC("SF_KEYBOARD_L"), static_cast<int>(sf::Keyboard::L));
    constTable.Const(_SC("SF_KEYBOARD_M"), static_cast<int>(sf::Keyboard::M));
    constTable.Const(_SC("SF_KEYBOARD_N"), static_cast<int>(sf::Keyboard::N));
    constTable.Const(_SC("SF_KEYBOARD_O"), static_cast<int>(sf::Keyboard::O));
    constTable.Const(_SC("SF_KEYBOARD_P"), static_cast<int>(sf::Keyboard::P));
    constTable.Const(_SC("SF_KEYBOARD_Q"), static_cast<int>(sf::Keyboard::Q));
    constTable.Const(_SC("SF_KEYBOARD_R"), static_cast<int>(sf::Keyboard::R));
    constTable.Const(_SC("SF_KEYBOARD_S"), static_cast<int>(sf::Keyboard::S));
    constTable.Const(_SC("SF_KEYBOARD_T"), static_cast<int>(sf::Keyboard::T));
    constTable.Const(_SC("SF_KEYBOARD_U"), static_cast<int>(sf::Keyboard::U));
    constTable.Const(_SC("SF_KEYBOARD_V"), static_cast<int>(sf::Keyboard::V));
    constTable.Const(_SC("SF_KEYBOARD_W"), static_cast<int>(sf::Keyboard::W));
    constTable.Const(_SC("SF_KEYBOARD_X"), static_cast<int>(sf::Keyboard::X));
    constTable.Const(_SC("SF_KEYBOARD_Y"), static_cast<int>(sf::Keyboard::Y));
    constTable.Const(_SC("SF_KEYBOARD_Z"), static_cast<int>(sf::Keyboard::Z));
    constTable.Const(_SC("SF_KEYBOARD_NUM0"), static_cast<int>(sf::Keyboard::Num0));
    constTable.Const(_SC("SF_KEYBOARD_NUM1"), static_cast<int>(sf::Keyboard::Num1));
    constTable.Const(_SC("SF_KEYBOARD_NUM2"), static_cast<int>(sf::Keyboard::Num2));
    constTable.Const(_SC("SF_KEYBOARD_NUM3"), static_cast<int>(sf::Keyboard::Num3));
    constTable.Const(_SC("SF_KEYBOARD_NUM4"), static_cast<int>(sf::Keyboard::Num4));
    constTable.Const(_SC("SF_KEYBOARD_NUM5"), static_cast<int>(sf::Keyboard::Num5));
    constTable.Const(_SC("SF_KEYBOARD_NUM6"), static_cast<int>(sf::Keyboard::Num6));
    constTable.Const(_SC("SF_KEYBOARD_NUM7"), static_cast<int>(sf::Keyboard::Num7));
    constTable.Const(_SC("SF_KEYBOARD_NUM8"), static_cast<int>(sf::Keyboard::Num8));
    constTable.Const(_SC("SF_KEYBOARD_NUM9"), static_cast<int>(sf::Keyboard::Num9));
    constTable.Const(_SC("SF_KEYBOARD_ESCAPE"), static_cast<int>(sf::Keyboard::Escape));
    constTable.Const(_SC("SF_KEYBOARD_LCONTROL"), static_cast<int>(sf::Keyboard::LControl));
    constTable.Const(_SC("SF_KEYBOARD_LSHIFT"), static_cast<int>(sf::Keyboard::LShift));
    constTable.Const(_SC("SF_KEYBOARD_LALT"), static_cast<int>(sf::Keyboard::LAlt));
    constTable.Const(_SC("SF_KEYBOARD_LSYSTEM"), static_cast<int>(sf::Keyboard::LSystem));
    constTable.Const(_SC("SF_KEYBOARD_RCONTROL"), static_cast<int>(sf::Keyboard::RControl));
    constTable.Const(_SC("SF_KEYBOARD_RSHIFT"), static_cast<int>(sf::Keyboard::RShift));
    constTable.Const(_SC("SF_KEYBOARD_RALT"), static_cast<int>(sf::Keyboard::RAlt));
    constTable.Const(_SC("SF_KEYBOARD_RSYSTEM"), static_cast<int>(sf::Keyboard::RSystem));
    constTable.Const(_SC("SF_KEYBOARD_MENU"), static_cast<int>(sf::Keyboard::Menu));
    constTable.Const(_SC("SF_KEYBOARD_LBRACKET"), static_cast<int>(sf::Keyboard::LBracket));
    constTable.Const(_SC("SF_KEYBOARD_RBRACKET"), static_cast<int>(sf::Keyboard::RBracket));
    constTable.Const(_SC("SF_KEYBOARD_SEMICOLON"), static_cast<int>(sf::Keyboard::SemiColon));
    constTable.Const(_SC("SF_KEYBOARD_COMMA"), static_cast<int>(sf::Keyboard::Comma));
    constTable.Const(_SC("SF_KEYBOARD_PERIOD"), static_cast<int>(sf::Keyboard::Period));
    constTable.Const(_SC("SF_KEYBOARD_QUOTE"), static_cast<int>(sf::Keyboard::Quote));
    constTable.Const(_SC("SF_KEYBOARD_SLASH"), static_cast<int>(sf::Keyboard::Slash));
    constTable.Const(_SC("SF_KEYBOARD_BACKSLASH"), static_cast<int>(sf::Keyboard::BackSlash));
    constTable.Const(_SC("SF_KEYBOARD_TILDE"), static_cast<int>(sf::Keyboard::Tilde));
    constTable.Const(_SC("SF_KEYBOARD_EQUAL"), static_cast<int>(sf::Keyboard::Equal));
    constTable.Const(_SC("SF_KEYBOARD_DASH"), static_cast<int>(sf::Keyboard::Dash));
    constTable.Const(_SC("SF_KEYBOARD_SPACE"), static_cast<int>(sf::Keyboard::Space));
    constTable.Const(_SC("SF_KEYBOARD_RETURN"), static_cast<int>(sf::Keyboard::Return));
    constTable.Const(_SC("SF_KEYBOARD_BACKSPACE"), static_cast<int>(sf::Keyboard::BackSpace));
    constTable.Const(_SC("SF_KEYBOARD_TAB"), static_cast<int>(sf::Keyboard::Tab));
    constTable.Const(_SC("SF_KEYBOARD_PAGE_UP"), static_cast<int>(sf::Keyboard::PageUp));
    constTable.Const(_SC("SF_KEYBOARD_PAGE_DOWN"), static_cast<int>(sf::Keyboard::PageDown));
    constTable.Const(_SC("SF_KEYBOARD_END"), static_cast<int>(sf::Keyboard::End));
    constTable.Const(_SC("SF_KEYBOARD_HOME"), static_cast<int>(sf::Keyboard::Home));
    constTable.Const(_SC("SF_KEYBOARD_INSERT"), static_cast<int>(sf::Keyboard::Insert));
    constTable.Const(_SC("SF_KEYBOARD_DELETE"), static_cast<int>(sf::Keyboard::Delete));
    constTable.Const(_SC("SF_KEYBOARD_ADD"), static_cast<int>(sf::Keyboard::Add));
    constTable.Const(_SC("SF_KEYBOARD_SUBTRACT"), static_cast<int>(sf::Keyboard::Subtract));
    constTable.Const(_SC("SF_KEYBOARD_MULTIPLY"), static_cast<int>(sf::Keyboard::Multiply));
    constTable.Const(_SC("SF_KEYBOARD_DIVIDE"), static_cast<int>(sf::Keyboard::Divide));
    constTable.Const(_SC("SF_KEYBOARD_LEFT"), static_cast<int>(sf::Keyboard::Left));
    constTable.Const(_SC("SF_KEYBOARD_RIGHT"), static_cast<int>(sf::Keyboard::Right));
    constTable.Const(_SC("SF_KEYBOARD_UP"), static_cast<int>(sf::Keyboard::Up));
    constTable.Const(_SC("SF_KEYBOARD_DOWN"), static_cast<int>(sf::Keyboard::Down));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD0"), static_cast<int>(sf::Keyboard::Numpad0));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD1"), static_cast<int>(sf::Keyboard::Numpad1));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD2"), static_cast<int>(sf::Keyboard::Numpad2));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD3"), static_cast<int>(sf::Keyboard::Numpad3));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD4"), static_cast<int>(sf::Keyboard::Numpad4));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD5"), static_cast<int>(sf::Keyboard::Numpad5));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD6"), static_cast<int>(sf::Keyboard::Numpad6));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD7"), static_cast<int>(sf::Keyboard::Numpad7));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD8"), static_cast<int>(sf::Keyboard::Numpad8));
    constTable.Const(_SC("SF_KEYBOARD_NUMPAD9"), static_cast<int>(sf::Keyboard::Numpad9));
    constTable.Const(_SC("SF_KEYBOARD_F1"), static_cast<int>(sf::Keyboard::F1));
    constTable.Const(_SC("SF_KEYBOARD_F2"), static_cast<int>(sf::Keyboard::F2));
    constTable.Const(_SC("SF_KEYBOARD_F3"), static_cast<int>(sf::Keyboard::F3));
    constTable.Const(_SC("SF_KEYBOARD_F4"), static_cast<int>(sf::Keyboard::F4));
    constTable.Const(_SC("SF_KEYBOARD_F5"), static_cast<int>(sf::Keyboard::F5));
    constTable.Const(_SC("SF_KEYBOARD_F6"), static_cast<int>(sf::Keyboard::F6));
    constTable.Const(_SC("SF_KEYBOARD_F7"), static_cast<int>(sf::Keyboard::F7));
    constTable.Const(_SC("SF_KEYBOARD_F8"), static_cast<int>(sf::Keyboard::F8));
    constTable.Const(_SC("SF_KEYBOARD_F9"), static_cast<int>(sf::Keyboard::F9));
    constTable.Const(_SC("SF_KEYBOARD_F10"), static_cast<int>(sf::Keyboard::F10));
    constTable.Const(_SC("SF_KEYBOARD_F11"), static_cast<int>(sf::Keyboard::F11));
    constTable.Const(_SC("SF_KEYBOARD_F12"), static_cast<int>(sf::Keyboard::F12));
    constTable.Const(_SC("SF_KEYBOARD_F13"), static_cast<int>(sf::Keyboard::F13));
    constTable.Const(_SC("SF_KEYBOARD_F14"), static_cast<int>(sf::Keyboard::F14));
    constTable.Const(_SC("SF_KEYBOARD_F15"), static_cast<int>(sf::Keyboard::F15));
    constTable.Const(_SC("SF_KEYBOARD_PAUSE"), static_cast<int>(sf::Keyboard::Pause));

    Sqrat::Class<sf::Keyboard> sfKeyboard(v, _SC("sf.Keyboard"));
    sfKeyboard.SquirrelFunc(_SC("constructor"), &sfKeyboard_constructor);
    sfKeyboard.StaticFunc(_SC("isKeyPressed"), &sf::Keyboard::isKeyPressed);

    namespaceTable.Bind(_SC("Keyboard"), sfKeyboard);
}

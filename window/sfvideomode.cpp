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
#include <SFML/Window/VideoMode.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVideoMode_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::VideoMode* instance = new sf::VideoMode();
        Sqrat::DefaultAllocator<sf::VideoMode>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::VideoMode&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::VideoMode* instance = new sf::VideoMode(copy.value);
            Sqrat::DefaultAllocator<sf::VideoMode>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<unsigned int> modeWidth(v, 2);
        Sqrat::Var<unsigned int> modeHeight(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::VideoMode* instance = new sf::VideoMode(modeWidth.value, modeHeight.value);
            Sqrat::DefaultAllocator<sf::VideoMode>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<unsigned int> modeWidth(v, 2);
        Sqrat::Var<unsigned int> modeHeight(v, 3);
        Sqrat::Var<unsigned int> modeBitsPerPixel(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::VideoMode* instance = new sf::VideoMode(modeWidth.value, modeHeight.value, modeBitsPerPixel.value);
            Sqrat::DefaultAllocator<sf::VideoMode>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfVideoMode_equals(const sf::VideoMode& left, const sf::VideoMode& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// Retrieves all the video modes supported in fullscreen mode
////////////////////////////////////////////////////////////
static SQInteger sfVideoMode_getFullscreenModes(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
        sq_newarray(v, modes.size());
        for (std::size_t i = 0; i < modes.size(); ++i) {
            Sqrat::PushVar(v, i);
            Sqrat::PushVar(v, modes[i]);
            sq_rawset(v, -3);
        }
        return 1;
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Invoked to emulate the < > <= >= operators
////////////////////////////////////////////////////////////
static int sfVideoMode_cmp(const sf::VideoMode& left, const sf::VideoMode& right)
{
    if (left == right)
        return 0;
    if (left < right)
        return -1;
    return 1;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML video mode library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlVideoModeLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::VideoMode> sfVideoMode(v, _SC("sf.VideoMode"));
    sfVideoMode.SquirrelFunc(_SC("constructor"), &sfVideoMode_constructor);
    sfVideoMode.SquirrelFunc(_SC("getFullscreenModes"), &sfVideoMode_getFullscreenModes);
    sfVideoMode.GlobalFunc(_SC("equals"), &sfVideoMode_equals);
    sfVideoMode.Func(_SC("isValid"), &sf::VideoMode::isValid);
    sfVideoMode.StaticFunc(_SC("getDesktopMode"), &sf::VideoMode::getDesktopMode);
    sfVideoMode.Var(_SC("width"), &sf::VideoMode::width);
    sfVideoMode.Var(_SC("height"), &sf::VideoMode::height);
    sfVideoMode.Var(_SC("bitsPerPixel"), &sf::VideoMode::bitsPerPixel);
    sfVideoMode.GlobalFunc(_SC("_cmp"), &sfVideoMode_cmp);

    namespaceTable.Bind(_SC("VideoMode"), sfVideoMode);
}

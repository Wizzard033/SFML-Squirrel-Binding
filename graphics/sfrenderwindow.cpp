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
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfRenderWindow_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::RenderWindow* instance = new sf::RenderWindow();
        Sqrat::DefaultAllocator<sf::RenderWindow>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::VideoMode> mode(v, 2);
        Sqrat::Var<const sf::String&> title(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderWindow* instance = new sf::RenderWindow(mode.value, title.value);
            Sqrat::DefaultAllocator<sf::RenderWindow>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::VideoMode> mode(v, 2);
        Sqrat::Var<const sf::String&> title(v, 3);
        Sqrat::Var<sf::Uint32> style(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderWindow* instance = new sf::RenderWindow(mode.value, title.value, style.value);
            Sqrat::DefaultAllocator<sf::RenderWindow>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<sf::VideoMode> mode(v, 2);
        Sqrat::Var<const sf::String&> title(v, 3);
        Sqrat::Var<sf::Uint32> style(v, 4);
        Sqrat::Var<unsigned int> antialiasing(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            sf::RenderWindow* instance = new sf::RenderWindow(mode.value, title.value, style.value, sf::ContextSettings(0, 0, antialiasing.value));
            Sqrat::DefaultAllocator<sf::RenderWindow>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Creates (or recreates) the window
////////////////////////////////////////////////////////////
static SQInteger sfRenderWindow_create(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderWindow&> left(v, 1);
        Sqrat::Var<sf::VideoMode> mode(v, 2);
        Sqrat::Var<const sf::String&> title(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.create(mode.value, title.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::RenderWindow&> left(v, 1);
        Sqrat::Var<sf::VideoMode> mode(v, 2);
        Sqrat::Var<const sf::String&> title(v, 3);
        Sqrat::Var<sf::Uint32> style(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.create(mode.value, title.value, style.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<sf::RenderWindow&> left(v, 1);
        Sqrat::Var<sf::VideoMode> mode(v, 2);
        Sqrat::Var<const sf::String&> title(v, 3);
        Sqrat::Var<sf::Uint32> style(v, 4);
        Sqrat::Var<unsigned int> antialiasing(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.create(mode.value, title.value, style.value, sf::ContextSettings(0, 0, antialiasing.value));
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Changes the window's icon
////////////////////////////////////////////////////////////
static SQInteger sfRenderWindow_setIcon(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::RenderWindow&> left(v, 1);
        Sqrat::Var<unsigned int> width(v, 2);
        Sqrat::Var<unsigned int> height(v, 3);
        Sqrat::Var<Sqrat::Array> pixels(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, pixels.value.GetObject());
            sq_pushnull(v);
            sf::Uint8 data[sq_getsize(v, -2)];
            while (SQ_SUCCEEDED(sq_next(v, -2))) {
                SQInteger key;
                sq_getinteger(v, -2, &key);
                Sqrat::Var<sf::Uint8> pixel(v, -1);
                if (Sqrat::Error::Occurred(v)) {
                    return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
                }
                sq_pop(v, 2);
                data[key] = pixel.value;
            }
            sq_pop(v, 2);
            left.value.setIcon(width.value, height.value, data);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Closes the window and destroys all its attached resources
////////////////////////////////////////////////////////////
static void sfRenderWindow_close(sf::RenderWindow& left)
{
    left.close();
}


////////////////////////////////////////////////////////////
// Displays on screen what has been rendered to the window so far
////////////////////////////////////////////////////////////
static void sfRenderWindow_display(sf::RenderWindow& left)
{
    left.display();
}


////////////////////////////////////////////////////////////
// Gets the level of antialiasing of the window
////////////////////////////////////////////////////////////
static unsigned int sfRenderWindow_getAntialiasingLevel(const sf::RenderWindow& left)
{
    return left.getSettings().antialiasingLevel;
}


////////////////////////////////////////////////////////////
// Gets the position of the window
////////////////////////////////////////////////////////////
static sf::Vector2i sfRenderWindow_getPosition(const sf::RenderWindow& left)
{
    return left.getPosition();
}


////////////////////////////////////////////////////////////
// Gets the size of the rendering region of the window
////////////////////////////////////////////////////////////
static sf::Vector2u sfRenderWindow_getSize(const sf::RenderWindow& left)
{
    return left.getSize();
}


////////////////////////////////////////////////////////////
// Determines whether the window has the input focus
////////////////////////////////////////////////////////////
static bool sfRenderWindow_hasFocus(const sf::RenderWindow& left)
{
    return left.hasFocus();
}


////////////////////////////////////////////////////////////
// Tells whether or not the window is open
////////////////////////////////////////////////////////////
static bool sfRenderWindow_isOpen(const sf::RenderWindow& left)
{
    return left.isOpen();
}


////////////////////////////////////////////////////////////
// Requests the current window to be made the active foreground window
////////////////////////////////////////////////////////////
static void sfRenderWindow_requestFocus(sf::RenderWindow& left)
{
    return left.requestFocus();
}


////////////////////////////////////////////////////////////
// Pops the event on top of the event queue, if any, and returns it
////////////////////////////////////////////////////////////
static bool sfRenderWindow_pollEvent(sf::RenderWindow& left, sf::Event& event)
{
    return left.pollEvent(event);
}


////////////////////////////////////////////////////////////
// Limits the framerate to a maximum, fixed frequency
////////////////////////////////////////////////////////////
static void sfRenderWindow_setFramerateLimit(sf::RenderWindow& left, unsigned int limit)
{
    left.setFramerateLimit(limit);
}


////////////////////////////////////////////////////////////
// Changes the joystick threshold
////////////////////////////////////////////////////////////
static void sfRenderWindow_setJoystickThreshold(sf::RenderWindow& left, float threshold)
{
    left.setJoystickThreshold(threshold);
}


////////////////////////////////////////////////////////////
// Enables or disables automatic key-repeat
////////////////////////////////////////////////////////////
static void sfRenderWindow_setKeyRepeatEnabled(sf::RenderWindow& left, bool enabled)
{
    left.setKeyRepeatEnabled(enabled);
}


////////////////////////////////////////////////////////////
// Shows or hides the mouse cursor
////////////////////////////////////////////////////////////
static void sfRenderWindow_setMouseCursorVisible(sf::RenderWindow& left, bool visible)
{
    left.setMouseCursorVisible(visible);
}


////////////////////////////////////////////////////////////
// Changes the position of the window on screen
////////////////////////////////////////////////////////////
static void sfRenderWindow_setPosition(sf::RenderWindow& left, const sf::Vector2i& position)
{
    left.setPosition(position);
}


////////////////////////////////////////////////////////////
// Changes the size of the rendering region of the window
////////////////////////////////////////////////////////////
static void sfRenderWindow_setSize(sf::RenderWindow& left, const sf::Vector2u& size)
{
    left.setSize(size);
}


////////////////////////////////////////////////////////////
// Changes the title of the window
////////////////////////////////////////////////////////////
static void sfRenderWindow_setTitle(sf::RenderWindow& left, const sf::String& title)
{
    left.setTitle(title);
}


////////////////////////////////////////////////////////////
// Enables or disables vertical synchronization
////////////////////////////////////////////////////////////
static void sfRenderWindow_setVerticalSyncEnabled(sf::RenderWindow& left, bool enabled)
{
    left.setVerticalSyncEnabled(enabled);
}


////////////////////////////////////////////////////////////
// Shows or hides the window
////////////////////////////////////////////////////////////
static void sfRenderWindow_setVisible(sf::RenderWindow& left, bool visible)
{
    left.setVisible(visible);
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML render window library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlRenderWindowLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::DerivedClass<sf::RenderWindow, sf::RenderTarget, Sqrat::NoCopy<sf::RenderWindow> > sfRenderWindow(v, _SC("sf.RenderWindow"));
    sfRenderWindow.SquirrelFunc(_SC("constructor"), &sfRenderWindow_constructor);
    sfRenderWindow.SquirrelFunc(_SC("create"), &sfRenderWindow_create);
    sfRenderWindow.SquirrelFunc(_SC("setIcon"), &sfRenderWindow_setIcon);
    sfRenderWindow.Func(_SC("capture"), &sf::RenderWindow::capture);
    sfRenderWindow.GlobalFunc(_SC("close"), &sfRenderWindow_close);
    sfRenderWindow.GlobalFunc(_SC("display"), &sfRenderWindow_display);
    sfRenderWindow.GlobalFunc(_SC("getAntialiasingLevel"), &sfRenderWindow_getAntialiasingLevel);
    sfRenderWindow.GlobalFunc(_SC("getPosition"), &sfRenderWindow_getPosition);
    sfRenderWindow.GlobalFunc(_SC("getSize"), &sfRenderWindow_getSize);
    sfRenderWindow.GlobalFunc(_SC("hasFocus"), &sfRenderWindow_hasFocus);
    sfRenderWindow.GlobalFunc(_SC("isOpen"), &sfRenderWindow_isOpen);
    sfRenderWindow.GlobalFunc(_SC("pollEvent"), &sfRenderWindow_pollEvent);
    sfRenderWindow.GlobalFunc(_SC("requestFocus"), &sfRenderWindow_requestFocus);
    sfRenderWindow.GlobalFunc(_SC("setFramerateLimit"), &sfRenderWindow_setFramerateLimit);
    sfRenderWindow.GlobalFunc(_SC("setJoystickThreshold"), &sfRenderWindow_setJoystickThreshold);
    sfRenderWindow.GlobalFunc(_SC("setKeyRepeatEnabled"), &sfRenderWindow_setKeyRepeatEnabled);
    sfRenderWindow.GlobalFunc(_SC("setMouseCursorVisible"), &sfRenderWindow_setMouseCursorVisible);
    sfRenderWindow.GlobalFunc(_SC("setPosition"), &sfRenderWindow_setPosition);
    sfRenderWindow.GlobalFunc(_SC("setSize"), &sfRenderWindow_setSize);
    sfRenderWindow.GlobalFunc(_SC("setTitle"), &sfRenderWindow_setTitle);
    sfRenderWindow.GlobalFunc(_SC("setVerticalSyncEnabled"), &sfRenderWindow_setVerticalSyncEnabled);
    sfRenderWindow.GlobalFunc(_SC("setVisible"), &sfRenderWindow_setVisible);

    namespaceTable.Bind(_SC("RenderWindow"), sfRenderWindow);
}

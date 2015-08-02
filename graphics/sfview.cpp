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
#include <SFML/Graphics/View.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfView_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::View* instance = new sf::View();
        Sqrat::DefaultAllocator<sf::View>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::View&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::View* instance = new sf::View(copy.value);
            Sqrat::DefaultAllocator<sf::View>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::FloatRect&> rectangle(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::View* instance = new sf::View(rectangle.value);
            Sqrat::DefaultAllocator<sf::View>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::View>::ClassName() + _SC("|") + Sqrat::ClassType<sf::FloatRect>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<const sf::Vector2f&> center(v, 2);
        Sqrat::Var<const sf::Vector2f&> size(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::View* instance = new sf::View(center.value, size.value);
            Sqrat::DefaultAllocator<sf::View>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Moves the view relative to its current position
////////////////////////////////////////////////////////////
static SQInteger sfView_move(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::View&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> offset(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.move(offset.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::View&> left(v, 1);
        Sqrat::Var<float> offsetX(v, 2);
        Sqrat::Var<float> offsetY(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.move(offsetX.value, offsetY.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets the center of the view
////////////////////////////////////////////////////////////
static SQInteger sfView_setCenter(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::View&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> center(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setCenter(center.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::View&> left(v, 1);
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setCenter(x.value, y.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets the size of the view
////////////////////////////////////////////////////////////
static SQInteger sfView_setSize(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::View&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> size(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setSize(size.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::View&> left(v, 1);
        Sqrat::Var<float> width(v, 2);
        Sqrat::Var<float> height(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setSize(width.value, height.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML view library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlViewLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::View> sfView(v, _SC("sf.View"));
    sfView.SquirrelFunc(_SC("constructor"), &sfView_constructor);
    sfView.SquirrelFunc(_SC("move"), &sfView_move);
    sfView.SquirrelFunc(_SC("setCenter"), &sfView_setCenter);
    sfView.SquirrelFunc(_SC("setSize"), &sfView_setSize);
    sfView.Func(_SC("getCenter"), &sf::View::getCenter);
    sfView.Func(_SC("getInverseTransform"), &sf::View::getInverseTransform);
    sfView.Func(_SC("getRotation"), &sf::View::getRotation);
    sfView.Func(_SC("getSize"), &sf::View::getSize);
    sfView.Func(_SC("getTransform"), &sf::View::getTransform);
    sfView.Func(_SC("getViewport"), &sf::View::getViewport);
    sfView.Func(_SC("reset"), &sf::View::reset);
    sfView.Func(_SC("rotate"), &sf::View::rotate);
    sfView.Func(_SC("setRotation"), &sf::View::setRotation);
    sfView.Func(_SC("setViewport"), &sf::View::setViewport);
    sfView.Func(_SC("zoom"), &sf::View::zoom);

    namespaceTable.Bind(_SC("View"), sfView);
}

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
#include <SFML/Graphics/Rect.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfIntRect_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::IntRect* instance = new sf::IntRect();
        Sqrat::DefaultAllocator<sf::IntRect>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::IntRect&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::IntRect* instance = new sf::IntRect(copy.value);
            Sqrat::DefaultAllocator<sf::IntRect>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::FloatRect&> floatRect(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::IntRect* instance = new sf::IntRect(floatRect.value);
            Sqrat::DefaultAllocator<sf::IntRect>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::IntRect>::ClassName() + _SC("|") + Sqrat::ClassType<sf::FloatRect>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<const sf::Vector2i&> position(v, 2);
        Sqrat::Var<const sf::Vector2i&> size(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::IntRect* instance = new sf::IntRect(position.value, size.value);
            Sqrat::DefaultAllocator<sf::IntRect>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<int> rectLeft(v, 2);
        Sqrat::Var<int> rectTop(v, 3);
        Sqrat::Var<int> rectWidth(v, 4);
        Sqrat::Var<int> rectHeight(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            sf::IntRect* instance = new sf::IntRect(rectLeft.value, rectTop.value, rectWidth.value, rectHeight.value);
            Sqrat::DefaultAllocator<sf::IntRect>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Checks if a point is inside the rectangle's area
////////////////////////////////////////////////////////////
static SQInteger sfIntRect_contains(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::IntRect&> left(v, 1);
        Sqrat::Var<const sf::Vector2i&> point(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.contains(point.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::IntRect&> left(v, 1);
        Sqrat::Var<int> x(v, 2);
        Sqrat::Var<int> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.contains(x.value, y.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfIntRect_equals(const sf::IntRect& left, const sf::IntRect& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// Checks the intersection between two rectangles
////////////////////////////////////////////////////////////
static SQInteger sfIntRect_intersects(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::IntRect&> left(v, 1);
        Sqrat::Var<const sf::IntRect&> rectangle(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.intersects(rectangle.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::IntRect&> left(v, 1);
        Sqrat::Var<const sf::IntRect&> rectangle(v, 2);
        Sqrat::Var<sf::IntRect&> intersection(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.intersects(rectangle.value, intersection.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfFloatRect_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::FloatRect* instance = new sf::FloatRect();
        Sqrat::DefaultAllocator<sf::FloatRect>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::FloatRect&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::FloatRect* instance = new sf::FloatRect(copy.value);
            Sqrat::DefaultAllocator<sf::FloatRect>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::IntRect&> intRect(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::FloatRect* instance = new sf::FloatRect(intRect.value);
            Sqrat::DefaultAllocator<sf::FloatRect>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::IntRect>::ClassName() + _SC("|") + Sqrat::ClassType<sf::FloatRect>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<const sf::Vector2f&> position(v, 2);
        Sqrat::Var<const sf::Vector2f&> size(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::FloatRect* instance = new sf::FloatRect(position.value, size.value);
            Sqrat::DefaultAllocator<sf::FloatRect>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<float> rectLeft(v, 2);
        Sqrat::Var<float> rectTop(v, 3);
        Sqrat::Var<float> rectWidth(v, 4);
        Sqrat::Var<float> rectHeight(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            sf::FloatRect* instance = new sf::FloatRect(rectLeft.value, rectTop.value, rectWidth.value, rectHeight.value);
            Sqrat::DefaultAllocator<sf::FloatRect>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Checks if a point is inside the rectangle's area
////////////////////////////////////////////////////////////
static SQInteger sfFloatRect_contains(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::FloatRect&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> point(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.contains(point.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::FloatRect&> left(v, 1);
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.contains(x.value, y.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfFloatRect_equals(const sf::FloatRect& left, const sf::FloatRect& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// Checks the intersection between two rectangles
////////////////////////////////////////////////////////////
static SQInteger sfFloatRect_intersects(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::FloatRect&> left(v, 1);
        Sqrat::Var<const sf::FloatRect&> rectangle(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.intersects(rectangle.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::FloatRect&> left(v, 1);
        Sqrat::Var<const sf::FloatRect&> rectangle(v, 2);
        Sqrat::Var<sf::FloatRect&> intersection(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.intersects(rectangle.value, intersection.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML rect library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlRectLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::IntRect> sfIntRect(v, _SC("sf.IntRect"));
    sfIntRect.SquirrelFunc(_SC("constructor"), &sfIntRect_constructor);
    sfIntRect.SquirrelFunc(_SC("contains"), &sfIntRect_contains);
    sfIntRect.SquirrelFunc(_SC("intersects"), &sfIntRect_intersects);
    sfIntRect.GlobalFunc(_SC("equals"), &sfIntRect_equals);
    sfIntRect.Var(_SC("left"), &sf::IntRect::left);
    sfIntRect.Var(_SC("top"), &sf::IntRect::top);
    sfIntRect.Var(_SC("width"), &sf::IntRect::width);
    sfIntRect.Var(_SC("height"), &sf::IntRect::height);

    Sqrat::Class<sf::FloatRect> sfFloatRect(v, _SC("sf.FloatRect"));
    sfFloatRect.SquirrelFunc(_SC("constructor"), &sfFloatRect_constructor);
    sfFloatRect.SquirrelFunc(_SC("contains"), &sfFloatRect_contains);
    sfFloatRect.SquirrelFunc(_SC("intersects"), &sfFloatRect_intersects);
    sfFloatRect.GlobalFunc(_SC("equals"), &sfFloatRect_equals);
    sfFloatRect.Var(_SC("left"), &sf::FloatRect::left);
    sfFloatRect.Var(_SC("top"), &sf::FloatRect::top);
    sfFloatRect.Var(_SC("width"), &sf::FloatRect::width);
    sfFloatRect.Var(_SC("height"), &sf::FloatRect::height);

    namespaceTable.Bind(_SC("IntRect"), sfIntRect);
    namespaceTable.Bind(_SC("FloatRect"), sfFloatRect);
}

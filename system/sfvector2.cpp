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
#include <SFML/System/Vector2.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVector2i_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Vector2i* instance = new sf::Vector2i();
        Sqrat::DefaultAllocator<sf::Vector2i>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Vector2i&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2i* instance = new sf::Vector2i(copy.value);
            Sqrat::DefaultAllocator<sf::Vector2i>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2u&> vector2u(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2i* instance = new sf::Vector2i(vector2u.value);
            Sqrat::DefaultAllocator<sf::Vector2i>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2f&> vector2f(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2i* instance = new sf::Vector2i(vector2f.value);
            Sqrat::DefaultAllocator<sf::Vector2i>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Vector2i>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2u>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<int> x(v, 2);
        Sqrat::Var<int> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2i* instance = new sf::Vector2i(x.value, y.value);
            Sqrat::DefaultAllocator<sf::Vector2i>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfVector2i_equals(const sf::Vector2i& left, const sf::Vector2i& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// The + operator
////////////////////////////////////////////////////////////
static sf::Vector2i sfVector2i_add(const sf::Vector2i& left, const sf::Vector2i& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// The - operator
////////////////////////////////////////////////////////////
static sf::Vector2i sfVector2i_sub(const sf::Vector2i& left, const sf::Vector2i& right)
{
    return left - right;
}


////////////////////////////////////////////////////////////
// The * operator
////////////////////////////////////////////////////////////
static sf::Vector2i sfVector2i_mul(const sf::Vector2i& left, int right)
{
    return left * right;
}


////////////////////////////////////////////////////////////
// The / operator
////////////////////////////////////////////////////////////
static sf::Vector2i sfVector2i_div(const sf::Vector2i& left, int right)
{
    return left / right;
}


////////////////////////////////////////////////////////////
// The unary minus operator
////////////////////////////////////////////////////////////
static sf::Vector2i sfVector2i_unm(const sf::Vector2i& right)
{
    return -right;
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVector2u_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Vector2u* instance = new sf::Vector2u();
        Sqrat::DefaultAllocator<sf::Vector2u>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Vector2u&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2u* instance = new sf::Vector2u(copy.value);
            Sqrat::DefaultAllocator<sf::Vector2u>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2i&> vector2i(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2u* instance = new sf::Vector2u(vector2i.value);
            Sqrat::DefaultAllocator<sf::Vector2u>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2f&> vector2f(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2u* instance = new sf::Vector2u(vector2f.value);
            Sqrat::DefaultAllocator<sf::Vector2u>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Vector2i>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2u>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<unsigned int> x(v, 2);
        Sqrat::Var<unsigned int> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2u* instance = new sf::Vector2u(x.value, y.value);
            Sqrat::DefaultAllocator<sf::Vector2u>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfVector2u_equals(const sf::Vector2u& left, const sf::Vector2u& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// The + operator
////////////////////////////////////////////////////////////
static sf::Vector2u sfVector2u_add(const sf::Vector2u& left, const sf::Vector2u& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// The - operator
////////////////////////////////////////////////////////////
static sf::Vector2u sfVector2u_sub(const sf::Vector2u& left, const sf::Vector2u& right)
{
    return left - right;
}


////////////////////////////////////////////////////////////
// The * operator
////////////////////////////////////////////////////////////
static sf::Vector2u sfVector2u_mul(const sf::Vector2u& left, unsigned int right)
{
    return left * right;
}


////////////////////////////////////////////////////////////
// The / operator
////////////////////////////////////////////////////////////
static sf::Vector2u sfVector2u_div(const sf::Vector2u& left, unsigned int right)
{
    return left / right;
}


////////////////////////////////////////////////////////////
// The unary minus operator
////////////////////////////////////////////////////////////
static sf::Vector2u sfVector2u_unm(const sf::Vector2u& right)
{
    return -right;
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVector2f_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Vector2f* instance = new sf::Vector2f();
        Sqrat::DefaultAllocator<sf::Vector2f>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Vector2f&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2f* instance = new sf::Vector2f(copy.value);
            Sqrat::DefaultAllocator<sf::Vector2f>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2i&> vector2i(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2f* instance = new sf::Vector2f(vector2i.value);
            Sqrat::DefaultAllocator<sf::Vector2f>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector2u&> vector2u(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2f* instance = new sf::Vector2f(vector2u.value);
            Sqrat::DefaultAllocator<sf::Vector2f>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Vector2i>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2u>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector2f* instance = new sf::Vector2f(x.value, y.value);
            Sqrat::DefaultAllocator<sf::Vector2f>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfVector2f_equals(const sf::Vector2f& left, const sf::Vector2f& right)
{
    bool ret = left == right;
    return ret;
}


////////////////////////////////////////////////////////////
// The + operator
////////////////////////////////////////////////////////////
static sf::Vector2f sfVector2f_add(const sf::Vector2f& left, const sf::Vector2f& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// The - operator
////////////////////////////////////////////////////////////
static sf::Vector2f sfVector2f_sub(const sf::Vector2f& left, const sf::Vector2f& right)
{
    return left - right;
}


////////////////////////////////////////////////////////////
// The * operator
////////////////////////////////////////////////////////////
static sf::Vector2f sfVector2f_mul(const sf::Vector2f& left, float right)
{
    return left * right;
}


////////////////////////////////////////////////////////////
// The / operator
////////////////////////////////////////////////////////////
static sf::Vector2f sfVector2f_div(const sf::Vector2f& left, float right)
{
    return left / right;
}


////////////////////////////////////////////////////////////
// The unary minus operator
////////////////////////////////////////////////////////////
static sf::Vector2f sfVector2f_unm(const sf::Vector2f& right)
{
    return -right;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML vector2 library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlVector2Lib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Vector2i> sfVector2i(v, _SC("sf.Vector2i"));
    sfVector2i.SquirrelFunc(_SC("constructor"), &sfVector2i_constructor);
    sfVector2i.GlobalFunc(_SC("equals"), &sfVector2i_equals);
    sfVector2i.Var(_SC("x"), &sf::Vector2i::x);
    sfVector2i.Var(_SC("y"), &sf::Vector2i::y);
    sfVector2i.GlobalFunc(_SC("_add"), &sfVector2i_add);
    sfVector2i.GlobalFunc(_SC("_sub"), &sfVector2i_sub);
    sfVector2i.GlobalFunc(_SC("_mul"), &sfVector2i_mul);
    sfVector2i.GlobalFunc(_SC("_div"), &sfVector2i_div);
    sfVector2i.GlobalFunc(_SC("_unm"), &sfVector2i_unm);

    Sqrat::Class<sf::Vector2u> sfVector2u(v, _SC("sf.Vector2u"));
    sfVector2u.SquirrelFunc(_SC("constructor"), &sfVector2u_constructor);
    sfVector2u.GlobalFunc(_SC("equals"), &sfVector2u_equals);
    sfVector2u.Var(_SC("x"), &sf::Vector2u::x);
    sfVector2u.Var(_SC("y"), &sf::Vector2u::y);
    sfVector2u.GlobalFunc(_SC("_add"), &sfVector2u_add);
    sfVector2u.GlobalFunc(_SC("_sub"), &sfVector2u_sub);
    sfVector2u.GlobalFunc(_SC("_mul"), &sfVector2u_mul);
    sfVector2u.GlobalFunc(_SC("_div"), &sfVector2u_div);
    sfVector2u.GlobalFunc(_SC("_unm"), &sfVector2u_unm);

    Sqrat::Class<sf::Vector2f> sfVector2f(v, _SC("sf.Vector2f"));
    sfVector2f.SquirrelFunc(_SC("constructor"), &sfVector2f_constructor);
    sfVector2f.GlobalFunc(_SC("equals"), &sfVector2f_equals);
    sfVector2f.Var(_SC("x"), &sf::Vector2f::x);
    sfVector2f.Var(_SC("y"), &sf::Vector2f::y);
    sfVector2f.GlobalFunc(_SC("_add"), &sfVector2f_add);
    sfVector2f.GlobalFunc(_SC("_sub"), &sfVector2f_sub);
    sfVector2f.GlobalFunc(_SC("_mul"), &sfVector2f_mul);
    sfVector2f.GlobalFunc(_SC("_div"), &sfVector2f_div);
    sfVector2f.GlobalFunc(_SC("_unm"), &sfVector2f_unm);

    namespaceTable.Bind(_SC("Vector2i"), sfVector2i);
    namespaceTable.Bind(_SC("Vector2u"), sfVector2u);
    namespaceTable.Bind(_SC("Vector2f"), sfVector2f);
}

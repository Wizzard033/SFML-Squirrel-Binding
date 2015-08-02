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
#include <SFML/System/Vector3.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVector3i_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Vector3i* instance = new sf::Vector3i();
        Sqrat::DefaultAllocator<sf::Vector3i>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Vector3i&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector3i* instance = new sf::Vector3i(copy.value);
            Sqrat::DefaultAllocator<sf::Vector3i>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector3f&> vector3f(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector3i* instance = new sf::Vector3i(vector3f.value);
            Sqrat::DefaultAllocator<sf::Vector3i>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Vector3i>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector3f>::ClassName()).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<int> x(v, 2);
        Sqrat::Var<int> y(v, 3);
        Sqrat::Var<int> z(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector3i* instance = new sf::Vector3i(x.value, y.value, z.value);
            Sqrat::DefaultAllocator<sf::Vector3i>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfVector3i_equals(const sf::Vector3i& left, const sf::Vector3i& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// The + operator
////////////////////////////////////////////////////////////
static sf::Vector3i sfVector3i_add(const sf::Vector3i& left, const sf::Vector3i& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// The - operator
////////////////////////////////////////////////////////////
static sf::Vector3i sfVector3i_sub(const sf::Vector3i& left, const sf::Vector3i& right)
{
    return left - right;
}


////////////////////////////////////////////////////////////
// The * operator
////////////////////////////////////////////////////////////
static sf::Vector3i sfVector3i_mul(const sf::Vector3i& left, int right)
{
    return left * right;
}


////////////////////////////////////////////////////////////
// The / operator
////////////////////////////////////////////////////////////
static sf::Vector3i sfVector3i_div(const sf::Vector3i& left, int right)
{
    return left / right;
}


////////////////////////////////////////////////////////////
// The unary minus operator
////////////////////////////////////////////////////////////
static sf::Vector3i sfVector3i_unm(const sf::Vector3i& right)
{
    return -right;
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVector3f_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Vector3f* instance = new sf::Vector3f();
        Sqrat::DefaultAllocator<sf::Vector3f>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Vector3f&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector3f* instance = new sf::Vector3f(copy.value);
            Sqrat::DefaultAllocator<sf::Vector3f>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<const sf::Vector3i&> vector3i(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector3f* instance = new sf::Vector3f(vector3i.value);
            Sqrat::DefaultAllocator<sf::Vector3f>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Vector3i>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector3f>::ClassName()).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        Sqrat::Var<float> z(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Vector3f* instance = new sf::Vector3f(x.value, y.value, z.value);
            Sqrat::DefaultAllocator<sf::Vector3f>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfVector3f_equals(const sf::Vector3f& left, const sf::Vector3f& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// The + operator
////////////////////////////////////////////////////////////
static sf::Vector3f sfVector3f_add(const sf::Vector3f& left, const sf::Vector3f& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// The - operator
////////////////////////////////////////////////////////////
static sf::Vector3f sfVector3f_sub(const sf::Vector3f& left, const sf::Vector3f& right)
{
    return left - right;
}


////////////////////////////////////////////////////////////
// The * operator
////////////////////////////////////////////////////////////
static sf::Vector3f sfVector3f_mul(const sf::Vector3f& left, float right)
{
    return left * right;
}


////////////////////////////////////////////////////////////
// The / operator
////////////////////////////////////////////////////////////
static sf::Vector3f sfVector3f_div(const sf::Vector3f& left, float right)
{
    return left / right;
}


////////////////////////////////////////////////////////////
// The unary minus operator
////////////////////////////////////////////////////////////
static sf::Vector3f sfVector3f_unm(const sf::Vector3f& right)
{
    return -right;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML vector3 library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlVector3Lib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Vector3i> sfVector3i(v, _SC("sf.Vector3i"));
    sfVector3i.SquirrelFunc(_SC("constructor"), &sfVector3i_constructor);
    sfVector3i.GlobalFunc(_SC("equals"), &sfVector3i_equals);
    sfVector3i.Var(_SC("x"), &sf::Vector3i::x);
    sfVector3i.Var(_SC("y"), &sf::Vector3i::y);
    sfVector3i.Var(_SC("z"), &sf::Vector3i::z);
    sfVector3i.GlobalFunc(_SC("_add"), &sfVector3i_add);
    sfVector3i.GlobalFunc(_SC("_sub"), &sfVector3i_sub);
    sfVector3i.GlobalFunc(_SC("_mul"), &sfVector3i_mul);
    sfVector3i.GlobalFunc(_SC("_div"), &sfVector3i_div);
    sfVector3i.GlobalFunc(_SC("_unm"), &sfVector3i_unm);

    Sqrat::Class<sf::Vector3f> sfVector3f(v, _SC("sf.Vector3f"));
    sfVector3f.SquirrelFunc(_SC("constructor"), &sfVector3f_constructor);
    sfVector3f.GlobalFunc(_SC("equals"), &sfVector3f_equals);
    sfVector3f.Var(_SC("x"), &sf::Vector3f::x);
    sfVector3f.Var(_SC("y"), &sf::Vector3f::y);
    sfVector3f.Var(_SC("z"), &sf::Vector3f::z);
    sfVector3f.GlobalFunc(_SC("_add"), &sfVector3f_add);
    sfVector3f.GlobalFunc(_SC("_sub"), &sfVector3f_sub);
    sfVector3f.GlobalFunc(_SC("_mul"), &sfVector3f_mul);
    sfVector3f.GlobalFunc(_SC("_div"), &sfVector3f_div);
    sfVector3f.GlobalFunc(_SC("_unm"), &sfVector3f_unm);

    namespaceTable.Bind(_SC("Vector3i"), sfVector3i);
    namespaceTable.Bind(_SC("Vector3f"), sfVector3f);
}

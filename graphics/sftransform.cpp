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
#include <SFML/Graphics/Transform.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfTransform_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Transform* instance = new sf::Transform();
        Sqrat::DefaultAllocator<sf::Transform>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Transform&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Transform* instance = new sf::Transform(copy.value);
            Sqrat::DefaultAllocator<sf::Transform>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 10) {
        Sqrat::Var<float> a00(v, 2);
        Sqrat::Var<float> a01(v, 3);
        Sqrat::Var<float> a02(v, 4);
        Sqrat::Var<float> a10(v, 5);
        Sqrat::Var<float> a11(v, 6);
        Sqrat::Var<float> a12(v, 7);
        Sqrat::Var<float> a20(v, 8);
        Sqrat::Var<float> a21(v, 9);
        Sqrat::Var<float> a22(v, 10);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Transform* instance = new sf::Transform(a00.value, a01.value, a02.value, a10.value, a11.value, a12.value, a20.value, a21.value, a22.value);
            Sqrat::DefaultAllocator<sf::Transform>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Combines the transform with a rotation
////////////////////////////////////////////////////////////
static SQInteger sfTransform_rotate(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<float> angle(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.rotate(angle.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<float> angle(v, 2);
        Sqrat::Var<const sf::Vector2f&> center(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.rotate(angle.value, center.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<float> angle(v, 2);
        Sqrat::Var<float> centerX(v, 3);
        Sqrat::Var<float> centerY(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.rotate(angle.value, centerX.value, centerY.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Combines the transform with a scaling
////////////////////////////////////////////////////////////
static SQInteger sfTransform_scale(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> factors(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.scale(factors.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<float> scaleX(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::Var<float> scaleY(v, 3);
                if (!Sqrat::Error::Occurred(v)) {
                    Sqrat::PushVar(v, left.value.scale(scaleX.value, scaleY.value));
                    return 1;
                }
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const sf::Vector2f&> factors(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::Var<const sf::Vector2f&> center(v, 3);
                if (!Sqrat::Error::Occurred(v)) {
                    Sqrat::PushVar(v, left.value.scale(factors.value, center.value));
                    return 1;
                }
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, _SC("float|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<float> scaleX(v, 2);
        Sqrat::Var<float> scaleY(v, 3);
        Sqrat::Var<float> centerX(v, 4);
        Sqrat::Var<float> centerY(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.scale(scaleX.value, scaleY.value, centerX.value, centerY.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Transforms a 2D point
////////////////////////////////////////////////////////////
static SQInteger sfTransform_transformPoint(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> point(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.transformPoint(point.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.transformPoint(x.value, y.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Combines the transform with a translation
////////////////////////////////////////////////////////////
static SQInteger sfTransform_translate(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> offset(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.translate(offset.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.translate(x.value, y.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// The * operator
////////////////////////////////////////////////////////////
static SQInteger sfTransform_mul(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transform&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<const sf::Transform&> transform(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::PushVar(v, left.value * transform.value);
                return 1;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const sf::Vector2f&> vector2f(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::PushVar(v, left.value * vector2f.value);
                return 1;
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Transform>::ClassName() + _SC("|") + Sqrat::ClassType<sf::Vector2f>::ClassName()).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML transform library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlTransformLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Transform> sfTransform(v, _SC("sf.Transform"));
    sfTransform.SquirrelFunc(_SC("constructor"), &sfTransform_constructor);
    sfTransform.SquirrelFunc(_SC("rotate"), &sfTransform_rotate);
    sfTransform.SquirrelFunc(_SC("scale"), &sfTransform_scale);
    sfTransform.SquirrelFunc(_SC("transformPoint"), &sfTransform_transformPoint);
    sfTransform.SquirrelFunc(_SC("translate"), &sfTransform_translate);
    sfTransform.SquirrelFunc(_SC("_mul"), &sfTransform_mul);
    sfTransform.Func(_SC("combine"), &sf::Transform::combine);
    sfTransform.Func(_SC("getInverse"), &sf::Transform::getInverse);
    sfTransform.Func(_SC("transformRect"), &sf::Transform::transformRect);
    sfTransform.SetStaticValue(_SC("Identity"), sf::Transform::Identity);

    namespaceTable.Bind(_SC("Transform"), sfTransform);
}

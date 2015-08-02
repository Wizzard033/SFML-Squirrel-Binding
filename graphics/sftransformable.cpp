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
#include <SFML/Graphics/Transformable.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfTransformable_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Transformable* instance = new sf::Transformable();
        Sqrat::DefaultAllocator<sf::Transformable>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Transformable&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Transformable* instance = new sf::Transformable(copy.value);
            Sqrat::DefaultAllocator<sf::Transformable>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Moves the object by a given offset
////////////////////////////////////////////////////////////
static SQInteger sfTransformable_move(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> offset(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.move(offset.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
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
// Scales the object
////////////////////////////////////////////////////////////
static SQInteger sfTransformable_scale(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> factor(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.scale(factor.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<float> factorX(v, 2);
        Sqrat::Var<float> factorY(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.scale(factorX.value, factorY.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets the local origin of the object
////////////////////////////////////////////////////////////
static SQInteger sfTransformable_setOrigin(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> origin(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setOrigin(origin.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setOrigin(x.value, y.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets the position of the object
////////////////////////////////////////////////////////////
static SQInteger sfTransformable_setPosition(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> position(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setPosition(position.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setPosition(x.value, y.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets the scale factors of the object
////////////////////////////////////////////////////////////
static SQInteger sfTransformable_setScale(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> factors(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setScale(factors.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::Transformable&> left(v, 1);
        Sqrat::Var<float> x(v, 2);
        Sqrat::Var<float> y(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.setScale(x.value, y.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML transformable library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlTransformableLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Transformable> sfTransformable(v, _SC("sf.Transformable"));
    sfTransformable.SquirrelFunc(_SC("constructor"), &sfTransformable_constructor);
    sfTransformable.SquirrelFunc(_SC("move"), &sfTransformable_move);
    sfTransformable.SquirrelFunc(_SC("scale"), &sfTransformable_scale);
    sfTransformable.SquirrelFunc(_SC("setOrigin"), &sfTransformable_setOrigin);
    sfTransformable.SquirrelFunc(_SC("setPosition"), &sfTransformable_setPosition);
    sfTransformable.SquirrelFunc(_SC("setScale"), &sfTransformable_setScale);
    sfTransformable.Func(_SC("getInverseTransform"), &sf::Transformable::getInverseTransform);
    sfTransformable.Func(_SC("getOrigin"), &sf::Transformable::getOrigin);
    sfTransformable.Func(_SC("getPosition"), &sf::Transformable::getPosition);
    sfTransformable.Func(_SC("getRotation"), &sf::Transformable::getRotation);
    sfTransformable.Func(_SC("getScale"), &sf::Transformable::getScale);
    sfTransformable.Func(_SC("getTransform"), &sf::Transformable::getTransform);
    sfTransformable.Func(_SC("rotate"), &sf::Transformable::rotate);
    sfTransformable.Func(_SC("setRotation"), &sf::Transformable::setRotation);

    namespaceTable.Bind(_SC("Transformable"), sfTransformable);
}

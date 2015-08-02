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
#include <SFML/Graphics/VertexArray.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfVertexArray_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::VertexArray* instance = new sf::VertexArray();
        Sqrat::DefaultAllocator<sf::VertexArray>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::VertexArray&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::VertexArray* instance = new sf::VertexArray(copy.value);
            Sqrat::DefaultAllocator<sf::VertexArray>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        Sqrat::Var<sf::PrimitiveType> type(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::VertexArray* instance = new sf::VertexArray(type.value);
            Sqrat::DefaultAllocator<sf::VertexArray>::SetInstance(v, 1, instance);
            return 0;
        }
        Sqrat::Error::Clear(v);
        return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Vertex>::ClassName() + _SC("|integer")).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::PrimitiveType> type(v, 2);
        Sqrat::Var<unsigned int> vertexCount(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::VertexArray* instance = new sf::VertexArray(type.value, vertexCount.value);
            Sqrat::DefaultAllocator<sf::VertexArray>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Gets a vertex by its index
////////////////////////////////////////////////////////////
static SQInteger sfVertexArray_get(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::VertexArray&> left(v, 1);
        Sqrat::Var<SQInteger> idx(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            if (idx.value < 0 || idx.value >= static_cast<SQInteger>(left.value.getVertexCount())) {
                return sq_throwerror(v, _SC("index out of range"));
            }
            Sqrat::PushVarR(v, left.value[idx.value]);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets a vertex by its index
////////////////////////////////////////////////////////////
static SQInteger sfVertexArray_set(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::VertexArray&> left(v, 1);
        Sqrat::Var<SQInteger> idx(v, 2);
        Sqrat::Var<const sf::Vertex&> val(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            if (idx.value < 0 || idx.value >= static_cast<SQInteger>(left.value.getVertexCount())) {
                return sq_throwerror(v, _SC("index out of range"));
            }
            Sqrat::PushVarR(v, left.value[idx.value] = val.value);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Invoked when a class instance is iterated by a foreach loop
////////////////////////////////////////////////////////////
static SQInteger sfVertexArray_nexti(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::VertexArray&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            if (sq_gettype(v, 2) == OT_NULL) {
                if (left.value.getVertexCount() > 0) {
                    Sqrat::PushVar(v, 0);
                    return 1;
                }
                sq_pushnull(v);
                return 1;
            }
            Sqrat::Var<SQInteger> idx(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                if (idx.value + 1 < static_cast<SQInteger>(left.value.getVertexCount())) {
                    Sqrat::PushVar(v, idx.value + 1);
                    return 1;
                }
                sq_pushnull(v);
                return 1;
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, _SC("null|integer")).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML vertex array library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlVertexArrayLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::VertexArray> sfVertexArray(v, _SC("sf.VertexArray"));
    sfVertexArray.SquirrelFunc(_SC("constructor"), &sfVertexArray_constructor);
    sfVertexArray.Func(_SC("append"), &sf::VertexArray::append);
    sfVertexArray.Func(_SC("clear"), &sf::VertexArray::clear);
    sfVertexArray.Func(_SC("getBounds"), &sf::VertexArray::getBounds);
    sfVertexArray.Func(_SC("getPrimitiveType"), &sf::VertexArray::getPrimitiveType);
    sfVertexArray.Func(_SC("getVertexCount"), &sf::VertexArray::getVertexCount);
    sfVertexArray.Func(_SC("resize"), &sf::VertexArray::resize);
    sfVertexArray.Func(_SC("setPrimitiveType"), &sf::VertexArray::setPrimitiveType);
    sfVertexArray.SquirrelFunc(_SC("_get"), &sfVertexArray_get);
    sfVertexArray.SquirrelFunc(_SC("_set"), &sfVertexArray_set);
    sfVertexArray.SquirrelFunc(_SC("_nexti"), &sfVertexArray_nexti);

    namespaceTable.Bind(_SC("VertexArray"), sfVertexArray);
}

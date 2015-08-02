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
#include <SFML/System/String.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfString_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::String* instance = new sf::String();
        Sqrat::DefaultAllocator<sf::String>::SetInstance(v, 1, instance);
        return 0;
    }
    Sqrat::Var<Sqrat::Array> utf32String(v, 2);
    if (!Sqrat::Error::Occurred(v)) {
        sq_pushobject(v, utf32String.value.GetObject());
        sq_pushnull(v);
        sf::Uint32 data[sq_getsize(v, -2) + 1];
        while (SQ_SUCCEEDED(sq_next(v, -2))) {
            SQInteger key;
            sq_getinteger(v, -2, &key);
            Sqrat::Var<sf::Uint32> utf32Char(v, -1);
            if (Sqrat::Error::Occurred(v)) {
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            sq_pop(v, 2);
            data[key] = utf32Char.value;
        }
        data[sq_getsize(v, -2)] = 0;
        sq_pop(v, 2);
        sf::String* instance = new sf::String(data);
        Sqrat::DefaultAllocator<sf::String>::SetInstance(v, 1, instance);
        return 0;
    }
    Sqrat::Error::Clear(v);
    Sqrat::Var<sf::Uint32> utf32Char(v, 2);
    if (!Sqrat::Error::Occurred(v)) {
        sf::String* instance = new sf::String(utf32Char.value);
        Sqrat::DefaultAllocator<sf::String>::SetInstance(v, 1, instance);
        return 0;
    }
    Sqrat::Error::Clear(v);
    Sqrat::Var<const sf::String&> copy(v, 2);
    sf::String* instance = new sf::String(copy.value);
    Sqrat::DefaultAllocator<sf::String>::SetInstance(v, 1, instance);
    return 0;
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfString_equals(const sf::String& left, const sf::String& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// Erases one or more characters from the string
////////////////////////////////////////////////////////////
static SQInteger sfString_erase(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<std::size_t> position(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.erase(position.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<std::size_t> position(v, 2);
        Sqrat::Var<std::size_t> count(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.erase(position.value, count.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Finds a sequence of one or more characters in the string
////////////////////////////////////////////////////////////
static SQInteger sfString_find(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<const sf::String&> str(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            std::size_t pos = left.value.find(str.value);
            if (pos != sf::String::InvalidPos) {
                Sqrat::PushVar(v, pos);
                return 1;
            }
            sq_pushnull(v);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<const sf::String&> str(v, 2);
        Sqrat::Var<std::size_t> start(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            std::size_t pos = left.value.find(str.value, start.value);
            if (pos != sf::String::InvalidPos) {
                Sqrat::PushVar(v, pos);
                return 1;
            }
            sq_pushnull(v);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Gets an array of characters representing the string
////////////////////////////////////////////////////////////
static SQInteger sfString_getData(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        Sqrat::Var<sf::String&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            const sf::Uint32* data = left.value.getData();
            sq_newarray(v, left.value.getSize());
            for (std::size_t i = 0; i < left.value.getSize(); ++i) {
                Sqrat::PushVar(v, i);
                Sqrat::PushVar(v, data[i]);
                sq_rawset(v, -3);
            }
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Replaces a substring or all occurrences of a substring with another string
////////////////////////////////////////////////////////////
static SQInteger sfString_replace(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<const sf::String&> searchFor(v, 2);
        Sqrat::Var<const sf::String&> replaceWith(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.replace(searchFor.value, replaceWith.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<std::size_t> position(v, 2);
        Sqrat::Var<std::size_t> length(v, 3);
        Sqrat::Var<const sf::String&> replaceWith(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.replace(position.value, length.value, replaceWith.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Returns a section of the string as a new string
////////////////////////////////////////////////////////////
static SQInteger sfString_slice(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<SQInteger> start(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            if (start.value < 0)                                            start.value += left.value.getSize();
            if (start.value > static_cast<SQInteger>(left.value.getSize())) return sq_throwerror(v, _SC("wrong indexes"));
            sf::String slice;
            for (SQInteger i = start.value; i < static_cast<SQInteger>(left.value.getSize()); ++i) {
                slice += sf::String(left.value[i]);
            }
            Sqrat::PushVar(v, slice);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<SQInteger> start(v, 2);
        Sqrat::Var<SQInteger> end(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            if (start.value < 0)                                            start.value += left.value.getSize();
            if (end.value   < 0)                                            end.value   += left.value.getSize();
            if (start.value > end.value)                                    return sq_throwerror(v, _SC("wrong indexes"));
            if (end.value   > static_cast<SQInteger>(left.value.getSize())) return sq_throwerror(v, _SC("slice out of range"));
            sf::String slice;
            for (SQInteger i = start.value; i < end.value; ++i) {
                slice += sf::String(left.value[i]);
            }
            Sqrat::PushVar(v, slice);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Returns a part of the string
////////////////////////////////////////////////////////////
static SQInteger sfString_substring(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<std::size_t> position(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.substring(position.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<std::size_t> position(v, 2);
        Sqrat::Var<std::size_t> length(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.substring(position.value, length.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Converts the unicode string to an ANSI string
////////////////////////////////////////////////////////////
static std::string sfString_toAnsiString(const sf::String& left)
{
    return left.toAnsiString();
}


////////////////////////////////////////////////////////////
// Converts the string to a float and returns it
////////////////////////////////////////////////////////////
static SQFloat sfString_tofloat(const sf::String& left)
{
    SQFloat val;
    std::istringstream(left.toAnsiString()) >> val;
    return val;
}


////////////////////////////////////////////////////////////
// Converts the string to an integer and returns it
////////////////////////////////////////////////////////////
static SQInteger sfString_tointeger(const sf::String& left)
{
    SQInteger val;
    std::istringstream(left.toAnsiString()) >> val;
    return val;
}


////////////////////////////////////////////////////////////
// Returns a lower-case copy of the string
////////////////////////////////////////////////////////////
static sf::String sfString_tolower(const sf::String& left)
{
    sf::String lowerCaseCopy;
    for (sf::String::ConstIterator it = left.begin(); it != left.end(); ++it) {
        if (*it < 'A' || *it > 'Z') {
            lowerCaseCopy += sf::String(*it);
        } else {
            lowerCaseCopy += sf::String(*it + 32);
        }
    }
    return lowerCaseCopy;
}


////////////////////////////////////////////////////////////
// Returns an upper-case copy of the string
////////////////////////////////////////////////////////////
static sf::String sfString_toupper(const sf::String& left)
{
    sf::String upperCaseCopy;
    for (sf::String::ConstIterator it = left.begin(); it != left.end(); ++it) {
        if (*it < 'a' || *it > 'z') {
            upperCaseCopy += sf::String(*it);
        } else {
            upperCaseCopy += sf::String(*it - 32);
        }
    }
    return upperCaseCopy;
}


////////////////////////////////////////////////////////////
// Gets a character by its position
////////////////////////////////////////////////////////////
static SQInteger sfString_get(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<SQInteger> idx(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            if (idx.value < 0 || idx.value >= static_cast<SQInteger>(left.value.getSize())) {
                return sq_throwerror(v, _SC("index out of range"));
            }
            Sqrat::PushVar(v, left.value[idx.value]);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sets a character by its position
////////////////////////////////////////////////////////////
static SQInteger sfString_set(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::String&> left(v, 1);
        Sqrat::Var<SQInteger> idx(v, 2);
        Sqrat::Var<sf::Uint32> val(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            if (idx.value < 0 || idx.value >= static_cast<SQInteger>(left.value.getSize())) {
                return sq_throwerror(v, _SC("index out of range"));
            }
            Sqrat::PushVar(v, left.value[idx.value] = val.value);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Invoked when a class instance is iterated by a foreach loop
////////////////////////////////////////////////////////////
static SQInteger sfString_nexti(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::String&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            if (sq_gettype(v, 2) == OT_NULL) {
                if (left.value.getSize() > 0) {
                    Sqrat::PushVar(v, 0);
                    return 1;
                }
                sq_pushnull(v);
                return 1;
            }
            Sqrat::Var<SQInteger> idx(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                if (idx.value + 1 < static_cast<SQInteger>(left.value.getSize())) {
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
// The + operator
////////////////////////////////////////////////////////////
static sf::String sfString_add(const sf::String& left, const sf::String& right)
{
    return left + right;
}


////////////////////////////////////////////////////////////
// Invoked to emulate the < > <= >= operators
////////////////////////////////////////////////////////////
static int sfString_cmp(const sf::String& left, const sf::String& right)
{
    if (left == right)
        return 0;
    if (left < right)
        return -1;
    return 1;
}


////////////////////////////////////////////////////////////
// Invoked during string conacatenation or when the print function prints an instance
////////////////////////////////////////////////////////////
static std::string sfString_tostring(const sf::String& right)
{
    return right;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML string library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlStringLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::String> sfString(v, _SC("sf.String"));
    sfString.SquirrelFunc(_SC("constructor"), &sfString_constructor);
    sfString.SquirrelFunc(_SC("erase"), &sfString_erase);
    sfString.SquirrelFunc(_SC("find"), &sfString_find);
    sfString.SquirrelFunc(_SC("getData"), &sfString_getData);
    sfString.SquirrelFunc(_SC("replace"), &sfString_replace);
    sfString.SquirrelFunc(_SC("slice"), &sfString_slice);
    sfString.SquirrelFunc(_SC("substring"), &sfString_substring);
    sfString.Func(_SC("clear"), &sf::String::clear);
    sfString.GlobalFunc(_SC("equals"), &sfString_equals);
    sfString.Func(_SC("getSize"), &sf::String::getSize);
    sfString.Func(_SC("insert"), &sf::String::insert);
    sfString.Func(_SC("isEmpty"), &sf::String::isEmpty);
    sfString.Func(_SC("len"), &sf::String::getSize);
    sfString.GlobalFunc(_SC("toAnsiString"), &sfString_toAnsiString);
    sfString.GlobalFunc(_SC("tofloat"), &sfString_tofloat);
    sfString.GlobalFunc(_SC("tointeger"), &sfString_tointeger);
    sfString.GlobalFunc(_SC("tolower"), &sfString_tolower);
    sfString.GlobalFunc(_SC("tostring"), &sfString_toAnsiString);
    sfString.GlobalFunc(_SC("toupper"), &sfString_toupper);
    sfString.SquirrelFunc(_SC("_get"), &sfString_get);
    sfString.SquirrelFunc(_SC("_set"), &sfString_set);
    sfString.SquirrelFunc(_SC("_nexti"), &sfString_nexti);
    sfString.GlobalFunc(_SC("_add"), &sfString_add);
    sfString.GlobalFunc(_SC("_cmp"), &sfString_cmp);
    sfString.GlobalFunc(_SC("_tostring"), &sfString_tostring);

    namespaceTable.Bind(_SC("String"), sfString);
}

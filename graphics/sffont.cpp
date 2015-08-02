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
#include <SFML/Graphics/Font.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfFontInfo_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sq_pushobject(v, Sqrat::ClassType<sf::Font::Info>::getClassData(v)->classObj);
        sq_createinstance(v, -1);
        sq_remove(v, -2);
        sf::Font::Info* instance = new sf::Font::Info();
        Sqrat::DefaultAllocator<sf::Font::Info>::SetInstance(v, -1, instance);
        return 1;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Font::Info&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, Sqrat::ClassType<sf::Font::Info>::getClassData(v)->classObj);
            sq_createinstance(v, -1);
            sq_remove(v, -2);
            sf::Font::Info* instance = new sf::Font::Info(copy.value);
            Sqrat::DefaultAllocator<sf::Font::Info>::SetInstance(v, -1, instance);
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfFont_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Font* instance = new sf::Font();
        Sqrat::DefaultAllocator<sf::Font>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Font&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Font* instance = new sf::Font(copy.value);
            Sqrat::DefaultAllocator<sf::Font>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Loads the font from a file in memory
////////////////////////////////////////////////////////////
static SQInteger sfFont_loadFromMemory(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Font&> left(v, 1);
        Sqrat::Var<const std::string&> data(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.loadFromMemory(data.value.c_str(), data.value.size()));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML font library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlFontLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Font::Info> sfFontInfo(v, _SC("sf.Font.Info"));
    sfFontInfo.Var(_SC("family"), &sf::Font::Info::family);

    Sqrat::Class<sf::Font> sfFont(v, _SC("sf.Font"));
    sfFont.SquirrelFunc(_SC("Info"), &sfFontInfo_constructor);
    sfFont.SquirrelFunc(_SC("constructor"), &sfFont_constructor);
    sfFont.SquirrelFunc(_SC("loadFromMemory"), &sfFont_loadFromMemory);
    sfFont.Func(_SC("getGlyph"), &sf::Font::getGlyph);
    sfFont.Func(_SC("getInfo"), &sf::Font::getInfo);
    sfFont.Func(_SC("getKerning"), &sf::Font::getKerning);
    sfFont.Func(_SC("getLineSpacing"), &sf::Font::getLineSpacing);
    sfFont.Func(_SC("getTexture"), &sf::Font::getTexture);
    sfFont.Func(_SC("getUnderlinePosition"), &sf::Font::getUnderlinePosition);
    sfFont.Func(_SC("getUnderlineThickness"), &sf::Font::getUnderlineThickness);
    sfFont.Func(_SC("loadFromFile"), &sf::Font::loadFromFile);

    namespaceTable.Bind(_SC("Font"), sfFont);
}

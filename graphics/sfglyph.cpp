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
#include <SFML/Graphics/Glyph.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfGlyph_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Glyph* instance = new sf::Glyph();
        Sqrat::DefaultAllocator<sf::Glyph>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Glyph&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Glyph* instance = new sf::Glyph(copy.value);
            Sqrat::DefaultAllocator<sf::Glyph>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML glyph library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlGlyphLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Glyph> sfGlyph(v, _SC("sf.Glyph"));
    sfGlyph.SquirrelFunc(_SC("constructor"), &sfGlyph_constructor);
    sfGlyph.Var(_SC("advance"), &sf::Glyph::advance);
    sfGlyph.Var(_SC("bounds"), &sf::Glyph::bounds);
    sfGlyph.Var(_SC("textureRect"), &sf::Glyph::textureRect);

    namespaceTable.Bind(_SC("Glyph"), sfGlyph);
}

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
#include <SFML/Graphics/Text.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfText_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Text* instance = new sf::Text();
        Sqrat::DefaultAllocator<sf::Text>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Text&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Text* instance = new sf::Text(copy.value);
            Sqrat::DefaultAllocator<sf::Text>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<const sf::String&> string(v, 2);
        Sqrat::Var<const sf::Font&> font(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Text* instance = new sf::Text(string.value, font.value);
            Sqrat::DefaultAllocator<sf::Text>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<const sf::String&> string(v, 2);
        Sqrat::Var<const sf::Font&> font(v, 3);
        Sqrat::Var<unsigned int> characterSize(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Text* instance = new sf::Text(string.value, font.value, characterSize.value);
            Sqrat::DefaultAllocator<sf::Text>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML text library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlTextLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::ConstTable constTable(v);
    constTable.Const(_SC("SF_TEXT_REGULAR"), static_cast<int>(sf::Text::Regular));
    constTable.Const(_SC("SF_TEXT_BOLD"), static_cast<int>(sf::Text::Bold));
    constTable.Const(_SC("SF_TEXT_ITALIC"), static_cast<int>(sf::Text::Italic));
    constTable.Const(_SC("SF_TEXT_UNDERLINED"), static_cast<int>(sf::Text::Underlined));
    constTable.Const(_SC("SF_TEXT_STRIKE_THROUGH"), static_cast<int>(sf::Text::StrikeThrough));

    Sqrat::DerivedClass<sf::Text, sf::Transformable> sfText(v, _SC("sf.Text"));
    sfText.SquirrelFunc(_SC("constructor"), &sfText_constructor);
    sfText.Func(_SC("findCharacterPos"), &sf::Text::findCharacterPos);
    sfText.Func(_SC("getCharacterSize"), &sf::Text::getCharacterSize);
    sfText.Func(_SC("getColor"), &sf::Text::getColor);
    sfText.Func(_SC("getFont"), &sf::Text::getFont);
    sfText.Func(_SC("getGlobalBounds"), &sf::Text::getGlobalBounds);
    sfText.Func(_SC("getLocalBounds"), &sf::Text::getLocalBounds);
    sfText.Func(_SC("getString"), &sf::Text::getString);
    sfText.Func(_SC("getStyle"), &sf::Text::getStyle);
    sfText.Func(_SC("setCharacterSize"), &sf::Text::setCharacterSize);
    sfText.Func(_SC("setColor"), &sf::Text::setColor);
    sfText.Func(_SC("setFont"), &sf::Text::setFont);
    sfText.Func(_SC("setString"), &sf::Text::setString);
    sfText.Func(_SC("setStyle"), &sf::Text::setStyle);

    namespaceTable.Bind(_SC("Text"), sfText);
}

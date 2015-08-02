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
#include <SFML/Graphics/BlendMode.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfBlendMode_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::BlendMode* instance = new sf::BlendMode();
        Sqrat::DefaultAllocator<sf::BlendMode>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::BlendMode::Factor> sourceFactor(v, 2);
        Sqrat::Var<sf::BlendMode::Factor> destinationFactor(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            sf::BlendMode* instance = new sf::BlendMode(sourceFactor.value, destinationFactor.value);
            Sqrat::DefaultAllocator<sf::BlendMode>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::BlendMode::Factor> sourceFactor(v, 2);
        Sqrat::Var<sf::BlendMode::Factor> destinationFactor(v, 3);
        Sqrat::Var<sf::BlendMode::Equation> blendEquation(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sf::BlendMode* instance = new sf::BlendMode(sourceFactor.value, destinationFactor.value, blendEquation.value);
            Sqrat::DefaultAllocator<sf::BlendMode>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 7) {
        Sqrat::Var<sf::BlendMode::Factor> colorSourceFactor(v, 2);
        Sqrat::Var<sf::BlendMode::Factor> colorDestinationFactor(v, 3);
        Sqrat::Var<sf::BlendMode::Equation> colorBlendEquation(v, 4);
        Sqrat::Var<sf::BlendMode::Factor> alphaSourceFactor(v, 5);
        Sqrat::Var<sf::BlendMode::Factor> alphaDestinationFactor(v, 6);
        Sqrat::Var<sf::BlendMode::Equation> alphaBlendEquation(v, 7);
        if (!Sqrat::Error::Occurred(v)) {
            sf::BlendMode* instance = new sf::BlendMode(colorSourceFactor.value, colorDestinationFactor.value, colorBlendEquation.value, alphaSourceFactor.value, alphaDestinationFactor.value, alphaBlendEquation.value);
            Sqrat::DefaultAllocator<sf::BlendMode>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfBlendMode_equals(const sf::BlendMode& left, const sf::BlendMode& right)
{
    return left == right;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML blend mode library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlBlendModeLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::ConstTable constTable(v);
    constTable.Const(_SC("SF_BLEND_MODE_ZERO"), static_cast<int>(sf::BlendMode::Zero));
    constTable.Const(_SC("SF_BLEND_MODE_ONE"), static_cast<int>(sf::BlendMode::One));
    constTable.Const(_SC("SF_BLEND_MODE_SRC_COLOR"), static_cast<int>(sf::BlendMode::SrcColor));
    constTable.Const(_SC("SF_BLEND_MODE_ONE_MINUS_SRC_COLOR"), static_cast<int>(sf::BlendMode::OneMinusSrcColor));
    constTable.Const(_SC("SF_BLEND_MODE_DST_COLOR"), static_cast<int>(sf::BlendMode::DstColor));
    constTable.Const(_SC("SF_BLEND_MODE_ONE_MINUS_DST_COLOR"), static_cast<int>(sf::BlendMode::OneMinusDstColor));
    constTable.Const(_SC("SF_BLEND_MODE_SRC_ALPHA"), static_cast<int>(sf::BlendMode::SrcAlpha));
    constTable.Const(_SC("SF_BLEND_MODE_ONE_MINUS_SRC_ALPHA"), static_cast<int>(sf::BlendMode::OneMinusSrcAlpha));
    constTable.Const(_SC("SF_BLEND_MODE_DST_ALPHA"), static_cast<int>(sf::BlendMode::DstAlpha));
    constTable.Const(_SC("SF_BLEND_MODE_ONE_MINUS_DST_ALPHA"), static_cast<int>(sf::BlendMode::OneMinusDstAlpha));
    constTable.Const(_SC("SF_BLEND_MODE_ADD"), static_cast<int>(sf::BlendMode::Add));
    constTable.Const(_SC("SF_BLEND_MODE_SUBTRACT"), static_cast<int>(sf::BlendMode::Subtract));

    Sqrat::Class<sf::BlendMode> sfBlendMode(v, _SC("sf.BlendMode"));
    sfBlendMode.SquirrelFunc(_SC("constructor"), &sfBlendMode_constructor);
    sfBlendMode.GlobalFunc(_SC("equals"), &sfBlendMode_equals);
    sfBlendMode.Var(_SC("colorSrcFactor"), &sf::BlendMode::colorSrcFactor);
    sfBlendMode.Var(_SC("colorDstFactor"), &sf::BlendMode::colorDstFactor);
    sfBlendMode.Var(_SC("colorEquation"), &sf::BlendMode::colorEquation);
    sfBlendMode.Var(_SC("alphaSrcFactor"), &sf::BlendMode::alphaSrcFactor);
    sfBlendMode.Var(_SC("alphaDstFactor"), &sf::BlendMode::alphaDstFactor);
    sfBlendMode.Var(_SC("alphaEquation"), &sf::BlendMode::alphaEquation);
    sfBlendMode.SetStaticValue(_SC("Alpha"), sf::BlendAlpha);
    sfBlendMode.SetStaticValue(_SC("Add"), sf::BlendAdd);
    sfBlendMode.SetStaticValue(_SC("Multiply"), sf::BlendMultiply);
    sfBlendMode.SetStaticValue(_SC("None"), sf::BlendNone);

    namespaceTable.Bind(_SC("BlendMode"), sfBlendMode);
}

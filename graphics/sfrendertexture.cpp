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
#include <SFML/Graphics/RenderTexture.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfRenderTexture_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::RenderTexture* instance = new sf::RenderTexture();
        Sqrat::DefaultAllocator<sf::RenderTexture>::SetInstance(v, 1, instance);
        return 0;
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Creates the render-texture
////////////////////////////////////////////////////////////
static SQInteger sfRenderTexture_create(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTexture&> left(v, 1);
        Sqrat::Var<unsigned int> width(v, 2);
        Sqrat::Var<unsigned int> height(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.create(width.value, height.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML render texture library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlRenderTextureLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::DerivedClass<sf::RenderTexture, sf::RenderTarget, Sqrat::NoCopy<sf::RenderTexture> > sfRenderTexture(v, _SC("sf.RenderTexture"));
    sfRenderTexture.SquirrelFunc(_SC("constructor"), &sfRenderTexture_constructor);
    sfRenderTexture.SquirrelFunc(_SC("create"), &sfRenderTexture_create);
    sfRenderTexture.Func(_SC("display"), &sf::RenderTexture::display);
    sfRenderTexture.Func(_SC("getSize"), &sf::RenderTexture::getSize);
    sfRenderTexture.Func(_SC("getTexture"), &sf::RenderTexture::getTexture);
    sfRenderTexture.Func(_SC("isRepeated"), &sf::RenderTexture::isRepeated);
    sfRenderTexture.Func(_SC("isSmooth"), &sf::RenderTexture::isSmooth);
    sfRenderTexture.Func(_SC("setRepeated"), &sf::RenderTexture::setRepeated);
    sfRenderTexture.Func(_SC("setSmooth"), &sf::RenderTexture::setSmooth);

    namespaceTable.Bind(_SC("RenderTexture"), sfRenderTexture);
}

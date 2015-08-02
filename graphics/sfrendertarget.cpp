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
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/VertexArray.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_constructor(HSQUIRRELVM v)
{
    return sq_throwerror(v, _SC("constructor is protected"));
}


////////////////////////////////////////////////////////////
// Clears the entire target with a single color
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_clear(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.clear();
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Color&> color(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.clear(color.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Draws a circle shape to the render-target
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_drawCircle(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::CircleShape&> circle(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(circle.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::CircleShape&> circle(v, 2);
        Sqrat::Var<const sf::RenderStates&> states(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(circle.value, states.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Draws a convex shape to the render-target
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_drawConvex(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::ConvexShape&> convex(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(convex.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::ConvexShape&> convex(v, 2);
        Sqrat::Var<const sf::RenderStates&> states(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(convex.value, states.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Draws a rectangle shape to the render-target
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_drawRectangle(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::RectangleShape&> rectangle(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(rectangle.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::RectangleShape&> rectangle(v, 2);
        Sqrat::Var<const sf::RenderStates&> states(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(rectangle.value, states.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Draws a sprite to the render-target
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_drawSprite(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Sprite&> sprite(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(sprite.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Sprite&> sprite(v, 2);
        Sqrat::Var<const sf::RenderStates&> states(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(sprite.value, states.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Draws text to the render-target
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_drawText(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Text&> text(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(text.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Text&> text(v, 2);
        Sqrat::Var<const sf::RenderStates&> states(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(text.value, states.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Draws vertices to the render-target
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_drawVertices(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::VertexArray&> vertices(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(vertices.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::VertexArray&> vertices(v, 2);
        Sqrat::Var<const sf::RenderStates&> states(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            left.value.draw(vertices.value, states.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<Sqrat::Array> vertices(v, 2);
        Sqrat::Var<unsigned int> vertexCount(v, 3);
        Sqrat::Var<sf::PrimitiveType> type(v, 4);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, vertices.value.GetObject());
            sq_pushnull(v);
            sf::Vertex data[sq_getsize(v, -2)];
            while (SQ_SUCCEEDED(sq_next(v, -2))) {
                SQInteger key;
                sq_getinteger(v, -2, &key);
                Sqrat::Var<const sf::Vertex&> vertex(v, -1);
                if (Sqrat::Error::Occurred(v)) {
                    return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
                }
                sq_pop(v, 2);
                data[key] = vertex.value;
            }
            sq_pop(v, 2);
            left.value.draw(data, vertexCount.value, type.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 5) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<Sqrat::Array> vertices(v, 2);
        Sqrat::Var<unsigned int> vertexCount(v, 3);
        Sqrat::Var<sf::PrimitiveType> type(v, 4);
        Sqrat::Var<const sf::RenderStates&> states(v, 5);
        if (!Sqrat::Error::Occurred(v)) {
            sq_pushobject(v, vertices.value.GetObject());
            sq_pushnull(v);
            sf::Vertex data[sq_getsize(v, -2)];
            while (SQ_SUCCEEDED(sq_next(v, -2))) {
                SQInteger key;
                sq_getinteger(v, -2, &key);
                Sqrat::Var<const sf::Vertex&> vertex(v, -1);
                if (Sqrat::Error::Occurred(v)) {
                    return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
                }
                sq_pop(v, 2);
                data[key] = vertex.value;
            }
            sq_pop(v, 2);
            left.value.draw(data, vertexCount.value, type.value, states.value);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Converts a point from world coordinates to target coordinates
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_mapCoordsToPixel(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> point(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.mapCoordsToPixel(point.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Vector2f&> point(v, 2);
        Sqrat::Var<const sf::View&> view(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.mapCoordsToPixel(point.value, view.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Converts a point from target coordinates to world coordinates
////////////////////////////////////////////////////////////
static SQInteger sfRenderTarget_mapPixelToCoords(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Vector2i&> point(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.mapPixelToCoords(point.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    } else if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::RenderTarget&> left(v, 1);
        Sqrat::Var<const sf::Vector2i&> point(v, 2);
        Sqrat::Var<const sf::View&> view(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.mapPixelToCoords(point.value, view.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML render target library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlRenderTargetLib(HSQUIRRELVM v, Sqrat::Table & namespaceTable)
{
    Sqrat::Class<sf::RenderTarget, Sqrat::NoConstructor<sf::RenderTarget> > sfRenderTarget(v, _SC("sf.RenderTarget"));
    sfRenderTarget.SquirrelFunc(_SC("constructor"), &sfRenderTarget_constructor);
    sfRenderTarget.SquirrelFunc(_SC("clear"), &sfRenderTarget_clear);
    sfRenderTarget.SquirrelFunc(_SC("drawCircle"), &sfRenderTarget_drawCircle);
    sfRenderTarget.SquirrelFunc(_SC("drawConvex"), &sfRenderTarget_drawConvex);
    sfRenderTarget.SquirrelFunc(_SC("drawRectangleShape"), &sfRenderTarget_drawRectangle);
    sfRenderTarget.SquirrelFunc(_SC("drawSprite"), &sfRenderTarget_drawSprite);
    sfRenderTarget.SquirrelFunc(_SC("drawText"), &sfRenderTarget_drawText);
    sfRenderTarget.SquirrelFunc(_SC("drawVertices"), &sfRenderTarget_drawVertices);
    sfRenderTarget.SquirrelFunc(_SC("mapCoordsToPixel"), &sfRenderTarget_mapCoordsToPixel);
    sfRenderTarget.SquirrelFunc(_SC("mapPixelToCoords"), &sfRenderTarget_mapPixelToCoords);
    sfRenderTarget.Func(_SC("getDefaultView"), &sf::RenderTarget::getDefaultView);
    sfRenderTarget.Func(_SC("getView"), &sf::RenderTarget::getView);
    sfRenderTarget.Func(_SC("getViewport"), &sf::RenderTarget::getViewport);
    sfRenderTarget.Func(_SC("setView"), &sf::RenderTarget::setView);

    namespaceTable.Bind(_SC("RenderTarget"), sfRenderTarget);
}

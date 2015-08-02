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
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <sfml/network/sfport.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfTcpListener_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::TcpListener* instance = new sf::TcpListener();
        instance->setBlocking(false);
        Sqrat::DefaultAllocator<sf::TcpListener>::SetInstance(v, 1, instance);
        return 0;
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Accepts a new connection
////////////////////////////////////////////////////////////
static SQInteger sfTcpListener_accept(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::TcpListener&> left(v, 1);
        Sqrat::Var<sf::TcpSocket&> socket(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.accept(socket.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Starts listening for connections
////////////////////////////////////////////////////////////
static SQInteger sfTcpListener_listen(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::TcpListener&> left(v, 1);
        Sqrat::Var<const sf::Port&> port(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.listen(port.value.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML TCP listener library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlTcpListenerLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::TcpListener, Sqrat::NoCopy<sf::TcpListener> > sfTcpListener(v, _SC("sf.TcpListener"));
    sfTcpListener.SquirrelFunc(_SC("constructor"), &sfTcpListener_constructor);
    sfTcpListener.SquirrelFunc(_SC("accept"), &sfTcpListener_accept);
    sfTcpListener.SquirrelFunc(_SC("listen"), &sfTcpListener_listen);
    sfTcpListener.Func(_SC("close"), &sf::TcpListener::close);
    sfTcpListener.Func(_SC("getLocalPort"), &sf::TcpListener::getLocalPort);

    namespaceTable.Bind(_SC("TcpListener"), sfTcpListener);
}

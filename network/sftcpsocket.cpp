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
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <sfml/network/sfport.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfTcpSocket_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::TcpSocket* instance = new sf::TcpSocket();
        instance->setBlocking(false);
        Sqrat::DefaultAllocator<sf::TcpSocket>::SetInstance(v, 1, instance);
        return 0;
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Connects the socket to a remote peer
////////////////////////////////////////////////////////////
static SQInteger sfTcpSocket_connect(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 3) {
        Sqrat::Var<sf::TcpSocket&> left(v, 1);
        Sqrat::Var<const sf::IpAddress&> remoteAddress(v, 2);
        Sqrat::Var<const sf::Port&> remotePort(v, 3);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.connect(remoteAddress.value, remotePort.value.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Receives from the remote peer
////////////////////////////////////////////////////////////
static SQInteger sfTcpSocket_receive(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::TcpSocket&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<sf::Packet&> packet(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::PushVar(v, left.value.receive(packet.value));
                return 1;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<std::size_t> size(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                char data[size.value];
                std::size_t received = 0;
                sf::Socket::Status status = left.value.receive(data, size.value, received);
                if (received > 0 && received <= size.value) {
                    Sqrat::PushVar(v, std::string(data, received));
                } else {
                    Sqrat::PushVar(v, status);
                }
                return 1;
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Packet>::ClassName() + _SC("|integer")).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sends to the remote peer
////////////////////////////////////////////////////////////
static SQInteger sfTcpSocket_send(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::TcpSocket&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<sf::Packet&> packet(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::PushVar(v, left.value.send(packet.value));
                return 1;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const std::string&> data(v, 2);
            Sqrat::PushVar(v, left.value.send(data.value.c_str(), data.value.size()));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML TCP socket library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlTcpSocketLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::TcpSocket, Sqrat::NoCopy<sf::TcpSocket> > sfTcpSocket(v, _SC("sf.TcpSocket"));
    sfTcpSocket.SquirrelFunc(_SC("constructor"), &sfTcpSocket_constructor);
    sfTcpSocket.SquirrelFunc(_SC("connect"), &sfTcpSocket_connect);
    sfTcpSocket.SquirrelFunc(_SC("receive"), &sfTcpSocket_receive);
    sfTcpSocket.SquirrelFunc(_SC("send"), &sfTcpSocket_send);
    sfTcpSocket.Func(_SC("disconnect"), &sf::TcpSocket::disconnect);
    sfTcpSocket.Func(_SC("getLocalPort"), &sf::TcpSocket::getLocalPort);
    sfTcpSocket.Func(_SC("getRemoteAddress"), &sf::TcpSocket::getRemoteAddress);
    sfTcpSocket.Func(_SC("getRemotePort"), &sf::TcpSocket::getRemotePort);

    namespaceTable.Bind(_SC("TcpSocket"), sfTcpSocket);
}

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
#include <SFML/Network/UdpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <sfml/network/sfport.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfUdpSocket_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::UdpSocket* instance = new sf::UdpSocket();
        instance->setBlocking(false);
        Sqrat::DefaultAllocator<sf::UdpSocket>::SetInstance(v, 1, instance);
        return 0;
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Binds the socket to a specific port
////////////////////////////////////////////////////////////
static SQInteger sfUdpSocket_bind(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::UdpSocket&> left(v, 1);
        Sqrat::Var<const sf::Port&> port(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, left.value.bind(port.value.value));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Receives from a remote peer
////////////////////////////////////////////////////////////
static SQInteger sfUdpSocket_receive(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::UdpSocket&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<sf::Packet&> packet(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::Var<sf::IpAddress&> remoteAddress(v, 3);
                Sqrat::Var<sf::Port&> remotePort(v, 4);
                if (!Sqrat::Error::Occurred(v)) {
                    Sqrat::PushVar(v, left.value.receive(packet.value, remoteAddress.value, remotePort.value.value));
                    return 1;
                }
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<std::size_t> size(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::Var<sf::IpAddress&> remoteAddress(v, 3);
                Sqrat::Var<sf::Port&> remotePort(v, 4);
                if (!Sqrat::Error::Occurred(v)) {
                    char data[size.value];
                    std::size_t received = 0;
                    sf::Socket::Status status = left.value.receive(data, size.value, received, remoteAddress.value, remotePort.value.value);
                    if (received > 0 && received <= size.value) {
                        Sqrat::PushVar(v, std::string(data, received));
                    } else {
                        Sqrat::PushVar(v, status);
                    }
                    return 1;
                }
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            Sqrat::Error::Clear(v);
            return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Packet>::ClassName() + _SC("|integer")).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Sends to a remote peer
////////////////////////////////////////////////////////////
static SQInteger sfUdpSocket_send(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 4) {
        Sqrat::Var<sf::UdpSocket&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<sf::Packet&> packet(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::Var<const sf::IpAddress&> remoteAddress(v, 3);
                Sqrat::Var<const sf::Port&> remotePort(v, 4);
                if (!Sqrat::Error::Occurred(v)) {
                    Sqrat::PushVar(v, left.value.send(packet.value, remoteAddress.value, remotePort.value.value));
                    return 1;
                }
                return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const std::string&> data(v, 2);
            Sqrat::Var<const sf::IpAddress&> remoteAddress(v, 3);
            Sqrat::Var<const sf::Port&> remotePort(v, 4);
            if (!Sqrat::Error::Occurred(v)) {
                Sqrat::PushVar(v, left.value.send(data.value.c_str(), data.value.size(), remoteAddress.value, remotePort.value.value));
                return 1;
            }
            return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML UDP socket library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlUdpSocketLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::ConstTable(v).Const(_SC("SF_UDP_SOCKET_MAX_DATAGRAM_SIZE"), sf::UdpSocket::MaxDatagramSize);

    Sqrat::Class<sf::UdpSocket, Sqrat::NoCopy<sf::UdpSocket> > sfUdpSocket(v, _SC("sf.UdpSocket"));
    sfUdpSocket.SquirrelFunc(_SC("constructor"), &sfUdpSocket_constructor);
    sfUdpSocket.SquirrelFunc(_SC("bind"), &sfUdpSocket_bind);
    sfUdpSocket.SquirrelFunc(_SC("receive"), &sfUdpSocket_receive);
    sfUdpSocket.SquirrelFunc(_SC("send"), &sfUdpSocket_send);
    sfUdpSocket.Func(_SC("getLocalPort"), &sf::UdpSocket::getLocalPort);
    sfUdpSocket.Func(_SC("unbind"), &sf::UdpSocket::unbind);

    namespaceTable.Bind(_SC("UdpSocket"), sfUdpSocket);
}

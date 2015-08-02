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
#include <SFML/Network/Packet.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfPacket_constructor(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        sf::Packet* instance = new sf::Packet();
        Sqrat::DefaultAllocator<sf::Packet>::SetInstance(v, 1, instance);
        return 0;
    } else if (sq_gettop(v) == 2) {
        Sqrat::Var<const sf::Packet&> copy(v, 2);
        if (!Sqrat::Error::Occurred(v)) {
            sf::Packet* instance = new sf::Packet(copy.value);
            Sqrat::DefaultAllocator<sf::Packet>::SetInstance(v, 1, instance);
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Appends data to the end of the packet
////////////////////////////////////////////////////////////
static SQInteger sfPacket_append(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 2) {
        Sqrat::Var<sf::Packet&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::Var<const sf::Packet&> packet(v, 2);
            if (!Sqrat::Error::Occurred(v)) {
                left.value.append(packet.value.getData(), packet.value.getDataSize());
                return 0;
            }
            Sqrat::Error::Clear(v);
            Sqrat::Var<const std::string&> data(v, 2);
            left.value.append(data.value.c_str(), data.value.size());
            return 0;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Gets the data contained in the packet
////////////////////////////////////////////////////////////
static SQInteger sfPacket_getData(HSQUIRRELVM v)
{
    if (sq_gettop(v) == 1) {
        Sqrat::Var<sf::Packet&> left(v, 1);
        if (!Sqrat::Error::Occurred(v)) {
            Sqrat::PushVar(v, std::string((const char*) left.value.getData(), left.value.getDataSize()));
            return 1;
        }
        return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
    }
    return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Tests the validity of the packet after reading
////////////////////////////////////////////////////////////
static bool sfPacket_isValid(const sf::Packet& left)
{
    return left;
}


////////////////////////////////////////////////////////////
// Reads a bool from the packet
////////////////////////////////////////////////////////////
static bool sfPacket_readBool(sf::Packet& left)
{
    bool data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads a signed 8 bit integer from the packet
////////////////////////////////////////////////////////////
static sf::Int8 sfPacket_readInt8(sf::Packet& left)
{
    sf::Int8 data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads an unsigned 8 bit integer from the packet
////////////////////////////////////////////////////////////
static sf::Uint8 sfPacket_readUint8(sf::Packet& left)
{
    sf::Uint8 data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads a signed 16 bit integer from the packet
////////////////////////////////////////////////////////////
static sf::Int16 sfPacket_readInt16(sf::Packet& left)
{
    sf::Int16 data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads an unsigned 16 bit integer from the packet
////////////////////////////////////////////////////////////
static sf::Uint16 sfPacket_readUint16(sf::Packet& left)
{
    sf::Uint16 data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads a signed 32 bit integer from the packet
////////////////////////////////////////////////////////////
static sf::Int32 sfPacket_readInt32(sf::Packet& left)
{
    sf::Int32 data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads a float from the packet
////////////////////////////////////////////////////////////
static float sfPacket_readFloat(sf::Packet& left)
{
    float data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads a string from the packet
////////////////////////////////////////////////////////////
static std::string sfPacket_readString(sf::Packet& left)
{
    std::string data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Reads a unicode string from the packet
////////////////////////////////////////////////////////////
static sf::String sfPacket_readUnicodeString(sf::Packet& left)
{
    sf::String data;
    left >> data;
    return data;
}


////////////////////////////////////////////////////////////
// Writes a bool into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeBool(sf::Packet& left, bool data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes a signed 8 bit integer into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeInt8(sf::Packet& left, sf::Int8 data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes an unsigned 8 bit integer into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeUint8(sf::Packet& left, sf::Uint8 data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes a signed 16 bit integer into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeInt16(sf::Packet& left, sf::Int16 data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes an unsigned 16 bit integer into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeUint16(sf::Packet& left, sf::Uint16 data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes a signed 32 bit integer into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeInt32(sf::Packet& left, sf::Int32 data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes a float into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeFloat(sf::Packet& left, float data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes a string into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeString(sf::Packet& left, const std::string& data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Writes a unicode string into the packet
////////////////////////////////////////////////////////////
static void sfPacket_writeUnicodeString(sf::Packet& left, const sf::String& data)
{
    left << data;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML packet library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlPacketLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
    Sqrat::Class<sf::Packet> sfPacket(v, _SC("sf.Packet"));
    sfPacket.SquirrelFunc(_SC("constructor"), &sfPacket_constructor);
    sfPacket.SquirrelFunc(_SC("append"), &sfPacket_append);
    sfPacket.SquirrelFunc(_SC("getData"), &sfPacket_getData);
    sfPacket.Func(_SC("clear"), &sf::Packet::clear);
    sfPacket.Func(_SC("endOfPacket"), &sf::Packet::endOfPacket);
    sfPacket.Func(_SC("getDataSize"), &sf::Packet::getDataSize);
    sfPacket.GlobalFunc(_SC("isValid"), &sfPacket_isValid);
    sfPacket.GlobalFunc(_SC("readBool"), &sfPacket_readBool);
    sfPacket.GlobalFunc(_SC("readInt8"), &sfPacket_readInt8);
    sfPacket.GlobalFunc(_SC("readUint8"), &sfPacket_readUint8);
    sfPacket.GlobalFunc(_SC("readInt16"), &sfPacket_readInt16);
    sfPacket.GlobalFunc(_SC("readUint16"), &sfPacket_readUint16);
    sfPacket.GlobalFunc(_SC("readInt32"), &sfPacket_readInt32);
    sfPacket.GlobalFunc(_SC("readFloat"), &sfPacket_readFloat);
    sfPacket.GlobalFunc(_SC("readString"), &sfPacket_readString);
    sfPacket.GlobalFunc(_SC("readUnicodeString"), &sfPacket_readUnicodeString);
    sfPacket.GlobalFunc(_SC("writeBool"), &sfPacket_writeBool);
    sfPacket.GlobalFunc(_SC("writeInt8"), &sfPacket_writeInt8);
    sfPacket.GlobalFunc(_SC("writeUint8"), &sfPacket_writeUint8);
    sfPacket.GlobalFunc(_SC("writeInt16"), &sfPacket_writeInt16);
    sfPacket.GlobalFunc(_SC("writeUint16"), &sfPacket_writeUint16);
    sfPacket.GlobalFunc(_SC("writeInt32"), &sfPacket_writeInt32);
    sfPacket.GlobalFunc(_SC("writeFloat"), &sfPacket_writeFloat);
    sfPacket.GlobalFunc(_SC("writeString"), &sfPacket_writeString);
    sfPacket.GlobalFunc(_SC("writeUnicodeString"), &sfPacket_writeUnicodeString);

    namespaceTable.Bind(_SC("Packet"), sfPacket);
}

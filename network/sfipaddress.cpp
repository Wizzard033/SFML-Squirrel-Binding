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
#include <SFML/Network/IpAddress.hpp>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfIpAddress_constructor(HSQUIRRELVM v)
{
	if (sq_gettop(v) == 1) {
		sf::IpAddress* instance = new sf::IpAddress();
		Sqrat::DefaultAllocator<sf::IpAddress>::SetInstance(v, 1, instance);
		return 0;
	} else if (sq_gettop(v) == 2) {
		Sqrat::Var<const sf::IpAddress&> copy(v, 2);
		if (!Sqrat::Error::Occurred(v)) {
			sf::IpAddress* instance = new sf::IpAddress(copy.value);
			Sqrat::DefaultAllocator<sf::IpAddress>::SetInstance(v, 1, instance);
			return 0;
		}
		Sqrat::Error::Clear(v);
		Sqrat::Var<sf::Uint32> addressInteger(v, 2);
		if (!Sqrat::Error::Occurred(v)) {
			sf::IpAddress* instance = new sf::IpAddress(addressInteger.value);
			Sqrat::DefaultAllocator<sf::IpAddress>::SetInstance(v, 1, instance);
			return 0;
		}
		Sqrat::Error::Clear(v);
		Sqrat::Var<const std::string&> addressString(v, 2);
		sf::IpAddress* instance = new sf::IpAddress(addressString.value);
		Sqrat::DefaultAllocator<sf::IpAddress>::SetInstance(v, 1, instance);
		return 0;
	} else if (sq_gettop(v) == 5) {
		Sqrat::Var<sf::Uint8> byte0(v, 2);
		Sqrat::Var<sf::Uint8> byte1(v, 3);
		Sqrat::Var<sf::Uint8> byte2(v, 4);
		Sqrat::Var<sf::Uint8> byte3(v, 5);
		if (!Sqrat::Error::Occurred(v)) {
			sf::IpAddress* instance = new sf::IpAddress(byte0.value, byte1.value, byte2.value, byte3.value);
			Sqrat::DefaultAllocator<sf::IpAddress>::SetInstance(v, 1, instance);
			return 0;
		}
		return sq_throwerror(v, Sqrat::Error::Message(v).c_str());
	}
	return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfIpAddress_equals(const sf::IpAddress& left, const sf::IpAddress& right)
{
	return left == right;
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML IP address library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlIpAddressLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
	Sqrat::Class<sf::IpAddress> sfIpAddress(v, _SC("sf.IpAddress"));
	sfIpAddress.SquirrelFunc(_SC("constructor"), &sfIpAddress_constructor);
	sfIpAddress.GlobalFunc(_SC("equals"), &sfIpAddress_equals);
	sfIpAddress.StaticFunc(_SC("getLocalAddress"), &sf::IpAddress::getLocalAddress);
	sfIpAddress.Func(_SC("toInteger"), &sf::IpAddress::toInteger);
	sfIpAddress.Func(_SC("toString"), &sf::IpAddress::toString);
	sfIpAddress.Func(_SC("tointeger"), &sf::IpAddress::toInteger);
	sfIpAddress.Func(_SC("tostring"), &sf::IpAddress::toString);
	sfIpAddress.SetStaticValue(_SC("Broadcast"), sf::IpAddress::Broadcast);
	sfIpAddress.SetStaticValue(_SC("LocalHost"), sf::IpAddress::LocalHost);
	sfIpAddress.SetStaticValue(_SC("None"), sf::IpAddress::None);
	sfIpAddress.Func(_SC("_tostring"), &sf::IpAddress::toString);

	namespaceTable.Bind(_SC("IpAddress"), sfIpAddress);
}

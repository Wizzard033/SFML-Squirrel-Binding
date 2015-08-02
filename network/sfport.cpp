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
#include <sfml/network/sfport.hpp>
#include <sstream>


////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////
static SQInteger sfPort_constructor(HSQUIRRELVM v)
{
	if (sq_gettop(v) == 1) {
		sf::Port* instance = new sf::Port();
		Sqrat::DefaultAllocator<sf::Port>::SetInstance(v, 1, instance);
		return 0;
	} else if (sq_gettop(v) == 2) {
		Sqrat::Var<const sf::Port&> copy(v, 2);
		if (!Sqrat::Error::Occurred(v)) {
			sf::Port* instance = new sf::Port(copy.value);
			Sqrat::DefaultAllocator<sf::Port>::SetInstance(v, 1, instance);
			return 0;
		}
		Sqrat::Error::Clear(v);
		Sqrat::Var<unsigned short> port(v, 2);
		if (!Sqrat::Error::Occurred(v)) {
			sf::Port* instance = new sf::Port(port.value);
			Sqrat::DefaultAllocator<sf::Port>::SetInstance(v, 1, instance);
			return 0;
		}
		Sqrat::Error::Clear(v);
		return sq_throwerror(v, Sqrat::FormatTypeError(v, 2, Sqrat::ClassType<sf::Port>::ClassName() + _SC("|integer")).c_str());
	}
	return sq_throwerror(v, _SC("wrong number of parameters"));
}


////////////////////////////////////////////////////////////
// Implements the C++ == operator in Squirrel
////////////////////////////////////////////////////////////
static bool sfPort_equals(const sf::Port& left, const sf::Port& right)
{
	return left.value == right.value;
}


////////////////////////////////////////////////////////////
// Invoked during string conacatenation or when the print function prints an instance
////////////////////////////////////////////////////////////
static std::string sfPort_tostring(const sf::Port& right)
{
	std::stringstream ss;
	ss << right.value;
	return ss.str();
}


////////////////////////////////////////////////////////////
// Initializes and registers the SFML port library in the given VM
////////////////////////////////////////////////////////////
void RegisterSfmlPortLib(HSQUIRRELVM v, Sqrat::Table& namespaceTable)
{
	Sqrat::Class<sf::Port> sfPort(v, _SC("sf.Port"));
	sfPort.SquirrelFunc(_SC("constructor"), &sfPort_constructor);
	sfPort.GlobalFunc(_SC("equals"), &sfPort_equals);
	sfPort.Var(_SC("value"), &sf::Port::value);
	sfPort.GlobalFunc(_SC("_tostring"), &sfPort_tostring);

	namespaceTable.Bind(_SC("Port"), sfPort);
}

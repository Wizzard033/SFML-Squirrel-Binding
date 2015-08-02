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

#ifndef SFSQRAT_HPP
#define SFSQRAT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <sqrat.h>
#include <SFML/System/String.hpp>


namespace Sqrat
{

template<>
struct Var<sf::String> {

	sf::String value;

	Var(HSQUIRRELVM v, SQInteger idx) {
		if (!Sqrat::Error::Occurred(v)) {
			sf::String* ptr = ClassType<sf::String>::GetInstance(v, idx);
			if (ptr != NULL) {
				value = *ptr;
			} else {
				Sqrat::Error::Clear(v);
				const SQChar* str;
				sq_tostring(v, idx);
				sq_getstring(v, -1, &str);
				value = sf::String(str);
				sq_pop(v, 1);
			}
		}
	}

	static void push(HSQUIRRELVM v, const sf::String& value) {
		ClassType<sf::String>::PushInstanceCopy(v, value);
	}
};


template<>
struct Var<const sf::String&> {

	sf::String value;

	Var(HSQUIRRELVM v, SQInteger idx) {
		if (!Sqrat::Error::Occurred(v)) {
			sf::String* ptr = ClassType<sf::String>::GetInstance(v, idx);
			if (ptr != NULL) {
				value = *ptr;
			} else {
				Sqrat::Error::Clear(v);
				const SQChar* str;
				sq_tostring(v, idx);
				sq_getstring(v, -1, &str);
				value = sf::String(str);
				sq_pop(v, 1);
			}
		}
	}

	static void push(HSQUIRRELVM v, const sf::String& value) {
		ClassType<sf::String>::PushInstanceCopy(v, value);
	}
};


SCRAT_MAKE_NONREFERENCABLE(sf::String);


} // namespace Sqrat


#endif // SFSQRAT_HPP

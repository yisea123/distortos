/**
 * \file
 * \brief Mock of Mutex class
 *
 * \author Copyright (C) 2017 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef UNIT_TEST_INCLUDE_MOCKS_MUTEX_HPP_DISTORTOS_MUTEX_HPP_
#define UNIT_TEST_INCLUDE_MOCKS_MUTEX_HPP_DISTORTOS_MUTEX_HPP_

#include "unit-test-common.hpp"

#include "distortos/MutexProtocol.hpp"
#include "distortos/MutexType.hpp"
#include "distortos/TickClock.hpp"

#include <climits>

namespace distortos
{

namespace internal
{

class MutexControlBlock
{
public:

	constexpr static uint8_t typeShift {0};
	constexpr static uint8_t protocolShift {typeShift + CHAR_BIT / 2};
};

}	// namespace internal

class Mutex
{
public:

	using Protocol = MutexProtocol;
	using Type = MutexType;

	struct UnitTestTag
	{

	};

	Mutex(UnitTestTag)
	{

	}

	Mutex(const Type type, const Protocol protocol, const uint8_t priorityCeiling)
	{
		REQUIRE(getProxyInstance() != nullptr);
		getProxyInstance()->construct(type, protocol, priorityCeiling);
	}

	virtual ~Mutex() = default;

	MAKE_MOCK3(construct, void(Type, Protocol, uint8_t));
	MAKE_MOCK0(lock, int());
	MAKE_MOCK0(tryLock, int());
	MAKE_MOCK1(tryLockFor, int(TickClock::duration));
	MAKE_MOCK1(tryLockUntil, int(TickClock::time_point));
	MAKE_MOCK0(unlock, int());

	static Mutex*& getProxyInstance()
	{
		static Mutex* proxyInstance;
		return proxyInstance;
	}
};

}	// namespace distortos

#endif	// UNIT_TEST_INCLUDE_MOCKS_MUTEX_HPP_DISTORTOS_MUTEX_HPP_

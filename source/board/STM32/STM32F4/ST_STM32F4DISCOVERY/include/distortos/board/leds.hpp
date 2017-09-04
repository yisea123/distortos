/**
 * \file
 * \brief Declaration of leds for ST,STM32F4DISCOVERY
 *
 * \author Copyright (C) 2014-2017 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \warning
 * Automatically generated file - do not edit!
 */

#ifndef SOURCE_BOARD_STM32_STM32F4_ST_STM32F4DISCOVERY_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_
#define SOURCE_BOARD_STM32_STM32F4_ST_STM32F4DISCOVERY_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_

#include <cstddef>

/// total number of leds on the board
#define DISTORTOS_BOARD_TOTAL_LEDS		(1 + 1 + 1 + 1)

namespace distortos
{

namespace chip
{

class ChipOutputPin;

}	// namespace chip

namespace board
{

/// total number of leds on the board
constexpr size_t totalLeds {DISTORTOS_BOARD_TOTAL_LEDS};

/*---------------------------------------------------------------------------------------------------------------------+
| indexes of leds
+---------------------------------------------------------------------------------------------------------------------*/

enum
{
		/// index of ld3 LED (orange)
		ld3LedIndex,
		/// index of ld4 LED (green)
		ld4LedIndex,
		/// index of ld5 LED (red)
		ld5LedIndex,
		/// index of ld6 LED (blue)
		ld6LedIndex,
};

/*---------------------------------------------------------------------------------------------------------------------+
| alternative (label-based) indexes of leds
+---------------------------------------------------------------------------------------------------------------------*/

/// alternative index of ld3 LED (orange)
constexpr size_t orangeLedIndex {ld3LedIndex};

/// alternative index of ld4 LED (green)
constexpr size_t greenLedIndex {ld4LedIndex};

/// alternative index of ld5 LED (red)
constexpr size_t redLedIndex {ld5LedIndex};

/// alternative index of ld6 LED (blue)
constexpr size_t blueLedIndex {ld6LedIndex};

/*---------------------------------------------------------------------------------------------------------------------+
| indexed access to leds objects
+---------------------------------------------------------------------------------------------------------------------*/

/// array with all leds objects
extern chip::ChipOutputPin leds[totalLeds];

}	// namespace board

}	// namespace distortos

#endif	// SOURCE_BOARD_STM32_STM32F4_ST_STM32F4DISCOVERY_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_

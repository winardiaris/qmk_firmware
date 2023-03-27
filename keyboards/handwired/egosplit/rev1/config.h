/*
Copyright 2020 Aris Winardi <ariswinardy@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x4F45
#define PRODUCT_ID 0x1612
#define DEVICE_VER 0x0001
#define MANUFACTURER winardians
#define PRODUCT egosplit
#define DESCRIPTION egoisplit keyboard

#define DIODE_DIRECTION COL2ROW

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS \
    { D3, D4, C6, D7 }
#define MATRIX_COL_PINS \
    { E6, B4, B5, B6, B2, B3 }

#define MATRIX_ROW_PINS_RIGHT \
    { D3, D4, C6, D7 }
#define MATRIX_COL_PINS_RIGHT \
    { E6, B4, B5, B6, B2, B3 }

/* Comment this line for the right half firmware */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define USE_SERIAL

#ifndef SOFT_SERIAL_PIN
#    define SOFT_SERIAL_PIN D2
#    define SERIAL_USE_MULTI_TRANSACTION
#endif

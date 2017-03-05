/**
* @file nrf51_sys_headers.h
* @brief NRF51 System Header files headers.
*
*/

#pragma once

//-------------------------------------------------------------------------------------------------
// Nordic NRF51 Headers
//-------------------------------------------------------------------------------------------------

#include "nordic_common.h"

// Note: this header includes the nrf51.h header, #include <nrf51.h> will include the version
// from the ARM compiler which we don't want
//
#include "nrf.h"

//-------------------------------------------------------------------------------------------------
// Nordic NRF51 Peripheral / Utility Headers
//-------------------------------------------------------------------------------------------------
#include "nrf_peripherals.h"
#include "nrf_gpio.h"
#include "nrf_gpiote.h"
#include "nrf_delay.h"

#include "BLE400_Utils.h"
#include "DebugMacros.h"

//-------------------------------------------------------------------------------------------------
// Nordic NRF51 System Headers
//-------------------------------------------------------------------------------------------------
#include "nrf51_sys_initialize.h"
#include "nrf51_sys_uart.h"

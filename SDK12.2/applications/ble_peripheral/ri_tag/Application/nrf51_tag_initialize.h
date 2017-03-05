/**
* @file nrf51_tag_initialize.h
* @brief Header file for the nrf51 tag initialization functions.
*
*/

#pragma once

#include "std_headers.h"
#include "nrf51_sys_headers.h"
#include "nrf51_ble_headers.h"

#include "nrf51_tag_tx_power.h"

// ------------------------------------------------------------------------------------------------
// Global Variables
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Initialize Interface Functions
// ------------------------------------------------------------------------------------------------

/**@brief Function for initializing the application code.
 */
void nrf51_tag_initialize(void);

// ------------------------------------------------------------------------------------------------
// Debug Message(s)
// ------------------------------------------------------------------------------------------------
#define ENABLE_INITIALIZE_MESSAGES

#if defined(ENABLE_INITIALIZE_MESSAGES)

#define DBG_RAMON() {\
    DBG("--> power ram blocks  : 0x%x\r\n", NRF_POWER->RAMON ); }

#define DBG_RESET_REASON() {\
    DBG("--> power reset reason: 0x%x\r\n", NRF_POWER->RESETREAS ); }

#define DBG_GPRR() {\
    DBG("--> retention register: 0x%x\r\n", NRF_POWER->GPREGRET ); }

#define DBG_TX_POWER() \
    DBG("--> TX Power: %d (dBm)\r\n", get_tx_power())

#else

#define DBG_RAMON()
#define DBG_RESET_REASON()
#define DBG_GPRR()
#define DBG_TX_POWER()

#endif


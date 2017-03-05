/**
* @file nrf51_tag_tx_power.h
* @brief Header file for setting the Transmit Power.
*
*/

#pragma once

#include "std_headers.h"
#include "nrf51_sys_headers.h"
#include "nrf51_ble_headers.h"

// ---------------------------------------------------------------------------
// Constants / enums
// ---------------------------------------------------------------------------

typedef enum tx_power_level_e
{
    DBM_p4  = 4,  // +4  dBm
    DBM_0   = 0,  //  0  dBm
    DBM_m4  =-4,  // -4  dBm
    DBM_m8  =-8,  // -8  dBm
    DBM_m12 =-12, // -12 dBm  
    DBM_m16 =-16, // -16 dBm  
    DBM_m20 =-20, // -20 dBm  
    DBM_m30 =-30, // -30 dBm
}tx_power_level_e;

// ---------------------------------------------------------------------------
// Interface Functions
// ---------------------------------------------------------------------------

/**@brief Function to reset the default RF transmit power.
 */
void reset_tx_power(void);

/**@brief Function to set the RF transmit power.
 */
void set_tx_power(tx_power_level_e tx_power_level);

/**@brief Function to get the RF transmit power.
 */
int8_t get_tx_power(void);

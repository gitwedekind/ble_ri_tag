/**
* @file _power_manage.h
* @brief Header file for Power Management.
*
*/

#pragma once

#include "std_headers.h"
#include "nrf51_sys_headers.h"
#include "nrf51_ble_headers.h"

//----------------------------------------------------------------------------
// Power Manage Modes
//----------------------------------------------------------------------------

/**@brief 
 */
typedef enum power_mode_t
{
    PM_IDLE,
    PM_SLEEP,
    PM_OFF,
} power_mode_t;

//----------------------------------------------------------------------------
// Power Manage Functions
//----------------------------------------------------------------------------

/**@brief Function for the Initializing the Power Manager Module.
 */
void initialize_power_manage(void);

/**@brief Function for the Power Manager.
 */
void power_manage(void);

/**@brief Function to set the Power Mode to RDI_PM_IDLE.
 */
void set_power_mode_idle(void);

/**@brief Function to set the Power Mode to RDI_PM_SLEEP.
 */
void set_power_mode_sleep(void);

/**@brief Function to set the Power Mode to RDI_PM_OFF.
 */
void set_power_mode_off(void);

/**@brief Function to get the Power Mode.
 */
power_mode_t get_power_mode(void);

/** @brief
*/
void power_mode_off(void);

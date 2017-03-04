/**
* @file sys_ram_control.h
* @brief Header File for the Nordic RAM Control Interface.
*
*/

#pragma once

//----------------------------------------------------------------------------
// RAM Control Constants
//----------------------------------------------------------------------------

static const uint32_t SYS_RAM_ALL_ON  = 0x00030003;
static const uint32_t SYS_RAM_ALL_OFF = 0x00000000;

static const uint32_t SYS_RAM_SD  = 0x00010001;
static const uint32_t SYS_RAM_APP = 0x00020002;

//----------------------------------------------------------------------------
// System Interface RAM Control Functions
//----------------------------------------------------------------------------

/**@brief Function for the RAM Status.
 */
uint32_t sys_ram_status(void);

/**@brief Function for turning the RAM ON.
 */
void sys_ram_on(void);

/**@brief Function for turning the RAM Off.
 */
void sys_ram_off(void);

/**@brief Function for turning the Soft Device RAM ON.
 */
void sys_sd_ram_on(void);

/**@brief Function for turning the Soft Device RAM Off.
 */
void sys_sd_ram_off(void);

/**@brief Function for turning the Application RAM ON.
 */
void sys_app_ram_on(void);

/**@brief Function for turning the Application RAM Off.
 */
void sys_app_ram_off(void);

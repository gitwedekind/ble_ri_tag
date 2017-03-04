/**
* @file sys_ram_control.c
* @brief Source File for the Nordic RAM Control Interface.
*
*/

#include "nrf51_sys_headers.h"

//----------------------------------------------------------------------------
// RAM Control Functions
//----------------------------------------------------------------------------

/**@brief Function for the RAM Status.
 */
uint32_t sys_ram_status(void)
{
    return NRF_POWER->RAMON;
}

/**@brief Function for turning the RAM ON.
 */
void sys_ram_on(void)
{
    NRF_POWER->RAMON = SYS_RAM_ALL_ON;
}

/**@brief Function for turning the RAM Off.
 */
void sys_ram_off(void)
{
    NRF_POWER->RAMON = SYS_RAM_ALL_OFF;
}

/**@brief Function for turning the Soft Device RAM ON.
 */
void sys_sd_ram_on(void)
{
    NRF_POWER->RAMON |= SYS_RAM_SD;
}

/**@brief Function for turning the Soft Device RAM Off.
 */
void sys_sd_ram_off(void)
{
    NRF_POWER->RAMON &= ~SYS_RAM_SD;
}

/**@brief Function for turning the Application RAM ON.
 */
void sys_app_ram_on(void)
{
    NRF_POWER->RAMON |= SYS_RAM_APP;
}

/**@brief Function for turning the Application RAM Off.
 */
void sys_app_ram_off(void)
{
    NRF_POWER->RAMON &= ~SYS_RAM_APP;
}

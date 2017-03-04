/**
* @file sys_reset.c
* @brief Source file for for System Reset.
*
*/

#include "nrf51_sys_headers.h"

/**@brief Function for System Reset.
 */
void sys_reset(void)
{
    NVIC_SystemReset();
}

/**@brief Function for the Reset Status.
 */
uint32_t sys_reset_status(void)
{
    return NRF_POWER->RESETREAS;
}

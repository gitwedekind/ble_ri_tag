/**
* @file nrf51_tag_initialize.c
* @brief Source file for Initializing the nrf51 tag application code.
*
*/

#include "nrf51_tag_initialize.h"
#include "nrf51_tag_power_manage.h"

// ----------------------------------------------------------------------------
// Global Variables
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// 
// ----------------------------------------------------------------------------

/**@brief Function for initializing the Dexcom application code.
 */
void nrf51_tag_initialize(void)
{
    DBG_RAMON();
    DBG_RESET_REASON();
    DBG_GPRR();
    DBG_TX_POWER();
    
    initialize_power_manage();
}

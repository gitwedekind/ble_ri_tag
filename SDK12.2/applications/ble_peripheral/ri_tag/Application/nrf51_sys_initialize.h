/**
* @file sys_initialize.h
* @brief System Header for System Initialize Functions.
*
*/

#pragma once

//----------------------------------------------------------------------------
// Constants
//----------------------------------------------------------------------------

#define GPRR_0 0x01 
#define GPRR_1 0x02 
#define GPRR_2 0x04 
#define GPRR_3 0x08 
#define GPRR_4 0x10 
#define GPRR_5 0x20 
#define GPRR_6 0x40 
#define GPRR_7 0x80 

//----------------------------------------------------------------------------
// System Initialize Functions
//----------------------------------------------------------------------------

/**@brief Function to initialize the system.
 */
void sys_initialize(void);

/**@brief Function to set general purpose retention register.
 */
void sys_set_retention_register(uint8_t retention_register);

/**@brief Function to get general purpose retention register.
 */
uint8_t sys_get_retention_register(void);

/**
* @file main.h
* @brief Header file for main.
*
*/

#pragma once

#include "BLE400_Utils.h"

//-------------------------------------------------------------------------------------------------
// Main Loop Tasks
//-------------------------------------------------------------------------------------------------

static const uint32_t MAIN_LOOP_TASK_IDLE         = 0x00000000; 
static const uint32_t MAIN_LOOP_TASK_BLE_TRANSMIT = 0x00000001;
static const uint32_t MAIN_LOOP_TASK_BLE_RECEIVE  = 0x00000002;
static const uint32_t MAIN_LOOP_TASK_BLE_START    = 0x00000004;
static const uint32_t MAIN_LOOP_TASK_BLE_STOP     = 0x00000008;
static const uint32_t MAIN_LOOP_TASK_RESERVED     = 0xFFFFFFF0;

//-------------------------------------------------------------------------------------------------
// Main Loop Interface Functions
//-------------------------------------------------------------------------------------------------

/**@brief Sets the active task bit to trigger main loop processing. 
 */
void ml_set_active_task(uint32_t TaskId);

/**@brief Sets the active task bits to idle.
 */
void ml_active_tasks_idle(void);

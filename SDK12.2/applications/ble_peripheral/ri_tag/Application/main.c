/**
 *
 */

#include "std_headers.h"
#include "nrf51_sys_headers.h"
#include "nrf51_ble_headers.h"

#include "nrf51_tag_initialize.h"
#include "nrf51_tag_power_manage.h"

#include "main.h"

//-------------------------------------------------------------------------------------------------
// Static Variables / Constants
//-------------------------------------------------------------------------------------------------

/**
* Active Tasks "Bit-Array".    
*/
static uint32_t s_ActiveTasks = MAIN_LOOP_TASK_IDLE;

//-------------------------------------------------------------------------------------------------
// Main Loop Interface / Support Functions
//-------------------------------------------------------------------------------------------------

/**@brief Clears the active task bit.
 */
static void ml_clear_active_task(uint32_t TaskId)
{
    s_ActiveTasks &= ~TaskId;
    s_ActiveTasks &= ~MAIN_LOOP_TASK_RESERVED;
}

/**@brief Sets the active task bit to trigger main loop processing.
 */
void ml_set_active_task(uint32_t TaskId)
{
    s_ActiveTasks |= TaskId;
}

/**@brief Sets the active task bits to idle.
 */
void ml_active_tasks_idle(void)
{
    s_ActiveTasks = MAIN_LOOP_TASK_IDLE;
}

void rx_callback(uint8_t chr)
{
}

uint32_t count = 0;

void tx_callback(void)
{
    ++count;
}

void error_callback(uint32_t err)
{
}

/**@brief main.
 */
int main(void)
{
    sys_uart_initialize(rx_callback, tx_callback, error_callback);
    
    DBG_MAIN_ENTERED();
    
    DEV_BOARD_INIT_LEDS();
    DEV_BOARD_INIT_GPIO();
    DEV_BOARD_INIT_BUTTONS();

    ml_active_tasks_idle();
    
    nrf51_tag_initialize();
    
    LED_ON(LED0);
    
    while (1)
    {
        if ( s_ActiveTasks == MAIN_LOOP_TASK_IDLE )
        {
            //power_manage();
        }

        if ( s_ActiveTasks & MAIN_LOOP_TASK_BLE_TRANSMIT )
        {
            ml_clear_active_task(MAIN_LOOP_TASK_BLE_TRANSMIT);
        }
        else if ( s_ActiveTasks & MAIN_LOOP_TASK_BLE_RECEIVE )
        {
            ml_clear_active_task(MAIN_LOOP_TASK_BLE_RECEIVE);
        }
        else if ( s_ActiveTasks & MAIN_LOOP_TASK_BLE_START )
        {
            ml_clear_active_task(MAIN_LOOP_TASK_BLE_START);
        }
        else if ( s_ActiveTasks & MAIN_LOOP_TASK_BLE_STOP )
        {
            ml_clear_active_task(MAIN_LOOP_TASK_BLE_STOP);
        }
    }
}

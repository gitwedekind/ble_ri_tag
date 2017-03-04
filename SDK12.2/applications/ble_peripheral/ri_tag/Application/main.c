/**
 *
 */

#include "std_headers.h"
#include "nrf51_sys_headers.h"
#include "nrf51_ble_headers.h"

#include "BLE400_Utils.h"

#include "SEGGER.h"
#include "SEGGER_RTT.h"
 
#include "SEGGER_SYSVIEW.h"

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
    //static const char* p_segger_msg = "--> segger\r\n"; 
    //SEGGER_RTT_Init();
    //SEGGER_RTT_Write(0, p_segger_msg, strlen(p_segger_msg));
    
    DEV_BOARD_INIT_LEDS();
    DEV_BOARD_INIT_GPIO();
    DEV_BOARD_INIT_BUTTONS();

    sys_uart_initialize(rx_callback, tx_callback, error_callback);
    
    static char test[128] = {0};
    
    //sys_uart_tx_buffer_isr(p_test, strlen((char*)p_test));
    
    //sys_uart_tx_string(p_test);
    
    //while (1)
    //{
    //    sys_uart_tx_string(p_test);
    //    nrf_delay_ms(1000);
    //}
    
    ml_active_tasks_idle();
    
    uint32_t index = 0;
    
    while ( index < 100 )
    {
        if ( !sys_uart_tx_active() )
        {
            ++index;
            snprintf(test, sizeof(test), "--> %d\r\n", index );
            sys_uart_tx_buffer_isr(test, strlen((char*)test));
        }
    }
    
    while ( 1 )
    {
        if ( !sys_uart_tx_active() )
        {
            snprintf(test, sizeof(test), "--> tx count %d\r\n", count );
            sys_uart_tx_buffer_isr(test, strlen((char*)test));
            
            break;
        }
    }

    
    while (1)
    {
        if ( s_ActiveTasks == MAIN_LOOP_TASK_IDLE )
        {
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

/**
 *
 */

#include "std_headers.h"
#include "nrf51_sys_headers.h"
#include "nrf51_ble_headers.h"

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

static const uint32_t LED0 = 18;
static const uint32_t LED1 = 19;
static const uint32_t LED2 = 20;
static const uint32_t LED3 = 21;
static const uint32_t LED4 = 22;

static const uint32_t LED_BLINK_DELAY = 100;

enum {
    LED_OFF = 0,
    LED_ON  = 1,
};

#define LED_ON(x_led) nrf_gpio_pin_write(x_led, LED_ON)
#define LED_OFF(x_led) nrf_gpio_pin_write(x_led, LED_OFF)

void initialize_led(uint32_t pin)
{
    nrf_gpio_cfg_output(pin);

    nrf_gpio_pin_write(pin, LED_ON);
    nrf_delay_ms(LED_BLINK_DELAY);
    nrf_gpio_pin_write(pin, LED_OFF);
    nrf_gpio_pin_write(pin, LED_ON);
    nrf_gpio_pin_write(pin, LED_OFF);
}

void initialize_leds(void)
{
    initialize_led(LED0);
    initialize_led(LED1);
    initialize_led(LED2);
    initialize_led(LED3);
    initialize_led(LED4);
}

static const uint32_t GPIO0 = 0;
static const uint32_t GPIO1 = 1;
static const uint32_t GPIO_TOGGLE_DELAY = 100;

enum {
    GPIO_OFF = 0,
    GPIO_ON  = 1,
};

#define GPIO0_ON() nrf_gpio_pin_write(GPIO0, GPIO_ON)
#define GPIO0_OFF() nrf_gpio_pin_write(GPIO0, GPIO_OFF)

#define GPIO1_ON() nrf_gpio_pin_write(GPIO1, GPIO_ON)
#define GPIO1_OFF() nrf_gpio_pin_write(GPIO1, GPIO_OFF)

void initialize_gpio(uint32_t pin)
{
    nrf_gpio_cfg_output(pin);

    nrf_gpio_pin_write(pin, GPIO_ON);
    nrf_delay_ms(GPIO_TOGGLE_DELAY);
    nrf_gpio_pin_write(pin, GPIO_OFF);
    nrf_gpio_pin_write(pin, GPIO_ON);
    nrf_gpio_pin_write(pin, GPIO_OFF);
}

void initialize_gpio_pins(void)
{
    initialize_gpio(GPIO0);
    initialize_gpio(GPIO1);
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
    
    initialize_gpio_pins();

    initialize_leds();
    
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

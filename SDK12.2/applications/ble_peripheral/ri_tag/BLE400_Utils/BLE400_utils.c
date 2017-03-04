/**
* @file BLE400_Utils.c
* @brief Source file for BLE400 Development Board
 */

#include "std_headers.h"
#include "nrf51_sys_headers.h"

#include "BLE400_Utils.h"

//-------------------------------------------------------------------------------------------------
// LED Implementation
//-------------------------------------------------------------------------------------------------

static void ble400_initialize_led(uint32_t pin)
{
    nrf_gpio_cfg_output(pin);

    nrf_gpio_pin_write(pin, ON);
    nrf_delay_ms(LED_BLINK_DELAY);
    nrf_gpio_pin_write(pin, OFF);
    nrf_gpio_pin_write(pin, ON);
    nrf_gpio_pin_write(pin, OFF);
}

void ble400_initialize_leds(void)
{
    ble400_initialize_led(LED0);
    ble400_initialize_led(LED1);
    ble400_initialize_led(LED2);
    ble400_initialize_led(LED3);
    ble400_initialize_led(LED4);
}

//-------------------------------------------------------------------------------------------------
// GPIO Implementation
//-------------------------------------------------------------------------------------------------

static void ble400_initialize_gpio(uint32_t pin)
{
    nrf_gpio_cfg_output(pin);

    nrf_gpio_pin_write(pin, ON);
    nrf_delay_ms(GPIO_TOGGLE_DELAY);
    nrf_gpio_pin_write(pin, OFF);
    nrf_gpio_pin_write(pin, ON);
    nrf_gpio_pin_write(pin, OFF);
}

void ble400_initialize_gpio_pins(void)
{
    ble400_initialize_gpio(GPIO0);
    ble400_initialize_gpio(GPIO1);
    ble400_initialize_gpio(GPIO2);
    ble400_initialize_gpio(GPIO3);
    ble400_initialize_gpio(GPIO4);
}

//-------------------------------------------------------------------------------------------------
// Button Implementation
//-------------------------------------------------------------------------------------------------

static void ble400_initialize_button(uint32_t pin)
{
}

void ble400_initialize _buttons(void)
{
}

/**
* @file sys_initialize.c
* @brief Source file for System Initialize Functions.
*
*/

#include "nrf51_sys_headers.h"

//----------------------------------------------------------------------------
// System Initialize Static Support Functions
//----------------------------------------------------------------------------

/**@brief Function to configure the power for the system modules.
 *
 * The Nordic Chip system modules are at "Power ON" at system startup.  
 * Modules not used are set to "Power OFF" to ensure Low Power Operation
 * of the chip.  Modules without a POWER bit are commented so this function
 * can be used as a quick reference for all the system modules (nrf51.h).
 *
 */
static void sys_module_power_settings(void)
{
    // NRF_POWER - Power Control
    // NRF_CLOCK - Clock Control
    // NRF_MPU   - Memory Protection Unit  
    // NRF_PU    - Patch Unit
    // NRF_AMLI  - AHB Multi-Layer Interface
    // NRF_RADIO - 2.4 GHz Radio
    
    NRF_UART0->POWER  = 1; // Universal Asynchronous Receiver / Transmitter 0
    NRF_SPI0->POWER   = 1; // Serial Peripheral Interface (Master) 0
    NRF_TWI0->POWER   = 1; // Two Wire Interface (Master) 0 Note: will not work without enabling this 
    NRF_SPI1->POWER   = 0; // Serial Peripheral Interface (Slave) 1
    NRF_TWI1->POWER   = 0; // Two Wire Interface (Slave) 1
    NRF_SPIS1->POWER  = 0; // Serial Peripheral Interface 0
    NRF_GPIOTE->POWER = 1; // GPIO Tasks and Events
    NRF_ADC->POWER    = 0; // Analog-to-Digital Controller
    NRF_TIMER0->POWER = 0; // Timer / Counter 0
    NRF_TIMER1->POWER = 0; // Timer / Counter 1
    NRF_TIMER2->POWER = 0; // Timer / Counter 2
    NRF_RTC0->POWER   = 1; // Real Time Counter 0 
    NRF_TEMP->POWER   = 0; // Temperature Sensor
    NRF_RNG->POWER    = 1; // Random Number Generator
    NRF_ECB->POWER    = 1; // Crypto ECB
    NRF_AAR->POWER    = 1; // Accelerated Address Resolver
    NRF_CCM->POWER    = 1; // AES CCM Mode Encryption
    NRF_WDT->POWER    = 0; // Watchdog Timer
    NRF_RTC1->POWER   = 1; // Real Time Counter 1
    NRF_QDEC->POWER   = 0; // Rotary Quadrature Decoder
    NRF_LPCOMP->POWER = 0; // Low Power Comparator
    
    // NRF_SWI  - Software Interrupts 
    // NRF_NVMC - non-volatile memory controller 
    // NRF_PPI  - Programmable Peripheral Interconnect 
    // NRF_FICR - Factory Information Configuration Registers 
    // NRF_UICR - User Information Configuration Registers 
    // NRF_GPIO - General Purpose Input / Output
}

/**@brief Function to configure unused GPIO Pins.
 *
 * The Nordic Chip GPIO pins are set to outputs to minimize
 * leakage current. 
 */
static void sys_set_unused_gpio_pins(void)
{
    //nrf_gpio_cfg_output(0);  // SPI0 MOSI
    //nrf_gpio_cfg_output(1);  // SPI0 SCLK
    //nrf_gpio_cfg_output(2);  // SPI0 CSN
    //nrf_gpio_cfg_output(3);  // SPI0 ACK
    //nrf_gpio_cfg_output(4);  // SPI0 REQ
    //nrf_gpio_cfg_output(5);  // SPI0 ACTIVE
    //nrf_gpio_cfg_output(6);  // SPI0 SDRDY
    
    nrf_gpio_cfg_output(7);
    nrf_gpio_cfg_output(8);
    nrf_gpio_cfg_output(9);
    nrf_gpio_cfg_output(10);
    
    //nrf_gpio_cfg_output(11);
    
    nrf_gpio_cfg_output(12);
    nrf_gpio_cfg_output(13);
    nrf_gpio_cfg_output(14);
    
    nrf_gpio_cfg_output(15);
    nrf_gpio_cfg_output(16);
    nrf_gpio_cfg_output(17);
    nrf_gpio_cfg_output(18);
    nrf_gpio_cfg_output(19);
    nrf_gpio_cfg_output(20);
    nrf_gpio_cfg_output(21);
    nrf_gpio_cfg_output(22);
    nrf_gpio_cfg_output(23);
    nrf_gpio_cfg_output(24);
    nrf_gpio_cfg_output(25);
    nrf_gpio_cfg_output(26);
    
    //nrf_gpio_cfg_output(27); // ACLK XC1
    
    nrf_gpio_cfg_output(28);
    nrf_gpio_cfg_output(29);
    
    //nrf_gpio_cfg_output(30); // SPI0 MISO
}

//----------------------------------------------------------------------------
// System Initialize Functions
//----------------------------------------------------------------------------

/**@brief Function to initialize the system.
 */
void sys_initialize(void)
{
    sys_module_power_settings();
    
    sys_set_unused_gpio_pins();
}

/**@brief Function to set general purpose retention register.
 */
void sys_set_retention_register(uint8_t retention_register)
{
    NRF_POWER->GPREGRET &= ~retention_register;
}

/**@brief Function to get general purpose retention register.
 */
uint8_t sys_get_retention_register(void)
{
    return NRF_POWER->GPREGRET;
}

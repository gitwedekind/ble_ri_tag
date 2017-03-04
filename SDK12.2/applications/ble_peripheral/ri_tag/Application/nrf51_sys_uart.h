/**
* @file sys_uart.h
* @brief Header file for the system UART.
*
*/

#pragma once

//-------------------------------------------------------------------------------------------------
// UART Callback(s)
//-------------------------------------------------------------------------------------------------

typedef void (*PFN_RX_CALLBACK)(uint8_t);
typedef void (*PFN_TX_CALLBACK)(void);
typedef void (*PFN_ERROR_CALLBACK)(uint32_t);

//-------------------------------------------------------------------------------------------------
// UART Interface Functions
//-------------------------------------------------------------------------------------------------

void sys_uart_initialize(PFN_RX_CALLBACK pfn_rx_callback, PFN_TX_CALLBACK pfn_tx_callback, PFN_ERROR_CALLBACK pfn_error_callback);
bool sys_is_uart_enabled(void);
void sys_disable_uart(void);
void sys_enable_uart(void);

void sys_uart_tx_buffer_isr(const uint8_t* p_buffer, uint32_t length);
void sys_uart_tx_string_isr(const uint8_t* pString);
uint8_t sys_uart_tx_active(void);


/* 
 */

#pragma once

#include "std_headers.h"
#include "nrf51_sys_headers.h"
#include "nrf51_sys_uart.h"

// ------------------------------------------------------------------------------------------------
// Debug constants
// ------------------------------------------------------------------------------------------------

//#define ENABLE_UART_DEBUG
//#define ENABLE_RTT_DEBUG

// ------------------------------------------------------------------------------------------------
// UART API
// ------------------------------------------------------------------------------------------------

#if defined(ENABLE_UART_DEBUG) || defined(ENABLE_RTT_DEBUG)

static const char* CLEAR_SCREEN_STR = "\033[2J\033[1;1H";

static const char* CRLF  = "\r\n";
static const char* ARROW = "\r\n--> ";

//-------------------------------------------------------------------------------------------------
// Preprocessor Magic
//-------------------------------------------------------------------------------------------------
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define LINE_NO TOSTRING(__LINE__)

#endif

#if defined(ENABLE_UART_DEBUG)

#define UART_TX_BUFFER_LENGTH 128
extern char g_uart_tx[UART_TX_BUFFER_LENGTH];

void uart_hex_dump(const char* p_msg, const uint8_t* p_data, size_t length);
void bd_address(const char* p_msg, const uint8_t* p_data, size_t length);

#define DBG_PRINT(x_str) sys_uart_tx_string_isr_pend((uint8_t*)x_str)

#define DBG(...) \
    snprintf(g_uart_tx, UART_TX_BUFFER_LENGTH-1, __VA_ARGS__); \
    DBG_PRINT(g_uart_tx)
    
#define DBG_HEX_DUMP(x_msg, x_data, x_length) \
	uart_hex_dump(x_msg, x_data, x_length)

#define DBG_ADDRESS(x_msg, x_data, x_length) \
	bd_address(x_msg, x_data, x_length)

#endif // ENABLE_UART_DEBUG

#if defined(ENABLE_RTT_DEBUG)

#include "SEGGER.h"
#include "SEGGER_RTT.h"
#include "SEGGER_SYSVIEW.h"

int SEGGER_RTT_printf(unsigned BufferIndex, const char * sFormat, ...);

void uart_hex_dump(const char* p_msg, const uint8_t* p_data, size_t length);
void bd_address(const char* p_msg, const uint8_t* p_data, size_t length);

#define DBG_PRINT(x_str) SEGGER_RTT_printf(0, (char*)x_str)

#define DBG(...) \
	SEGGER_RTT_printf(0, __VA_ARGS__);

#define DBG_HEX_DUMP(x_msg, x_data, x_length) \
	uart_hex_dump(x_msg, x_data, x_length)

#define DBG_ADDRESS(x_msg, x_data, x_length) \
	bd_address(x_msg, x_data, x_length)

#endif // ENABLE_RTT_DEBUG

#if !defined(ENABLE_UART_DEBUG) && !defined(ENABLE_RTT_DEBUG)

#define DBG_PRINT(x_str)

#define DBG_HEX_DUMP(x_msg, x_data, x_length)
#define DBG_ADDRESS(x_msg, x_data, x_length)

#define DBG(...)

#endif // ENABLE_UART_DEBUG || ENABLE_RTT_DEBUG

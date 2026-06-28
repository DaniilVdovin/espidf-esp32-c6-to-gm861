/*
 * ESP32-C6 + GM861-LED Barcode Scanner
 *
 * Reads barcode/QR data from the GM861-LED scanner module via UART.
 * The scanner sends decoded data as ASCII text terminated by \r\n.
 *
 * Wiring:       GM861-LED  ->  ESP32-C6
 *   TX (scanner)  ->  GPIO18 (RX pin)
 *   RX (scanner)  ->  GPIO19 (TX pin)
 *   VCC           ->  3.3V
 *   GND           ->  GND
 *
 * Default scanner settings: 9600 baud, 8N1 (factory reset if needed).
 */

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"

// === Configuration ===
// UART peripheral to use (UART_NUM_0 is typically used for console output,
// so we pick UART_NUM_1 to avoid conflicts).
#define SCANNER_UART_NUM    UART_NUM_1

// GPIO pins connected to the scanner module.
// Software-configurable — almost any GPIO will work.
#define SCANNER_RX_PIN      18   // ESP32-C6 RX <- GM861 TX
#define SCANNER_TX_PIN      19   // ESP32-C6 TX -> GM861 RX

// Buffer for incoming data. Must be large enough to hold the longest
// expected barcode payload (GM861 supports up to ~500 bytes per scan).
#define SCANNER_BUF_SIZE    1024

// The GM861-LED defaults to 9600 baud, 8 data bits, no parity, 1 stop bit.
// If your module was reconfigured, scan the "9600 8N1" QR code from the manual.
#define SCANNER_BAUD_RATE   9600

// Log tag used for all ESP-IDF log output from this module.
static const char *TAG = "GateCon";

// === Scanner initialization ===
// Configures UART parameters, assigns GPIO pins, and installs the driver.
void init_scanner(void) {
    // UART configuration struct — all fields must be explicitly set.
    uart_config_t uart_config = {
        .baud_rate  = SCANNER_BAUD_RATE,   // 9600 bps
        .data_bits  = UART_DATA_8_BITS,    // 8 data bits
        .parity     = UART_PARITY_DISABLE, // no parity bit
        .stop_bits  = UART_STOP_BITS_1,    // 1 stop bit
        .flow_ctrl  = UART_HW_FLOWCTRL_DISABLE, // no hardware flow control
    };

    // Apply the configuration to the UART peripheral.
    uart_param_config(SCANNER_UART_NUM, &uart_config);

    // Assign GPIO pins: tx pin (ESP -> scanner), rx pin (scanner -> ESP).
    // The last two arguments (RTS, CTS) are left unassigned.
    uart_set_pin(SCANNER_UART_NUM, SCANNER_TX_PIN, SCANNER_RX_PIN,
                 UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    // Install the UART driver with a 2x buffer for safety.
    // Parameters: (uart_num, rx_buffer_size, tx_buffer_size, queue_size, queue_handle, intr_flags).
    uart_driver_install(SCANNER_UART_NUM, SCANNER_BUF_SIZE * 2, 0, 0, NULL, 0);

    ESP_LOGI(TAG, "📷 Scanner ready (UART1: 9600 8N1)");
}

void app_main(void) {
    ESP_LOGI(TAG, "=================================");
    ESP_LOGI(TAG, "🏛 Gate Controller v0.1");
    ESP_LOGI(TAG, "=================================");

    // Set up the scanner hardware.
    init_scanner();

    ESP_LOGI(TAG, "✅ System ready");
    ESP_LOGI(TAG, "Waiting for QR code...");

    // Buffer for one scan line. GM861 sends a variable-length string
    // terminated by \r\n (carriage return + line feed).
    uint8_t data[SCANNER_BUF_SIZE];

    // === Main event loop ===
    // Polls UART every 100 ms for incoming data from the scanner.
    while (1) {
        // Try to read up to (SCANNER_BUF_SIZE - 1) bytes with a 100 ms timeout.
        // Returns the number of bytes actually read, or 0 if nothing was received.
        int len = uart_read_bytes(SCANNER_UART_NUM, data,
                                  (SCANNER_BUF_SIZE - 1), pdMS_TO_TICKS(100));

        if (len > 0) {
            // Null-terminate so we can treat the buffer as a C string.
            data[len] = '\0';

            // The scanner appends \r\n to every transmission.
            // Remove any trailing carriage-return / line-feed characters
            // so we get a clean string to work with.
            while (len > 0 && (data[len - 1] == '\r' || data[len - 1] == '\n')) {
                data[--len] = '\0';
            }

            // Print the decoded barcode / QR content to the console.
            ESP_LOGI(TAG, "📷 QR scanned: %s", (char *)data);

            // === PLACEHOLDER ===
            // Add your business logic here — e.g.:
            //   - validate against an access list
            //   - open a gate via a relay
            //   - send data over WiFi/MQTT
            //   - beep a buzzer on success/failure
        }
    }
}

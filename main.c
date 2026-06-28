#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"

// === Сканер QR ===
#define SCANNER_UART_NUM UART_NUM_1
#define SCANNER_RX_PIN 18
#define SCANNER_TX_PIN 19
#define SCANNER_BUF_SIZE 1024
#define SCANNER_BAUD_RATE 9600

static const char *TAG = "GateCon";

// === Инициализация сканера ===
void init_scanner(void) {
    uart_config_t uart_config = {0};
    uart_config.baud_rate = SCANNER_BAUD_RATE;
    uart_config.data_bits = UART_DATA_8_BITS;
    uart_config.parity = UART_PARITY_DISABLE;
    uart_config.stop_bits = UART_STOP_BITS_1;
    uart_config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
    
    uart_param_config(SCANNER_UART_NUM, &uart_config);
    uart_set_pin(SCANNER_UART_NUM, SCANNER_TX_PIN, SCANNER_RX_PIN, 
                 UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(SCANNER_UART_NUM, SCANNER_BUF_SIZE * 2, 0, 0, NULL, 0);
    
    ESP_LOGI(TAG, "📷 Сканер QR готов (UART1: 9600 8N1)");
}

extern void app_main(void) {
    ESP_LOGI(TAG, "=================================");
    ESP_LOGI(TAG, "🏛 Gate Controller v0.1");
    ESP_LOGI(TAG, "=================================");
        
    // Инициализация сканера
    init_scanner();
    
    ESP_LOGI(TAG, "✅ Система готова к работе");
    ESP_LOGI(TAG, "Ожидание QR-кода...");
    
    // Основной цикл
    uint8_t data[SCANNER_BUF_SIZE];
    while (1) {
        int len = uart_read_bytes(SCANNER_UART_NUM, data, (SCANNER_BUF_SIZE - 1), pdMS_TO_TICKS(100));
        if (len > 0) {
            data[len] = '\0';
            // Убираем возможные \r\n в конце
            while (len > 0 && (data[len-1] == '\r' || data[len-1] == '\n')) {
                data[--len] = '\0';
            }
            
            ESP_LOGI(TAG, "📷 QR считан: %s", (char*)data);
        }
    }
}

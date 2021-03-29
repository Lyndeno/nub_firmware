#ifndef ROUTING_H
#define ROUTING_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "lwip/sockets.h"
#include "network.h"
#include <stdbool.h>
//#include "lwip/inet.h"


extern QueueHandle_t q_uart_rx_bytes; // bytes received from UART
extern QueueHandle_t q_uart_tx_bytes; // bytes to send through UART
extern QueueHandle_t q_wifi_rx_frames; // frame of bytes received from WiFi
extern QueueHandle_t q_wifi_tx_frames; // frame of bytes to send through WiFI

// Simple message frame
typedef struct message_frame {
    uint8_t *data;
    size_t len;
    //in_addr_t ip_addr;
    //in_port_t port;
    struct sockaddr_in devaddr;
} message_frame;

typedef struct wifi_device {
    uint8_t mac[6];
    struct sockaddr_in netaddr;
} wifi_device;

typedef struct wifi_table {
    wifi_device device[ESP_WIFI_MAX_CONN];
    bool occupied[ESP_WIFI_MAX_CONN]; 
} wifi_table;

void tx_byte(uint8_t);
void rx_byte(uint8_t * );

#endif
#ifndef MQTT_FUNCTIONS_H_  
#define MQTT_FUNCTIONS_H_

#include "mqtt_client.h"
#include "esp_log.h"
#include "sensor_config.h"


// Set your local broker URI
#define BROKER_URI "mqtts://192.168.1.100:8883"//1883

#define MOSQUITO_USER_NAME            "Sensor2"//"Gus" // "usr1"
#define MOSQUITO_USER_PASSWORD        "Sensor2Pass"// "GusPass" //"miPassword"
esp_mqtt_client_handle_t client;

extern const uint8_t client_cert_pem_start[] asm("_binary_client_crt_start");
extern const uint8_t client_cert_pem_end[] asm("_binary_client_crt_end");
extern const uint8_t client_key_pem_start[] asm("_binary_client_key_start");
extern const uint8_t client_key_pem_end[] asm("_binary_client_key_end");
extern const uint8_t server_cert_pem_start[] asm("_binary_broker_CA_crt_start");
extern const uint8_t server_cert_pem_end[] asm("_binary_broker_CA_crt_end");


extern const char *TAG;

char buff[800]; // buffer for dataSend
char recBuff[800]; // buffer for process received Data
char recTopic[100]; // buffer for process received topic
extern int flagProcessMessage; // flag for proccessing received frames

void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);
void mqtt_app_start(void);
void log_error_if_nonzero(const char *message, int error_code);

#endif
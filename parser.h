#ifndef PARSER_H
#define PARSER_H

#include <libxml/parser.h>

typedef struct {
    char username[32];
    char password[16];
    char device_id[64];
    char wifi_ssid[32];
    int config_version;
} config_t;

int parse_config(const char* filename, config_t* cfg);

#endif

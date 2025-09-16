#include <stdio.h>
#include "parser.h"

int main() {
    config_t cfg;
    if (parse_config("config.xml", &cfg) == 0) {
        printf("username: %s\n", cfg.username);
        printf("password: %s\n", cfg.password);
        printf("device_id: %s\n", cfg.device_id);
        printf("wifi_ssid: %s\n", cfg.wifi_ssid);
        printf("config_ver: %d\n", cfg.config_version);
    } else {
        printf("failed to parse config\n");
    }
    return 0;
}

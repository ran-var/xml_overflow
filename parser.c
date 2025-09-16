#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/parser.h>

typedef struct {
    char username[32];
    char password[16];
    char device_id[64];
    char wifi_ssid[32];
    int config_version;
} config_t;

int parse_config(const char* filename, config_t* cfg) {
    xmlDocPtr doc = xmlParseFile(filename);
    if (!doc) return -1;

    xmlNodePtr root = xmlDocGetRootElement(doc);
    if (!root) { xmlFreeDoc(doc); return -1; }

    xmlNodePtr node;
    char buf[256];
    for (node = root->children; node; node = node->next) {
        if (node->type != XML_ELEMENT_NODE) continue;

        char* content = (char*)xmlNodeGetContent(node);
        if (!content) continue;

        strcpy(buf, content);

        if (strcmp((char*)node->name, "username") == 0)
            strcpy(cfg->username, buf);
        else if (strcmp((char*)node->name, "password") == 0)
            strcpy(cfg->password, buf);
        else if (strcmp((char*)node->name, "device_id") == 0)
            strcpy(cfg->device_id, buf);
        else if (strcmp((char*)node->name, "wifi_network") == 0)
            strcpy(cfg->wifi_ssid, buf);
        else if (strcmp((char*)node->name, "config_ver") == 0)
            cfg->config_version = atoi(buf);

        xmlFree(content);
    }

    xmlFreeDoc(doc);
    return 0;
}


#include "cJSON.h"
#include <stdio.h>

#ifndef GROUP_A_TAXFILINGSOFTWARE_MAILING_ADDRESS_H
#define GROUP_A_TAXFILINGSOFTWARE_MAILING_ADDRESS_H

#define MAILING_ADDRESS_KEY "mailing_address"
#define MAILING_STREET_NUMBER "street_number"
#define MAILING_STREET_NAME "street_name"
#define MAILING_CITY "city"
#define MAILING_PROVINCE "province"
#define MAILING_POSTAL_CODE "postal_code"
#define MAILING_CONTACT_NUMBER "contact_number"

typedef struct {
    char street_number[32];
    char street_name[32];
    char city[32];
    char province[32];
    char postal_code[8];
    char contact_number[20];
} mailing_address;

int input_mailing_address(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_MAILING_ADDRESS_H
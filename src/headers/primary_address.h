#ifndef GROUP_A_TAXFILINGSOFTWARE_PRIMARY_ADDRESS_H
#define GROUP_A_TAXFILINGSOFTWARE_PRIMARY_ADDRESS_H

#define PRIMARY_ADDRESS_KEY "primary_address"
#define STREET_NUMBER "street_number"
#define STREET_NAME "street_name"
#define CITY "city"
#define PROVINCE "province"
#define POSTAL_CODE "postal_code"

typedef struct {
    char street_number[32];
    char street_name[32];
    char city[32];
    char province[32];
    char postal_code[8];
    char contact_number[20];
} primary_address;

int input_primary_residence(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_PRIMARY_ADDRESS_H

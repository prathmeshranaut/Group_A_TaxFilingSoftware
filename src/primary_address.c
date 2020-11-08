#include "headers/primary_address.h"

int input_primary_residence(cJSON *root) {
    primary_address address;
    printf("\n#######################################################################################\n");
    printf("Enter your Primary Address\n");
    printf("\n#######################################################################################\n");

    printf("Enter your Street Number:");
    scanf("%s", address.street_number);

    printf("Enter your Street Name");
    scanf("%s", address.street_name);

    printf("Enter your City:");
    scanf("%s", address.city);

    printf("Enter your Province:");
    scanf("%s", address.province);

    printf("Enter your Postal Code:");
    scanf("%s", address.postal_code);

    cJSON *address_object = cJSON_CreateObject();

    cJSON_AddItemToObject(address_object, STREET_NUMBER, cJSON_CreateString(address.street_number));
    cJSON_AddItemToObject(address_object, STREET_NAME, cJSON_CreateString(address.street_name));
    cJSON_AddItemToObject(address_object, CITY, cJSON_CreateString(address.city));
    cJSON_AddItemToObject(address_object, PROVINCE, cJSON_CreateString(address.province));
    cJSON_AddItemToObject(address_object, POSTAL_CODE, cJSON_CreateString(address.postal_code));

    cJSON_AddItemToObject(root, PRIMARY_ADDRESS_KEY, address_object);

    return 0;
}
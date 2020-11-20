/**
 * @file primary_address.c
 *
 * @brief Contains the definition for getting users primary address details
 * */

#include "headers/primary_address.h"

/** @brief Gets primary address details from the user
 *
 * @detail Asks user to fill in details of their primary address and adds it the JSON structure
 *
 * @param[in,out] JSON root element
 *
 * @return 0 in case of success
 * */

int input_primary_residence(cJSON *root) {
    primary_address address;
    printf("\n#######################################################################################\n");
    printf("Enter your Primary Address");
    printf("\n#######################################################################################");

    printf("\nEnter your Street Number:");
    scanf("%s", address.street_number);

    printf("\nEnter your Street Name");
    scanf("%s", address.street_name);

    printf("\nEnter your City:");
    scanf("%s", address.city);

    printf("\nEnter your Province:");
    scanf("%s", address.province);

    printf("\nEnter your Postal Code:");
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
/**
 * @file primary_address.c
 *
 * @brief Contains the definition for getting users primary address details
 * @author Prathmesh Ranaut
 * */

#include "headers/primary_address.h"
#include <assert.h>
#include "headers/commons.h"

#define MAX_RETRIES 3

/** @brief Gets primary address details from the user
 *
 * @detail Asks user to fill in details of their primary address and adds it the JSON structure
 *
 * @param[in,out] JSON root element
 *
 * @return 0 in case of success
 * */

int input_primary_residence(cJSON *root) {
    primary_address address = {"", "", "Ottawa", "ON", "", ""};
    printf("\n\t\t#######################################################################################\n");
    printf("\n\n\t\t\t\t\t\tPrimary Address\n\n\n");
    printf("\n\t\t#######################################################################################\n");

    do {
        printf("\n\t\tEnter your Street number : ");
        scanf("%s", address.street_number);
    } while (!number_isvalid(address.street_number));
    do {
        printf("\n\t\tEnter your Street Name : ");
        scanf("%s", address.street_name);
    } while (!string_isvalid(address.street_name));

    do {
        printf("\n\t\tEnter your City : ");
        scanf("%s", address.city);
    } while (!string_isvalid(address.city));

    do {
        printf("\n\t\tEnter your Province : ");
        scanf("%s", address.province);
    } while (!string_isvalid(address.province));


    do {
        printf("\n\t\tEnter your Postal Code : ");
        scanf("%s", address.postal_code);
    } while (!zip_isvalid(address.postal_code));


    cJSON *address_object = cJSON_CreateObject();

    cJSON_AddItemToObject(address_object, STREET_NUMBER, cJSON_CreateString(address.street_number));
    cJSON_AddItemToObject(address_object, STREET_NAME, cJSON_CreateString(address.street_name));
    cJSON_AddItemToObject(address_object, CITY, cJSON_CreateString(address.city));
    cJSON_AddItemToObject(address_object, PROVINCE, cJSON_CreateString(address.province));
    cJSON_AddItemToObject(address_object, POSTAL_CODE, cJSON_CreateString(address.postal_code));

    cJSON_AddItemToObject(root, PRIMARY_ADDRESS_KEY, address_object);

    return 0;
}
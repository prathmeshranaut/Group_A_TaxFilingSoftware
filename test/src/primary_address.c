#include "../include/unity.h"
#include "../../src/headers/primary_address.h"
#include "../../include/cJSON.h"

void test_input_primary_address_aborts_if_root_passed_is_null() {
    cJSON *root = NULL;
    stdin = freopen("test/data/t4_1.txt", "r", stdin);
    TEST_ABORT();
    input_primary_residence(root);
    fclose(stdin);
}

void test_input_primary_address_details_add_primary_address_key_to_json() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/primary_address_1.txt", "r", stdin);

    input_primary_residence(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, PRIMARY_ADDRESS_KEY));

    fclose(stdin);
}

void test_input_primary_address_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/primary_address_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_primary_residence(root));

    fclose(stdin);
}

void test_input_primary_address_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/primary_address_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_primary_residence(root));

    cJSON *primary_address = cJSON_GetObjectItem(root, PRIMARY_ADDRESS_KEY);

    TEST_ASSERT_EQUAL_STRING("1", cJSON_GetObjectItem(primary_address, STREET_NUMBER)->valuestring);
    TEST_ASSERT_EQUAL_STRING("CARLETON", cJSON_GetObjectItem(primary_address, STREET_NAME)->valuestring);

    TEST_ASSERT_EQUAL_STRING("OTTAWA", cJSON_GetObjectItem(primary_address, CITY)->valuestring);
    TEST_ASSERT_EQUAL_STRING("ON", cJSON_GetObjectItem(primary_address, PROVINCE)->valuestring);
    TEST_ASSERT_EQUAL_STRING("K1S2N1", cJSON_GetObjectItem(primary_address, POSTAL_CODE)->valuestring);

    fclose(stdin);
}
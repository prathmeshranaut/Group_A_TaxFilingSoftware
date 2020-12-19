#include "../include/unity.h"
#include "../../src/headers/mailing_address.h"
#include "../../include/cJSON.h"

void test_input_mailing_address_aborts_if_root_passed_is_null() {
    cJSON *root = NULL;
    stdin = freopen("test/data/mailing_address_1.txt", "r", stdin);
    TEST_ABORT();
    input_mailing_address(root);
    fclose(stdin);
}

void test_input_mailing_address_details_add_primary_address_key_to_json() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/mailing_address_1.txt", "r", stdin);

    input_mailing_address(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, MAILING_ADDRESS_KEY));

    fclose(stdin);
}

void test_input_mailing_address_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/mailing_address_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_mailing_address(root));

    fclose(stdin);
}

void test_input_mailing_address_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/mailing_address_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_mailing_address(root));

    cJSON *mailing_address = cJSON_GetObjectItem(root, MAILING_ADDRESS_KEY);

    TEST_ASSERT_EQUAL_STRING("1", cJSON_GetObjectItem(mailing_address, MAILING_STREET_NUMBER)->valuestring);
    TEST_ASSERT_EQUAL_STRING("CARLETON", cJSON_GetObjectItem(mailing_address, MAILING_STREET_NAME)->valuestring);

    TEST_ASSERT_EQUAL_STRING("OTTAWA", cJSON_GetObjectItem(mailing_address, MAILING_CITY)->valuestring);
    TEST_ASSERT_EQUAL_STRING("ON", cJSON_GetObjectItem(mailing_address, MAILING_PROVINCE)->valuestring);
    TEST_ASSERT_EQUAL_STRING("K1S2N1", cJSON_GetObjectItem(mailing_address, MAILING_POSTAL_CODE)->valuestring);
    TEST_ASSERT_EQUAL_STRING("3432345678", cJSON_GetObjectItem(mailing_address, MAILING_CONTACT_NUMBER)->valuestring);

    fclose(stdin);
}

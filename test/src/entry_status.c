#include "../include/unity.h"
#include "../../src/headers/entry_status.h"
#include "../../include/cJSON.h"

void test_input_entry_status_aborts_if_root_passed_is_null() {
    cJSON *root = NULL;
    stdin = freopen("test/data/entry_status_1.txt", "r", stdin);
    TEST_ABORT();
    input_entry_status(root);
    fclose(stdin);
}

void test_input_entry_status_details_add_entry_status_key_to_json() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/entry_status_1.txt", "r", stdin);

    input_entry_status(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, ENTRY_STATUS_KEY));

    fclose(stdin);
}

void test_input_entry_status_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/entry_status_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_entry_status(root));

    fclose(stdin);
}

void test_input_entry_status_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/entry_status_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_entry_status(root));

    cJSON *entry_status = cJSON_GetObjectItem(root, ENTRY_STATUS_KEY);

    TEST_ASSERT_EQUAL_STRING("2019-08-18", cJSON_GetObjectItem(entry_status, DATE_OF_ENTRY)->valuestring);
    TEST_ASSERT_EQUAL_STRING("ON", cJSON_GetObjectItem(entry_status, CURRENT_PROVINCE)->valuestring);
    TEST_ASSERT_EQUAL_STRING("y", cJSON_GetObjectItem(entry_status, IS_RESIDENT_IN_TAX_FILING_YEAR)->valuestring);


    fclose(stdin);
}
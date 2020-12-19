#include "../include/unity.h"
#include "../../src/headers/maritial_status.h"
#include "../../include/cJSON.h"

void test_input_maritial_status_aborts_if_root_passed_is_null() {
    cJSON *root = NULL;
    stdin = freopen("test/data/maritial_status_1.txt", "r", stdin);
    TEST_ABORT();
    input_maritial_status(root);
    fclose(stdin);
}

void test_input_maritial_status_details_add_maritial_status_key_to_json() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/maritial_status_1.txt", "r", stdin);

    input_maritial_status(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, MARITIAL_STATUS_KEY));

    fclose(stdin);
}

void test_input_maritial_status_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/maritial_status_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_maritial_status(root));

    fclose(stdin);
}

void test_input_maritial_status_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/maritial_status_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_maritial_status(root));

    cJSON *maritial_status = cJSON_GetObjectItem(root, MARITIAL_STATUS_KEY);

    TEST_ASSERT_EQUAL_STRING("MARRIED", cJSON_GetObjectItem(maritial_status, CURRENT_MARITIAL_STATUS)->valuestring);
    TEST_ASSERT_EQUAL_STRING("n", cJSON_GetObjectItem(maritial_status, IS_CHANGE_OF_STATUS)->valuestring);
    TEST_ASSERT_EQUAL_STRING("", cJSON_GetObjectItem(maritial_status, DATE_OF_CHANGE)->valuestring);


    fclose(stdin);
}
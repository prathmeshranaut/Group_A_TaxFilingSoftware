#include "../include/unity.h"
#include "../../src/headers/spouse_details.h"
#include "../../include/cJSON.h"

void test_input_spouse_details_aborts_if_root_passed_is_null() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/spouse_1.txt", "r", stdin);

    input_spouse_details(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, SPOUSE_DETAILS_KEY));

    fclose(stdin);
}

void test_input_spouse_details_add_spouse_key_to_json() {
    cJSON *root = NULL;
    stdin = freopen("test/data/spouse_1.txt", "r", stdin);

    TEST_ABORT();
    input_spouse_details(root);
    fclose(stdin);
}


void test_input_spouse_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/spouse_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_spouse_details(root));

    fclose(stdin);
}

void test_input_spouse_details_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/spouse_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_spouse_details(root));

    cJSON *spouse_object = cJSON_GetObjectItem(root, SPOUSE_DETAILS_KEY);
    TEST_ASSERT_EQUAL_STRING("WIFE", cJSON_GetObjectItem(spouse_object, SPOUSE_NAME)->valuestring);
    TEST_ASSERT_EQUAL_STRING("1990-09-09", cJSON_GetObjectItem(spouse_object, SPOUSE_DOB)->valuestring);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 24000.00, cJSON_GetObjectItem(spouse_object, SPOUSE_NET_INCOME)->valuedouble);
    TEST_ASSERT_EQUAL_STRING("999999999", cJSON_GetObjectItem(spouse_object, SPOUSE_SIN)->valuestring);
    TEST_ASSERT_EQUAL_STRING("y", cJSON_GetObjectItem(spouse_object, SPOUSE_CARE_BENEFITS)->valuestring);
    TEST_ASSERT_EQUAL_INT(30, cJSON_GetObjectItem(spouse_object, SPOUSE_AGE)->valueint);


    fclose(stdin);
}

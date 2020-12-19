#include "../include/unity.h"
#include "../../src/headers/t2202.h"
#include "../../include/cJSON.h"

void test_input_t2202_details_aborts_if_root_passed_is_null() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t2202_1.txt", "r", stdin);

    input_t2202_details(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, T2202_KEY));

    fclose(stdin);
}

void test_input_t2202_details_add_t2202_key_to_json() {
    cJSON *root = NULL;
    stdin = freopen("test/data/t2202_1.txt", "r", stdin);

    TEST_ABORT();
    input_t2202_details(root);
    fclose(stdin);
}


void test_input_t2202_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t2202_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_t2202_details(root));

    fclose(stdin);
}

void test_input_t2202_details_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t2202_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_t2202_details(root));

    cJSON *t2202_object = cJSON_GetObjectItem(root, T2202_KEY);
    TEST_ASSERT_EQUAL_STRING("CARLETON", cJSON_GetObjectItem(t2202_object, INSTITUTION_NAME)->valuestring);
    TEST_ASSERT_EQUAL_STRING("UNIVERSITY", cJSON_GetObjectItem(t2202_object, SCHOOL_TYPE)->valuestring);
    TEST_ASSERT_EQUAL_STRING("9876543", cJSON_GetObjectItem(t2202_object, STUDENT_NUMBER)->valuestring);
    TEST_ASSERT_EQUAL_STRING("MEng", cJSON_GetObjectItem(t2202_object, COURSE)->valuestring);
    TEST_ASSERT_EQUAL_STRING("f", cJSON_GetObjectItem(t2202_object, SESSION)->valuestring);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 24000.00, cJSON_GetObjectItem(t2202_object, AMOUNT)->valuedouble);

    fclose(stdin);
}

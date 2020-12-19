#include "../include/unity.h"
#include "../../src/headers/dependent_details.h"
#include "../../include/cJSON.h"

void test_input_dependent_details_aborts_if_root_passed_is_null() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/dependent_1.txt", "r", stdin);

    input_dependent_details(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, DEPENDENT_DETAILS_KEY));

    fclose(stdin);
}

void test_input_dependent_details_add_dependent_key_to_json() {
    cJSON *root = NULL;
    stdin = freopen("test/data/dependent_1.txt", "r", stdin);

    TEST_ABORT();
    input_dependent_details(root);
    fclose(stdin);
}


void test_input_dependent_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/dependent_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_dependent_details(root));

    fclose(stdin);
}

void test_input_dependent_details_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/dependent_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_dependent_details(root));

    cJSON *dependent_object = cJSON_GetObjectItem(root, DEPENDENT_DETAILS_KEY);
    TEST_ASSERT_EQUAL_STRING("DEPENDENT", cJSON_GetObjectItem(dependent_object, DEPENDENT_NAME)->valuestring);
    TEST_ASSERT_EQUAL_STRING("SON", cJSON_GetObjectItem(dependent_object, RELATIONSHIP)->valuestring);
    TEST_ASSERT_EQUAL_STRING("n", cJSON_GetObjectItem(dependent_object, DISABILITY)->valuestring);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 0.00, cJSON_GetObjectItem(dependent_object, DEPENDENT_NET_INCOME)->valuedouble);
    TEST_ASSERT_EQUAL_STRING("n", cJSON_GetObjectItem(dependent_object, CLAIM_CHILD_CARE_BENEFITS)->valuestring);
    TEST_ASSERT_EQUAL_STRING("2000-09-09", cJSON_GetObjectItem(dependent_object, DEPENDENT_DOB)->valuestring);
    TEST_ASSERT_EQUAL_INT(20, cJSON_GetObjectItem(dependent_object, DEPENDENT_AGE)->valueint);


    fclose(stdin);
}

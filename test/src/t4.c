#include "../include/unity.h"
#include "../../src/headers/t4.h"
#include "../../include/cJSON.h"

void test_input_t4_details_add_t4_key_to_json() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t4_1.txt", "r", stdin);

    input_t4_details(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, T4_KEY));

    fclose(stdin);
}

void test_input_t4_details_aborts_if_root_passed_is_null() {
    cJSON *root = NULL;
    stdin = freopen("test/data/t4_1.txt", "r", stdin);

    TEST_ABORT();
    input_t4_details(root);
    fclose(stdin);
}


void test_input_t4_details_correctly_increases_array_size() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t4_1.txt", "r", stdin);

    input_t4_details(root);
    cJSON *t4_object = cJSON_GetObjectItem(root, T4_KEY);

    TEST_ASSERT_EQUAL(1, cJSON_GetArraySize(t4_object));

    fclose(stdin);
}

void test_input_t4_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t4_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_t4_details(root));

    fclose(stdin);
}

void test_input_t4_details_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t4_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_t4_details(root));

    cJSON *t4_object = cJSON_GetObjectItem(root, T4_KEY);
    cJSON *first_t4_details = cJSON_GetArrayItem(t4_object, 0);
    cJSON *employer_name = cJSON_GetObjectItem(first_t4_details, EMPLOYER_NAME);

    TEST_ASSERT_EQUAL_STRING("Employer", employer_name->valuestring);
    TEST_ASSERT_EQUAL_STRING("ON", cJSON_GetObjectItem(first_t4_details, PROVINCE)->valuestring);

    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.3, cJSON_GetObjectItem(first_t4_details, EMPLOYMENT_INCOME)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.4,
                              cJSON_GetObjectItem(first_t4_details, EMPLOYEES_CPP_CONTRIBUTION)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.5,
                              cJSON_GetObjectItem(first_t4_details, EMPLOYEES_QPP_CONTRIBUTION)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.6, cJSON_GetObjectItem(first_t4_details, EMPLOYEES_EI_PREMIUMS)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.7, cJSON_GetObjectItem(first_t4_details, RPP_CONTRIBUTIONS)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.8, cJSON_GetObjectItem(first_t4_details, INCOME_TAX_DEDUCTED)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.9, cJSON_GetObjectItem(first_t4_details, EI_INSURABLE_EARNINGS)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.0,
                              cJSON_GetObjectItem(first_t4_details, CPP_QPP_PENSIONABLE_EARNINGS)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.1, cJSON_GetObjectItem(first_t4_details, UNION_DUES)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.2, cJSON_GetObjectItem(first_t4_details, CHARITABLE_DONATIONS)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.3,
                              cJSON_GetObjectItem(first_t4_details, RPP_DSSP_REGISTRATION_NUMBER)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.4, cJSON_GetObjectItem(first_t4_details, PENSION_ADJUSTMENT)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.5, cJSON_GetObjectItem(first_t4_details, EMPLOYEES_PPIP_PREMIUMS)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 1.6, cJSON_GetObjectItem(first_t4_details, PPIP_INSURABLE_EARNINGS)->valuedouble);

    fclose(stdin);
}

void test_input_t4_details_incorrectly_retries_3_times() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/t4_2.txt", "r", stdin);

    TEST_ASSERT_EQUAL(1, input_t4_details(root));

    fclose(stdin);
}
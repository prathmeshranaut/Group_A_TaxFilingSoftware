#include "../include/unity.h"
#include "../../src/headers/world_income.h"
#include "../../include/cJSON.h"

void test_input_world_income_aborts_if_root_passed_is_null() {
    cJSON *root = NULL;
    stdin = freopen("test/data/world_income_1.txt", "r", stdin);
    TEST_ABORT();
    input_world_income(root);
    fclose(stdin);
}

void test_input_world_income_details_add_world_income_key_to_json() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/world_income_1.txt", "r", stdin);

    input_world_income(root);

    TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, WORLD_INCOME_KEY));

    fclose(stdin);
}

void test_input_world_income_details_correctly_and_returns() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/world_income_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_world_income(root));

    fclose(stdin);
}

void test_input_world_income_correctly_adds_value_for_fields() {
    cJSON *root = cJSON_CreateObject();
    stdin = freopen("test/data/world_income_1.txt", "r", stdin);

    TEST_ASSERT_EQUAL(0, input_world_income(root));

    cJSON *world_income = cJSON_GetObjectItem(root, WORLD_INCOME_KEY);

    TEST_ASSERT_DOUBLE_WITHIN(0.001, 50000.00, cJSON_GetObjectItem(world_income, CANADIAN_SOURCE_OF_INCOME)->valuedouble);
    TEST_ASSERT_DOUBLE_WITHIN(0.001, 10000.00, cJSON_GetObjectItem(world_income, FOREIGN_SOURCE_OF_INCOME)->valuedouble);
    
    

    fclose(stdin);
}
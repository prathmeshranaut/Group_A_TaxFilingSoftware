#include "../include/unity.h"
#include "../../src/headers/t4.h"
#include "../../include/cJSON.h"

void test_input_t4_details_aborts_if_root_passed_is_null() {
    cJSON* root = NULL;
    stdin = freopen("test/data/t4_1.txt", "r", stdin);

    TEST_ABORT();
    input_t4_details(root);
    fclose(stdin);
}
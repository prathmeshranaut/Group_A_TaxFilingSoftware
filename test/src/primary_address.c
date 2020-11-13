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

#include "headers/runner.h"
#include "../include/unity.h"
#include "../../include/cJSON.h"

void setUp(void) {}

void tearDown(void) {}

int main() {
    int return_value = 0;

    UnityBegin("test/src/t4.c");

    RUN_TEST(test_input_t4_details_aborts_if_root_passed_is_null);

    return_value = UNITY_END();
    if (return_value)
        return return_value;


    UnityBegin("test/src/primary_residence.c");

    RUN_TEST(test_input_primary_address_aborts_if_root_passed_is_null);

    return UNITY_END();
}
#include "headers/runner.h"
#include "../include/unity.h"
#include "../../include/cJSON.h"

void setUp(void) {}

void tearDown(void) {}

int main() {
    int return_value = 0;

    UnityBegin("test/src/t4.c");

    RUN_TEST(test_input_t4_details_aborts_if_root_passed_is_null);
    RUN_TEST(test_input_t4_details_add_t4_key_to_json);
    RUN_TEST(test_input_t4_details_correctly_increases_array_size);
    RUN_TEST(test_input_t4_details_correctly_and_returns);
    RUN_TEST(test_input_t4_details_correctly_adds_value_for_fields);
    RUN_TEST(test_input_t4_details_incorrectly_retries_3_times);

    return_value = UNITY_END();
    if (return_value)
        return return_value;


    UnityBegin("test/src/primary_residence.c");

    RUN_TEST(test_input_primary_address_aborts_if_root_passed_is_null);
    RUN_TEST(test_input_primary_address_details_add_primary_address_key_to_json);
    RUN_TEST(test_input_primary_address_details_correctly_and_returns);
    RUN_TEST(test_input_primary_address_correctly_adds_value_for_fields);
    
    return_value = UNITY_END();
    if (return_value)
        return return_value;


    UnityBegin("test/src/mailing_details.c");

    RUN_TEST(test_input_mailing_address_aborts_if_root_passed_is_null);
    RUN_TEST(test_input_mailing_address_details_add_primary_address_key_to_json);
    RUN_TEST(test_input_mailing_address_details_correctly_and_returns);
    RUN_TEST(test_input_mailing_address_correctly_adds_value_for_fields);

    return UNITY_END();
}

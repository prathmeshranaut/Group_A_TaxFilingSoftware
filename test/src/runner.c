#include "headers/runner.h"
#include "../include/unity.h"
#include "../../include/cJSON.h"

void setUp(void) {}

void tearDown(void) {}

int main() {
    int return_value = 0;

	UnityBegin("test/src/input_new_taxfile.c");

	RUN_TEST(test_input_basic_details_aborts_if_root_passed_is_null);
	RUN_TEST(test_input_basic_details_details_add_primary_address_key_to_json);
	RUN_TEST(test_input_basic_details_details_correctly_and_returns);
	RUN_TEST(test_input_basic_details_correctly_adds_value_for_fields);


	return_value = UNITY_END();
	if (return_value)
		return return_value;

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
    
    
    UnityBegin("test/src/entry_status.c");

    RUN_TEST(test_input_entry_status_aborts_if_root_passed_is_null);
    RUN_TEST(test_input_entry_status_details_add_entry_status_key_to_json);
    RUN_TEST(test_input_entry_status_details_correctly_and_returns);
    RUN_TEST(test_input_entry_status_correctly_adds_value_for_fields);
    
    return_value = UNITY_END();
    if (return_value)
        return return_value;


    UnityBegin("test/src/maritial_status.c");

    RUN_TEST(test_input_maritial_status_aborts_if_root_passed_is_null);
    RUN_TEST(test_input_maritial_status_details_add_maritial_status_key_to_json);
    RUN_TEST(test_input_maritial_status_details_correctly_and_returns);
    RUN_TEST(test_input_maritial_status_correctly_adds_value_for_fields);
    
    return_value = UNITY_END();
    if (return_value)
        return return_value;


    UnityBegin("test/src/world_income.c");

    RUN_TEST(test_input_world_income_aborts_if_root_passed_is_null);
    RUN_TEST(test_input_world_income_details_add_world_income_key_to_json);
    RUN_TEST(test_input_world_income_details_correctly_and_returns);
    RUN_TEST(test_input_world_income_correctly_adds_value_for_fields);
    
    return_value = UNITY_END();
    if (return_value)
        return return_value;



    UnityBegin("test/src/mailing_details.c");

    RUN_TEST(test_input_mailing_address_aborts_if_root_passed_is_null);
    RUN_TEST(test_input_mailing_address_details_add_primary_address_key_to_json);
    RUN_TEST(test_input_mailing_address_details_correctly_and_returns);
    RUN_TEST(test_input_mailing_address_correctly_adds_value_for_fields);

	return_value = UNITY_END();
	if (return_value)
		return return_value;

	UnityBegin("test/src/t2202.c");

	RUN_TEST(test_input_t2202_details_aborts_if_root_passed_is_null);
	RUN_TEST(test_input_t2202_details_add_t2202_key_to_json);
	RUN_TEST(test_input_t2202_details_correctly_and_returns);
	RUN_TEST(test_input_t2202_details_correctly_adds_value_for_fields);

	return_value = UNITY_END();
	if (return_value)
		return return_value;


	UnityBegin("test/src/spouse_details.c");

	RUN_TEST(test_input_spouse_details_aborts_if_root_passed_is_null);
	RUN_TEST(test_input_spouse_details_add_spouse_key_to_json);
	RUN_TEST(test_input_spouse_details_correctly_and_returns);
	RUN_TEST(test_input_spouse_details_correctly_adds_value_for_fields);

	return_value = UNITY_END();
	if (return_value)
		return return_value;

	UnityBegin("test/src/dependent_details.c");

	RUN_TEST(test_input_dependent_details_aborts_if_root_passed_is_null);
	RUN_TEST(test_input_dependent_details_add_dependent_key_to_json);
	RUN_TEST(test_input_dependent_details_correctly_and_returns);
	RUN_TEST(test_input_dependent_details_correctly_adds_value_for_fields);

	return_value = UNITY_END();
	if (return_value)
		return return_value;

    return UNITY_END();
}

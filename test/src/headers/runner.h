#ifndef GROUP_A_TAXFILINGSOFTWARE_RUNNER_H
#define GROUP_A_TAXFILINGSOFTWARE_RUNNER_H


//Basic tax details Tests
extern void test_input_basic_details_aborts_if_root_passed_is_null();

extern void test_input_basic_details_details_add_primary_address_key_to_json();

extern void test_input_basic_details_details_correctly_and_returns();

extern void test_input_basic_details_correctly_adds_value_for_fields();


//Mailing Address Tests
extern void test_input_mailing_address_aborts_if_root_passed_is_null();

extern void test_input_mailing_address_details_add_primary_address_key_to_json();

extern void test_input_mailing_address_details_correctly_and_returns();

extern void test_input_mailing_address_correctly_adds_value_for_fields();

//Primary Address Tests
extern void test_input_primary_address_aborts_if_root_passed_is_null();

extern void test_input_primary_address_details_add_primary_address_key_to_json();

extern void test_input_primary_address_details_correctly_and_returns();

extern void test_input_primary_address_correctly_adds_value_for_fields();


//Entry Status Tests
extern void test_input_entry_status_aborts_if_root_passed_is_null();

extern void test_input_entry_status_details_add_entry_status_key_to_json();

extern void test_input_entry_status_details_correctly_and_returns();

extern void test_input_entry_status_correctly_adds_value_for_fields();


//World Income Tests
extern void test_input_world_income_aborts_if_root_passed_is_null();

extern void test_input_world_income_details_add_world_income_key_to_json();

extern void test_input_world_income_details_correctly_and_returns();

extern void test_input_world_income_correctly_adds_value_for_fields();

//Maritial Status Tests
extern void test_input_maritial_status_aborts_if_root_passed_is_null();

extern void test_input_maritial_status_details_add_maritial_status_key_to_json();

extern void test_input_maritial_status_details_correctly_and_returns();

extern void test_input_maritial_status_correctly_adds_value_for_fields();

//T4 Tests
extern void test_input_t4_details_aborts_if_root_passed_is_null();

extern void test_input_t4_details_add_t4_key_to_json();

extern void test_input_t4_details_correctly_increases_array_size();

extern void test_input_t4_details_correctly_and_returns();

extern void test_input_t4_details_correctly_adds_value_for_fields();

extern void test_input_t4_details_incorrectly_retries_3_times();

//T2202 Tests
extern void test_input_t2202_details_aborts_if_root_passed_is_null();

extern void test_input_t2202_details_add_t2202_key_to_json();

extern void test_input_t2202_details_correctly_and_returns();

extern void test_input_t2202_details_correctly_adds_value_for_fields();

extern void test_input_t2202_details_incorrectly_retries_3_times();

//Spouse Tests
extern void test_input_spouse_details_aborts_if_root_passed_is_null();

extern void test_input_spouse_details_add_spouse_key_to_json();

extern void test_input_spouse_details_correctly_and_returns();

extern void test_input_spouse_details_correctly_adds_value_for_fields();

//Dependent Tests
extern void test_input_dependent_details_aborts_if_root_passed_is_null();

extern void test_input_dependent_details_add_dependent_key_to_json();

extern void test_input_dependent_details_correctly_and_returns();

extern void test_input_dependent_details_correctly_adds_value_for_fields();


#endif //GROUP_A_TAXFILINGSOFTWARE_RUNNER_H

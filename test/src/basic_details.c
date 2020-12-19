#include "../include/unity.h"
#include "../../src/headers/new_taxfile.h"
#include "../../include/cJSON.h"

void test_input_basic_details_aborts_if_root_passed_is_null() {
	cJSON* root = NULL;
	stdin = freopen("test/data/basic_details_1.txt", "r", stdin);
	TEST_ABORT();
	input_new_taxfile(root);
	fclose(stdin);
}

void test_input_basic_details_details_add_primary_address_key_to_json() {
	cJSON* root = cJSON_CreateObject();
	stdin = freopen("test/data/basic_details_1.txt", "r", stdin);

	input_new_taxfile(root);

	TEST_ASSERT_NOT_NULL(cJSON_GetObjectItem(root, BASIC_DETAILS_KEY));

	fclose(stdin);
}

void test_input_basic_details_details_correctly_and_returns() {
	cJSON* root = cJSON_CreateObject();
	stdin = freopen("test/data/basic_details_1.txt", "r", stdin);

	TEST_ASSERT_EQUAL(0, input_new_taxfile(root));

	fclose(stdin);
}

void test_input_basic_details_correctly_adds_value_for_fields() {
	cJSON* root = cJSON_CreateObject();
	stdin = freopen("test/data/basic_details_1.txt", "r", stdin);

	TEST_ASSERT_EQUAL(0, input_new_taxfile(root));

	cJSON* basic = cJSON_GetObjectItem(root, BASIC_DETAILS_KEY);

	TEST_ASSERT_EQUAL_STRING("FIRST", cJSON_GetObjectItem(basic, FIRST_NAME)->valuestring);
	TEST_ASSERT_EQUAL_STRING("LAST", cJSON_GetObjectItem(basic, LAST_NAME)->valuestring);
	TEST_ASSERT_EQUAL_STRING("mail@email.com", cJSON_GetObjectItem(basic, EMAIL)->valuestring);
	TEST_ASSERT_EQUAL_STRING("999999999", cJSON_GetObjectItem(basic, SIN)->valuestring);
	TEST_ASSERT_EQUAL_STRING("1980-09-09", cJSON_GetObjectItem(basic, DATE_OF_BIRTH)->valuestring);


	fclose(stdin);
}

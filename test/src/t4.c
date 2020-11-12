#include "../include/unity.h"
#include "../../src/headers/t4.h"
#include "mocks/mock_t4.h"

void setUp(void) {}

void tearDown(void) {}

void test_check_if_it_works() {
    TEST_ASSERT_EQUAL(0, 0);
}

void test_check_if_it_works_not() {
    //TEST_ASSERT_EQUAL(1, 3);
}

int main() {
    UnityBegin("test/src/t4.c");

    cJSON *root = cJSON_CreateObject();

    input_t4_details_ExpectAndReturn(root, 0);

    RUN_TEST(test_check_if_it_works);
    RUN_TEST(test_check_if_it_works_not);

    return (UnityEnd());
}
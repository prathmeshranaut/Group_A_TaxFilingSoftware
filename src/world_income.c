/**
 * @file input_world_income.c
 *
 * @brief Contains the definition for getting income details from user
 * @author Shreya Dhanani
 * */

#include "headers/world_income.h"

/** @brief Gets income details from the user
  *
  * @detail Asks user to fill in their income details from Canadian Sources and Foreign Sources
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int input_world_income(cJSON *root) {
    world_income income = {0, 0};
    printf("\n\t\t#######################################################################################\n");
    printf("\n\n\t\t\t\t\t\tSources of Income\n\n\n");
    printf("\t\t#######################################################################################\n");

    printf("\n\t\tEnter Amount for your Canadian Source of Income (CAD) : ");

    while (scanf("%lf", &income.canadian_source_of_income) == 0) {
        printf("Invalid input. Please enter a number, such as 1.5, or 3:");
        scanf("%*s");
    }


    printf("\n\t\tEnter Amount for your Foreign Source of Income (CAD)(if applicable) : ");

    while (scanf("%lf", &income.foreign_source_of_income) == 0) {
        printf("Invalid input. Please enter a number, such as 1.5, or 3:");
        scanf("%*s");
    }


    cJSON *income_object = cJSON_CreateObject();

    cJSON_AddItemToObject(income_object, CANADIAN_SOURCE_OF_INCOME,
                          cJSON_CreateNumber(income.canadian_source_of_income));
    cJSON_AddItemToObject(income_object, FOREIGN_SOURCE_OF_INCOME, cJSON_CreateNumber(income.foreign_source_of_income));


    cJSON_AddItemToObject(root, WORLD_INCOME_KEY, income_object);

    return 0;
}

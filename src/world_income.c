#include "headers/world_income.h"

int input_world_income(cJSON *root) {
    world_income income;
    printf("\n#######################################################################################\n");
    printf("Enter Details for your Sources of Income\n");
    printf("\n#######################################################################################\n");

    printf("\nEnter Amount for your Canadian Source of Income (CAD): ");
    while (scanf("%lf", &income.canadian_source_of_income) == 0) {
             printf("Invalid input. Please enter a number, such as 1.5, or 3:");
             scanf("%*s");
         }

    printf("\nEnter Amount for your Foreign Source of Income (CAD): (if applicable)");
    while (scanf("%lf", &income.foreign_source_of_income) == 0) {
             printf("Invalid input. Please enter a number, such as 1.5, or 3:");
             scanf("%*s");
         }


    
    cJSON *income_object = cJSON_CreateObject();

    cJSON_AddItemToObject(income_object, CANADIAN_SOURCE_OF_INCOME, cJSON_CreateNumber(income.canadian_source_of_income));
    cJSON_AddItemToObject(income_object, FOREIGN_SOURCE_OF_INCOME, cJSON_CreateNumber(income.foreign_source_of_income));
    

    cJSON_AddItemToObject(root, WORLD_INCOME_KEY, income_object);

    return 0;
}

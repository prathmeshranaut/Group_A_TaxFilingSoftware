#include "headers/world_income.h"

int input_maritial_status(cJSON *root) {
    world_income income;
    printf("\n#######################################################################################\n");
    printf("Enter Details for your Sources of Income\n");
    printf("\n#######################################################################################\n");

    printf("Enter Amount for your Canadian Source of Income (CAD): ");
    scanf("%lf", income.canadian_source_of_income);

    printf("Enter Amount for your Foreign Source of Income (CAD): (if applicable)");
    scanf("%lf", income.foreign_source_of_income);


    
    cJSON *income_object = cJSON_CreateObject();

    cJSON_AddItemToObject(income_object, CANADIAN_SOURCE_OF_INCOME, cJSON_CreateString(income.canadian_source_of_income));
    cJSON_AddItemToObject(income_object, FOREIGN_SOURCE_OF_INCOME, cJSON_CreateString(income.foreign_source_of_income));
    

    cJSON_AddItemToObject(root, WORLD_INCOME_KEY, income_object);

    return 0;
}

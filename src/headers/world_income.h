#include "cJSON.h"
#include <stdio.h>

#ifndef GROUP_A_TAXFILINGSOFTWARE_WORLD_INCOME_H
#define GROUP_A_TAXFILINGSOFTWARE_WORLD_INCOME_H

#define WORLD_INCOME_KEY "world_income"
#define CANADIAN_SOURCE_OF_INCOME "canadian_source_of_income"
#define FOREIGN_SOURCE_OF_INCOME "foreign_source_of_income"


typedef struct {
    double canadian_source_of_income;
    double foreign_source_of_income;
} world_income;

int input_world_income(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_WORLD_INCOME_H
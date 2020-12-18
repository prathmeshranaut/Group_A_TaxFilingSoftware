#include "cJSON.h"
#include <stdio.h>

#ifndef GROUP_A_TAXFILINGSOFTWARE_MARITIAL_STATUS_H
#define GROUP_A_TAXFILINGSOFTWARE_MARITIAL_STATUS_H

#define MARITIAL_STATUS_KEY "maritial_status"
#define CURRENT_MARITIAL_STATUS "current_maritial_status"
#define IS_CHANGE_OF_STATUS "is_change_of_status"
#define DATE_OF_CHANGE "date_of_change"


typedef struct {
    char current_maritial_status[32];
    char is_change_of_status[5];
    char date_of_change[10];
} maritial_status;

int input_maritial_status(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_MARITIAL_STATUS_H

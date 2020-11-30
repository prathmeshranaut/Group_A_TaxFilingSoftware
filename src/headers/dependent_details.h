#include <stdio.h>
#include "cJSON.h"

#ifndef GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H
#define GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H

#define DEPENDENT_DETAILS_KEY "dependent_details"
#define DEPENDENT_NAME "dependent_name"
#define RELATIONSHIP "relationship"
#define DEPENDENT_DOB "dependent_dob"
#define NET_INCOME "net_income"


typedef struct {
    char dependent_name[1024];
    char relationship[20];
    char dependent_dob[10];
    double net_income;
} dependent_details;

int input_dependent_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H
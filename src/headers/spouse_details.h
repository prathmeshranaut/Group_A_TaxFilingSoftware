#include <stdio.h>
#include "cJSON.h"
#ifndef GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H
#define GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H

#define SPOUSE_DETAILS_KEY "spouse_details"
#define SPOUSE_NAME "spouse_name"
#define SPOUSE_DOB "spouse_dob"
#define SIN "sin"
#define NET_INCOME "net_income"


typedef struct {
    char spouse_name[1024];
    char spouse_dob[10];
    long int sin;
    double net_income;
} spouse_details;

int input_spouse_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H
#include <stdio.h>
#include "cJSON.h"
#ifndef GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H
#define GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H

#define SPOUSE_DETAILS_KEY "spouse_details"
#define SPOUSE_NAME "spouse_name"
#define SPOUSE_DOB "spouse_dob"
#define SPOUSE_SIN "spouse_sin"
#define SPOUSE_NET_INCOME "spouse_net_income"
#define SPOUSE_CARE_BENEFITS "spouse_care_benefits"
#define SPOUSE_AGE "spouse_age"



typedef struct {
    char spouse_name[1024];
    char spouse_dob[10];
    double spouse_net_income;
	char spouse_sin[10];
    char spouse_care_benefits[1];
	int spouse_age;
} spouse_details;

int input_spouse_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H
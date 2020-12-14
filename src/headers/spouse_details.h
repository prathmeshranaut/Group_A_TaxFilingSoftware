#include <stdio.h>
#include "cJSON.h"
#ifndef GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H
#define GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H

#define SPOUSE_DETAILS_KEY "spouse_details"
#define SPOUSE_NAME "spouse_name"
#define SPOUSE_DOB "spouse_dob"
#define SPOUSE_SIN "spouse_sin"
#define SPOUSE_NET_INCOME "spouse_net_income"
#define SPOUSE_CARE_BENIFITS "spouse_care_benefits"



typedef struct {
    char spouse_name[1024];
    char spouse_dob[10];
    long int spouse_sin;
    double spouse_net_income;
	char spouse_care_benefits[1];
} spouse_details;

int input_spouse_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_SPOUSE_DETAILS_H
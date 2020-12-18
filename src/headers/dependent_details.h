#include <stdio.h>
#include "cJSON.h"
#ifndef GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H
#define GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H

#define DEPENDENT_DETAILS_KEY "dependent_details"
#define DEPENDENT_NAME "dependent_name"
#define RELATIONSHIP "relationship"
#define DEPENDENT_DOB "dependent_dob"
#define DEPENDENT_NET_INCOME "dependent_net_income"
#define DISABILITY "disability"
#define CLAIM_CHILD_CARE_BENEFITS "claim_child_care_benefits"
#define DEPENDENT_AGE "dependent_age"

typedef struct {
    char dependent_name[1024];
    char relationship[20];
    char dependent_dob[10];
    double dependent_net_income;
    char disability[40];
    char claim_child_care_benefits[10];
	int dependent_age;
} dependent_details;

int input_dependent_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H
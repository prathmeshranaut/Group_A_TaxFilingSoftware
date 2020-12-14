#include <stdio.h>
#include "cJSON.h"


#ifndef GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H
#define GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H

#define DEPENDENT_DETAILS_KEY "dependent_details"
#define DEPENDENT_NAME "dependent_name"
#define RELATIONSHIP "relationship"
#define DEPENDENT_DOB "dependent_dob"
#define DEPENDENT_NET_INCOME "dependent_net_income"
#define CHILD_CARE_BENIFITS "child_care_benefits"


typedef struct {
    char dependent_name[1024];
    char relationship[20];
    char dependent_dob[10];
    double dependent_net_income;
	char child_care_benefits[1];
} dependent_details;

int input_dependent_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_DEPENDENT_DETAILS_H
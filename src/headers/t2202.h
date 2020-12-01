#include <stdio.h>
#include "cJSON.h"
<<<<<<< HEAD
=======

>>>>>>> 1e1f2ee (weaks)
#ifndef GROUP_A_TAXFILINGSOFTWARE_T2202_H
#define GROUP_A_TAXFILINGSOFTWARE_T2202_H

#define T2202_KEY "t2202"
#define INSTITUTION_NAME "institute_name"
#define SCHOOL_TYPE "school_type"
#define STUDENT_NUMBER "student_number"
#define COURSE "course"
#define SESSION "session"
#define AMOUNT "amount"
#define CHILD_CARE_BENEFITS "child_care_benefits"

typedef struct {
    char institute_name[1024];
    char school_type[32];
    char student_number[32];
    char course[32];
    char session[32];
    double amount; 
    char child_care_benefits[1024];
} t2202;

int input_t2202_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_T2202_H
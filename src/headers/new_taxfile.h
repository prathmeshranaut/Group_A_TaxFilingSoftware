#include "cJSON.h"
#include <stdio.h>


#ifndef GROUP_A_TAXFILINGSOFTWARE_NEW_TAXFILE_H
#define GROUP_A_TAXFILINGSOFTWARE_NEW_TAXFILE_H
#define BASIC_DETAILS_KEY "basic"
#define FIRST_NAME "first_name"
#define LAST_NAME "last_name"
#define EMAIL "email"
#define SIN "sin"
#define DATE_OF_BIRTH "date_of_birth"
#define AGE "age"


typedef struct {
    char first_name[32];
    char last_name[32];
    char email[64];
    char sin[10];
    char date_of_birth[12];
    int age;
} basic;

int input_new_taxfile(cJSON *root);

int create_new_taxfile(cJSON *root);

int display_guide(void);

int display_tax_summary(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_NEW_TAXFILE_H

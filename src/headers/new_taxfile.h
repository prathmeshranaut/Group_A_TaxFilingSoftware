#include "cJSON.h"
#include <stdio.h>


#ifndef GROUP_A_TAXFILINGSOFTWARE_NEW_TAXFILE_H
#define GROUP_A_TAXFILINGSOFTWARE_NEW_TAXFILE_H

#define FIRST_NAME "first_name"
#define LAST_NAME "last_name"
#define EMAIL "email"
#define SIN "sin"
#define DATE_OF_BIRTH "date_of_birth"

typedef struct
{
	char first_name[32];
	char last_name[32];
	char email[64];
	char sin[10];
	char date_of_birth[12];
}basic;

int input_new_taxfile(cJSON* root);
int create_new_taxfile(cJSON* root);
void print_json(cJSON* root);
int display_guide(void);
int display_file(char* filename);
int spc_email_isvalid(const char* address);
int string_isvalid(const char* address);
int sin_isvalid(const char* address);
#endif //GROUP_A_TAXFILINGSOFTWARE_NEW_TAXFILE_H

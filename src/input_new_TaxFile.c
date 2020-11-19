#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/new_taxfile.h"

int input_new_taxfile(cJSON* root)
{

	basic worker;
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tBasic Details\n\n\n");
	printf("\t\t#######################################################################################\n");
	printf("Enter your First name:");
	scanf("%s", worker.first_name);
	printf("Enter your Last name:");
	scanf("%s", worker.last_name);
	printf("Enter a valid email address:");
	scanf("%s", worker.email);
	printf("Enter your SIN(9 Digits):");
	scanf("%s", worker.sin);
	printf("Enter your Date of Birth(YYYY-MM-DD):");
	scanf("%s", worker.date_of_birth);

	printf(" first_name= %s \n last_name= %s \n email= %s \n sin= %s \n date_of_birth= %s\n ",
		worker.first_name,
		worker.last_name,
		worker.email,
		worker.sin,
		worker.date_of_birth);


	if (!root)
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		cJSON* obj_person = cJSON_CreateObject();

		cJSON* item = cJSON_CreateString(worker.first_name);
		cJSON_AddItemToObject(obj_person, "first_name", item);

		item = cJSON_CreateString(worker.last_name);
		cJSON_AddItemToObject(obj_person, "last_name", item);

		item = cJSON_CreateString(worker.email);
		cJSON_AddItemToObject(obj_person, "email", item);

		item = cJSON_CreateString(worker.sin);
		cJSON_AddItemToObject(obj_person, "sin", item);

		item = cJSON_CreateString(worker.date_of_birth);
		cJSON_AddItemToObject(obj_person, "date_of_birth", item);

		cJSON_AddItemToObject(root, "basic", obj_person);

	}

	return 0;
}

void print_json(char* root) {
	char* out = cJSON_Print(root);
	printf("JSON Output:%s\n", out);
}


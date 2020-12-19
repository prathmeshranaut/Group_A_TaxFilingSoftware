/**
 * @file input_new_taxfile.c
 *
 * @brief Contains the definition for getting users Basic details
 * @author Ragunath Anbarasu
 * */

#include "headers/new_taxfile.h"
#include "headers/commons.h"
#include<string.h>

 /** @brief Gets Basic details from the user
  *
  * @detail Asks user to fill in their basic details so that can be used in calculation of tax
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int input_new_taxfile(cJSON* root)
{
	MYDAY md;
	basic worker = { "", "", "", "", "", 0 };
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tBasic Details\n\n\n");
	printf("\t\t#######################################################################################\n");
	
	do {
		printf("\n\t\tEnter your First name : ");
		scanf("%s", worker.first_name);
	} while (!string_isvalid(worker.first_name));
	do {
		printf("\n\t\tEnter your Last name : ");
		scanf("%s", worker.last_name);
	} while (!string_isvalid(worker.last_name));
	do {
		printf("\n\t\tEnter a valid email address : ");
		scanf("%s", worker.email);
	} while (!spc_email_isvalid(worker.email));
	do {
		printf("\n\t\tEnter your SIN(9 Digits) : ");
		scanf("%s", worker.sin);
	} while (!sin_isvalid(worker.sin));
	re_date:
		printf("\n\t\tEnter your Date of Birth(YYYY-MM-DD) : ");
		if((scanf("%4d-%2d-%2d", &md.year, &md.month, &md.day)) != 3)
		{
			scanf("%*[^\n]");
			scanf("%*c");
			goto re_date;
		}
		else
		{
			if ((validate_date(md))) {
				strcpy(worker.date_of_birth, struct2str(md));
				worker.age = find_age(md);
			}
			else
				goto re_date;

		}
		
		
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

		item = cJSON_CreateNumber(worker.age);
		cJSON_AddItemToObject(obj_person, "age", item);

		cJSON_AddItemToObject(root, "basic", obj_person);

	return 0;
}


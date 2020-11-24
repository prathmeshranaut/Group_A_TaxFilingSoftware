/*** The function gets the details of mailing address from the user and stores it in the JSON object(root)*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/mailing_address.h"


int input_mailing_address(cJSON* root)
{
	
	mailing_address worker;
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tMailing Address Details\n\n\n");
	printf("\t\t#######################################################################################\n");
	printf("\nEnter your Street number: ");
	scanf("%s", worker.street_number);
	printf("\nEnter your Street name: ");
	scanf("%s", worker.street_name);
	printf("\nEnter the City name: ");
	scanf("%s", worker.city);
	printf("\nEnter the Provice: ");
	scanf("%s", worker.province);
	printf("\nEnter your Postal code: ");
	scanf("%s", worker.postal_code);
	printf("\nEnter your Contact number: ");
	scanf("%s", worker.contact_number);
	
	cJSON* obj_person = cJSON_CreateObject();

	cJSON* item = cJSON_CreateString(worker.street_number);
	cJSON_AddItemToObject(obj_person, "street_number", item);

	item = cJSON_CreateString(worker.street_name);
	cJSON_AddItemToObject(obj_person, "street_name", item);

	item = cJSON_CreateString(worker.city);
	cJSON_AddItemToObject(obj_person, "city", item);

	item = cJSON_CreateString(worker.province);
	cJSON_AddItemToObject(obj_person, "province", item);

	item = cJSON_CreateString(worker.postal_code);
	cJSON_AddItemToObject(obj_person, "postal_code", item);

	item = cJSON_CreateString(worker.contact_number);
	cJSON_AddItemToObject(obj_person, "contact_number", item);

	cJSON_AddItemToObject(root, "mailing_address", obj_person);

		


	return 0;
}


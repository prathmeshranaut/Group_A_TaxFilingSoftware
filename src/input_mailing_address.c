/**
 * @file input_mailing_address.c
 *
 * @brief Contains the definition for getting users Mailing address details
 * @author Ragunath Anbarasu
 * */

#include "headers/mailing_address.h"
#include <assert.h>
#include "headers/commons.h"
#define MAX_RETRIES 3
 /** @brief Gets Mailing address details from the user
  *
  * @detail Asks user to fill in details of their mailing address so that can be used in calculation of tax
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int input_mailing_address(cJSON* root)
{

	mailing_address worker = { "", "", "Ottawa", "ON", "", ""};
	printf("\n\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\tMailing Address Details\n\n\n");
	printf("\t\t#######################################################################################\n");

	do {
	printf("\n\t\tEnter your Street number : ");
	scanf("%s", worker.street_number);
	} while (!number_isvalid(worker.street_number));
	do {
	printf("\n\t\tEnter your Street name : ");
	scanf("%s", worker.street_name);
	} while (!string_isvalid(worker.street_name));
	do {
	printf("\n\t\tEnter the City name : ");
	scanf("%s", worker.city);
	} while (!string_isvalid(worker.city));
	do {
	printf("\n\t\tEnter the Provice : ");
	scanf("%s", worker.province);
	} while (!string_isvalid(worker.province));
	do {
	printf("\n\t\tEnter your Postal code : ");
	scanf("%s", worker.postal_code);
	} while (!zip_isvalid(worker.postal_code));
	do {
	printf("\n\t\tEnter your Contact number (10 digits) : ");
	scanf("%s", worker.contact_number);
	} while (!phone_isvalid(worker.contact_number));

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


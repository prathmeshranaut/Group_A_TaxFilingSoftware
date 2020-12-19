/**
 * @file spouse_details.c
 *
 * @brief Contains the definition for getting users spouse details
 * */

#include "headers/spouse_details.h"
#include <assert.h>
#include<string.h>
#include "headers/commons.h"
#define MAX_RETRIES 3
 /** @brief Gets Spouse details from the user
  *
  * @detail Asks user to fill in thier spouse details so that can be used in calculation of tax
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int input_spouse_details(cJSON* root) {
	spouse_details details = { "", "", 0 , "", "", 0 };
	MYDAY md;
	char opt = 'y';
	printf("\n\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tSpouse Details\n\n\n");
	printf("\t\t#######################################################################################\n");

	do {
		printf("\n\t\tWould you like to enter Dependent details (y/n) : ");
		scanf(" %c", &opt);
	} while (opt != 'y' && opt != 'n');

	if (opt == 'y') {
		do {
			printf("\n\t\tEnter your Spouse Name : ");
			scanf("%s", details.spouse_name);
		} while (!string_isvalid(details.spouse_name));

	re_date:
		printf("\n\t\tEnter your Spouse Date of Birth(YYYY-MM-DD) : ");
		if ((scanf("%4d-%2d-%2d", &md.year, &md.month, &md.day)) != 3)
		{
			scanf("%*[^\n]");
			scanf("%*c");
			goto re_date;
		}
		else
		{
			if ((validate_date(md))) {
				strcpy(details.spouse_dob, struct2str(md));
				details.spouse_age = find_age(md);
			}
			else {
				goto re_date;
			}

		}

		printf("\n\t\tEnter your Spouse Net Income : ");
		DOUBLE_VALUE_INPUT(&details.spouse_net_income);


		do {
			printf("\n\t\tEnter your Spouse Social Insurance Number : ");
			scanf("%s", details.spouse_sin);
		} while (!sin_isvalid(details.spouse_sin));


		do {
			printf("\n\t\tWould you like to opt in for spouse benefits (y/n) : ");
			scanf("%s", details.spouse_care_benefits);
		} while (!string_isyn(details.spouse_care_benefits));
	}
	

	cJSON* spouse_details_object = cJSON_CreateObject();

	cJSON_AddItemToObject(spouse_details_object, SPOUSE_NAME, cJSON_CreateString(details.spouse_name));
	cJSON_AddItemToObject(spouse_details_object, SPOUSE_DOB, cJSON_CreateString(details.spouse_dob));
	cJSON_AddItemToObject(spouse_details_object, SPOUSE_NET_INCOME, cJSON_CreateNumber(details.spouse_net_income));
	cJSON_AddItemToObject(spouse_details_object, SPOUSE_SIN, cJSON_CreateString(details.spouse_sin));
	cJSON_AddItemToObject(spouse_details_object, SPOUSE_CARE_BENEFITS, cJSON_CreateString(details.spouse_care_benefits));
	cJSON_AddItemToObject(spouse_details_object, SPOUSE_AGE, cJSON_CreateNumber(details.spouse_age));

	cJSON_AddItemToObject(root, SPOUSE_DETAILS_KEY, spouse_details_object);

	return 0;
}

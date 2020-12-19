/**
 * @file dependent_details.c
 *
 * @brief Contains the definition for getting users Dependent details
 * */


#include "headers/dependent_details.h"
#include <assert.h>
#include<string.h>
#include "headers/commons.h"
#define MAX_RETRIES 3

 /** @brief Gets Dependent details from the user
  *
  * @detail Asks user to fill in details of their dependents
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int input_dependent_details(cJSON *root) {
	dependent_details details={ "", "", "", 0, "n", "n", 0 };
	char opt='y';

	MYDAY md;
	printf("\n\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\tDependent Details\n\n\n");
	printf("\t\t#######################################################################################\n");
	do {
		printf("\n\t\tWould you like to enter Dependent details (y/n) : ");
		scanf(" %c", &opt);
	} while (opt != 'y' && opt != 'n');
	if (opt == 'y') {
		do {
			printf("\n\t\tEnter your Dependent Name : ");
			scanf("%s", details.dependent_name);
		} while (!string_isvalid(details.dependent_name));
		do {
			printf("\n\t\tEnter your Relationship(father/mother/brother/sister/son/daughter) : ");
			scanf("%s", details.relationship);
		} while (!string_isvalid(details.relationship));

	re_date:
		printf("\n\t\tEnter your Dependent Date of birth(YYYY-MM-DD) : ");
		if ((scanf("%4d-%2d-%2d", &md.year, &md.month, &md.day)) != 3)
		{
			scanf("%*[^\n]");
			scanf("%*c");
			goto re_date;
		}
		else
		{
			if ((validate_date(md))) {
				strcpy(details.dependent_dob, struct2str(md));
				details.dependent_age = find_age(md);
			}
			else
				goto re_date;

		}

		printf("\n\t\tEnter your Dependent Net Income : ");
		DOUBLE_VALUE_INPUT(&details.dependent_net_income);

		do {
			printf("\n\t\tEnter Dependent status of  Disability (y/n) : ");
			scanf("%s", details.disability);
		} while (!string_isyn(details.disability));
		do {
			printf("\n\t\tWould you like to claim for child care benefits? (y/n) : ");
			scanf("%s", details.claim_child_care_benefits);
		} while (!string_isyn(details.claim_child_care_benefits));
	}

   

	cJSON* dependent_details_object = cJSON_CreateObject();

	cJSON_AddItemToObject(dependent_details_object, DEPENDENT_NAME, cJSON_CreateString(details.dependent_name));
	cJSON_AddItemToObject(dependent_details_object, RELATIONSHIP, cJSON_CreateString(details.relationship));
	cJSON_AddItemToObject(dependent_details_object, DEPENDENT_DOB, cJSON_CreateString(details.dependent_dob));
	cJSON_AddItemToObject(dependent_details_object, DEPENDENT_NET_INCOME, cJSON_CreateNumber(details.dependent_net_income));
	cJSON_AddItemToObject(dependent_details_object, DISABILITY, cJSON_CreateString(details.disability));
	cJSON_AddItemToObject(dependent_details_object, CLAIM_CHILD_CARE_BENEFITS, cJSON_CreateString(details.claim_child_care_benefits));
	cJSON_AddItemToObject(dependent_details_object, DEPENDENT_AGE, cJSON_CreateNumber(details.dependent_age));

	cJSON_AddItemToObject(root, DEPENDENT_DETAILS_KEY, dependent_details_object);

	return 0;
} 

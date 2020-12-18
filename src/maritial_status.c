/**
 * @file maritial_status.c
 *
 * @brief Contains the definition for getting users marital status details
 * */
#include<string.h>
#include "headers/maritial_status.h"
#include <assert.h>
#include "headers/commons.h"
#define MAX_RETRIES 3
 /** @brief Gets Marital details from the user
  *
  * @detail Asks user to fill in marital details so that it can be used in calculation of tax
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int input_maritial_status(cJSON* root) {
	maritial_status m_status = { "", "", ""};
	MYDAY md;
	printf("\n\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\tMarital Status as of 31st December 2019\n\n\n");
	printf("\t\t#######################################################################################\n");
	do {
	printf("\n\t\tEnter your Current Marital Status (single/married/divorced/widowed) : ");
	scanf("%s", m_status.current_maritial_status);
	} while (!string_isvalid(m_status.current_maritial_status));
	do {
	printf("\n\t\tIs change of Maritial Status in tax filing year? (y/n) : ");
	scanf("%s", m_status.is_change_of_status);
	} while (!string_isyn(m_status.current_maritial_status));

	if (strcmp(m_status.is_change_of_status, "y") == 0) {

	re_date:
		printf("\n\t\tEnter Date of change in status (YYYY-MM-DD)  : ");
		if ((scanf("%4d-%2d-%2d", &md.year, &md.month, &md.day)) != 3)
		{
			scanf("%*[^\n]");
			scanf("%*c");
			goto re_date;
		}
		else
		{
			if ((validate_date(md))) {
				strcpy(m_status.date_of_change, struct2str(md));
			}
			else
				goto re_date;

		}
	}


	cJSON* m_status_object = cJSON_CreateObject();

	cJSON_AddItemToObject(m_status_object, CURRENT_MARITIAL_STATUS, cJSON_CreateString(m_status.current_maritial_status));
	cJSON_AddItemToObject(m_status_object, IS_CHANGE_OF_STATUS, cJSON_CreateString(m_status.is_change_of_status));
	cJSON_AddItemToObject(m_status_object, DATE_OF_CHANGE, cJSON_CreateString(m_status.date_of_change));


	cJSON_AddItemToObject(root, MARITIAL_STATUS_KEY, m_status_object);

	return 0;
}

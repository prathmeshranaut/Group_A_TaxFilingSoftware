/**
 * @file entry_status.c
 *
 * @brief Contains the definition for getting users entry status details
 * */

#include "headers/entry_status.h"
#include <assert.h>
#include<string.h>
#include "headers/commons.h"
#define MAX_RETRIES 3
 /** @brief Gets Entry details from the user
  *
  * @detail Asks user to fill in details of their entry to the country for tax calculation
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int input_entry_status(cJSON* root) {
	entry_status status = { "", "", "y" };
	MYDAY md;
	printf("\n\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tEntry Status\n\n\n");
	printf("\t\t#######################################################################################\n");

re_date:
	printf("\n\t\tEnter your Date of Entry in Canada (YYYY-MM-DD) : ");
	if ((scanf("%4d-%2d-%2d", &md.year, &md.month, &md.day)) != 3)
	{
		scanf("%*[^\n]");
		scanf("%*c");
		goto re_date;
	}
	else
	{
		if ((validate_date(md))) {
			strcpy(status.date_of_entry, struct2str(md));
		}
		else
			goto re_date;

	}


	do {
	printf("\n\t\tEnter your Current Province : ");
	scanf("%s", status.current_province);
	} while (!string_isvalid(status.current_province));
	
	do {
	printf("\n\t\tAre you a resident of Canada in current tax filing year? (y/n) : ");
	scanf("%s", status.is_resident_in_tax_filing_year);
	} while (!string_isyn(status.is_resident_in_tax_filing_year));

	cJSON* status_object = cJSON_CreateObject();

	cJSON_AddItemToObject(status_object, DATE_OF_ENTRY, cJSON_CreateString(status.date_of_entry));
	cJSON_AddItemToObject(status_object, CURRENT_PROVINCE, cJSON_CreateString(status.current_province));
	cJSON_AddItemToObject(status_object, IS_RESIDENT_IN_TAX_FILING_YEAR, cJSON_CreateString(status.is_resident_in_tax_filing_year));


	cJSON_AddItemToObject(root, ENTRY_STATUS_KEY, status_object);

	return 0;
}

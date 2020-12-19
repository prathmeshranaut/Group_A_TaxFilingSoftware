/**
 * @file calculate_gst_hst_bebefits.c
 *
 * @brief Contains the definition for calculating GST/HST Benefits
 * @author Ragunath Anbarasu
 * */
#include "headers/new_taxfile.h"
#include "headers/spouse_details.h"
#include "headers/dependent_details.h"
#include "headers/gst_hst.h"

 /** @brief Contains the definition for calculating GST/HST Benefits
  *
  * @detail Uses the details collected before to calcualte the GST/HST Benefits
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int calculate_gst_hst_benefits(cJSON* root) {
	gst_hst benefit = { 0 };
	char opt = 'y';
	do {
		printf("\n\t\tWould you like to Opt in for GST/HST Benefits (y/n) : ");
		scanf(" %c", &opt);
	} while (opt != 'y' && opt != 'n');
	if (opt == 'y') {
		cJSON* applicant_object = cJSON_GetObjectItem(root, BASIC_DETAILS_KEY);
		cJSON* spouse_object = cJSON_GetObjectItem(root, SPOUSE_DETAILS_KEY);
		cJSON* dependent_object = cJSON_GetObjectItem(root, DEPENDENT_DETAILS_KEY);

		benefit.gst_hst_credit = 0;

		if (cJSON_GetObjectItem(applicant_object, AGE)) {
			benefit.gst_hst_credit += 296;
		}

		if (cJSON_GetObjectItem(spouse_object, SPOUSE_AGE)) {
			benefit.gst_hst_credit += 296;
		}

		if (cJSON_GetObjectItem(dependent_object, DEPENDENT_AGE)) {
			benefit.gst_hst_credit += 296;
		}
	}
	

	cJSON* obj_applicant = cJSON_CreateObject();

	cJSON* item = cJSON_CreateNumber(benefit.gst_hst_credit);
	cJSON_AddItemToObject(obj_applicant, "gst_hst_credit", item);
	
	cJSON_AddItemToObject(root, "gst_hst", obj_applicant);

	return 0;
}
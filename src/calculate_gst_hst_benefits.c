#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/new_taxfile.h"
#include "headers/spouse_details.h"
#include "headers/dependent_details.h"
#include "headers/gst_hst.h"

int calculate_gst_hst_benefits(cJSON* root) {
	gst_hst benefit;

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

	cJSON* obj_applicant = cJSON_CreateObject();

	cJSON* item = cJSON_CreateNumber(benefit.gst_hst_credit);
	cJSON_AddItemToObject(obj_applicant, "gst_hst_credit", item);
	cJSON_AddItemToObject(root, "gst_hst", obj_applicant);

	return 0;
}
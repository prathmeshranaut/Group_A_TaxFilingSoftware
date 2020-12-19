/**
 * @file calculate_otbenifits.c
 *
 * @brief Contains the definition for calculating Ontario Trillium Benefits
 * @author Ragunath Anbarasu
 * */


#include "headers/ot_benefits.h"
#include "headers/commons.h"

 /** @brief Contains the definition for calculating Ontario Trillium Benefits
  *
  * @detail Uses the OTB details collected before to calcualte the OTB credits 
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */


int calcualte_otbenefits(cJSON* root){

	otb_calculate calculation = {0,0,0,0};
	cJSON* applicant_object = cJSON_GetObjectItem(root, OT_BENEFITS_KEY);

	calculation.energy_benefits = 237;
	calculation.sales_tax_benefits = 0;
	calculation.northern_benefits = 0;
	calculation.calcualted_otb = 0;


	if (((cJSON_GetObjectItem(applicant_object, AGE)->valueint) < 64)) {

		calculation.sales_tax_benefits = (((cJSON_GetObjectItem(applicant_object, HOUSE_RENT)->valuedouble)+(cJSON_GetObjectItem(applicant_object, HOUSE_RENT_OWN_RENT)->valuedouble)))*0.2;

		calculation.sales_tax_benefits += 59;

			if (calculation.sales_tax_benefits > 691) {
		
				calculation.sales_tax_benefits=691;
			}
			if (strcmp((cJSON_GetObjectItem(applicant_object, NORTHERN_ONTARIO)->valuestring), "y")) {

				calculation.northern_benefits = 157;
			}
			calculation.calcualted_otb = calculation.energy_benefits + calculation.sales_tax_benefits + calculation.northern_benefits;
			if (strcmp((cJSON_GetObjectItem(applicant_object, COLLEGE_RESIDENCE)->valuestring), "y")) {

				calculation.calcualted_otb += 25;
			}
			if (strcmp((cJSON_GetObjectItem(applicant_object, HOUSE_RENT_OWN_LONG_TERM_CARE)->valuestring), "y")) {

				calculation.calcualted_otb += 157;
			}
	
	}
	else {

		calculation.sales_tax_benefits = (((cJSON_GetObjectItem(applicant_object, HOUSE_RENT)->valuedouble) + (cJSON_GetObjectItem(applicant_object, HOUSE_RENT_OWN_RENT)->valuedouble))) * 0.2;
		
		calculation.sales_tax_benefits += 59;

		if (calculation.sales_tax_benefits > 757) {
			calculation.sales_tax_benefits = 757;
		}
		if (strcmp((cJSON_GetObjectItem(applicant_object, NORTHERN_BENEFITS)->valuestring), "y")) {
			calculation.northern_benefits = 241;
		}
		calculation.calcualted_otb = calculation.energy_benefits + calculation.sales_tax_benefits + calculation.northern_benefits;
		if (strcmp((cJSON_GetObjectItem(applicant_object, COLLEGE_RESIDENCE)->valuestring), "y")) {
			calculation.calcualted_otb += 25;
		}
		if (strcmp((cJSON_GetObjectItem(applicant_object, HOUSE_RENT_OWN_LONG_TERM_CARE)->valuestring), "y")) {
			calculation.calcualted_otb += 241;
		}
	}

	cJSON* calculation_object = cJSON_CreateObject();

	cJSON* item = cJSON_CreateNumber(calculation.energy_benefits);
	cJSON_AddItemToObject(calculation_object, "energy_benefits", item);

	item = cJSON_CreateNumber(calculation.sales_tax_benefits);
	cJSON_AddItemToObject(calculation_object, "sales_tax_benefits", item);

	item = cJSON_CreateNumber(calculation.northern_benefits);
	cJSON_AddItemToObject(calculation_object, "northern_benefits", item);

	item = cJSON_CreateNumber(calculation.calcualted_otb);
	cJSON_AddItemToObject(calculation_object, "calcualted_otb", item);

	cJSON_AddItemToObject(root, "otb_calculate", calculation_object);

	return 0;
}
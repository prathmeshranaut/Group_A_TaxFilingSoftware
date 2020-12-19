/**
 * @file tax_summary.c
 *
 * @brief Contains the definition for displaying the tax summary
 * @author Shreya Dhanani
 * */

#include<string.h>
#include "headers/new_taxfile.h"
#include "headers/calculate_tax.h"
#include "headers/t4.h"

 /** @brief Display tax summary
  *
  * @detail Displays the summary of the tax calculated
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int display_tax_summary(cJSON *root)
{
	basic personal_details;
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tTax Summary\n\n\n");
	printf("\t\t#######################################################################################\n");
   
   double c_employment_income = 0.0;
   double c_income_tax_deducted = 0.0;
   double c_ei_insurable_earnings = 0.0;
   double c_income_tax = 0.0;
   double c_payable = 0.0;
   double c_refund = 0.0;


   cJSON* t4_object = cJSON_GetObjectItem(root, T4_KEY);
   cJSON* t4_details = cJSON_GetArrayItem(t4_object, 0);
   c_employment_income = cJSON_GetObjectItem(t4_details, EMPLOYMENT_INCOME)->valuedouble;
   c_income_tax_deducted = cJSON_GetObjectItem(t4_details, INCOME_TAX_DEDUCTED)->valuedouble;
   c_ei_insurable_earnings = cJSON_GetObjectItem(t4_details, EI_INSURABLE_EARNINGS)->valuedouble;


   cJSON* tax_object = cJSON_GetObjectItem(root, "tax");
   c_income_tax = cJSON_GetObjectItem(tax_object, INCOME_TAX)->valuedouble;
   c_payable = cJSON_GetObjectItem(tax_object, PAYABLE)->valuedouble;
   c_refund = cJSON_GetObjectItem(tax_object, REFUND)->valuedouble; 

   cJSON* personal_details_object = cJSON_GetObjectItem(root, "basic");
   strcpy(personal_details.first_name,cJSON_GetObjectItem(personal_details_object, FIRST_NAME)->valuestring);
   strcpy(personal_details.last_name,cJSON_GetObjectItem(personal_details_object, LAST_NAME)->valuestring);
   strcpy(personal_details.date_of_birth,cJSON_GetObjectItem(personal_details_object, DATE_OF_BIRTH)->valuestring);
   strcpy(personal_details.sin,cJSON_GetObjectItem(personal_details_object, SIN)->valuestring);

   printf("\n\t\t\t First Name = %s", personal_details.first_name);
   printf("\n\t\t\t Last Name = %s", personal_details.last_name);
   printf("\n\t\t\t Date of Birth = %s", personal_details.date_of_birth);
   printf("\n\t\t\t SIN Number = %s", personal_details.sin);
   printf("\n\t\t\t Employment Income = %lf", c_employment_income);
   printf("\n\t\t\t Income Tax Deducted = %lf", c_income_tax_deducted);
   printf("\n\t\t\t EI Insurable Earnings = %lf", c_ei_insurable_earnings);
   printf("\n\t\t\t Total Tax = %lf", c_income_tax);
   printf("\n\t\t\t Payable Amount = %lf", c_payable);
   printf("\n\t\t\t Refund Amount = %lf\n\n", c_refund);

return 0;
}

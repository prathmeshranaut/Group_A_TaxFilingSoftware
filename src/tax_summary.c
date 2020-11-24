#include<stdio.h>
#include<string.h>
#include "headers/new_taxfile.h"
#include "headers/calculate_tax.h"
#include "headers/t4.h"


int display_tax_summary(cJSON *root)
{
   printf("\n#######################################################################################\n");
   printf("\Tax Summary:");
   printf("\n#######################################################################################\n");
   basic personal_details;
   //t4 t4_details;
   //tax tax_details;

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



   printf("\n First Name = %s",personal_details.first_name);
   printf("\n Last Name = %s",personal_details.last_name);
   printf("\n Date of Birth = %s",personal_details.date_of_birth);
   printf("\n SIN Number = %s",personal_details.sin);
   printf("\n Employment Income = %lf",c_employment_income);
   printf("\n Income Tax Deducted = %lf",c_income_tax_deducted);
   printf("\n EI Insurable Earnings = %lf",c_ei_insurable_earnings);
   printf("\n Total Tax = %lf",c_income_tax);
   printf("\n Payable Amount = %lf",c_payable);
   printf("\n Refund Amount = %lf",c_refund);

return 0;
}


#include<stdio.h>
#include<string.h>
#include "headers/new_taxfile.h"
#include "headers/calculate_tax.h"
#include "headers/t4.h"


int display_tax_summary(cJSON *root)
{
   printf("\nTax Summary:");
   basic personal_details;
   t4 t4_details;
   tax tax_details;

   cJSON* t4_object = cJSON_GetObjectItem(root, T4_KEY);
   strcpy(t4_details.employment_income,cJSON_GetObjectItem(t4_object, EMPLOYMENT_INCOME)->valuedouble);
   strcpy(t4_details.income_tax_deducted,cJSON_GetObjectItem(t4_object, INCOME_TAX_DEDUCTED)->valuedouble);
   strcpy(t4_details.ei_insurable_earnings,cJSON_GetObjectItem(t4_object, EI_INSURABLE_EARNINGS)->valuedouble); 

   cJSON* tax_object = cJSON_GetObjectItem(root, "tax");
   strcpy(tax_details.income_tax,cJSON_GetObjectItem(tax_object, INCOME_TAX)->valuedouble);
   strcpy(tax_details.payable,cJSON_GetObjectItem(tax_object, PAYABLE)->valuedouble);
   strcpy(tax_details.refund,cJSON_GetObjectItem(tax_object, REFUND)->valuedouble); 

   cJSON* personal_details_object = cJSON_GetObjectItem(root, "basic");
   strcpy(personal_details.first_name,cJSON_GetObjectItem(personal_details_object, FIRST_NAME)->valuestring);
   strcpy(personal_details.last_name,cJSON_GetObjectItem(personal_details_object, LAST_NAME)->valuestring);
   strcpy(personal_details.date_of_birth,cJSON_GetObjectItem(personal_details_object, DATE_OF_BIRTH)->valuestring);
   strcpy(personal_details.sin,cJSON_GetObjectItem(personal_details_object, SIN)->valuestring);



   printf("\n First Name = %s",personal_details.first_name);
   printf("\n Last Name = %s",personal_details.last_name);
   printf("\n Date of Birth = %s",personal_details.date_of_birth);
   printf("\n SIN Number = %s",personal_details.sin);
   printf("\n Employment Income = %lf",t4_details.employment_income);
   printf("\n Income Tax Deducted = %lf",t4_details.income_tax_deducted);
   printf("\n EI Insurable Earnings = %lf",t4_details.ei_insurable_earnings);
   printf("\n Total Tax = %lf",tax_details.income_tax);
   printf("\n Payable Amount = %lf",tax_details.payable);
   printf("\n Refund Amount = %lf",tax_details.refund);

return 0;
}


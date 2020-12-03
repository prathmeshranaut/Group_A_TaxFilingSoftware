/***** This function will take the dependent details from the user*/
#include "headers/dependent_details.h"

int input_dependent_details(cJSON *root) {
     dependent_details details;
     printf("\n#######################################################################################\n");
     printf("Enter your Dependent Details\n");
     printf("\n#######################################################################################\n");

     printf("\nEnter your Dependent Name:\n");
     scanf("%s", details.dependent_name);

     printf("Enter your Relationship:");
     scanf("%s", details.relationship);

     printf("Enter your Dependent Date of birth(YYYY-MM-DD)");
     scanf("%s", details.dependent_dob);

     printf("Enter your Dependent Net Income:");
     scanf("%lf", &details.net_income);
   

     cJSON *dependent_details_object = cJSON_CreateObject();

     cJSON_AddItemToObject(dependent_details_object, DEPENDENT_NAME, cJSON_CreateString(details.dependent_name));
     cJSON_AddItemToObject(dependent_details_object, RELATIONSHIP, cJSON_CreateString(details.relationship));
     cJSON_AddItemToObject(dependent_details_object, DEPENDENT_DOB, cJSON_CreateString(details.dependent_dob));
     cJSON_AddItemToObject(dependent_details_object, NET_INCOME, cJSON_CreateNumber(details.net_income));
     


     cJSON_AddItemToObject(root, DEPENDENT_DETAILS_KEY, dependent_details_object);

     return 0;
} 

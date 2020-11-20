#include "dependent_details.h"

int input_dependant_details(cJSON *root) {
     dependent_details details;
     printf("\n#######################################################################################\n");
     printf("Enter your Dependent Details\n");
     printf("\n#######################################################################################\n");

     printf("Enter your Dependent Name:");
     scanf("%s", details.dependent_name);

     printf("Enter your Relationship:");
     scanf("%s", details.relationship);

     printf("Enter your Dependent Date of birth(MM-DD-YYYY)");
     scanf("%s", details.dependent_dob);

     printf("Enter your Net Income:");
     scanf("%lf", &details.net_income);

     printf("Enter your status of  Disability (Yes or No):");
     scanf("%s", details.disability);

     printf("Would you like to claim for child care benefits? (Yes or No):");
     scanf("%s", details.claim_child_care_benefits);

     cJSON *dependent_details_object = cJSON_CreateObject();

     cJSON_AddItemToObject(dependent_details_object, DEPENDENT_NAME, cJSON_CreateString(details.dependent_name));
     cJSON_AddItemToObject(dependent_details_object, RELATIONSHIP, cJSON_CreateString(details.relationship));
     cJSON_AddItemToObject(dependent_details_object, DEPENDENT_DOB, cJSON_CreateString(details.dependent_dob));
     cJSON_AddItemToObject(dependent_details_object, NET_INCOME, cJSON_CreateString(details.net_income));
     cJSON_AddItemToObject(dependent_details_object, DISABILITY, cJSON_CreateString(details.disability));
     cJSON_AddItemToObject(dependent_details_object, CLAIM_CHILD_CARE_BENEFITS, cJSON_CreateString(details.claim_child_care_benefits));

     cJSON_AddItemToObject(root, DEPENDENT_DETAILS_KEY, dependent_details_object);

     return 0;
} 
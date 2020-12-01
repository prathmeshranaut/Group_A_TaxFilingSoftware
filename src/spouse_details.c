#include "headers/spouse_details.h"

int input_spouse_details(cJSON *root) {
     spouse_details details;
     printf("\n#######################################################################################\n");
     printf("Enter your Spouse Details\n");
     printf("\n#######################################################################################\n");

     printf("Enter your Spouse Name:");
     scanf("%s", details.spouse_name);

     printf("Enter your Spouse Date of birth(YYYY-MM-DD)");
     scanf("%s", details.spouse_dob);

     printf("Enter your Social Insurance Number(9 Digit):");
     scanf("%ld", &details.sin);
      

     printf("Enter your Net Income:");
     scanf("%lf", &details.net_income);


     cJSON *spouse_details_object = cJSON_CreateObject();

     cJSON_AddItemToObject(spouse_details_object, SPOUSE_NAME, cJSON_CreateString(details.spouse_name));
     cJSON_AddItemToObject(spouse_details_object, SPOUSE_DOB, cJSON_CreateString(details.spouse_dob));
     cJSON_AddItemToObject(spouse_details_object, SIN, cJSON_CreateNumber(details.sin));
     cJSON_AddItemToObject(spouse_details_object, NET_INCOME, cJSON_CreateNumber(details.net_income));
<<<<<<< HEAD
     cJSON_AddItemToObject(spouse_details_object, CHILD_CARE_BENEFITS, cJSON_CreateString(details.child_care_benefits));
=======

>>>>>>> 1e1f2ee (weaks)

     cJSON_AddItemToObject(root, SPOUSE_DETAILS_KEY, spouse_details_object);

     return 0;
} 

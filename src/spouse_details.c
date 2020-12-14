/***** This function will take the spouse details from the user*/
#include "headers/spouse_details.h"

int input_spouse_details(cJSON *root) {
        char has_details = 'y';
        printf("Do you like to Claim Childcare Benefits? (y/n) : ");
        scanf("%c", &has_details);

        if(has_details =='y'){
     spouse_details details;
     printf("\n#######################################################################################\n");
     printf("Enter your Spouse Details\n");
     printf("\n#######################################################################################\n");

	 printf("\n\t\tEnter your Spouse Name : ");
	 scanf("%s", details.spouse_name);

	 printf("\n\t\tEnter your Spouse Date of birth(YYYY-MM-DD) : ");
	 scanf("%s", details.spouse_dob);

	 printf("\n\t\tEnter your Spouse Social Insurance Number : ");
	 scanf("%ld", &details.spouse_sin);

	 printf("\n\t\tEnter your Spouse Net Income : ");
	 scanf("%lf", &details.spouse_net_income);

	 printf("\n\t\tWould you like to opt in for spouse benefits (y/n) : ");
	 scanf("%s", details.spouse_care_benefits);

	 cJSON* spouse_details_object = cJSON_CreateObject();

	 cJSON_AddItemToObject(spouse_details_object, SPOUSE_NAME, cJSON_CreateString(details.spouse_name));
	 cJSON_AddItemToObject(spouse_details_object, SPOUSE_DOB, cJSON_CreateString(details.spouse_dob));
	 cJSON_AddItemToObject(spouse_details_object, SPOUSE_SIN, cJSON_CreateNumber(details.spouse_sin));
	 cJSON_AddItemToObject(spouse_details_object, SPOUSE_NET_INCOME, cJSON_CreateNumber(details.spouse_net_income));
	 cJSON_AddItemToObject(spouse_details_object, SPOUSE_CARE_BENIFITS, cJSON_CreateString(details.spouse_care_benefits));

     cJSON_AddItemToObject(root, SPOUSE_DETAILS_KEY, spouse_details_object);

     }
     return 0;
} 

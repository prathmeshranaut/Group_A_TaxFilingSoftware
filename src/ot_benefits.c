/**
 * @file input_ot_benefits.c
 *
 * @brief Contains the definition for getting details for calculating Ontario Trillium Benefits from user
 * @author Shreya Dhanani
 * */

#include "headers/ot_benefits.h"
#include "headers/commons.h"
#include<string.h>
#include <assert.h>
#define MAX_RETRIES 3

/** @brief Gets OTB details from the user
  *
  * @detail Asks user to fill in details of their property taxes so that can be used in calculation of tax benefits
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */


int input_ot_benefits(cJSON *root) {
    ot_benefits otb = {"", 0, "y", 0, 0, "y", "", 0, "y", 0, 0, "y", "y", "", "", 0, "y", "", 0, 0, 0, "y", "", "y", "y", 0, "y" };
    printf("\n#######################################################################################\n");
    printf("Enter Details to Calculate OT Benefits\n");
    printf("\n#######################################################################################\n");

    do { 
    printf("How old were you on December 31, 2019? :  ");
    scanf("%s", otb.age);
    } while(!number_isvalid(otb.age));
    
    printf("What was your estimated income in 2019? :  ");
    while (scanf("%lf", &otb.income) == 0) {
             printf("Invalid input. Please enter a number, such as 1.5, or 3:");
             scanf("%*s");
    }

    do {
    printf("Did you receive or repay any social assistance benefits income in 2019? (y/n)\nIncludes Employment Insurance (EI) benefit, Universal child care benefit (UCCB), and Registered disability savings plan (RDSP)\t:");
    scanf("%s", otb.social_assistance);
    } while(!string_isyn(otb.social_assistance));

    if(strcmp(otb.social_assistance,"y")==0) {
        printf("How much did you Receive (CAD) :");
        while (scanf("%lf", &otb.social_assistance_receive) == 0) {
             printf("Invalid input. Please enter a number, such as 1.5, or 3:");
             scanf("%*s");
        }

        printf("How much did you Repay (CAD) :");
        while (scanf("%lf", &otb.social_assistance_repay) == 0) {
             printf("Invalid input. Please enter a number, such as 1.5, or 3:");
             scanf("%*s");
        }
    }

    do {
    printf("Did you have a spouse/common-law partner on December 31, 2019? (y/n) : ");
    scanf("%s", otb.spouse);
    } while(!string_isyn(otb.spouse));

    if(strcmp(otb.spouse,"y")==0) {
        do {
        printf("How old were they on December 31, 2019? : ");
        scanf("%s", otb.spouse_age);
        } while(!number_isvalid(otb.spouse_age));

    	printf("What was their estimated income in 2019? : ");
    	while (scanf("%lf", &otb.spouse_income) == 0) {
             printf("Invalid input. Please enter a number, such as 1.5, or 3:");
             scanf("%*s");
        }

        do {
    	printf("Did they receive or repay any social assistance benefits income in 2019? (y/n)\nIncludes Employment Insurance (EI) benefit, Universal child care benefit (UCCB), and Registered disability savings plan (RDSP)\t:");
    	scanf("%s", otb.spouse_social_assistance);
        } while(!string_isyn(otb.spouse_social_assistance));

   	 if(strcmp(otb.spouse_social_assistance,"y")==0) {
        	printf("How much did they Receive (CAD) :");
		while (scanf("%lf", &otb.spouse_social_assistance_receive) == 0) {
                       printf("Invalid input. Please enter a number, such as 1.5, or 3:");
                       scanf("%*s");
                } 

        	printf("How much did they Repay (CAD) :");
        	while (scanf("%lf", &otb.spouse_social_assistance_repay) == 0) {
                       printf("Invalid input. Please enter a number, such as 1.5, or 3:");
                       scanf("%*s");
                }
          }

    }

    do {
    printf("Did you have children living with you in 2019? (y/n) : ");
    scanf("%s", otb.children);
    } while(!string_isyn(otb.children));

    if(strcmp(otb.children,"y")==0) {
        do {
        printf("Has the child been approved by Canada Revenue Agency for the disability tax credit? (y/n) :");
        scanf("%s", otb.children_dtc);
        } while(!string_isyn(otb.children_dtc));

        do {
        printf("How old was the child on December 31, 2019?\nEnter 1 for a child less than a year old :");
        scanf("%s", otb.children_age);
        } while(!number_isvalid(otb.children_age));
    }

    do {
    printf("In 2019, did you rent or own the place you lived in? (Enter R for rent , O for own, RO for both) : ");
    scanf("%s", otb.house);
    } while(!string_isvalid(otb.house));

    if(strcmp(otb.house,"R")==0) {
        	printf("How much rent did you pay in 2019? (CAD) :");
                while (scanf("%lf", &otb.house_r_rent) == 0) {
                       printf("Invalid input. Please enter a number, such as 1.5, or 3:");
                       scanf("%*s");
                }
          
                do {
        	printf("Did you live in a long-term care home in 2019? (y/n) :");
        	scanf("%s", otb.house_r_long_term_care);
                } while(!string_isyn(otb.house_r_long_term_care));

		if(strcmp(otb.house_r_long_term_care,"y")==0) {
                        do {
        		printf("Was it a public or private long-term care home? :");
        		scanf("%s", otb.house_r_long_term_care_type);
                        } while(!string_isvalid(otb.house_r_long_term_care_type));
    		}
     }

     if(strcmp(otb.house,"O")==0) {
        	printf("How much property tax did you pay in 2019? (CAD) :");
                while (scanf("%lf", &otb.house_o_tax) == 0) {
                       printf("Invalid input. Please enter a number, such as 1.5, or 3:");
                       scanf("%*s");
                }
     }

     if(strcmp(otb.house,"RO")==0) {
                printf("How much rent did you pay in 2019? (CAD) :");
        	while (scanf("%lf", &otb.house_ro_rent) == 0) {
                       printf("Invalid input. Please enter a number, such as 1.5, or 3:");
                       scanf("%*s");
                }
		 
        	printf("How much property tax did you pay in 2019? (CAD) :");
        	while (scanf("%lf", &otb.house_ro_tax) == 0) {
                       printf("Invalid input. Please enter a number, such as 1.5, or 3:");
                       scanf("%*s");
                }

                do {
        	printf("Did you live in a long-term care home in 2019? (y/n) :");
        	scanf("%s", otb.house_ro_long_term_care);
                } while(!string_isyn(otb.house_ro_long_term_care));

		if(strcmp(otb.house_ro_long_term_care,"y")==0) {
                        do {
        		printf("Was it a public or private long-term care home? :");
        		scanf("%s", otb.house_ro_long_term_care_type);
                        } while (!string_isvalid(otb.house_ro_long_term_care_type));
    		}
     }

     do {
     printf("Did you live on residence at an eligible Ontario university or college residence in 2019? (y/n) : ");
     scanf("%s", otb.college_residence);
     } while(!string_isyn(otb.college_residence));

     do {
     printf("Did you live on a First Nations reserve in Ontario in 2019? (y/n) : ");
     scanf("%s", otb.first_nations_reserve);
     } while(!string_isyn(otb.first_nations_reserve));

     if(strcmp(otb.first_nations_reserve,"y")==0) {
        	printf("How much did you spend on home energy costs in 2019? : ");
                while (scanf("%lf", &otb.first_nations_reserve_energy_cost) == 0) {
                       printf("Invalid input. Please enter a number, such as 1.5, or 3:");
                       scanf("%*s");
                }
    }

    do {
    printf("Did you live in Northern Ontario on December 31, 2019? (y/n) : ");
    scanf("%s", otb.northern_ontario);
    } while(!string_isyn(otb.northern_ontario));


    cJSON *otb_object = cJSON_CreateObject();

    cJSON_AddItemToObject(otb_object, AGE, cJSON_CreateString(otb.age));
    cJSON_AddItemToObject(otb_object, INCOME, cJSON_CreateNumber(otb.income));
    cJSON_AddItemToObject(otb_object, SOCIAL_ASSISTANCE, cJSON_CreateString(otb.social_assistance));
    cJSON_AddItemToObject(otb_object, SOCIAL_ASSISTANE_RECEIVE, cJSON_CreateNumber(otb.social_assistance_receive));
    cJSON_AddItemToObject(otb_object, SOCIAL_ASSISTANCE_REPAY, cJSON_CreateNumber(otb.social_assistance_repay));
    cJSON_AddItemToObject(otb_object, SPOUSE, cJSON_CreateString(otb.spouse));
    cJSON_AddItemToObject(otb_object, SPOUSE_AGE, cJSON_CreateString(otb.spouse_age));
    cJSON_AddItemToObject(otb_object, SPOUSE_INCOME, cJSON_CreateNumber(otb.spouse_income));
    cJSON_AddItemToObject(otb_object, SPOUSE_SOCIAL_ASSISTANCE, cJSON_CreateString(otb.spouse_social_assistance));
    cJSON_AddItemToObject(otb_object, SPOUSE_SOCIAL_ASSISTANCE_RECEIVE, cJSON_CreateNumber(otb.spouse_social_assistance_receive));
    cJSON_AddItemToObject(otb_object, SPOUSE_SOCIAL_ASSISTANCE_REPAY, cJSON_CreateNumber(otb.spouse_social_assistance_repay));
    cJSON_AddItemToObject(otb_object, CHILDREN, cJSON_CreateString(otb.children));
    cJSON_AddItemToObject(otb_object, CHILDREN_DISABILITY_CREDIT, cJSON_CreateString(otb.children_dtc));
    cJSON_AddItemToObject(otb_object, CHILDREN_AGE, cJSON_CreateString(otb.children_age));
    cJSON_AddItemToObject(otb_object, HOUSE, cJSON_CreateString(otb.house));
    cJSON_AddItemToObject(otb_object, HOUSE_RENT, cJSON_CreateNumber(otb.house_r_rent));
    cJSON_AddItemToObject(otb_object, HOUSE_RENT_LONG_TERM_CARE, cJSON_CreateString(otb.house_r_long_term_care));
    cJSON_AddItemToObject(otb_object, HOUSE_RENT_LONG_TERM_CARE_TYPE, cJSON_CreateString(otb.house_r_long_term_care_type));
    cJSON_AddItemToObject(otb_object, HOUSE_TAX, cJSON_CreateNumber(otb.house_o_tax));
    cJSON_AddItemToObject(otb_object, HOUSE_RENT_OWN_RENT, cJSON_CreateNumber(otb.house_ro_rent));
    cJSON_AddItemToObject(otb_object, HOUSE_RENT_OWN_TAX, cJSON_CreateNumber(otb.house_ro_tax));
    cJSON_AddItemToObject(otb_object, HOUSE_RENT_OWN_LONG_TERM_CARE, cJSON_CreateString(otb.house_ro_long_term_care));
    cJSON_AddItemToObject(otb_object, HOUSE_RENT_OWN_LONG_TERM_CARE_TYPE, cJSON_CreateString(otb.house_ro_long_term_care_type));
    cJSON_AddItemToObject(otb_object, COLLEGE_RESIDENCE, cJSON_CreateString(otb.college_residence));
    cJSON_AddItemToObject(otb_object, FIRST_NATIONS_RESERVE, cJSON_CreateString(otb.first_nations_reserve));
    cJSON_AddItemToObject(otb_object, FIRST_NATIONS_RESERVE_COST, cJSON_CreateNumber(otb.first_nations_reserve_energy_cost));
    cJSON_AddItemToObject(otb_object, NORTHERN_ONTARIO, cJSON_CreateString(otb.northern_ontario));
    
   

    cJSON_AddItemToObject(root, OT_BENEFITS_KEY, otb_object);

    return 0;
}

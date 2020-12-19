/**
 * @file main.c
 *
 * @brief Contains the definition for executing the tax calcualte function
 * */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "../include/cJSON.h"
#include "headers/commons.h"
#include "headers/primary_address.h"
#include "headers/t4.h"
#include "headers/mailing_address.h"
#include "headers/new_taxfile.h"
#include "headers/calculate_tax.h"
#include "headers/entry_status.h"
#include "headers/maritial_status.h"
#include "headers/world_income.h"
#include "headers/t2202.h"
#include "headers/spouse_details.h"
#include "headers/dependent_details.h"
#include "headers/ot_benefits.h"
#include "headers/generate_pdf.h"
#include "headers/gst_hst.h"

 /** @brief Gets details and calculate tax from the user
  *
  * @detail Asks user to fill in the necessary details for calculation of tax and output a PDF file.
  *
  * @param
  *
  * @return 0 in case of success or 1 in case of failure
  * */

int main(void) {
    //Declaring and initializing variabless
    int attempt, max_attempt = 5;
    char choice,save,opt;
	save = 'y';
	opt = 'y';
    topmenu:

    printf("\t\t#######################################################################################\n");
    printf("\n\n\t\t\t\t\t\tWelcome to Tax Filing software\n\n\n");
    printf("\t\t#######################################################################################\n");
    menu:
    attempt = 0;

    do {
        printf("\n\n\t\t\tMain Menu\n\n");
        printf("\t\t\t\ta.File New Tax\n\t\t\t\tb.Guide\n\t\t\t\tc.Exit\n");
        printf("\n\n\t\tYou have %d attempts", max_attempt - attempt);
        printf("\n\n\t\t\tEnter the choice : \t");
        scanf(" %c", &choice);
        attempt++;
        if (attempt > max_attempt)
            goto exit;
    } while (choice != 'a' && choice != 'b' && choice != 'c' && attempt <= max_attempt);
    switch (choice) {
        case 'a':
			printf("\n\n\t\t\t\t\tFile New Tax\n\n\n");
            cJSON *root = cJSON_CreateObject();
            input_new_taxfile(root); //Get basic details from user
            //input_mailing_address(root); //Get mailing details from user
            //input_primary_residence(root); //Get primary residence details from user
            //input_entry_status(root); //Get entry status details from user
            //input_world_income(root); //Get world income details from user
            //input_maritial_status(root); //Get maritial status details from user
            input_t4_details(root); //Get t4 details from user
            input_t2202_details(root); //Get t2202 details from user
			input_dependent_details(root); //Get dependent details from user
			input_spouse_details(root); //Get spouse details from user

			do {
				printf("\n\t\tWould you like to Opt in for Ontario Trillium Benefits (y/n) : ");
				scanf(" %c", &opt);
				if (opt == 'y') {
					input_ot_benefits(root); //Get OTB details from user
					calcualte_otbenefits(root);
				}
			} while (opt != 'y' && opt != 'n');

			do {
				printf("\n\t\tWould you like to Opt in for GST/HST Benefits (y/n) : ");
				scanf(" %c", &opt);
				if (opt == 'y') {
					calculate_gst_hst_benefits(root); //Add GST/HST benifits
				}
			} while (opt != 'y' && opt != 'n');


			//child_benifits(root);
            
            calculate_tax(root); //Calculate tax of user
            //print_json(root); // display JSON details (developer feature)
            create_new_taxfile(root); //Write details to JSON file
            display_tax_summary(root);
			printf("\n\n\t\t\tDo you want to save the summary as PDF ? (y/n) : ");
			scanf(" %c", &save);
			if (save == 'y') {
				printf("\n\t\t\tFile tax_details.pdf generated\n");
				generate_pdf(root);
			}				
            cJSON_Delete(root);
            goto topmenu;
            break;
        case 'b':
			/*printf("\t\t\t\tGuide\n\n\n");*/
            /* Guide menu */
            display_guide();
            goto menu;
            break;
        case 'c':
            printf("\t\t\t\tExit\n\n\n");
            goto exit;
            break;
        default:
            printf("\t\t\t\tInvalid entry\n\n\n");
            goto menu;
    }


 exit:
    printf("\t\t#######################################################################################\n");
    printf("\n\n\t\t\t\t\tThankyou for using Tax Filing Software\n\n\n");
    printf("\t\t#######################################################################################\n");
    return 0;
}

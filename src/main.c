#include<stdio.h>
#include "cJSON.h"
#include "headers/primary_address.h"
#include "headers/t4.h"
#include "headers/mailing_address.h"
#include "headers/new_taxfile.h"
#include "headers/calculate_tax.h"
#include "headers/entry_status.h"
#include "headers/maritial_status.h"
#include "headers/world_income.h"




//void do_test(const char* test_name);
//int show_files(void);
int main(void) {
	//Declaring and initializing variabless
	int attempt, max_attempt = 5;
	char choice;
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tWelcome to Tax Filing software\n\n\n");
	printf("\t\t#######################################################################################\n");
menu:
	attempt = 0;

	do {
		printf("\n\n\t\t\tMain Menu\n\n");
		printf("\t\t\t\ta.File New Tax\n\t\t\t\tb.Guide\n\t\t\t\tc.Exit\n");
		printf("You have %d attempts", max_attempt - attempt);
		printf("\n\n\tEnter the choice : \n\t\t");
		scanf("%c", &choice);
		attempt++;
		if (attempt > max_attempt)
			goto exit;
	} while (choice != 'a' && choice != 'b' && choice != 'c' && attempt <= max_attempt);
	switch (choice) {
	case 'a':
		printf("\t\t\t\tFile New Tax\n\n\n");
		cJSON* root = cJSON_CreateObject();
		input_new_taxfile(root);
		input_mailing_address(root);
		input_primary_residence(root);
		input_entry_status(root);
		input_world_income(root);
		input_maritial_status(root);
		input_t4_details(root);
		//otb_benefits(root);
		//calculate_tax(root);
		print_json(root);
		//Write to a file
		create_new_taxfile(root);
		goto menu;
		break;
	case 'b':
		printf("\t\t\t\tGuide\n\n\n");
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
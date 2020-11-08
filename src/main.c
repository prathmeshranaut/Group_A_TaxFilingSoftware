#include<stdio.h>
#include<cJSON.h>
#include "headers/primary_address.h"

int displayGuide(void);

cJSON *dofile(char *filename);

void printJson(char *root);

int input_new_TaxFile(cJSON *root);


//void do_test(const char* test_name);
//int show_files(void);
int main(void) {
    //Declaring and initializing variabless
    int choice = 0, income = 0, tax = 0;
    printf("\t\t#######################################################################################\n");
    printf("\n\n\t\t\t\t\t\tWelcome to Tax Filing software\n\n\n");
    printf("\t\t#######################################################################################\n");
    menu:
    printf("\n\n\t\t\tMain Menu\n\n");
    printf("\t\t\t\t1.File New Tax\n\t\t\t\t2.Guide\n\t\t\t\t3.Exit\n");

    printf("\n\n\tEnter the choice : \n\t\t");
    scanf("%d", &choice);
    switch (choice) {
        case 1 :
            printf("\t\t\t\tFile New Tax\n\n\n");
            //show_files();
            //do_test("test1");
            cJSON *root = cJSON_CreateObject();
            input_new_TaxFile(root);
//		mailing_address(root);
            input_primary_residence(root);
//		entry_status(root);
//		world_income(root);
//		maritial_status(root);
            input_t4_details(root);
//		otb_benefits(root);
//		calculate_tax(root);
            printJson(root);
            //Write to a file
            //create_NewTaxFile();
            //dofile("./data/testJSON.json");
            goto menu;
            break;
        case 2:
            printf("\t\t\t\tGuide\n\n\n");
            /* Guide menu */
            displayGuide();
            goto menu;
            break;
        case 3:
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
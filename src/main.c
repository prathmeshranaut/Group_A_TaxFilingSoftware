#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "cJSON.h"
#include "test.h"

int displayGuide(void);

cJSON *dofile(char *filename);

void do_test(const char *test_name);

int show_files(void);

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
            dofile("./data/testJSON.json");
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
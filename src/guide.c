#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int displayGuide(void) {
    int option = 0;
    printf("\t\t#######################################################################################\n");
    printf("\n\n\t\t\t\t\t\tWelcome to Tax Filing software\n\n\n");
    printf("\t\t#######################################################################################\n");
    guide:
    printf("\n\n\t\t\tUser Manual\n\n");
    printf("\t\t\t\t1.Basic Tax filing\n\t\t\t\t2.Child Benifits\n\t\t\t\t3.Ontario Trillium Benifits\n\t\t\t\t4.GST/HST Credits\n\t\t\t\t5.Return to Main menu\n");

    printf("\n\n\tEnter the choice : \n\t\t");
    scanf("%d", &option);
    switch (option) {
        case 1:

            printf("\t\t\t\tBasic Tax filing\n\n\n");

            goto guide;
            break;

        case 2:

            printf("\t\t\t\tChild Benifits\n\n\n");

            goto guide;
            break;

        case 3:

            printf("\t\t\t\tOntario Trillium Benifits\n\n\n");

            goto guide;
            break;

        case 4:

            printf("\t\t\t\tGST/HST Credits\n\n\n");

            goto guide;
            break;

        case 5:

            printf(".....Returning to Main menu\n\n\n");

            break;

        default:

            printf("\t\t\t\tInvalid Option\n\n\n");

            goto guide;
    }
    return 0;
}
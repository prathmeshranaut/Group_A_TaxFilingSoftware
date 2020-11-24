#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int display_file(char* filename)
{
	FILE* fptr;

	char c;
	printf("file name is %s\n", filename);
	// Open file 
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("\t\tCannot open file \n");
		exit(0);
	}

	// Read contents from file 
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}

	fclose(fptr);
	return 0;
}

int display_guide(void)
{
	int attempt, max_attempt = 5;
	char choice;
	
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tGuide - Tax Filing software\n\n\n");
	printf("\t\t#######################################################################################\n");

guide:
	attempt = 0;
	do {
		printf("\n\n\t\t\tUser Manual\n\n");
		printf("\t\t\t\ta.Basic Tax filing\n\t\t\t\tb.Child Benifits\n\t\t\t\tc.Ontario Trillium Benifits\n\t\t\t\td.GST/HST Credits\n\t\t\t\te.Return to Main menu\n");
		printf("You have %d attempts", max_attempt - attempt);
		printf("\n\n\tEnter the choice : \n\t\t");
		scanf(" %c", &choice);
		attempt++;
		if (attempt > max_attempt)
			goto exit;
	} while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && attempt <= max_attempt);

	switch (choice) {
	case 'a':

		printf("\t\t\t\tBasic Tax filing\n\n\n");
		display_file("./data/guide_basic.dat");
		goto guide;
		break;

	case 'b':

		printf("\t\t\t\tChild Benifits\n\n\n");
		display_file("./data/guide_child.dat");
		goto guide;
		break;

	case 'c':

		printf("\t\t\t\tOntario Trillium Benifits\n\n\n");
		display_file("./data/guide_otb.dat");
		goto guide;
		break;

	case 'd':

		printf("\t\t\t\tGST/HST Credits\n\n\n");
		display_file("./data/guide_hst.dat");
		goto guide;
		break;

	case 'e': 

		printf(".....Returning to Main menu\n\n\n");

		break;

	default:

		printf("\t\t\t\tInvalid Option\n\n\n");

		goto guide;
	}
exit: 
	return 0;
}

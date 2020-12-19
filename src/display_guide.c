/**
 * @file display_guide.c
 *
 * @brief Contains the definition for displaying the User manual
 * @author Ragunath Anbarasu
 * */
#include<stdio.h>
#include<stdlib.h>
 /** @brief Display User manual
  *
  * @detail Ask user to select which User manual to view and display 
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */


int display_file(char* filename)
{
	FILE* fptr;

	char c;

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
		printf("\n\n\t\t\tYou have %d attempts", max_attempt - attempt);
		printf("\n\n\t\t\tEnter the choice : \t\t");
		scanf(" %c", &choice);
		attempt++;
		if (attempt > max_attempt)
			goto exit;
	} while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && attempt <= max_attempt);

	switch (choice) {
	case 'a':

		
		display_file("./data/guide_basic.dat");
		goto guide;
		break;

	case 'b':

		
		display_file("./data/guide_child.dat");
		goto guide;
		break;

	case 'c':

		
		display_file("./data/guide_otb.dat");
		goto guide;
		break;

	case 'd':

		
		display_file("./data/guide_hst.dat");
		goto guide;
		break;

	case 'e':

		printf("\n\t\t\t\t.....Returning to Main menu\n\n\n");

		break;

	default:

		printf("\n\t\t\t\tInvalid Option\n\n\n");

		goto guide;
	}
exit:
	return 0;
}

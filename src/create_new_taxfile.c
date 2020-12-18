/**
 * @file create_new_taxfile.c
 *
 * @brief Contains the definition for writing the data collected and computed into a json file.
 * */

#include<string.h>
#include<stdlib.h>
#include "headers/new_taxfile.h"

 /** @brief Writes data into json file
  *
  * @detail Writes the data collected from user and the tax summary calculated into a json file
  *
  * @param[in,out] JSON root element
  *
  * @return 0 in case of success or 1 in case of failure
  * */


int create_new_taxfile(cJSON* root)
{

	FILE* f;
	char* out = NULL;

	cJSON* json; //
	json = root;	//Convert text string to cJSON object
	if (NULL == json)	//If text is not in json format
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}

	f = fopen("./data/taxfile_new.json", "w");
	fseek(f, 0, SEEK_END);
	ftell(f);
	fseek(f, 0, SEEK_SET);
	out = cJSON_Print(root);
	fwrite(out, 1, strlen(out), f);
	fclose(f);
	return 0;
}

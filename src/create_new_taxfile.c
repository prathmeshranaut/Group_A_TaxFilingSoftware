#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/new_taxfile.h"


int create_new_taxfile(cJSON* root)
{
	
	int len=0;
	//time_t rawtime;
	//char* buffer[255];
	//time(&rawtime);
	FILE* f;
	char* out = NULL;
	//char file_name= "taxfile";
	//char* file_path = NULL;
	cJSON* json; //* json_first_name, * json_basic, * json_last_name
	json = root;	//Convert text string to cJSON object
	if (NULL == json)	//If text is not in json format
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}

	/*json_basic = cJSON_GetObjectItem(root, "basic");
	json_first_name = cJSON_GetObjectItem(json_basic, "first_name");
	json_last_name = cJSON_GetObjectItem(json_basic, "last_name");
	file_name = json_first_name->valuestring;
	strcat(file_name, json_last_name->valuestring);
	sprintf(buffer, "%s_%s", file_name, ctime(&rawtime));
	char* p = buffer;
	for (; *p; ++p)
	{
		if (*p == ' ' || *p == ':')
			* p = '_';
	}
	file_path= sprintf(file_path, "%s.json", buffer);
	//strcpy(file_path, buffer);
	//strcat(file_path, buffer);
	printf("%s\n", file_path);*/
	f = fopen("./data/taxfile_new.json", "w");
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, SEEK_SET);
	out = cJSON_Print(root);
	fwrite(out, 1, strlen(out), f);
	fclose(f);
	free(out);
	return 0;
}

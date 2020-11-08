#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include "cJSON.h"
#include<stdbool.h>
#include <dirent.h>
#include <time.h>

typedef struct
{
	char first_name[32];
	char last_name[32];
	char email[64];
	int sin;
	char date_of_birth[12];
}basic;

/*
int basic_struct_to_cJSON(char* json_string, basic* person)
{

	if ((json_string == NULL) || (person == NULL))
	{
		printf("%s: input is invalid", __func__);
	}

	char* out = NULL;
	cJSON* root = cJSON_CreateObject();

	if (!root)
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		cJSON* obj_person = cJSON_CreateObject();

		cJSON* item = cJSON_CreateString(person->first_name);
		cJSON_AddItemToObject(obj_person, "first_name", item);

		item = cJSON_CreateString(person->last_name);
		cJSON_AddItemToObject(obj_person, "last_name", item);

		item = cJSON_CreateString(person->email);
		cJSON_AddItemToObject(obj_person, "email", item);

		item = cJSON_CreateNumber(person->sin);
		cJSON_AddItemToObject(obj_person, "sin", item);

		item = cJSON_CreateString(person->date_of_birth);
		cJSON_AddItemToObject(obj_person, "date_of_birth", item);

		cJSON_AddItemToObject(root, "person", obj_person);

		out = cJSON_Print(root);
		printf("out2:%s\n", out);

		cJSON_Delete(root);
		if (out != NULL)
		{
			memcpy(json_string, out, strlen(out));
			free(out);
		}
	}

	return 0;
}
*/

int input_new_TaxFile(cJSON* root)
{
	printf("Entered array_to_JSON\n");
	cJSON *arrayItem, *item, *object;
	int i;

	basic worker;
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tBasic Details\n\n\n");
	printf("\t\t#######################################################################################\n");
	printf("Enter your First name:");
	scanf("%s", &worker.first_name);
	printf("Enter your Last name:");
	scanf("%s", &worker.last_name);
	printf("Enter a valid email address:");
	scanf("%s", &worker.email);
	printf("Enter your SIN(9 Digits):");
	scanf("%d", &worker.sin);
	printf("Enter your Date of Birth(YYYY-MM-DD):");
	scanf("%s", &worker.date_of_birth);

	printf(" first_name= %s \n last_name= %s \n email= %s \n sin= %d \n date_of_birth= %s\n ",
		worker.first_name,
		worker.last_name,
		worker.email,
		worker.sin,
		worker.date_of_birth);

	char* out = NULL;

	if (!root)
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		cJSON* obj_person = cJSON_CreateObject();

		cJSON* item = cJSON_CreateString(worker.first_name);
		cJSON_AddItemToObject(obj_person, "first_name", item);

		item = cJSON_CreateString(worker.last_name);
		cJSON_AddItemToObject(obj_person, "last_name", item);

		item = cJSON_CreateString(worker.email);
		cJSON_AddItemToObject(obj_person, "email", item);

		item = cJSON_CreateNumber(worker.sin);
		cJSON_AddItemToObject(obj_person, "sin", item);

		item = cJSON_CreateString(worker.date_of_birth);
		cJSON_AddItemToObject(obj_person, "date_of_birth", item);

		cJSON_AddItemToObject(root, "basic", obj_person);

		//cJSON_Delete(root);
		//if (out != NULL)
		//{
		//	memcpy(text, out, strlen(out));
		//	free(out);
		//}
	}

	return 0;
}

void printJson(char* root) {
	char* out = cJSON_Print(root);
	printf("JSON Output:%s\n", out);
}

char* getUniqueFileName(char* name)
{
	time_t rawtime;
	char* buffer[255];
	time(&rawtime);
	sprintf(buffer, "%s_%s", name,ctime(&rawtime));
	// Lets convert space to _ in

	char* p = buffer;
	for (; *p; ++p)
	{
		if (*p == ' ' || *p == ':')
			* p = '_';
	}

	printf("%s\n", buffer);
	return buffer;
}
/*
int create_NewTaxFile()
{
	FILE* f;
	int len;
	char data[1024];
	char* file_name= "";
	char* path="";
	
	
	strcat(file_name, worker.first_name);
	strcat(file_name, worker.last_name);

	path=getUniqueFileName(file_name);
	printf("\n\nfile name is %s\t", path);

	f = fopen(path, "w+");
	//fseek(f, 0, SEEK_END);
//	len = ftell(f);
	//fseek(f, 0, SEEK_SET);

	//printf("read file %s complete, len=%d.\n", path, len);

	basic_struct_array_to_cJSON(data, worker);

	

	fwrite(data, 1, sizeof(data), f);
	fclose(f);

	printf("\n.........Returning to Main menu\n");

	return 0;
}
*/
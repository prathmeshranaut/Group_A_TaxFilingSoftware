#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include "cJSON.h"

typedef struct
{
	char firstName[32];
	char lastName[32];
	char email[64];
	int SIN;
	char dOB[11];
}people;

void dofile(char* filename);/* Read a file, parse, render back, etc. */

/*int createFile(int argc, char** argv)
{

	dofile("json_str4.txt");

	return 0;
}*/


//create a key-value pair
int str_to_cJSON(char* json_string, char* str_val)
{
	char* out = NULL;
	cJSON* root = cJSON_CreateObject();
	if (!root)
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		cJSON* item = cJSON_CreateString("Brett");
		cJSON_AddItemToObject(root, "firstName", item);

		out = cJSON_Print(root);
		printf("out2:%s\n", out);

		cJSON_Delete(root);
		if (out != NULL)
		{
			free(out);
		}
	}
	return 0;
}

//create a object from struct
int struct_to_cJSON(char* json_string, people* person)
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

		cJSON* item = cJSON_CreateString(person->firstName);
		cJSON_AddItemToObject(obj_person, "firstName", item);

		item = cJSON_CreateString(person->lastName);
		cJSON_AddItemToObject(obj_person, "lastName", item);

		item = cJSON_CreateString(person->email);
		cJSON_AddItemToObject(obj_person, "email", item);

		item = cJSON_CreateNumber(person->SIN);
		cJSON_AddItemToObject(obj_person, "SIN", item);

		item = cJSON_CreateString(person->dOB);
		cJSON_AddItemToObject(obj_person, "dOB", item);

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


//a struct array to CJSON
int struct_array_to_cJSON(char* text, people worker[])
{
	cJSON* json, * arrayItem, * item, * object;
	int i;

	for (i = 0; i < 1; i++)
	{
		printf("firstName=%s,lastName=%s,email=%s,SIN=%d,dOB=%s\n",
			worker[i].firstName,
			worker[i].lastName,
			worker[i].email,
			worker[i].SIN,
			worker[i].dOB);
	}

	if ((text == NULL) || (worker == NULL))
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
		cJSON* array_person = cJSON_CreateArray();

		for (i = 0; i < 1; i++)
		{
			cJSON* obj_person = cJSON_CreateObject();

			cJSON* item = cJSON_CreateString(worker[i].firstName);
			cJSON_AddItemToObject(obj_person, "firstName", item);

			item = cJSON_CreateString(worker[i].lastName);
			cJSON_AddItemToObject(obj_person, "lastName", item);

			item = cJSON_CreateString(worker[i].email);
			cJSON_AddItemToObject(obj_person, "email", item);

			item = cJSON_CreateNumber(worker[i].SIN);
			cJSON_AddItemToObject(obj_person, "SIN", item);

			item = cJSON_CreateString(worker[i].dOB);
			cJSON_AddItemToObject(obj_person, "dOB", item);

			cJSON_AddItemToArray(array_person, obj_person);
		}

		cJSON_AddItemToObject(root, "people", array_person);

		out = cJSON_Print(root);
		printf("out:%s\n", out);

		cJSON_Delete(root);
		if (out != NULL)
		{
			memcpy(text, out, strlen(out));
			free(out);
		}
	}

	return 0;
}

// create CJSON, write file
void dofile(char* filename)
{
	FILE* f;
	int len;
	char data[1024];

	f = fopen(filename, "wb");
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, SEEK_SET);

	printf("read file %s complete, len=%d.\n", filename, len);

	//	char str_name[40];
	//	int ret = str_to_cJSON(data, str_name);

	people worker[1] = {
			{"zhong","Jason","bbbb@126.com",967450734,"1985-08-12"}
	};
	//	struct_to_cJSON(data, &worker[1]);
	struct_array_to_cJSON(data, worker);

	fwrite(data, 1, strlen(data), f);
	fclose(f);

	//cJSON* tree = NULL;
	//char* actual = NULL;

	//tree = parse_file(filename);
	//actual = cJSON_Print(tree);
}


//int show_files(void) {
//	DIR* dir;
//	struct dirent* ent;
//	if ((dir = opendir(".\\data\\")) != NULL) {
//		/* print all the files and directories within directory */
//		while ((ent = readdir(dir)) != NULL) {
//			printf("%s\n", ent->d_name);
//		}
//		closedir(dir);
//	}
//	else {
//		/* could not open directory */
//		perror("");
//		return EXIT_FAILURE;
//	}
//}


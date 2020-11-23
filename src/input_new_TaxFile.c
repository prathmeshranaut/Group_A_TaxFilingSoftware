#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/new_taxfile.h"

int input_new_taxfile(cJSON* root)
{

	basic worker;
	printf("\t\t#######################################################################################\n");
	printf("\n\n\t\t\t\t\t\tBasic Details\n\n\n");
	printf("\t\t#######################################################################################\n");
	do {
		printf("Enter your First name:");
		scanf("%s", worker.first_name);
	} while (!string_isvalid(worker.first_name));
	do {
		printf("Enter your Last name:");
		scanf("%s", worker.last_name);
	} while (!string_isvalid(worker.last_name));
	do {
	printf("Enter a valid email address:");
	scanf("%s", worker.email);
	} while (!spc_email_isvalid(worker.email));
	do {
	printf("Enter your SIN(9 Digits):");
	scanf("%s", worker.sin);
	} while (!sin_isvalid(worker.sin));
	printf("Enter your Date of Birth(YYYY-MM-DD):");
	scanf("%s", worker.date_of_birth);

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

		item = cJSON_CreateString(worker.sin);
		cJSON_AddItemToObject(obj_person, "sin", item);

		item = cJSON_CreateString(worker.date_of_birth);
		cJSON_AddItemToObject(obj_person, "date_of_birth", item);

		cJSON_AddItemToObject(root, "basic", obj_person);

	}

	return 0;
}

void print_json(char* root) {
	char* out = cJSON_Print(root);
	printf("JSON Output:%s\n", out);
}

int spc_email_isvalid(const char* address) {
	int count = 0;
	const char* c, * domain;
	static char* rfc822_specials = "()<>@,;:\\\"[]";  /* first we validate the name portion (name@domain) */
	for (c = address; *c; c++) {
		if (*c == '\"' && (c == address || *(c - 1) == '.' || *(c - 1) == '\"')) {
			while (*++c) {
				if (*c == '\"')
					break;
				if (*c == '\\' && (*++c == ' '))
					continue;
				if (*c <= ' ' || *c >= 127)
					return 0;
			}
			if (!*c++)
				return 0;
			if (*c == '@')
				break;
			if (*c != '.')
				return 0;
			continue;
		}
		if (*c == '@')
			break;
		if (*c <= ' ' || *c >= 127)
			return 0;
		if (strchr(rfc822_specials, *c))
			return 0;
	}
	if (c == address || *(c - 1) == '.')
		return 0;  /* next we validate the domain portion (name@domain) */
	if (!*(domain = ++c))
		return 0;
	do {
		if (*c == '.') {
			if (c == domain || *(c - 1) == '.')
				return 0;
			count++;
		}
		if (*c <= ' ' || *c >= 127)
			return 0;
		if (strchr(rfc822_specials, *c))
			return 0;
	} while (*++c);
	return (count >= 1);
}
int string_isvalid(const char* address) {
	int count_num = 0, count=0;
	const char* c;
	for (c = address; *c; c++) {
		if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
			count++;
		else
			count_num++;
	}
	if (count_num)
		return 0;
	else
		return 1;
}

int sin_isvalid(const char* address) {
	int count_num = 0, count = 0;
	const char* c;
	for (c = address; *c; c++) {
		if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
			count++;
		else
			count_num++;
	}
	if (count_num==9)
		return 1;
	else
		return 0;
}

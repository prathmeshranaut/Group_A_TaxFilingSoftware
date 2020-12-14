#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/new_taxfile.h"
#include <time.h>


int input_new_taxfile(cJSON* root)
{
	MYDAY md;
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
	do {
		printf("Enter your Date of Birth(YYYY-MM-DD):");
		scanf("%4d-%2d-%2d", &md.year, &md.month, &md.day);
		strcpy(worker.date_of_birth,struct2str(md));
	} while (!validate_date(md));
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

void print_json(cJSON* root) {
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


int validate_date(MYDAY md){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int res = 1;
	if (0 > md.year && (md.year > (tm.tm_year + 1900))) {
		//fprintf(stderr, "Year is invalid.\n");
		res = 0;
	}
	else if (md.month < 1 || md.month > 12) {
		//fprintf(stderr, "Month is invalid.\n");
		res = 0;
	}
	else if (md.day < 1 || md.day > 31) { // For simplification, we do not check if the month has 28, 29, or 30 days 
		//fprintf(stderr, "Day is invalid.\n");
		res = 0;
	}
	else if (md.year == tm.tm_year + 1900 && md.month == tm.tm_mon + 1 && md.day == tm.tm_mday) { // For simplification, we do not check if the month has 28, 29, or 30 days 
		//fprintf(stderr, "Todays date cannot be entered.\n");
		res = 0;
	}
	return res;
}
char* struct2str(MYDAY md)
{
	
	/* get lenght of string required to hold struct values */
	size_t len = 0;
	len = snprintf(NULL, len, "%d-%02d-%02d", md.year, md.month, md.day);

	/* allocate/validate string to hold all values (+1 to null-terminate) */
	char* mdstr = calloc(1, sizeof * mdstr * len + 1);
	if (!mdstr) {
		fprintf(stderr, "%s() error: virtual memory allocation failed.\n", __func__);
	}

	/* write/validate struct values to apstr */
	if (snprintf(mdstr, len + 1, "%d-%02d-%02d", md.year, md.month, md.day) > len + 1)
	{
		fprintf(stderr, "%s() error: snprintf returned truncated result.\n", __func__);
		return NULL;
	}

	return mdstr;
}

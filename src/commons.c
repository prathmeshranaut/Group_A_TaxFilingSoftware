/**
 * @file commons.c
 *
 * @brief Contains the definition for common functions used in the software
 * @author Prathmesh Ranaut, Ragunath Anbarasu
 * */
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "../include/cJSON.h"
#include "headers/commons.h"
 /** @brief Common functions used in the software
  *
  * @detail This code is a collection of inout validation and other commonly used codes in the software
  *
  * @param
  *
  * @return 
  * */


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
	int count_num = 0, count = 0;
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

int zip_isvalid(const char* address) {
	int count_num = 0, count = 0;
	const char* c;
	for (c = address; *c; c++) {
		if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z') || (*c >= '0' && *c <= '9'))
			count++;
		else
			count_num++;
	}
	if (count == 6)
		return 1;
	else
		return 0;
}

int sin_isvalid(const char* address) {
	int count_num = 0, count = 0;
	const char* c;
	for (c = address; *c; c++) {
		if((*c >= '0' && *c <= '9'))
			count++;
		else
			count_num++;
	}
	if (count == 9)
		return 1;
	else
		return 0;
}


int number_isvalid(const char* address) {
	int count_num = 0, count = 0;
	const char* c;
	for (c = address; *c; c++) {
		if ((*c >= '0' && *c <= '9'))
			count++;
		else
			count_num++;
	}
	if (count_num)
		return 0;
	else
		return 1;
}


int phone_isvalid(const char* address) {
	int count_num = 0, count = 0;
	const char* c;
	for (c = address; *c; c++) {
		if ((*c >= '0' && *c <= '9'))
			count++;
		else
			count_num++;
	}
	if (count == 10)
		return 1;
	else
		return 0;
}

int validate_date(MYDAY md) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int res = 1;
	if (0 > md.year && (md.year > (tm.tm_year + 1900))) {
		res = 0;
	}
	else if (md.month < 1 || md.month > 12) {
		res = 0;
	}
	else if (md.day < 1 || md.day > 31) { // For simplification, we do not check if the month has 28, 29, or 30 days 
		res = 0;
	}
	else if (md.year == tm.tm_year + 1900 && md.month == tm.tm_mon + 1 && md.day == tm.tm_mday) { // For simplification, we do not check if the month has 28, 29, or 30 days 
		res = 0;
	}
	return res;
}
char* struct2str(MYDAY md)
{

	/* get lenght of string required to hold struct values */
	size_t len = 0;
	len = snprintf(NULL, len, "%04d-%02d-%02d", md.year, md.month, md.day);

	/* allocate/validate string to hold all values (+1 to null-terminate) */
	char* mdstr = calloc(1, sizeof * mdstr * len + 1);
	if (!mdstr) {
		fprintf(stderr, "%s() error: virtual memory allocation failed.\n", __func__);
	}

	/* write/validate struct values to apstr */
	if (snprintf(mdstr, len + 1, "%04d-%02d-%02d", md.year, md.month, md.day) > len + 1)
	{
		fprintf(stderr, "%s() error: snprintf returned truncated result.\n", __func__);
		return NULL;
	}

	return mdstr;
}

int find_age(MYDAY md) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int age = 0;

	if (validate_date(md)) {
		age = ((tm.tm_year + 1900) - md.year);
	}
	return age;
}

int string_isyn(const char* address) {
	int count = 0;
	const char* c;
	for (c = address; *c; c++) {
		if ((*c == 'y' || *c == 'n') || (*c == 'Y' || *c == 'N'))
			count++;
	}
	if (count == 1)
		return 1;
	else
		return 0;
}

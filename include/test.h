#pragma once
#ifndef TEST_H
#define TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
struct record;
//int print_preallocated(cJSON* root);
//void create_objects(void);
//cJSON* createFile(char* filename);
//int write_file(char* filename, char* out);
cJSON* parse_file(const char* filename);
void do_test(const char* test_name);


#endif
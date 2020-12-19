/**
 * @file t2202.c
 *
 * @brief Contains the definition for getting users T2202 details
 * */
#include "headers/t2202.h"
#include <assert.h>
#include "headers/commons.h"

#define MAX_RETRIES 3

/** @brief Gets T2202 details from the user
 *
 * @detail Asks user to fill in details of their T2202 form so that can be used in calculation of tax
 *
 * @param[in,out] JSON root element
 *
 * @return 0 in case of success or 1 in case of failure
 * */

int input_t2202_details(cJSON *root) {
    char has_details = 'y';

    if (has_details == 'y') {
        t2202 t2202_details = {"", "", "", "", "", 0};
        printf("\n\t\t#######################################################################################\n");
        printf("\n\n\t\t\t\t\t\tT2202 details\n\n\n");
        printf("\t\t#######################################################################################\n");

        do {
            printf("\n\t\tEnter your Institution Name : ");
            scanf("%s", t2202_details.institute_name);
        } while (!string_isvalid(t2202_details.institute_name));

        do {
            printf("\n\t\tEnter your School Type : ");
            scanf("%s", t2202_details.school_type);
        } while (!string_isvalid(t2202_details.school_type));

        do {
            printf("\n\t\tEnter your Student Number : ");
            scanf("%s", t2202_details.student_number);
        } while (!number_isvalid(t2202_details.student_number));

        do {
            printf("\n\t\tEnter your Course Detail : ");
            scanf("%s", t2202_details.course);
        } while (!string_isvalid(t2202_details.course));

        do {
            printf("\n\t\tEnter your Session (f/w/s) : ");
            scanf("%s", t2202_details.session);
        } while (!string_isvalid(t2202_details.session));


        printf("\n\t\tEnter your tution Amount(CAD) : ");
        DOUBLE_VALUE_INPUT(&t2202_details.amount);


        cJSON *t2202_details_object = cJSON_CreateObject();

        cJSON_AddItemToObject(t2202_details_object, INSTITUTION_NAME, cJSON_CreateString(t2202_details.institute_name));
        cJSON_AddItemToObject(t2202_details_object, SCHOOL_TYPE, cJSON_CreateString(t2202_details.school_type));
        cJSON_AddItemToObject(t2202_details_object, STUDENT_NUMBER, cJSON_CreateString(t2202_details.student_number));
        cJSON_AddItemToObject(t2202_details_object, COURSE, cJSON_CreateString(t2202_details.course));
        cJSON_AddItemToObject(t2202_details_object, SESSION, cJSON_CreateString(t2202_details.session));
        cJSON_AddItemToObject(t2202_details_object, AMOUNT, cJSON_CreateNumber(t2202_details.amount));

        cJSON_AddItemToObject(root, T2202_KEY, t2202_details_object);

    }
    return 0;
}
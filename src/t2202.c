#include "t2202.h"

int input_t2202_details(cJSON *root) {
    char has_details = 'y';
    printf("Do you wish to enter T22 details? (y/n)");
    scanf(" %c", &has_details);
    printf("Done waiting");

    cJSON *t2202_details_array = cJSON_CreateArray();

    while ('y' == has_details) {
        t2202 t2202_details;
        printf("\n#######################################################################################\n");
        printf("Enter your T2202 details\n");
        printf("\n#######################################################################################\n");

        printf("Enter your Institution Name:");
        scanf("%s", t2202_details.institute_name);

        printf("Enter your School Type:");
        scanf("%s", t2202_details.school_type);

        printf("Enter your Student Number:");
        scanf("%s", t2202_details.student_number);

        printf("Enter your Course Detail:");
        scanf("%s", t2202_details.course);

        printf("Enter your Session:");
        scanf("%s", t2202_details.session);

        printf("Enter your Amount:");
        scanf("%lf", &t2202_details.amount);

    

        cJSON *t2202_details_object = cJSON_CreateObject();

        cJSON_AddItemToObject(t2202_details_object, INSTITUTION_NAME, cJSON_CreateString(t2202_details.institute_name));
        cJSON_AddItemToObject(t2202_details_object, SCHOOL_TYPE, cJSON_CreateString(t2202_details.school_type));
        cJSON_AddItemToObject(t2202_details_object, STUDENT_NUMBER, cJSON_CreateString(t2202_details.student_number));
        cJSON_AddItemToObject(t2202_details_object, COURSE, cJSON_CreateString(t2202_details.course));
        cJSON_AddItemToObject(t2202_details_object, SESSION, cJSON_CreateString(t2202_details.session));
        cJSON_AddItemToObject(t2202_details_object, AMOUNT, cJSON_CreateNumber(t2202_details.amount));
    
        cJSON_AddItemToArray(t2202_details_array, t2202_details_object);

        printf("Do you wish to enter more T2202 details? (y/n)");
        scanf(" %c", &has_details);
    }

    cJSON_AddItemToObject(root, T2202_KEY, t2202_details_array);
    return 0;
} 
#ifndef GROUP_A_TAXFILINGSOFTWARE_COMMONS_H
#define GROUP_A_TAXFILINGSOFTWARE_COMMONS_H


typedef struct {
    int year;
    int month;
    int day;
} MYDAY;


#define DOUBLE_VALUE_INPUT(variable) { \
    int retries = 0; \
    while (scanf("%lf", variable) == 0) { \
        if (retries >= MAX_RETRIES) { \
            return 1; \
        } \
        printf("\nInvalid input. Please enter a number, such as 1.5, or 3:"); \
        scanf("%*s"); \
        retries += 1; \
    } \
}

#define INTEGER_VALUE_INPUT(variable) { \
    int retries = 0; \
    while (scanf("%d", variable) == 0) { \
        if (retries >= MAX_RETRIES) { \
            return 1; \
        } \
        printf("\nInvalid input. Please enter a number, such as 1, or 30:"); \
        scanf("%*s"); \
        retries += 1; \
    } \
}

void print_json(cJSON *root);

int spc_email_isvalid(const char *address);

int string_isvalid(const char *address);

int sin_isvalid(const char *address);

int validate_date(MYDAY md);

char *struct2str(MYDAY md);

int find_age(MYDAY md);

int string_isyn(const char *address);

int phone_isvalid(const char *address);

int zip_isvalid(const char *address);

int number_isvalid(const char *address);

#endif //GROUP_A_TAXFILINGSOFTWARE_COMMONS_H

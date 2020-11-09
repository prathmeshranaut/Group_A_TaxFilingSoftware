#include "headers/t4.h"

int input_t4_details(cJSON *root) {
    char has_details = 'y';

    printf("Do you wish to enter T4 details? (y/n)");
    scanf(" %c", &has_details);

    cJSON *t4_details_array = cJSON_CreateArray();

    while ('y' == has_details) {
        t4 t4_details = {"", "ON", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        printf("\n#######################################################################################\n");
        printf("Enter your T4 details\n");
        printf("\n#######################################################################################\n");

        printf("Enter your Employers Name:");
        scanf("%s", t4_details.employer_name);

        printf("Enter your Employment Income(Field 14):");
        while (scanf("%lf", &t4_details.employment_income) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Employees CPP contribution(Field 16):");
        while (scanf("%lf", &t4_details.employees_cpp_contribution) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Employees QPP contribution(Field 17):");
        while (scanf("%lf", &t4_details.employees_qpp_contribution) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Employees EI Premiums(Field 18):");
        while (scanf("%lf", &t4_details.employees_ei_premiums) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your RPP Contributions(Field 20):");
        while (scanf("%lf", &t4_details.rpp_contributions) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Income Tax Deducted(Field 22):");
        while (scanf("%lf", &t4_details.income_tax_deducted) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your EI Insurable Earnings(Field 24):");
        while (scanf("%lf", &t4_details.ei_insurable_earnings) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your CPP/QPP Pensionable Earnings(Field 26):");
        while (scanf("%lf", &t4_details.cpp_qpp_pensionable_earnings) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Union Dues(Field 44):");
        while (scanf("%lf", &t4_details.union_dues) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Charitable Donations(Field 46):");
        while (scanf("%lf", &t4_details.charitable_donations) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your RPP/DSSP Registation Number (Field 50):");
        while (scanf("%lf", &t4_details.rpp_dssp_registation_number) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Pension Adjustment(Field 52):");
        while (scanf("%lf", &t4_details.pension_adjustment) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your Employees PPIP Premiums(Field 55):");
        while (scanf("%lf", &t4_details.employees_ppip_premiums) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        printf("Enter your PPIP insurable earnings(Field 56):");
        while (scanf("%lf", &t4_details.ppip_insurable_earnings) == 0) {
            printf("Invalid input. Please enter a number, such as 1.5, or 3:");
            scanf("%*s");
        }

        cJSON *t4_details_object = cJSON_CreateObject();

        cJSON_AddItemToObject(t4_details_object, EMPLOYER_NAME, cJSON_CreateString(t4_details.employer_name));
        cJSON_AddItemToObject(t4_details_object, PROVINCE, cJSON_CreateString(t4_details.province));
        cJSON_AddItemToObject(t4_details_object, EMPLOYMENT_INCOME, cJSON_CreateNumber(t4_details.employment_income));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_CPP_CONTRIBUTION,
                              cJSON_CreateNumber(t4_details.employees_cpp_contribution));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_QPP_CONTRIBUTION,
                              cJSON_CreateNumber(t4_details.employees_qpp_contribution));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_EI_PREMIUMS,
                              cJSON_CreateNumber(t4_details.employees_ei_premiums));
        cJSON_AddItemToObject(t4_details_object, RPP_CONTRIBUTIONS, cJSON_CreateNumber(t4_details.rpp_contributions));
        cJSON_AddItemToObject(t4_details_object, INCOME_TAX_DEDUCTED,
                              cJSON_CreateNumber(t4_details.income_tax_deducted));
        cJSON_AddItemToObject(t4_details_object, EI_INSURABLE_EARNINGS,
                              cJSON_CreateNumber(t4_details.ei_insurable_earnings));
        cJSON_AddItemToObject(t4_details_object, CPP_QPP_PENSIONABLE_EARNINGS,
                              cJSON_CreateNumber(t4_details.cpp_qpp_pensionable_earnings));
        cJSON_AddItemToObject(t4_details_object, UNION_DUES, cJSON_CreateNumber(t4_details.union_dues));
        cJSON_AddItemToObject(t4_details_object, CHARITABLE_DONATIONS,
                              cJSON_CreateNumber(t4_details.charitable_donations));
        cJSON_AddItemToObject(t4_details_object, RPP_DSSP_REGISTRATION_NUMBER,
                              cJSON_CreateNumber(t4_details.rpp_dssp_registation_number));
        cJSON_AddItemToObject(t4_details_object, PENSION_ADJUSTMENT, cJSON_CreateNumber(t4_details.pension_adjustment));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_PPIP_PREMIUMS,
                              cJSON_CreateNumber(t4_details.employees_ppip_premiums));
        cJSON_AddItemToObject(t4_details_object, PPIP_INSURABLE_EARNINGS,
                              cJSON_CreateNumber(t4_details.ppip_insurable_earnings));

        cJSON_AddItemToArray(t4_details_array, t4_details_object);

        printf("Do you wish to enter more T4 details? (y/n)");
        scanf(" %c", &has_details);
    }

    cJSON_AddItemToObject(root, T4_KEY, t4_details_array);

    return 0;
}
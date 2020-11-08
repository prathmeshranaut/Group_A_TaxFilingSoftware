#include "headers/t4.h"

int input_t4_details(cJSON *root) {
    char has_details = 'y';

    printf("Do you wish to enter T4 details? (y/n)");
    scanf(" %c", &has_details);
    printf("Done waiting");

    cJSON *t4_details_array = cJSON_CreateArray();

    while ('y' == has_details) {
        t4 t4_details;
        printf("\n#######################################################################################\n");
        printf("Enter your T4 details\n");
        printf("\n#######################################################################################\n");

        printf("Enter your Employers Name:");
        scanf("%s", t4_details.employer_name);

        printf("Enter your Province abbreviations(2 letters)(Field 10):");
        scanf("%s", t4_details.province);

        printf("Enter your Employment Income(Field 14):");
        scanf("%lf", &t4_details.employment_income);

        printf("Enter your Employees CPP contribution(Field 16):");
        scanf("%lf", &t4_details.employees_cpp_contribution);

        printf("Enter your Employees QPP contribution(Field 17):");
        scanf("%lf", &t4_details.employees_qpp_contribution);

        printf("Enter your Employees EI Premiums(Field 18):");
        scanf("%lf", &t4_details.employees_ei_premiums);

        printf("Enter your RPP Contributions(Field 20):");
        scanf("%lf", &t4_details.rpp_contributions);

        printf("Enter your Income Tax Deducted(Field 22):");
        scanf("%lf", &t4_details.income_tax_deducted);

        printf("Enter your EI Insurable Earnings(Field 24):");
        scanf("%lf", &t4_details.ei_insurable_earnings);

        printf("Enter your CPP/QPP Pensionable Earnings(Field 26):");
        scanf("%lf", &t4_details.cpp_qpp_pensionable_earnings);

        printf("Enter your Union Dues(Field 44):");
        scanf("%lf", &t4_details.union_dues);

        printf("Enter your Charitable Donations(Field 46):");
        scanf("%lf", &t4_details.charitable_donations);

        printf("Enter your RPP/DSSP Registation Number (Field 50):");
        scanf("%lf", &t4_details.rpp_dssp_registation_number);

        printf("Enter your Pension Adjustment(Field 52):");
        scanf("%lf", &t4_details.pension_adjustment);

        printf("Enter your Employees PPIP Premiums(Field 55):");
        scanf("%lf", &t4_details.employees_ppip_premiums);

        printf("Enter your PPIP insurable earnings(Field 56):");
        scanf("%lf", &t4_details.ppip_insurable_earnings);

        cJSON *t4_details_object = cJSON_CreateObject();

        cJSON_AddItemToObject(t4_details_object, EMPLOYER_NAME, cJSON_CreateString(t4_details.employer_name));
        cJSON_AddItemToObject(t4_details_object, PROVINCE, cJSON_CreateString(t4_details.province));
        cJSON_AddItemToObject(t4_details_object, EMPLOYMENT_INCOME, cJSON_CreateNumber(t4_details.employment_income));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_CPP_CONTRIBUTION, cJSON_CreateNumber(t4_details.employees_cpp_contribution));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_QPP_CONTRIBUTION, cJSON_CreateNumber(t4_details.employees_qpp_contribution));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_EI_PREMIUMS, cJSON_CreateNumber(t4_details.employees_ei_premiums));
        cJSON_AddItemToObject(t4_details_object, RPP_CONTRIBUTIONS, cJSON_CreateNumber(t4_details.rpp_contributions));
        cJSON_AddItemToObject(t4_details_object, INCOME_TAX_DEDUCTED, cJSON_CreateNumber(t4_details.income_tax_deducted));
        cJSON_AddItemToObject(t4_details_object, EI_INSURABLE_EARNINGS, cJSON_CreateNumber(t4_details.ei_insurable_earnings));
        cJSON_AddItemToObject(t4_details_object, CPP_QPP_PENSIONABLE_EARNINGS, cJSON_CreateNumber(t4_details.cpp_qpp_pensionable_earnings));
        cJSON_AddItemToObject(t4_details_object, UNION_DUES, cJSON_CreateNumber(t4_details.union_dues));
        cJSON_AddItemToObject(t4_details_object, CHARITABLE_DONATIONS, cJSON_CreateNumber(t4_details.charitable_donations));
        cJSON_AddItemToObject(t4_details_object, RPP_DSSP_REGISTRATION_NUMBER, cJSON_CreateNumber(t4_details.rpp_dssp_registation_number));
        cJSON_AddItemToObject(t4_details_object, PENSION_ADJUSTMENT, cJSON_CreateNumber(t4_details.pension_adjustment));
        cJSON_AddItemToObject(t4_details_object, EMPLOYEES_PPIP_PREMIUMS, cJSON_CreateNumber(t4_details.employees_ppip_premiums));
        cJSON_AddItemToObject(t4_details_object, PPIP_INSURABLE_EARNINGS, cJSON_CreateNumber(t4_details.ppip_insurable_earnings));

        cJSON_AddItemToArray(t4_details_array, t4_details_object);

        printf("Do you wish to enter more T4 details? (y/n)");
        scanf(" %c", &has_details);
    }

    cJSON_AddItemToObject(root, T4_KEY, t4_details_array);

    return 0;
}
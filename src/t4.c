/**
 * @file t4.c
 *
 * @brief Contains the definition for getting users T4 details
 * @author Prathmesh Ranaut
 * */

#include "headers/t4.h"
#include <assert.h>

#define MAX_RETRIES 3

/** @brief Gets T4 details from the user
 *
 * @detail Asks user to fill in details of his T4 form so that can be used in calculation of tax
 *
 * @param[in,out] JSON root element
 *
 * @return 0 in case of success or 1 in case of failure
 * */

int input_t4_details(cJSON *root) {
    assert(root != NULL);

    char has_details = 'y';

    cJSON *t4_details_array = cJSON_CreateArray();

    while ('y' == has_details) {
        t4 t4_details = {"", "ON", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		printf("\n\t\t#######################################################################################\n");
        printf("\n\n\t\t\t\t\t\tT4 details");
        printf("\n\n\t\t#######################################################################################\n");

        printf("\n\t\tEnter your Employers Name: ");
        scanf("%s", t4_details.employer_name);

        printf("\n\t\tEnter your Employment Income(Field 14): ");
        DOUBLE_VALUE_INPUT(&t4_details.employment_income);

        printf("\n\t\tEnter your Employees CPP contribution(Field 16): ");
        DOUBLE_VALUE_INPUT(&t4_details.employees_cpp_contribution);

        printf("\n\t\tEnter your Employees QPP contribution(Field 17): ");
        DOUBLE_VALUE_INPUT(&t4_details.employees_qpp_contribution);

        printf("\n\t\tEnter your Employees EI Premiums(Field 18): ");
        DOUBLE_VALUE_INPUT(&t4_details.employees_ei_premiums);

        printf("\n\t\tEnter your RPP Contributions(Field 20): ");
        DOUBLE_VALUE_INPUT(&t4_details.rpp_contributions);

        printf("\n\t\tEnter your Income Tax Deducted(Field 22): ");
        DOUBLE_VALUE_INPUT(&t4_details.income_tax_deducted);

        printf("\n\t\tEnter your EI Insurable Earnings(Field 24): ");
        DOUBLE_VALUE_INPUT(&t4_details.ei_insurable_earnings);

        printf("\n\t\tEnter your CPP/QPP Pensionable Earnings(Field 26): ");
        DOUBLE_VALUE_INPUT(&t4_details.cpp_qpp_pensionable_earnings);

        printf("\n\t\tEnter your Union Dues(Field 44): ");
        DOUBLE_VALUE_INPUT(&t4_details.union_dues);

        printf("\n\t\tEnter your Charitable Donations(Field 46): ");
        DOUBLE_VALUE_INPUT(&t4_details.charitable_donations);

        printf("\n\t\tEnter your RPP/DSSP Registation Number (Field 50): ");
        DOUBLE_VALUE_INPUT(&t4_details.rpp_dssp_registation_number);

        printf("\n\t\tEnter your Pension Adjustment(Field 52): ");
        DOUBLE_VALUE_INPUT(&t4_details.pension_adjustment);

        printf("\n\t\tEnter your Employees PPIP Premiums(Field 55): ");
        DOUBLE_VALUE_INPUT(&t4_details.employees_ppip_premiums);

        printf("\n\t\tEnter your PPIP insurable earnings(Field 56): ");
        DOUBLE_VALUE_INPUT(&t4_details.ppip_insurable_earnings);

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

		do {
        printf("\n\n\t\tDo you wish to enter more T4 details? (y/n) : ");
        scanf(" %c", &has_details);
		} while (!(has_details == 'y' || has_details == 'n') || (has_details == 'Y' || has_details == 'N'));
    }

    cJSON_AddItemToObject(root, T4_KEY, t4_details_array);

    return 0;
}
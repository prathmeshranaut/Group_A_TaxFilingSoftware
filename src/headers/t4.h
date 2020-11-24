#include <stdio.h>
#include "cJSON.h"
#include "commons.h"

#ifndef GROUP_A_TAXFILINGSOFTWARE_T4_H
#define GROUP_A_TAXFILINGSOFTWARE_T4_H

#define T4_KEY "t4"
#define EMPLOYER_NAME "employer_name"
#define PROVINCE "province"
#define EMPLOYMENT_INCOME "employment_income"
#define EMPLOYEES_CPP_CONTRIBUTION "employees_cpp_contribution"
#define EMPLOYEES_QPP_CONTRIBUTION "employees_qpp_contribution"
#define EMPLOYEES_EI_PREMIUMS "employees_ei_premiums"
#define RPP_CONTRIBUTIONS "rpp_contributions"
#define INCOME_TAX_DEDUCTED "income_tax_deducted"
#define EI_INSURABLE_EARNINGS "ei_insurable_earnings"
#define CPP_QPP_PENSIONABLE_EARNINGS "cpp_qpp_pensionable_earnings"
#define UNION_DUES "union_dues"
#define CHARITABLE_DONATIONS "charitable_donations"
#define RPP_DSSP_REGISTRATION_NUMBER "rpp_dssp_registation_number"
#define PENSION_ADJUSTMENT "pension_adjustment"
#define EMPLOYEES_PPIP_PREMIUMS "employees_ppip_premiums"
#define PPIP_INSURABLE_EARNINGS "ppip_insurable_earnings"

typedef struct {
    char employer_name[1024];
    char province[3]; //10
    double employment_income; //14
    double employees_cpp_contribution; //16
    double employees_qpp_contribution; //17
    double employees_ei_premiums; // 18
    double rpp_contributions; //20
    double income_tax_deducted; //22
    double ei_insurable_earnings; //24
    double cpp_qpp_pensionable_earnings; //26
    double union_dues; //44
    double charitable_donations; //46
    double rpp_dssp_registation_number; //50
    double pension_adjustment; //52
    double employees_ppip_premiums; //55
    double ppip_insurable_earnings; //56
} t4;

int input_t4_details(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_T4_H

#include "cJSON.h"
#include <stdio.h>

#ifndef GROUP_A_TAXFILINGSOFTWARE_OT_BENEFITS_H
#define GROUP_A_TAXFILINGSOFTWARE_OT_BENEFITS_H

#define OT_BENEFITS_KEY "ot_benefits"
#define AGE "age"
#define INCOME "income"
#define SOCIAL_ASSISTANCE "social_assistance"
#define SOCIAL_ASSISTANE_RECEIVE "social_assistance_receive"
#define SOCIAL_ASSISTANCE_REPAY "social_assistance_repay"
#define SPOUSE "spouse"
#define SPOUSE_AGE "spouse_age" 
#define SPOUSE_INCOME "spouse_income"
#define SPOUSE_SOCIAL_ASSISTANCE "spouse_social_assistance"
#define SPOUSE_SOCIAL_ASSISTANCE_RECEIVE "spouse_social_assistance_receive"
#define SPOUSE_SOCIAL_ASSISTANCE_REPAY "spouse_social_assistance_repay"
#define CHILDREN "children"
#define CHILDREN_DISABILITY_CREDIT "children_dtc"
#define CHILDREN_AGE "children_age"
#define HOUSE "house"
#define HOUSE_RENT "house_r_rent"
#define HOUSE_RENT_LONG_TERM_CARE "house_r_long_term_care"
#define HOUSE_RENT_LONG_TERM_CARE_TYPE "house_r_long_term_care_type"
#define HOUSE_TAX "house_o_tax"
#define HOUSE_RENT_OWN_RENT "house_ro_rent"
#define HOUSE_RENT_OWN_TAX "house_ro_tax"
#define HOUSE_RENT_OWN_LONG_TERM_CARE "house_ro_long_term_care"
#define HOUSE_RENT_OWN_LONG_TERM_CARE_TYPE "house_ro_long_term_care_type"
#define COLLEGE_RESIDENCE "college_residence"
#define FIRST_NATIONS_RESERVE "first_nations_reserve"
#define FIRST_NATIONS_RESERVE_COST "first_nations_reserve_energy_cost"
#define NORTHERN_ONTARIO "northern_ontario"

#define ENERGE_BENEFITS "energy_benefits"
#define SALES_TAX_BENEFITS "sales_tax_benefits"
#define NORTHERN_BENEFITS "northern_benefits"
#define CALCULATED_OTB "calcualted_otb"

#define OTB_CALCULATE_KEY "otb_calculate"

typedef struct {
    char age[5];
    double income;
    char social_assistance[5];
    double social_assistance_receive;
    double social_assistance_repay;
    char spouse[5];
    char spouse_age[5];
    double spouse_income;
    char spouse_social_assistance[5];
    double spouse_social_assistance_receive;
    double spouse_social_assistance_repay;
    char children[5];
    char children_dtc[5];
    char children_age[5];
    char house[5];
    double house_r_rent;
    char house_r_long_term_care[5];
    char house_r_long_term_care_type[10];
    double house_o_tax;
    double house_ro_rent;
    double house_ro_tax;
    char house_ro_long_term_care[5];
    char house_ro_long_term_care_type[10];
    char college_residence[5];
    char first_nations_reserve[5];
    double first_nations_reserve_energy_cost;
    char northern_ontario[5];
    
} ot_benefits;

typedef struct {
	double energy_benefits;
	double sales_tax_benefits;
	double northern_benefits;
	double calcualted_otb;
} otb_calculate;

int input_ot_benefits(cJSON *root);
int calcualte_otbenefits(cJSON* root);

#endif //GROUP_A_TAXFILINGSOFTWARE_OT_BENEFITS_H
#include "cJSON.h"
#include <stdio.h>

#ifndef GROUP_A_TAXFILINGSOFTWARE_CALCULATE_TAX_H
#define GROUP_A_TAXFILINGSOFTWARE_CALCULATE_TAX_H

#define CALCULATE_TAX_KEY "tax"
#define FEDERAL_TAX "federal_tax"
#define INCOME_TAX "income_tax"
#define PROVENCIAL_TAX "provencial_tax"
#define REFUND "refund"
#define PAYABLE "payable"


typedef struct
{
	double federal_tax;
	double income_tax;
	double provencial_tax;
	double refund;
	double payable;
}tax;
int calculate_tax(cJSON* root);
#endif //GROUP_A_TAXFILINGSOFTWARE_CALCULATE_TAX_H
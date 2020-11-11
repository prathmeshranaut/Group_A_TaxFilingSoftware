#include "cJSON.h"
#include <stdio.h>

#ifndef GROUP_A_TAXFILINGSOFTWARE_ENTRY_STATUS_H
#define GROUP_A_TAXFILINGSOFTWARE_ENTRY_STATUS_H

#define ENTRY_STATUS_KEY "entry_status"
#define DATE_OF_ENTRY "date_of_entry"
#define CURRENT_PROVINCE "current_province"
#define IS_RESIDENT_IN_TAX_FILING_YEAR "is_resident_in_tax_filing_year"


typedef struct {
    char date_of_entry[12];
    char current_province[32];
    char is_resident_in_tax_filing_year[5];
} entry_status;

int input_entry_status(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_ENTRY_STATUS_H
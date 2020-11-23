#include "headers/entry_status.h"

//This function gets details from user about thier entry status in Canada

int input_entry_status(cJSON *root) {
    entry_status status;
    printf("\n#######################################################################################\n");
    printf("Enter your Details for Entry Status\n");
    printf("\n#######################################################################################\n");

    printf("Enter your Date of Entry in Canada (YYYY-MM-DD):");
    scanf("%s", status.date_of_entry);

    printf("Enter your Current Province:");
    scanf("%s", status.current_province);

    printf("Are you a resident of Canada in current tax filing year? (y/n)");
    scanf("%s", status.is_resident_in_tax_filing_year);

    
    cJSON *status_object = cJSON_CreateObject();

    cJSON_AddItemToObject(status_object, DATE_OF_ENTRY, cJSON_CreateString(status.date_of_entry));
    cJSON_AddItemToObject(status_object, CURRENT_PROVINCE, cJSON_CreateString(status.current_province));
    cJSON_AddItemToObject(status_object, IS_RESIDENT_IN_TAX_FILING_YEAR, cJSON_CreateString(status.is_resident_in_tax_filing_year));
   

    cJSON_AddItemToObject(root, ENTRY_STATUS_KEY, status_object);

    return 0;
}

#include "headers/maritial_status.h"
#include<string.h>

int input_maritial_status(cJSON *root) {
    maritial_status m_status;
    printf("\n#######################################################################################\n");
    printf("Enter Details for your Maritial Status as of 31st December 2019\n");
    printf("\n#######################################################################################\n");

    printf("\nEnter your Current Maritial Status:");
    scanf("%s", m_status.current_maritial_status);

    printf("\nIs change of Maritial Status in tax filing year? (y/n) :");
    scanf("%s", m_status.is_change_of_status);

    if(strcmp(m_status.is_change_of_status,"y")==0) {
        printf("\nEnter Date of change in status (YYYY-MM-DD):");
        scanf("%s", m_status.date_of_change);
    }

    
    cJSON *m_status_object = cJSON_CreateObject();

    cJSON_AddItemToObject(m_status_object, CURRENT_MARITIAL_STATUS, cJSON_CreateString(m_status.current_maritial_status));
    cJSON_AddItemToObject(m_status_object, IS_CHANGE_OF_STATUS, cJSON_CreateString(m_status.is_change_of_status));
    cJSON_AddItemToObject(m_status_object, DATE_OF_CHANGE, cJSON_CreateString(m_status.date_of_change));
   

    cJSON_AddItemToObject(root, MARITIAL_STATUS_KEY, m_status_object);

    return 0;
}

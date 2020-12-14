#ifndef GROUP_A_TAXFILINGSOFTWARE_COMMONS_H
#define GROUP_A_TAXFILINGSOFTWARE_COMMONS_H

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


#endif //GROUP_A_TAXFILINGSOFTWARE_COMMONS_H

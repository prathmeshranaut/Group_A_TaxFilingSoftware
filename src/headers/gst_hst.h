#include "cJSON.h"
#include <stdio.h>

#ifndef GROUP_A_TAXFILINGSOFTWARE_GST_HST_H
#define GROUP_A_TAXFILINGSOFTWARE_GST_HST_H

#define GST_HST_KEY "gst_hst"
#define GST_HST_CREDIT "gst_hst_credit"

typedef struct {
    double gst_hst_credit;
} gst_hst;

int calculate_gst_hst_benefits(cJSON *root);

#endif //GROUP_A_TAXFILINGSOFTWARE_GST_HST_H
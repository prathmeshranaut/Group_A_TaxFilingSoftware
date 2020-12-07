#include <stdio.h>
#include "cJSON.h"
#include "commons.h"
#include <string.h>
#include "new_taxfile.h"
#include "primary_address.h"
#include "t4.h"
#include "mailing_address.h"
#include "new_taxfile.h"
#include "calculate_tax.h"
#include "entry_status.h"
#include "maritial_status.h"
#include "world_income.h"
#include "t2202.h"
#include "spouse_details.h"
#include "dependent_details.h"
#include <stdlib.h>
#include "../../include/pdfgen.h"

#ifndef GROUP_A_TAXFILINGSOFTWARE_GENERATE_PDF_H
#define GROUP_A_TAXFILINGSOFTWARE_GENERATE_PDF_H

int generate_pdf(cJSON *root);

void add_string_to_pdf(cJSON *object, char *key, char *name, struct pdf_doc *pdf, int *y_offset);

void add_long_to_pdf(cJSON *object, char *key, char *name, struct pdf_doc *pdf, int *y_offset);

#endif

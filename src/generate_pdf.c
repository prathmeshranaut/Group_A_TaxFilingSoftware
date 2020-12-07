/**
 * @file generate_pdf.c
 *
 * @brief Generate the PDF
 * @author Prathmesh Ranaut
 * */

#include "headers/generate_pdf.h"

/** @brief Generates the PDF file from tax data
 *
 * @detail Uses the JSON root object to generate a PDF for the user so he can easily verify and keep details for future
 *
 * @param[in,out] JSON root element
 *
 * @return 0 in case of success or 1 in case of failure
 * */

int generate_pdf(cJSON *root) {
    if (root == NULL) {
        return 1;
    }

    cJSON *personal_details_object = cJSON_GetObjectItem(root, "basic");
    cJSON *mailing_address_object = cJSON_GetObjectItem(root, MAILING_ADDRESS_KEY);
    cJSON *primary_address_object = cJSON_GetObjectItem(root, PRIMARY_ADDRESS_KEY);
    cJSON *entry_status_object = cJSON_GetObjectItem(root, ENTRY_STATUS_KEY);
    cJSON *world_income_object = cJSON_GetObjectItem(root, WORLD_INCOME_KEY);
    cJSON *maritial_status_object = cJSON_GetObjectItem(root, MARITIAL_STATUS_KEY);

    cJSON *t4_array = cJSON_GetObjectItem(root, T4_KEY);
    cJSON *t4_details = cJSON_GetArrayItem(t4_array, 0);

    cJSON *t2202_details = cJSON_GetObjectItem(root, T2202_KEY);

    struct pdf_info info = {
            .creator = "Tax Filing Software",
            .producer = "Tax Filing Software",
            .title = "Tax Details",
            .author = "Group A",
            .date = "Today"
    };
    struct pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, &info);
    pdf_set_font(pdf, "Times-Roman");
    pdf_append_page(pdf);
    pdf_add_text(pdf, NULL, "Tax Details", 18, 250, 780, PDF_BLACK);

    int *y_offset = malloc(sizeof(int));
    *y_offset = 740;
    /**
     * Personal Details
     */
    add_string_to_pdf(personal_details_object, FIRST_NAME, "First Name", pdf, y_offset);
    add_string_to_pdf(personal_details_object, LAST_NAME, "Last Name", pdf, y_offset);
    add_string_to_pdf(personal_details_object, EMAIL, "Email", pdf, y_offset);
    add_string_to_pdf(personal_details_object, SIN, "SIN", pdf, y_offset);
    add_string_to_pdf(personal_details_object, DATE_OF_BIRTH, "Date of Birth", pdf, y_offset);

    /**
     * Mailing Address
     */
    add_string_to_pdf(mailing_address_object, MAILING_STREET_NUMBER, "Street Number", pdf, y_offset);
    add_string_to_pdf(mailing_address_object, MAILING_STREET_NAME, "Street Name", pdf, y_offset);
    add_string_to_pdf(mailing_address_object, MAILING_CITY, "City", pdf, y_offset);
    add_string_to_pdf(mailing_address_object, MAILING_PROVINCE, "Province", pdf, y_offset);
    add_string_to_pdf(mailing_address_object, MAILING_POSTAL_CODE, "Postal Code", pdf, y_offset);
    add_string_to_pdf(mailing_address_object, MAILING_CONTACT_NUMBER, "Contact Number", pdf, y_offset);


    /**
     * Primary Residence
     */
    add_string_to_pdf(primary_address_object, STREET_NUMBER, "Street Number", pdf, y_offset);
    add_string_to_pdf(primary_address_object, STREET_NAME, "Street Name", pdf, y_offset);
    add_string_to_pdf(primary_address_object, CITY, "City", pdf, y_offset);
    add_string_to_pdf(primary_address_object, PROVINCE, "Province", pdf, y_offset);
    add_string_to_pdf(primary_address_object, POSTAL_CODE, "Postal Code", pdf, y_offset);

    /**
     * Entry Status
     */
    add_string_to_pdf(entry_status_object, DATE_OF_ENTRY, "Date of Entry", pdf, y_offset);
    add_string_to_pdf(entry_status_object, CURRENT_PROVINCE, "Current Province", pdf, y_offset);
    add_string_to_pdf(entry_status_object, IS_RESIDENT_IN_TAX_FILING_YEAR, "Is Resident in tax filing year", pdf, y_offset);


    /**
     * World Income (Long)
     */
    add_long_to_pdf(world_income_object, CANADIAN_SOURCE_OF_INCOME, "Canadian Source of Income", pdf, y_offset);
    add_long_to_pdf(world_income_object, FOREIGN_SOURCE_OF_INCOME, "Foreign Source of Income Province", pdf, y_offset);

    /**
     * Martial Status
     */
    add_string_to_pdf(maritial_status_object, CURRENT_MARITIAL_STATUS, "Current Martial Status", pdf, y_offset);
    add_string_to_pdf(maritial_status_object, IS_CHANGE_OF_STATUS, "Is change of status", pdf, y_offset);
    add_string_to_pdf(maritial_status_object, DATE_OF_CHANGE, "Date of Change", pdf, y_offset);

    /**
     * T4 Details
     */
    add_string_to_pdf(t4_details, EMPLOYER_NAME, "Employer Name", pdf, y_offset);
    add_string_to_pdf(t4_details, PROVINCE, "Province", pdf, y_offset);
    add_long_to_pdf(t4_details, EMPLOYMENT_INCOME, "Employment Income", pdf, y_offset);
    add_long_to_pdf(t4_details, EMPLOYEES_CPP_CONTRIBUTION, "CPP Contribution", pdf, y_offset);
    add_long_to_pdf(t4_details, EMPLOYEES_QPP_CONTRIBUTION, "QPP Contribution", pdf, y_offset);
    add_long_to_pdf(t4_details, EMPLOYEES_EI_PREMIUMS, "EI Premium", pdf, y_offset);
    add_long_to_pdf(t4_details, RPP_CONTRIBUTIONS, "RPP Contribution", pdf, y_offset);
    add_long_to_pdf(t4_details, INCOME_TAX_DEDUCTED, "Income Tax Deducted", pdf, y_offset);
    add_long_to_pdf(t4_details, EI_INSURABLE_EARNINGS, "EI Insurable Earnings", pdf, y_offset);
    add_long_to_pdf(t4_details, CPP_QPP_PENSIONABLE_EARNINGS, "CCP/QPP Pensionable earning", pdf, y_offset);
    add_long_to_pdf(t4_details, UNION_DUES, "Union Dues", pdf, y_offset);
    add_long_to_pdf(t4_details, CHARITABLE_DONATIONS, "Charitable Donations", pdf, y_offset);
    add_long_to_pdf(t4_details, RPP_DSSP_REGISTRATION_NUMBER, "RPP/DSSP Regisration Number", pdf, y_offset);
    add_long_to_pdf(t4_details, PENSION_ADJUSTMENT, "Pension adjustment", pdf, y_offset);
    add_long_to_pdf(t4_details, EMPLOYEES_PPIP_PREMIUMS, "Employees PPIP Premiums", pdf, y_offset);
    add_long_to_pdf(t4_details, PPIP_INSURABLE_EARNINGS, "PPIP Insurable Earnings", pdf, y_offset);

    /**
     * T2202 Details
     */
    add_string_to_pdf(t2202_details, INSTITUTION_NAME, "Institution Name", pdf, y_offset);
    add_string_to_pdf(t2202_details, SCHOOL_TYPE, "School Type", pdf, y_offset);
    add_string_to_pdf(t2202_details, STUDENT_NUMBER, "Student Number", pdf, y_offset);
    add_string_to_pdf(t2202_details, COURSE, "Course", pdf, y_offset);
    add_string_to_pdf(t2202_details, SESSION, "Session", pdf, y_offset);
    add_long_to_pdf(t2202_details, AMOUNT, "Amount", pdf, y_offset);

    pdf_save(pdf, "tax_details.pdf");


    int *err = NULL;

    if (pdf_get_err(pdf, err)) {
        pdf_destroy(pdf);
        return 1;
    }

    pdf_destroy(pdf);

    return 0;
}

void add_long_to_pdf(cJSON *object, char *key, char *name, struct pdf_doc *pdf, int *y_offset) {
    if (object == NULL) {
        return;
    }

    cJSON *detail_object = cJSON_GetObjectItem(object, key);
    if (detail_object != NULL && cJSON_IsNumber(detail_object)) {
        char *value = malloc(1024 * sizeof(char));
        sprintf(value, "%s: %0.2lf", name, detail_object->valuedouble);
        pdf_add_text(pdf, NULL,
                     value, 12,
                     50, *y_offset, PDF_BLACK);
        *y_offset = *y_offset - 20;
    }

    if (*y_offset < 40) {
        pdf_append_page(pdf);
        *y_offset = 740;
    }
}

void add_string_to_pdf(cJSON *object, char *key, char *name, struct pdf_doc *pdf, int *y_offset) {
    if (object == NULL) {
        return;
    }

    cJSON *detail_object = cJSON_GetObjectItem(object, key);
    if (detail_object != NULL && detail_object->valuestring != NULL) {
        char *value = malloc(1024 * sizeof(char));
        sprintf(value, "%s: %s", name, detail_object->valuestring);
        pdf_add_text(pdf, NULL,
                     value, 12,
                     50, *y_offset, PDF_BLACK);
        *y_offset = *y_offset - 20;
    }

    if (*y_offset < 40) {
        pdf_append_page(pdf);
        *y_offset = 740;
    }
}
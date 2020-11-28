#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/calculate_tax.h"
#include "headers/t4.h"
#include "headers/t2202.h"



int calculate_tax(cJSON* root)
{
	cJSON* t4_object = cJSON_GetObjectItem(root, T4_KEY);
	cJSON* first_t4_details = cJSON_GetArrayItem(t4_object, 0);
	cJSON* t2202_object = cJSON_GetObjectItem(root, T2202_KEY);
	cJSON* first_t2202_details = cJSON_GetArrayItem(t2202_object, 0);

	cJSON* json;
	double c_employment_income = 0;
	double c_income_tax_deducted = 0;
	double c_federal_tax = 0;
	double c_income_tax = 0;
	double c_provencial_tax = 0;
	double c_refund = 0;
	double c_payable = 0;
	double c_tuition =0;

	tax worker;

	json = root;	//Convert text string to cJSON object
	if (NULL == json)	//If text is not in json format
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}

	c_employment_income = cJSON_GetObjectItem(first_t4_details, EMPLOYMENT_INCOME)->valuedouble;
	c_income_tax_deducted = cJSON_GetObjectItem(first_t4_details, INCOME_TAX_DEDUCTED)->valuedouble;
	c_tuition = cJSON_GetObjectItem(first_t2202_details, AMOUNT )->valuedouble;

	if (c_income_tax <= 0)
	{
		if (c_employment_income <= 47630.00)
		{
			c_federal_tax = 0.15 * c_employment_income;
		}
		else if (c_employment_income > 47630.00 && c_employment_income <= 95259.00)
		{
			c_federal_tax = 7144.5 + (0.205 * (c_employment_income - 47630.00));
		}
		else if (c_employment_income > 95259.00 && c_employment_income <= 147667.00)
		{
			c_federal_tax = 16670.3 + (0.26 * (c_employment_income - 95259.00));
		}
		else if (c_employment_income > 147667.00 && c_employment_income <= 210371.00)
		{
			c_federal_tax = 30296.38 + (0.29 * (c_employment_income - 147667.00));
		}
		else if (c_employment_income > 210371.00)
		{
			c_federal_tax = 48480.5 + (0.33 * (c_employment_income - 210371.00));
		}

		if (c_employment_income <= 43906.00)
		{
			c_provencial_tax = 0.0505 * c_employment_income;
		}
		else if (c_employment_income > 43906.00 && c_employment_income <= 87812.00)
		{
			c_provencial_tax = 2217.253 + (0.0915 * (c_employment_income - 43906.00));
		}
		else if (c_employment_income > 87812.00 && c_employment_income <= 149999)
		{
			c_provencial_tax = 6234.929 + (0.1116 * (c_employment_income - 87812.00));
		}
		else if (c_employment_income > 149999.00 && c_employment_income <= 219999.00)
		{
			c_provencial_tax = 13174.9982 + (0.1216 * (c_employment_income - 149999.00));
		}
		else if (c_employment_income > 219999.00)
		{
			c_provencial_tax = 42126.9982 + (0.1316 * (c_employment_income - 149999.00));
		}


		c_income_tax = c_federal_tax + c_provencial_tax - c_income_tax_deducted;
		printf("\n\n\tThe income tax is calculated as %f\n", c_income_tax);

		if (c_income_tax <= (12069+c_tuition))
		{
			c_refund = c_income_tax;
		}

		else if (c_income_tax > (12069+c_tuition))
		{
			c_payable = c_income_tax - 12069 - c_tuition;
		}

	}

	char* out = NULL;

	if (!root)
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		cJSON* obj_person = cJSON_CreateObject();

		worker.federal_tax = c_federal_tax;
		worker.income_tax = c_income_tax;
		worker.provencial_tax = c_provencial_tax;
		worker.refund = c_refund;
		worker.payable = c_payable;

		cJSON* item = cJSON_CreateNumber(worker.federal_tax);
		cJSON_AddItemToObject(obj_person, "federal_tax", item);

		item = cJSON_CreateNumber(worker.income_tax);
		cJSON_AddItemToObject(obj_person, "income_tax", item);

		item = cJSON_CreateNumber(worker.provencial_tax);
		cJSON_AddItemToObject(obj_person, "provencial_tax", item);

		item = cJSON_CreateNumber(worker.refund);
		cJSON_AddItemToObject(obj_person, "refund", item);

		item = cJSON_CreateNumber(worker.payable);
		cJSON_AddItemToObject(obj_person, "payable", item);

		cJSON_AddItemToObject(root, "tax", obj_person);

	}
	return 0;

}

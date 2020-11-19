#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/calculate_tax.h"

int calculate_tax(cJSON* root)
{

	cJSON* json,* json_t4,* json_employment_income,* json_income_tax_deducted;//,* json_employees_cpp_contribution,* json_employees_ei_premiums,* json_rpp_contributions,* json_charitable_donations
	double c_employment_income; //14
	//double c_employees_cpp_contribution; //16
	//double c_employees_qpp_contribution; //17
	//double c_employees_ei_premiums; // 18
	//double c_rpp_contributions; //20
	double c_income_tax_deducted; //22
	//double c_ei_insurable_earnings; //24
	//double c_cpp_qpp_pensionable_earnings; //26
	//double c_union_dues; //44
	//double c_charitable_donations; //46
	//double c_rpp_dssp_registation_number; //50
	//double c_pension_adjustment; //52
	//double c_employees_ppip_premiums; //55
	//double c_ppip_insurable_earnings; //56
	double c_federal_tax	= 0;
	double c_income_tax		= 0;
	double c_provencial_tax = 0;
	double c_refund			= 0;
	double c_payable		= 0;

	tax worker;

	json = root;	//Convert text string to cJSON object
	if (NULL == json)	//If text is not in json format
	{
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}

	json_t4 = cJSON_GetObjectItem(root, "t4");
	
	json_employment_income =  cJSON_GetObjectItem(json_t4, "employment_income");
	c_employment_income = json_employment_income->valueint;
	//json_employees_cpp_contribution =  cJSON_GetObjectItem(json_t4, "employees_cpp_contribution");
	//c_employees_cpp_contribution = json_employees_cpp_contribution->valueint;
	//json_employees_ei_premiums =  cJSON_GetObjectItem(json_t4, "employees_ei_premiums");
	//c_employees_ei_premiums = json_employees_ei_premiums->valueint;
	//json_employees_ei_premiums =  cJSON_GetObjectItem(json_t4, "employees_ei_premiums");
	//c_employees_ei_premiums = json_employees_ei_premiums->valueint;
	//json_rpp_contributions =  cJSON_GetObjectItem(json_t4, "rpp_contributions");
	//c_rpp_contributions = json_rpp_contributions->valueint;
	json_income_tax_deducted =  cJSON_GetObjectItem(json_t4, "income_tax_deducted");
	c_income_tax_deducted = json_income_tax_deducted->valueint;
	//json_charitable_donations =  cJSON_GetObjectItem(json_t4, "charitable_donations");
	//c_charitable_donations = json_charitable_donations->valueint;
	/*
	c_employment_income = 98000.00;
	c_employees_cpp_contribution = 2000.00;
	c_employees_ei_premiums = 860.22;
	c_rpp_contributions = 320;
	c_income_tax_deducted = 230;
	c_charitable_donations = 200;
	*/
	if (c_income_tax <= 0)
	{
		if (c_employment_income <= 47630.00)
		{
			c_federal_tax	= 0.15 * c_employment_income;
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

		if (c_income_tax <= 12069)
		{
			c_refund = c_income_tax;
		}

		else if (c_income_tax > 12069)
		{
			c_payable = c_income_tax-12069;
		}

	}

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
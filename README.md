# Tax_Filing_Software

Tax_Filing_Software is a software that helps students in Ontario, CA to file taxes for the year 2019 with the maximum benefits.

# Authors

- Prathmesh Ranaut - Carleton University
- Ragunath Anbarasu - Carleton University
- Shreya Dhanani  - Carleton University
- Tirth Vyas - Carleton University

# Installation

Installation steps are mentioned in [User_Manual.md](https://github.com/prathmeshranaut/Group_A_TaxFilingSoftware/wiki/User_Manual)

# Usage

To run, you must first compile the repository. Follow the instructions in [User_Manual.md](https://github.com/prathmeshranaut/Group_A_TaxFilingSoftware/wiki/User_Manual).

# File Structure

The correct file structure

```
|   .gitignore
|   Doxyfile
|   INSTALL.md
|   LICENSE
|   Makefile
|   output.doc
|   output.txt
|   README.md
|   tax_details.pdf
|   test.log
|   
+---bin
|       tax.exe
|       
+---build
|       cJSON.o
|       pdfgen.o
|       tax_test.exe
|       unity.o
|       
+---data
|       guide_basic.dat
|       guide_child.dat
|       guide_hst.dat
|       guide_otb.dat
|       taxfile_new.json
|       
+---doc
|       Tax_filing_software-Page-final.jpg
|       
+---docs
|   +---html
|   |   |   annotated.html
|   |   |   bc_s.png
|   |   |   bdwn.png
|   |   |   calcualte__otbenefits_8c_source.html
|   |   |   calculate__gst__hst__benefits_8c_source.html
|   |   |   calculate__tax_8c.html
|   |   |   calculate__tax_8c_source.html
|   |   |   calculate__tax_8h_source.html
|   |   |   classes.html
|   |   |   closed.png
|   |   |   commons_8c.html
|   |   |   commons_8c_source.html
|   |   |   commons_8h_source.html
|   |   |   common_8h_source.html
|   |   |   create__new__taxfile_8c.html
|   |   |   create__new__taxfile_8c_source.html
|   |   |   c_j_s_o_n_8c_source.html
|   |   |   c_j_s_o_n_8h_source.html
|   |   |   dependent__details_8c.html
|   |   |   dependent__details_8c_source.html
|   |   |   dependent__details_8h_source.html
|   |   |   dir_68267d1309a1af8e8297ef4c3efbcdba.html
|   |   |   dir_d0381950fc41278198232cb047ffc1f9.html
|   |   |   dir_d44c64559bbebec7f509842c48db8b23.html
|   |   |   display__guide_8c.html
|   |   |   display__guide_8c_source.html
|   |   |   doc.png
|   |   |   doxygen.css
|   |   |   doxygen.svg
|   |   |   dynsections.js
|   |   |   entry__status_8c.html
|   |   |   entry__status_8c_source.html
|   |   |   entry__status_8h_source.html
|   |   |   files.html
|   |   |   folderclosed.png
|   |   |   folderopen.png
|   |   |   functions.html
|   |   |   functions_vars.html
|   |   |   generate__pdf_8c.html
|   |   |   generate__pdf_8c_source.html
|   |   |   generate__pdf_8h_source.html
|   |   |   globals.html
|   |   |   globals_defs.html
|   |   |   globals_eval.html
|   |   |   globals_func.html
|   |   |   group__subsystem.html
|   |   |   gst__hst_8h_source.html
|   |   |   index.html
|   |   |   input__mailing__address_8c.html
|   |   |   input__mailing__address_8c_source.html
|   |   |   input__new___tax_file_8c_source.html
|   |   |   jquery.js
|   |   |   mailing__address_8h_source.html
|   |   |   main_8c.html
|   |   |   main_8c_source.html
|   |   |   maritial__status_8c.html
|   |   |   maritial__status_8c_source.html
|   |   |   maritial__status_8h_source.html
|   |   |   md__i_n_s_t_a_l_l.html
|   |   |   md__r_e_a_d_m_e.html
|   |   |   menu.js
|   |   |   menudata.js
|   |   |   modules.html
|   |   |   nav_f.png
|   |   |   nav_g.png
|   |   |   nav_h.png
|   |   |   new__taxfile_8h_source.html
|   |   |   open.png
|   |   |   ot__benefits_8c_source.html
|   |   |   ot__benefits_8h_source.html
|   |   |   pages.html
|   |   |   pdfgen_8c_source.html
|   |   |   pdfgen_8h.html
|   |   |   pdfgen_8h_source.html
|   |   |   primary__address_8c.html
|   |   |   primary__address_8c_source.html
|   |   |   primary__address_8h_source.html
|   |   |   splitbar.png
|   |   |   spouse__details_8c.html
|   |   |   spouse__details_8c_source.html
|   |   |   spouse__details_8h_source.html
|   |   |   structbasic-members.html
|   |   |   structbasic.html
|   |   |   structc_j_s_o_n-members.html
|   |   |   structc_j_s_o_n.html
|   |   |   structc_j_s_o_n___hooks-members.html
|   |   |   structc_j_s_o_n___hooks.html
|   |   |   structdependent__details-members.html
|   |   |   structdependent__details.html
|   |   |   structdstr-members.html
|   |   |   structdstr.html
|   |   |   structentry__status-members.html
|   |   |   structentry__status.html
|   |   |   structerror-members.html
|   |   |   structerror.html
|   |   |   structflexarray-members.html
|   |   |   structflexarray.html
|   |   |   structgst__hst-members.html
|   |   |   structgst__hst.html
|   |   |   structinternal__hooks-members.html
|   |   |   structinternal__hooks.html
|   |   |   structmailing__address-members.html
|   |   |   structmailing__address.html
|   |   |   structmaritial__status-members.html
|   |   |   structmaritial__status.html
|   |   |   structotb__calculate-members.html
|   |   |   structotb__calculate.html
|   |   |   structot__benefits-members.html
|   |   |   structot__benefits.html
|   |   |   structparse__buffer-members.html
|   |   |   structparse__buffer.html
|   |   |   structpdf__doc-members.html
|   |   |   structpdf__doc.html
|   |   |   structpdf__info-members.html
|   |   |   structpdf__info.html
|   |   |   structpdf__object-members.html
|   |   |   structpdf__object.html
|   |   |   structpdf__path__operation-members.html
|   |   |   structpdf__path__operation.html
|   |   |   structprimary__address-members.html
|   |   |   structprimary__address.html
|   |   |   structprintbuffer-members.html
|   |   |   structprintbuffer.html
|   |   |   structspouse__details-members.html
|   |   |   structspouse__details.html
|   |   |   structt2202-members.html
|   |   |   structt2202.html
|   |   |   structt4-members.html
|   |   |   structt4.html
|   |   |   structtax-members.html
|   |   |   structtax.html
|   |   |   structworld__income-members.html
|   |   |   structworld__income.html
|   |   |   struct_m_y_d_a_y-members.html
|   |   |   struct_m_y_d_a_y.html
|   |   |   sync_off.png
|   |   |   sync_on.png
|   |   |   t2202_8c.html
|   |   |   t2202_8c_source.html
|   |   |   t2202_8h_source.html
|   |   |   t4_8c.html
|   |   |   t4_8c_source.html
|   |   |   t4_8h_source.html
|   |   |   tabs.css
|   |   |   tab_a.png
|   |   |   tab_b.png
|   |   |   tab_h.png
|   |   |   tab_s.png
|   |   |   tax__summary_8c.html
|   |   |   tax__summary_8c_source.html
|   |   |   world__income_8c_source.html
|   |   |   world__income_8h_source.html
|   |   |   
|   |   \---search
|   |           all_0.html
|   |           all_0.js
|   |           all_1.html
|   |           all_1.js
|   |           all_2.html
|   |           all_2.js
|   |           all_3.html
|   |           all_3.js
|   |           all_4.html
|   |           all_4.js
|   |           all_5.html
|   |           all_5.js
|   |           all_6.html
|   |           all_6.js
|   |           all_7.html
|   |           all_7.js
|   |           all_8.html
|   |           all_8.js
|   |           all_9.html
|   |           all_9.js
|   |           all_a.html
|   |           all_a.js
|   |           all_b.html
|   |           all_b.js
|   |           all_c.html
|   |           all_c.js
|   |           all_d.html
|   |           all_d.js
|   |           all_e.html
|   |           all_e.js
|   |           all_f.html
|   |           all_f.js
|   |           classes_0.html
|   |           classes_0.js
|   |           classes_1.html
|   |           classes_1.js
|   |           classes_2.html
|   |           classes_2.js
|   |           classes_3.html
|   |           classes_3.js
|   |           classes_4.html
|   |           classes_4.js
|   |           classes_5.html
|   |           classes_5.js
|   |           classes_6.html
|   |           classes_6.js
|   |           classes_7.html
|   |           classes_7.js
|   |           classes_8.html
|   |           classes_8.js
|   |           classes_9.html
|   |           classes_9.js
|   |           classes_a.html
|   |           classes_a.js
|   |           classes_b.html
|   |           classes_b.js
|   |           classes_c.html
|   |           classes_c.js
|   |           close.svg
|   |           defines_0.html
|   |           defines_0.js
|   |           enumvalues_0.html
|   |           enumvalues_0.js
|   |           files_0.html
|   |           files_0.js
|   |           files_1.html
|   |           files_1.js
|   |           files_2.html
|   |           files_2.js
|   |           files_3.html
|   |           files_3.js
|   |           files_4.html
|   |           files_4.js
|   |           files_5.html
|   |           files_5.js
|   |           files_6.html
|   |           files_6.js
|   |           files_7.html
|   |           files_7.js
|   |           files_8.html
|   |           files_8.js
|   |           functions_0.html
|   |           functions_0.js
|   |           functions_1.html
|   |           functions_1.js
|   |           functions_2.html
|   |           functions_2.js
|   |           functions_3.html
|   |           functions_3.js
|   |           functions_4.html
|   |           functions_4.js
|   |           functions_5.html
|   |           functions_5.js
|   |           groups_0.html
|   |           groups_0.js
|   |           mag_sel.svg
|   |           nomatches.html
|   |           pages_0.html
|   |           pages_0.js
|   |           pages_1.html
|   |           pages_1.js
|   |           search.css
|   |           search.js
|   |           searchdata.js
|   |           search_l.png
|   |           search_m.png
|   |           search_r.png
|   |           variables_0.html
|   |           variables_0.js
|   |           variables_1.html
|   |           variables_1.js
|   |           variables_2.html
|   |           variables_2.js
|   |           variables_3.html
|   |           variables_3.js
|   |           variables_4.html
|   |           variables_4.js
|   |           variables_5.html
|   |           variables_5.js
|   |           variables_6.html
|   |           variables_6.js
|   |           variables_7.html
|   |           variables_7.js
|   |           variables_8.html
|   |           variables_8.js
|   |           
|   +---latex
|   |       annotated.tex
|   |       calculate__tax_8c.tex
|   |       commons_8c.tex
|   |       create__new__taxfile_8c.tex
|   |       dependent__details_8c.tex
|   |       display__guide_8c.tex
|   |       doxygen.sty
|   |       entry__status_8c.tex
|   |       files.tex
|   |       generate__pdf_8c.tex
|   |       group__subsystem.tex
|   |       input__mailing__address_8c.tex
|   |       longtable_doxygen.sty
|   |       main_8c.tex
|   |       Makefile
|   |       maritial__status_8c.tex
|   |       md__i_n_s_t_a_l_l.tex
|   |       md__r_e_a_d_m_e.tex
|   |       modules.tex
|   |       pdfgen_8h.tex
|   |       primary__address_8c.tex
|   |       refman.tex
|   |       spouse__details_8c.tex
|   |       structbasic.tex
|   |       structc_j_s_o_n.tex
|   |       structc_j_s_o_n___hooks.tex
|   |       structdependent__details.tex
|   |       structdstr.tex
|   |       structentry__status.tex
|   |       structerror.tex
|   |       structflexarray.tex
|   |       structgst__hst.tex
|   |       structinternal__hooks.tex
|   |       structmailing__address.tex
|   |       structmaritial__status.tex
|   |       structotb__calculate.tex
|   |       structot__benefits.tex
|   |       structparse__buffer.tex
|   |       structpdf__doc.tex
|   |       structpdf__info.tex
|   |       structpdf__object.tex
|   |       structpdf__path__operation.tex
|   |       structprimary__address.tex
|   |       structprintbuffer.tex
|   |       structspouse__details.tex
|   |       structt2202.tex
|   |       structt4.tex
|   |       structtax.tex
|   |       structworld__income.tex
|   |       struct_m_y_d_a_y.tex
|   |       t2202_8c.tex
|   |       t4_8c.tex
|   |       tabu_doxygen.sty
|   |       tax__summary_8c.tex
|   |       
|   \---man
|       \---man3
|               basic.3
|               calculate_tax.c.3
|               cJSON.3
|               cJSON_Hooks.3
|               commons.c.3
|               create_new_taxfile.c.3
|               dependent_details.3
|               dependent_details.c.3
|               display_guide.c.3
|               dstr.3
|               entry_status.3
|               entry_status.c.3
|               error.3
|               flexarray.3
|               generate_pdf.c.3
|               gst_hst.3
|               input_mailing_address.c.3
|               internal_hooks.3
|               mailing_address.3
|               main.c.3
|               maritial_status.3
|               maritial_status.c.3
|               md__i_n_s_t_a_l_l.3
|               md__r_e_a_d_m_e.3
|               MYDAY.3
|               otb_calculate.3
|               ot_benefits.3
|               parse_buffer.3
|               pdfgen.h.3
|               pdf_doc.3
|               pdf_info.3
|               pdf_object.3
|               pdf_path_operation.3
|               primary_address.3
|               primary_address.c.3
|               printbuffer.3
|               spouse_details.3
|               spouse_details.c.3
|               subsystem.3
|               t2202.3
|               t2202.c.3
|               t4.3
|               t4.c.3
|               tax.3
|               tax_summary.c.3
|               world_income.3
|               
+---include
|       cJSON.c
|       cJSON.h
|       common.h
|       pdfgen.c
|       pdfgen.h
|       
+---src
|   |   calcualte_otbenefits.c
|   |   calculate_gst_hst_benefits.c
|   |   calculate_tax.c
|   |   commons.c
|   |   create_new_taxfile.c
|   |   dependent_details.c
|   |   display_guide.c
|   |   entry_status.c
|   |   generate_pdf.c
|   |   input_mailing_address.c
|   |   input_new_TaxFile.c
|   |   main.c
|   |   maritial_status.c
|   |   ot_benefits.c
|   |   primary_address.c
|   |   spouse_details.c
|   |   t2202.c
|   |   t4.c
|   |   tax_summary.c
|   |   world_income.c
|   |   
|   \---headers
|           calculate_tax.h
|           commons.h
|           dependent_details.h
|           entry_status.h
|           generate_pdf.h
|           gst_hst.h
|           mailing_address.h
|           maritial_status.h
|           new_taxfile.h
|           ot_benefits.h
|           primary_address.h
|           spouse_details.h
|           t2202.h
|           t4.h
|           world_income.h
|           
\---test
    +---data
    |       basic_details_1.txt
    |       dependent_1.txt
    |       entry_status_1.txt
    |       mailing_address_1.txt
    |       maritial_status_1.txt
    |       primary_address_1.txt
    |       spouse_1.txt
    |       t2202_1.txt
    |       t4_1.txt
    |       t4_2.txt
    |       world_income_1.txt
    |       
    +---include
    |       unity.c
    |       unity.h
    |       unity_internals.h
    |       
    \---src
        |   basic_details.c
        |   dependent_details.c
        |   entry_status.c
        |   mailing_details.c
        |   maritial_status.c
        |   primary_address.c
        |   runner.c
        |   spouse_details.c
        |   t2202.c
        |   t4.c
        |   world_income.c
        |   
        \---headers
                runner.h
                

```

# For Developers

The developer manual is available [here](https://github.com/prathmeshranaut/Group_A_TaxFilingSoftware/wiki/Developer-Manual).

# License

This project is licensed under the GPL 2.0 License - see the LICENSE.md file for details

# Acknowledgements

Thank to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.

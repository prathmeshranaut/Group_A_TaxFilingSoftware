# Tax_Filing_Software

Tax_Filing_Software is a software that helps students in Ontario, CA to file taxes for the year 2019 with the maximum benefits.

# Authors

- Prathmesh Ranaut - Carleton University
- Ragunath Anbarasu - Carleton University
- Shreya Dhanani  - Carleton University
- Tirth Vyas - Carleton University

# Installation

Installation steps are mentioned in [INSTALL.md](INSTALL.md)

# Usage

To run, you must first compile the repository. Follow the instructions in [INSTALL.md](INSTALL.md).Then you can follow instructions mentioned in
[User_Manual.md](doc/User_Manual.md).

# File Structure

The correct file structure

```
├── INSTALL.md 	-> Installation Guide
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file
├── doc
│   ├── html 	-> Doxygen documentation
│   ├── latex   -> Doxygen documentation in latex
│   ├── man     -> Doxygen documentation in man
│   ├── rtf     -> Doxygen documentation in rtf
│   ├── xml     -> Doxygen documentation in xml
│   ├── Developer_Manual.md -> Developer Manual
│   ├── Doxyfile -> Doxygen configuration file
│   └── User_Manual.md      -> User Manual
├── include 	-> Header files
│   ├── calculate_tax.h
│   ├── commons.h
│   ├── entry_status.h
│   ├── mailing_address.h
│   ├── maritial_status.h
│   ├── new_taxfile.h
│   ├── primary_address.h
│   ├── t4.h
│   ├── t2202.h
│   └── world_income.h
├── obj 	-> Object files
├── src 	-> Source files for Tax_Filing_Software
│   ├── calculate_tax.c
│   ├── create_new_taxfile.c
│   ├── display_guide.c
│   ├── entry_status.c
│   ├── input_mailing_address.c
│   ├── input_new_taxfile.c
│   ├── main.c
│   ├── maritial_status.c
│   ├── primary_address.c
│   ├── t4.c
│   ├── world_income.c
│   └── input_t2202.c
└── test
│    ├── data
│    │   ├── primary_address_1.txt
│    │   ├── t4_1.txt
│    │   ├── t4_2.txt
│    │   └── main.c
│    ├── include
│    │   ├── unity.c
│    │   ├── unity.h
│    │   ├── unity_internals.h
│    │   └── main.c
│    ├── src
│    │   ├── headers
│    │   │   ├── primary_address.h
│    │   │   ├── runner.h
│    │   │   ├── t4.h
│    │   │   └── commons.h
│    │   ├── primary_address.c
│    │   ├── runner.c
│    │   └── t4.c
│    └──
└──
```

# For Developers

The developer manual is available [here](doc/Developer_Manual.md).

# License

This project is licensed under the GPL 2.0 License - see the LICENSE.md file for details

# Acknowledgements

Thank to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.

// CppSolutions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "question1.h"
#include "question2.h"
#include "question3.h"
#include <stdio.h>

void show_disclaimer() {

    using namespace std;

    cout << "Powell Demo C++ Solutions" << endl
        << "Copyright (c) 2014 Michael W Powell" << endl
        << "Press Enter to proceed through the responses..." << endl << endl;
}

int _tmain(int argc, _TCHAR* argv[]) {

    show_disclaimer();

    q1::implement_stack();

    //DRY
    const std::string name_distinct = "distinct";
    const std::string name_non_distinct = "non distinct";
    const std::string fn_data = "data.txt";
    const std::string fn_data_no_distinct = "data-no-distinct.txt";

    const auto select_distinct = [](const q2::paired_type& a) { return a.second == 1; };
    const auto select_any = [](const q2::paired_type& a) { return true; };

    //SOLID
    q2::read_ints_print_n_largest_numbers(fn_data, name_distinct, select_distinct);
    q2::read_ints_print_n_largest_numbers(fn_data_no_distinct, name_distinct, select_distinct);
    q2::read_ints_print_n_largest_numbers(fn_data, name_non_distinct, select_any);

    auto& int_values = q3::get_int_values();

    q3::bisectional_find_test_ints(int_values, 3);
    q3::bisectional_find_test_ints(int_values, 4);
    q3::bisectional_find_test_ints(int_values, 5);
    q3::bisectional_find_test_ints(int_values, 6);

    auto& string_values = q3::get_string_values();

    q3::bisectional_find_test_strings(string_values, "alpha");
    q3::bisectional_find_test_strings(string_values, "bravo");
    q3::bisectional_find_test_strings(string_values, "foxtrot");
    q3::bisectional_find_test_strings(string_values, "blue");

    return 0;
}


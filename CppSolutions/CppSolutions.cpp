// CppSolutions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "question1.h"
#include "question2.h"

int _tmain(int argc, _TCHAR* argv[])
{
    q1::implement_stack();

    q2::read_ints_print_n_largest_numbers(
        "data.txt", "distinct",
        [](const q2::question_pair& a) { return a.second == 1; });

    q2::read_ints_print_n_largest_numbers(
        "data-no-distinct.txt", "distinct",
        [](const q2::question_pair& a) { return a.second == 1; });

    q2::read_ints_print_n_largest_numbers(
        "data.txt", "non distinct",
        [](const q2::question_pair& a) { return true; });

    return 0;
}


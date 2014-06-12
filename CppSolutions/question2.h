#ifndef QUESTION_2_H
#define QUESTION_2_H

#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <map>
#include <set>

namespace q2 {

    typedef std::map<int, int, std::greater<int> > question_input_map;

    typedef std::set<int, std::less<int> > question_result_set;

    typedef question_input_map::value_type paired_type;

    /// Read the integers and print the N largest numbers.
    /// @fn a file name
    /// @name the name of the exercise
    /// @predicate how to predicate the selection
    void read_ints_print_n_largest_numbers(
        const std::string fn,
        const std::string name,
        std::function<bool(const paired_type&)> predicate);
}

#endif //QUESTION_2_H

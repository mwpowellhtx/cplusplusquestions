#ifndef QUESTION_2_H
#define QUESTION_2_H

#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <map>

namespace q2 {

    typedef std::map<int, int> question_map;
    typedef std::pair<int, int> paired_type;

    /// Read the integers and print the N largest numbers.
    /// @fn a file name
    /// @name the name of the exercise
    /// @pp how to predicate the print
    void read_ints_print_n_largest_numbers(
        const std::string fn,
        const std::string name,
        std::function<bool(const paired_type&)> pp);
}

#endif //QUESTION_2_H

#ifndef QUESTION_3_H
#define QUESTION_3_H

#include <string>
#include <vector>
#include <functional>

namespace q3 {

    std::vector<int> get_int_values();

    std::vector<std::string> get_string_values();

    template<typename Iter, typename T>
    Iter bisectional_find(
        Iter begin,
        Iter end,
        const T& value,
        std::function<bool(const T&, const T&)> predicate) {

        //Nowhere else to go in this use case.
        if (begin == end) return end;

        //Also here.
        if ((end - begin) == 1) {
            return predicate(*begin, value) ? begin : end;
        }

        auto half = static_cast<Iter>(begin + (end - begin) / 2);

        if (predicate(*half, value)) return half;

        auto first = bisectional_find(begin, half, value, predicate);

        if (first != half) return first;

        auto next = static_cast<Iter>(half + 1);

        return bisectional_find(next, end, value, predicate);
    }

    template<typename Iter, typename T>
    Iter bisectional_find(
        std::vector<T>& values,
        const T& value,
        std::function<Iter(std::vector<T>&)> begin,
        std::function<Iter(std::vector<T>&)> end,
        std::function<bool(const T&, const T&)> predicate) {

            /* Algorithmically, this is more like a bisection than a binary search.
            http://en.wikipedia.org/wiki/Bisection_method */
            return bisectional_find(begin(values), end(values), value, predicate);
    }

    void bisectional_find_test_ints(std::vector<int>& values, int value_to_find);

    void bisectional_find_test_strings(std::vector<std::string>& values, std::string value_to_find);
}

#endif //QUESTION_3_H

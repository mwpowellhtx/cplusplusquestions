#include "question2.h"

#include <sstream>
#include "cpplinq.hpp"

namespace q2 {

    typedef question_map::value_type question_map_value_type;

    /// Read the next int from stream.
    /// @is an input stream
    /// @value receives the next int value
    /// @returns whether reading should continue
    bool read_int(std::istream& is, int& value) {

        using std::string;
        using std::getline;
        using std::istringstream;
        using std::ios_base;

        string line;

        if (!is) return false;

        getline(is, line);

        if (line.length())
            istringstream(line, ios_base::in) >> value;

        return line.length() > 0;
    }

    void read_ints_print_n_largest_numbers(
        const std::string fn,
        const std::string name,
        std::function<bool(const paired_type&)> pp) {

            using std::ifstream;
            using std::ios_base;
            using namespace cpplinq;
            using std::cout;
            using std::endl;
            using std::getchar;

            try {

                ifstream ifs(fn, ios_base::in);

                int count;

                /* Can work with map after all. It's a bit tricky querying
                 from the elements, but it's perfectly doable. */
                question_map paired;
                
                read_int(ifs, count);
                
                int value;

                while (read_int(ifs, value)) {

                    auto found = paired.find(value);
                    
                    if (found != paired.end()) {
                        found->second++;
                        continue;
                    }
                    
                    paired[value] = 1;
                }

                //Move away from the map and into a selected-vector as soon as possible.
                auto predicated = from(paired) >> select([](const question_map_value_type& p) {
                    return paired_type(p.first, p.second); }) >> where(pp) >> to_vector();
                
                //auto ascending = [](const paired_type& a, const paired_type& b) {
                //    return a.first < b.first;
                //};
                auto descending = [](const paired_type& a, const paired_type& b) {
                    return a.first > b.first;
                };
                // http://en.cppreference.com/w/cpp/algorithm/sort
                //This was correct the first time. To get the largest numbers from the front.
                sort(predicated.begin(), predicated.end(), descending);
                
                auto selected = from(predicated) >> take(count) >> to_vector();

                cout << "The largest " << count << " " << name << " numbers are: ";

                if (!(from(selected) >> any())) {
                    cout << "(there are not any)";
                }
                else {

                    //Which then we want to reverse the selected ones, for ascending order.
                    auto reversed = from(selected) >> reverse() >> to_vector();

                    for (const auto& p : reversed) {
                        cout << p.first << " ";
                    }
                }

                cout << endl;
            }
            catch (...) {
                //TODO: Generally better not to swallow exceptions like this.
            }

            getchar();
    }

}

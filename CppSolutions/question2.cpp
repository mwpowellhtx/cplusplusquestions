#include "question2.h"

#include <sstream>

namespace q2 {

    //obsolete
    typedef question_input_map::value_type question_map_value_type;

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
        std::function<bool(const paired_type&)> predicate) {

            using std::ifstream;
            using std::ios_base;
            using std::cout;
            using std::endl;
            using std::getchar;

            try {

                ifstream ifs(fn, ios_base::in);

                //1) read in the count
                int count;

                read_int(ifs, count);

                //2) tally the ordered values descending key value
                question_input_map paired;

                int value;

                while (read_int(ifs, value)) {

                    auto found = paired.find(value);
                    
                    if (found != paired.end()) {
                        found->second++;
                        continue;
                    }
                    
                    paired[value] = 1;
                }

                //3) capture the ordered results ascending set value
                question_result_set results;

                for (const auto& p : paired) {

                    if (results.size() == count) break;

                    if (!predicate(p)) continue;

                    results.insert(p.first);
                }

                //4) report the response
                cout << "The largest " << count << " " << name << " numbers are: ";

                if (!results.size()) {
                    cout << "(there are not any)";
                }
                else {
                    for (const auto& r : results) {
                        cout << r << " ";
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

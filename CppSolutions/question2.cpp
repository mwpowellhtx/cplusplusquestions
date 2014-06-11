#include "question2.h"

#include <sstream>
#include "cpplinq.hpp"

namespace q2 {

    typedef std::vector<question_pair> question_pair_vector;

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
        std::function<bool(const question_pair&)> pp) {

            using std::ifstream;
            using std::ios_base;
            using namespace cpplinq;
            using std::cout;
            using std::getchar;

            try {

                ifstream ifs(fn, ios_base::in);

                int count;

                /* It's all about trade-offs. But for the follow on questions, std::map
                could be a better initial choice. However, there are a couple of follow
                on questions that operate on vectors. Or potentially needs a LINQ for C++
                bridge. */
                question_pair_vector paired;
                
                read_int(ifs, count);
                
                int value;

                while (read_int(ifs, value)) {
            
                    auto paired_end = paired.end();
                    
                    auto found = find_if(paired.begin(), paired_end,
                        [value](const question_pair& p) { return p.first == value; });
                    
                    if (found != paired_end) {
                        found->second++;
                        continue;
                    }
                    
                    paired.push_back(question_pair(value, 1));
                }

                auto predicated = from(paired) >> where(pp) >> to_vector();
                
                auto ascending = [](const question_pair& a, const question_pair& b) {
                    return a.first < b.first;
                };
                //auto descending = [](const question_pair& a, const question_pair& b) {
                //    return a.first > b.first;
                //};
                // http://en.cppreference.com/w/cpp/algorithm/sort
                sort(predicated.begin(), predicated.end(), ascending);
                
                auto selected = from(predicated) >> take(count) >> to_vector();

                cout << "The largest " << count << " " << name << " numbers are: ";
                        
                if (!(from(selected) >> any())) {
                    cout << "(there are not any)";
                }
                else {
                    for (const auto& p : selected) {
                        cout << p.first << " ";
                    }
                }
            }
            catch (...) {
                //TODO: Generally better not to swallow exceptions like this.
            }

            getchar();
    }

}

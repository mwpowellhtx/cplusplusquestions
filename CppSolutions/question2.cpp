#include "question2.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "future_then.h"

namespace q2 {
    
    result_tallier::result_tallier(std::string name, std::string fn)
        : _name(name), _fn(fn), _count(0), _future() {
    }

    result_tallier::~result_tallier() {
    }

    /// Read the next int from stream.
    /// @is an input stream
    /// @value receives the next int value
    /// @returns whether reading should continue
    bool result_tallier::read_int(std::istream& is, int& value) {

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

    result_tallier::question_input_map result_tallier::load_input(std::string fn) {

            using std::ifstream;
            using std::ios_base;

            question_input_map paired;

            try {

                ifstream ifs(fn, ios_base::in);

                read_int(ifs, this->_count);

                int value;

                while (read_int(ifs, value)) {

                    auto found = paired.find(value);
                    
                    if (found != paired.end()) {
                        found->second++;
                        continue;
                    }

                    paired[value] = 1;
                }
            }
            catch (...) {
                //TODO: Generally better not to swallow exceptions like this.
            }

            return paired;
    }

    result_tallier::question_result_set result_tallier::compile_results(
        const question_input_map& input, selection_func predicate) {

            question_result_set results;

            for (const auto& i : input) {
                
                if (results.size() == this->_count) break;

                if (!predicate(i)) continue;

                results.insert(i.first);
            }
 
            return results;
    }

    void result_tallier::tally(selection_func predicate) {

        using std::async;

        auto fn = this->_fn;

        /* this is not too terrible of an async future nest,
         but would be better to chain using a then paradigm,
         which would also alleviate nested captures, etc */
        this->_future = async([this, fn, predicate]() -> question_result_set {

            auto input = async([this, fn]() -> question_input_map {
                return load_input(fn); });

            //input.wait();

            return compile_results(input.get(), predicate); 
        });

        /* "then" the function can return, and when we're ready to show,
        hopefully the results are waiting for us in the future, if not,
        not far from it */
    }

    void result_tallier::show(std::ostream& os) {

        using namespace std;

        //obtain the result from the future: hopefully not unobtainium
        auto results = this->_future.get();

        os << "The largest " << this->_count << " " << this->_name << " numbers are: ";

        if (!results.size()) {
            os << "(there are not any)";
        }
        else for (const auto& r : results) {
            os << r << " ";
        }

        os << endl;

        getchar();
    }

    ///read integers from file and print the n largest numbers
    /// @name the name of the scenario
    /// @fn a file name
    /// @predicate a predicate
    void read_ints_print_n_largest_numbers(
        std::string fn,
        std::string name,
        result_tallier::selection_func predicate) {

        result_tallier rt(name, fn);

        rt.tally(predicate);

        rt.show(std::cout);
    }
}

#ifndef QUESTION_2_H
#define QUESTION_2_H

#include <memory>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <future>

namespace q2 {

    class result_tallier {

    private:

        typedef std::map<int, int, std::greater<int> > question_input_map;

        typedef std::set<int> question_result_set;

        typedef std::future<question_result_set> result_future;

    public:

        typedef question_input_map::value_type paired_type;
        
        typedef std::function<bool(const paired_type&)> selection_func;

    private:

        ///name
        std::string _name;

        ///filename
        std::string _fn;

        ///count
        int _count;

        //captures the future result
        result_future _future;

    public:

        /// ctor
        /// @name
        /// @fn
        result_tallier(std::string name, std::string fn);

        /// dtor
        virtual ~result_tallier();

    private:

        //private copy ctor
        result_tallier(const result_tallier&) {
        }

    public:

        /// tallies the values
        /// @predicate how to select the results
        void tally(selection_func predicate);

        /// shows the results
        /// @o an output stream
        void show(std::ostream& o);

    private:

        static bool read_int(std::istream& is, int& value);

        question_input_map load_input(std::string fn);

        question_result_set compile_results(const question_input_map& input, selection_func predicate);
    };

    ///read integers from file and print the n largest numbers
    /// @name the name of the scenario
    /// @fn a file name
    /// @predicate a predicate
    void read_ints_print_n_largest_numbers(
        std::string fn,
        std::string name,
        result_tallier::selection_func predicate);

    ///helps with the transparent interface
    typedef result_tallier::paired_type paired_type;
}

#endif //QUESTION_2_H

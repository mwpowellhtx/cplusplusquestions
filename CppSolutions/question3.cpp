#include "question3.h"

#include <iostream>

namespace q3 {

    typedef std::vector<int>::iterator int_vector_iterator;
    typedef std::vector<std::string>::iterator string_vector_iterator;

    std::vector<int> get_int_values() {

        //VS2012: Lack of initializer lists is really hard!
        //std::vector<int> values = { ... };
        std::vector<int> values;
        
        /* TODO: By the same token, sorted list of ints interspersed with 0.
        Isn't it, by definition then, unsorted? Or we include a default case
        to filter out the noise first? */
        if (!values.size()) {
            values.push_back(1);
            values.push_back(2);
            values.push_back(3);
            values.push_back(0);
            values.push_back(0);
            values.push_back(4);
            values.push_back(5);
            values.push_back(0);
            values.push_back(0);
            values.push_back(7);
            values.push_back(8);
        }

        return values;
    }
    
    std::vector<std::string> get_string_values() {
        
        //VS2012: Lack of initializer lists is really hard!
        //std::vector<string> values = { ... };
        std::vector<std::string> values;

        /* TODO: By the same token, sorted list of ints interspersed with 0.
        Isn't it, by definition then, unsorted? Or we include a default case
        to filter out the noise first? */
        if (!values.size()) {
            values.push_back("alpha");
            values.push_back("bravo");
            values.push_back("");
            values.push_back("");
            values.push_back("charlie");
            values.push_back("delta");
            values.push_back("");
            values.push_back("");
            values.push_back("echo");
            values.push_back("");
            values.push_back("foxtrot");
            values.push_back("gamma");
        }

        return values;
    }
    
    void bisectional_find_test_ints(std::vector<int>& values, int value_to_find) {

        using std::vector;
        using std::cout;
        using std::endl;
        using std::getchar;

        auto begin = values.begin();
        auto end = values.end();

        //works with iterator math
        auto found = bisectional_find<int_vector_iterator, int>(
            values, value_to_find,
            [](vector<int>& v) -> int_vector_iterator { return v.begin(); },
            [](vector<int>& v) -> int_vector_iterator { return v.end(); },
            [](const int& a, const int& b) { return a > 0 && a == b; });
        
        if (found == end)
            cout << "did not find " << value_to_find;
        else
            cout << "found " << value_to_find << " at index " << (found - begin);

        cout << endl;

        getchar();
    }

    void bisectional_find_test_strings(std::vector<std::string>& values, std::string value_to_find) {

        using std::vector;
        using std::string;
        using std::cout;
        using std::endl;
        using std::getchar;

        auto begin = values.begin();
        auto end = values.end();

        //works with iterator math
        auto found = bisectional_find<string_vector_iterator, string>(
            values, value_to_find,
            [](vector<string>& v) { return v.begin(); },
            [](vector<string>& v) { return v.end(); },
            [](const string& a, const string& b) { return a != "" && a == b; });

        if (found == end)
            cout << "did not find " << value_to_find;
        else
            cout << "found " << value_to_find << " at index " << (found - begin);

        cout << endl;

        getchar();
    }

}

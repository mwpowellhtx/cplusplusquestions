#ifndef QUESTION_1_H
#define QUESTION_1_H

#include <vector>
#include <iostream>

namespace q1 {

    template<typename T>
    void show_stack(const std::vector<T>& stack) {

        using namespace std;

        cout << "stack::size: " << stack.size() << endl;
        
        cout << "stack values: ";

        ////using the iterator
        //auto end = stack.cend();
        //for (auto it = stack.cbegin(); it != end; it++) {
        //    cout << *it << " ";
        //}

        //using range based loop
        for (auto& x : stack) {
            cout << x << " ";
        }
        
        cout << endl;

        getchar();
    }

    extern void implement_stack();
}

#endif //QUESTION_1_H

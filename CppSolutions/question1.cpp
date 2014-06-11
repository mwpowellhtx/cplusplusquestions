#include "question1.h"

namespace q1 {

    /* 1. Implement a Stack data structure using a linked list node. Details below:
    Implement a linked list node class with two member variables: an integer and a pointer to another node
    Using the node class, implement a Stack data class with "PUSH" and "POP" member functions and other functions which are necessary to support them
    Implement a simple main function to show how to create a stack, "PUSH" an integer into stack and "POP" an integer from stack */
    void implement_stack() {
        
        using namespace std;

        /* It's good to know the academic exercise, but in the real-world,
        we rely on built-in collections, for starters. Or if using a library
        such as Qt, or something like that, whatever collections are built-in
        to those. */
        
        int value = 0;
        
        /* Vector is an obvious choice for stacks. Deque is also a fine one.
        http://en.cppreference.com/w/cpp/container/vector
        http://en.cppreference.com/w/cpp/container/deque, for front/back operation,
        plus a whole host of other range operations */
        vector<int> my_stack_of_ints;

        //Add-value:
        my_stack_of_ints.push_back(++value);
        my_stack_of_ints.push_back(++value);
        my_stack_of_ints.push_back(++value);
        
        show_stack(my_stack_of_ints);
        
        my_stack_of_ints.pop_back();
        my_stack_of_ints.pop_back();
        
        show_stack(my_stack_of_ints);
    }

}
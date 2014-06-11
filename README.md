# C++ Solutions

## Question 1 Proposal

Implement a Stack data structure using a linked list node. Details below:

Implement a linked list node class with two member variables: an integer and a pointer to another node.

Using the node class, implement a Stack data class with "PUSH" and "POP" member functions and other functions which are necessary to support them.

Implement a simple main function to show how to create a stack, "PUSH" an integer into stack and "POP" an integer from stack.

### Solution

No need to reinvent the wheel. Academically, we've all done lists, stacks, trees, possibly even graphs, and so on. It's bread and butter, largely boilerplate type stuff, and we should be cognizant of the implementations, performance implications, and so forth.

However, in the real-world, we may do this, or we would rather add value by focusing on the solution to the problem at hand. That means utilizing the already established features at our disposal.

Specifically, in this case, utilize the [std::vector](http://www.cplusplus.com/reference/vector/). There is also a [std::stack](http://www.cplusplus.com/reference/stack/), but I think vector is perfectly sufficient for most things. A second choice might be [std::deque](http://www.cplusplus.com/reference/deque/).

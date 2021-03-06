# C++ Solutions

## Solutions Organization

Overall, the layout separates the problem proposals into namespaces numbered according to the proposal number.

The solution depends on Visual Studio 2012 Professional.

## Question 1 Proposal

Implement a Stack data structure using a linked list node. Details below:

Implement a linked list node class with two member variables: an integer and a pointer to another node.

Using the node class, implement a Stack data class with "PUSH" and "POP" member functions and other functions which are necessary to support them.

Implement a simple main function to show how to create a stack, "PUSH" an integer into stack and "POP" an integer from stack.

### Solution

No need to reinvent the wheel. Academically, we've all done lists, stacks, trees, possibly even graphs, and so on. It's bread and butter, largely boilerplate type stuff, and we should be cognizant of the implementations, performance implications, and so forth.

However, in the real-world, we may do this, or we would rather add value by focusing on the solution to the problem at hand. That means utilizing the already established features at our disposal.

Specifically, in this case, utilize the [std::vector](http://www.cplusplus.com/reference/vector/). There is also a [std::stack](http://www.cplusplus.com/reference/stack/), but I think vector is perfectly sufficient for most things. A second choice might be [std::deque](http://www.cplusplus.com/reference/deque/).

## Question 2 Proposal

Write a program to read integers from a file and print N largest distinct numbers.

The first number read from the file is N.

Print the N largest numbers in ascending order.

### Question 2 Part 2 Proposal
    
How would you solve this problem if you had to print N largest numbers, not necessarily distinct?

### Solution

Key features solving this problem include the following highlights:

* Supply an integer reader function that reads one integer at a time from an input stream, assuming that one line contains one integer value. The stream may be derived from file, memory, and so on.

* Tally the input numbers in a [std::map](http://www.cplusplus.com/reference/map/), followed by extracting the [std::pair](http://www.cplusplus.com/reference/utility/pair/) elements from the map into a vector. From there we can [sort](http://en.cppreference.com/w/cpp/algorithm/sort), print, whatever else we need to do.

  * ~~Actually, map was the initial approach, but upon further examination, the trade off extracting vectors for sorting was not worth it. So I fell back on a purely vector-oriented approach. Just capture the paired tallies and do whatever selecting, sorting, and so forth, is required.~~

  * ~~After some experimentation, I was able to make map work through LINQ after all. Which means we get the performance goodness of maps when tallying, as well as the ability to nicely extract the tallied values.~~

  * LINQ has its uses, but for sake of this example, it is overkill. Again, we'll leverage built-in language features. We will use map to capture the input result, leveraging the [std::map::key_comp](http://www.cplusplus.com/reference/map/map/key_comp/) template argument. The default is [std::less](http://www.cplusplus.com/reference/functional/less/), but for input purposes, we actually want [std::greater](http://www.cplusplus.com/reference/functional/greater/). Then we capture the results using [std::set](http://www.cplusplus.com/reference/set/), whose [comparison object](http://www.cplusplus.com/reference/set/set/key_comp/) is also less, which we're satisfied with since we get the desired ascending order consequently.

* Inject [functional](http://www.cplusplus.com/reference/functional/function/) methods for key points of extensibility: i.e. Part 2 of the proposed issue. Injected handlers can be functions themselves, or I like to utilize lambda expressions, is a common thing to do in the industry.

* ~~Finally, I utilize a third-party library called [LINQ for C++](http://cpplinq.codeplex.com/), available through NuGet sources, or download from the project web site. Include one file, "cpplinq.hpp", and you get the feel of [LINQ](http://msdn.microsoft.com/en-us/library/bb397926.aspx) goodness operating in C++. This is important to ask two key questions about the tallied numbers:~~

  * ~~First, what we are predicating the response on: distinct, non-distinct, which we injected via the functional paradigm.~~

  * ~~Second, the scope of the response we are interested in: we want the first N largest numbers.~~

  * With the shift in approaches from LINQ to an asynchronous futures oriented approach, the need for LINQ virtually goes away, at least for this set of use cases. They are simple enough to capture through asynchronous futures. Would be better still with more advanced futures support, but for compiler constraints (i.e. partial C++11 coverage).

* I also challenged myself to simplify the issue through a class implementation, as well as leverage the use of asynchronous futures. With more advanced language features, things like future chaining can be possible, instead of nesting, which makes it that much easier to deal with and maintain on a consistent basis.

From there we simply use "standard" language features such as [std::cout](http://www.cplusplus.com/reference/iostream/cout/) to report the response.

## Question 3 Proposal

Given a sorted array of strings, which is interspersed with empty strings, write a binary search function to find the location of a given string.

For example, find:

<pre>
"ball"
</pre>

in:

<pre>
[ "at", "", "", "", "ball", "", "", "car", "dad", "", "" ]
</pre>

will return 4.

### Solution

I took an [iterator](http://www.cplusplus.com/reference/iterator/RandomAccessIterator/) based approach on this one. With iterator arithmetic the desired index can be determined. Assumptions are that we rely on our trusted vector, once again.

Additionally, "binary" is somewhat of a misnomer here. I understand what we are wanting to accomplish there, which is more like a [bisectional algorithm](http://en.wikipedia.org/wiki/Bisection_method) than a truly binary one. It's similar, but not quite; a key difference is, for instance, we make no assumptions, indeed cannot, that the vector is sorted. Indeed, it is not, as stated in the use case.

The solution itself depends on only vectors and iterators, with the element type along for the ride for functional predicate purposes. The tests, demonstrations of solution application, may interject additional dependencies on the element type, such as for integers or strings.

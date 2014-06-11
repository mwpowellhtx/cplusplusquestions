#include <map>
#include "cpplinq.hpp"

void spike_test_linq_map() {

    using namespace cpplinq;

    std::map<int, int> mapped;

    auto count = static_cast<int>(10);

    while (count--) {
        mapped[count] = 10 - count;
    }

    int criteria = 2;

    //It is possible to select a where clause from a map.
    auto selected = from(mapped)
        >> where([criteria](const std::map<int, int>::value_type& p) { return p.first > criteria; })
        >> to_vector();
}

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Type of vec: " << boost::typeindex::type_id_with_cvr<decltype(vec)>().pretty_name() << std::endl;
    return 0;
    return 0;
}

#include <iostream>

#include "hash_set.h"

int main() {
    HashSet<std::string> set(10);

    set.insert("hello");
    std::cout << set.contains("hello") << ' ' << set.contains("world") << '\n';
    set.clear();

    return 0;
}

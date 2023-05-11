//
// Created by jeremiah on 5/8/23.
//

#pragma once

#include <vector>
#include <list>

//TODO: make this a template
//template <typename T>
class HashSet {
public:

    size_t size() const {
        return set_size;
    }

    bool empty() const {
        return set_size == 0;
    }

    bool insert(int val) {
        const int hash = (int) hasher(val);

        const int index = hash % MAX_SIZE;

        for (const int ele: buckets[index]) {
            if (ele == val) {
                return false;
            }
        }

        set_size++;
        buckets[index].push_back(val);

        return true;
    }

    bool erase(int val) {
        const int hash = (int) hasher(val);

        const int index = hash % MAX_SIZE;

        std::list<int>& list = buckets[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it == val) {
                list.erase(it);
                set_size--;
                return true;
            }
        }

        return false;
    }

    void clear() {
        for (std::list<int>& list: buckets) {
            list.clear();
        }
        set_size = 0;
    }

private:

    static constexpr int MAX_SIZE = 100;
    std::hash<int> hasher;
    size_t set_size = 0;
    std::vector<std::list<int>> buckets{MAX_SIZE};
};

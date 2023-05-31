//
// Created by jeremiah on 5/8/23.
//

#pragma once

#include <vector>
#include <list>

template <typename T>
class HashSet {
public:

    explicit HashSet(size_t container_size = 100):MAX_SIZE(container_size) {}

    [[nodiscard]] size_t size() const {
        return set_size;
    }

    [[nodiscard]] bool empty() const {
        return set_size == 0;
    }

    bool insert(T val) {
        const size_t hash = hasher(val);

        const int index = hash % MAX_SIZE;

        for (const T& ele: buckets[index]) {
            if (ele == val) {
                return false;
            }
        }

        set_size++;
        buckets[index].push_back(val);

        return true;
    }

    bool erase(const T& val) {
        const size_t hash = hasher(val);

        const int index = hash % MAX_SIZE;

        std::list<T>& list = buckets[index];
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
        for (std::list<T>& list: buckets) {
            list.clear();
        }
        set_size = 0;
    }

    bool contains(const T& val) {
        const size_t hash = hasher(val);

        const int index = hash % MAX_SIZE;

        std::list<T>& list = buckets[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it == val) {
                return true;
            }
        }

        return false;
    }

private:

    const size_t MAX_SIZE = 100;
    std::hash<T> hasher;
    size_t set_size = 0;
    std::vector<std::list<T>> buckets{MAX_SIZE};
};

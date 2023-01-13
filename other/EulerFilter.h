#ifndef SORTALGORITHM_EULERFILTER_H
#define SORTALGORITHM_EULERFILTER_H

#include <vector>

inline void eulerFilter(std::vector<int>& array) {
    std::vector<int> prime(array.size());
    int count = 0;
    for (int i = 2; i < array.size(); i++) array[i] = 1;
    for (int i = 2; i < array.size(); i++) {
        if (array[i]) prime[count++] = i;
        for (int j = 0; j < count && i * prime[j] < array.size(); j++) {
            array[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}

#endif //SORTALGORITHM_EULERFILTER_H

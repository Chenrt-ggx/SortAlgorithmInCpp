#ifndef SORTALGORITHM_EULERSEIVE_H
#define SORTALGORITHM_EULERSEIVE_H

#include <vector>

void eulerSeive(std::vector<bool> &array) {
    std::vector<int> prime(array.size());
    int count = 0;
    for (int i = 2; i < array.size(); i++) array[i] = true;
    for (int i = 2; i < array.size(); i++) {
        if (array[i]) prime[count++] = i;
        for (int j = 0; j < count && i * prime[j] < array.size(); j++) {
            array[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

#endif //SORTALGORITHM_EULERSEIVE_H

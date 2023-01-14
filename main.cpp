#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include <catch2/catch_all.hpp>

#include "utils/fio.h"
#include "utils/sort.h"
#include "utils/rank.h"
#include "utils/other.h"
#include "other/EulerFilter.h"
#include "other/FindMajority.h"
#include "other/ReverseMerge.h"

void eulerTest() {
    std::vector<int> filter(read());
    eulerFilter(filter);
    for (int i = 0; i < filter.size(); i++)
        if (filter[i]) write(i);
}

void reverseTestA() {
    int total = read();
    int *array = (int *) malloc(sizeof(int) * total);
    for (int i = 0; i < total; i++) array[i] = read();
    write(reverseMerge(array, total));
}

void reverseTestB() {
    std::vector<int> array(read());
    for (int &i: array) i = read();
    write(reverseMerge(array.begin(), (int) array.size()));
}

void majorityTestA() {
    int total = read();
    int *array = (int *) malloc(sizeof(int) * total);
    int *answer = (int *) malloc(sizeof(int) * total);
    for (int i = 0; i < total; i++) array[i] = answer[i] = read();
    std::sort(answer, answer + total);
    puts(answer[total / 2] == findMajority(array, total) ? "true" : "false");
    free(array), free(answer);
}

void majorityTestB() {
    int total = read();
    std::vector<int> array(total);
    std::vector<int> answer(total);
    for (int i = 0; i < total; i++) array[i] = answer[i] = read();
    std::sort(answer.begin(), answer.end());
    puts(answer[total / 2] == findMajority(array, total) ? "true" : "false");
}

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return Catch::Session().run(argc, argv);
}

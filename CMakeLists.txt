cmake_minimum_required(VERSION 3.23)
project(SortAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./catch)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/catch
        ${CMAKE_CURRENT_SOURCE_DIR}/catch/include
)

add_executable(SortAlgorithm main.cpp utils/heap.h test/AbstractGenerator.h test/LargeRandomGenerator.h test/MiddleRandomGenerator.h test/SmallRandomGenerator.h test/IncreaseItemGenerator.h test/DecreaseItemGenerator.h test/SameItemGenerator.h sort/BubbleSort.h sort/SelectSort.h sort/InsertSort.h sort/ShellSort.h sort/QuickSort.h sort/HeapSort.h sort/MergeSort.h sort/RadixSort.h other/FindKth.h other/ReverseMerge.h other/MaintainKth.h other/FindMajority.h other/EulerSeive.h utils/sort.h utils/consts.h utils/rank.h utils/other.h other/ReverseBrute.h)

target_link_libraries(SortAlgorithm PRIVATE Catch2::Catch2)
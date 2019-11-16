#include <iostream>
#include "Clock.h"
#include "Quicksort.h"
#include "Randomized_Select.h"
#include "nth_element.h"

void printVector(std::vector<int> vec){
    std::cout << "[" ;
    for(int i=0; i< vec.size() -1; i++)
    {
        std::cout << vec[i] << "; " ;
    }
    std::cout << vec[vec.size()-1] << "]" << std::endl;
}

int main(int argc, const char * argv[]) {
    Clock clock;
    std::vector<int> randomValues1;
    srand(time(NULL));
    for(int i = 0; i < 10000001; i++) {
        randomValues1.push_back(rand() % 20000000);
    }
    int left = 0;
    int right = static_cast<int>((randomValues1.size()) - 1);
    std::vector<int> randomValues2 = randomValues1;
    std::vector<int> randomValues3 = randomValues1;
    std::vector<int> randomValues4 = randomValues1;

    std::chrono::high_resolution_clock::time_point quicksortStart = clock.getStartTime();
    //printVector(randomValues1);
    Quicksort sort;
    sort.quicksort(randomValues1, left, right);
    int median = sort.getMedian(randomValues1, left, right);
    //printVector(randomValues1);

    std::cout << "Quicksort Selection Median: " << median << std::endl;
    std::chrono::high_resolution_clock::time_point quicksortEnd = clock.getEndTime();
    std::cout << "Quicksort runtime:" << std::endl;
    clock.printTime(quicksortStart, quicksortEnd);
    
    std::chrono::high_resolution_clock::time_point randomizedStart = clock.getStartTime();

    Randomized_Select randomized_select;
    median = randomized_select.Randomized_Select_Median(randomValues2, left, right);
    std::chrono::high_resolution_clock::time_point randomizedEnd = clock.getEndTime();
    //printVector(randomValues2);
    std::cout << "Randomized Selection median: " << median << std::endl;
    std::cout << "Randomized Select runtime:" << std::endl;
    clock.printTime(randomizedStart, randomizedEnd);
    
    std::chrono::high_resolution_clock::time_point nth_elementStart = clock.getStartTime();
    Nth_Element nth_element;
    median = nth_element.selectMedian(randomValues3);
    std::chrono::high_resolution_clock::time_point nth_elementEnd = clock.getEndTime();
    std::cout << "nth element median: " << median << std::endl;
    std::cout << "nth element runtime:" << std::endl;
    clock.printTime(nth_elementStart, nth_elementEnd);

    
}

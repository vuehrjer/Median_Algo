#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>

class Quicksort {
public:
    Quicksort();
    int partition(std::vector<int>& values, int left, int right);

    void quicksort(std::vector<int>& values, int left, int right);
    int getMedian(std::vector<int>& values, int left, int right);
};

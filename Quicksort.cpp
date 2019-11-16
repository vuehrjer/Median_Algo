

#include "Quicksort.h"

Quicksort::Quicksort(){}


int Quicksort::partition(std::vector<int>& values, int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(values[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}


void Quicksort::quicksort(std::vector<int> &values, int left, int right)
{
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

// Select middle element of sorted list

int Quicksort::getMedian(std::vector<int> &values, int left, int right)
{
    int median;
    quicksort(values, left, right);
    if(values.size() % 2 == 0)
    {
        median = (values[values.size()/2] + values[values.size()/2 -1]) / 2;
        return median;
    }
    else
    {
        median = values[(values.size()-1)/2];
        return median;
    }
}

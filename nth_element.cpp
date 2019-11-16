

#include "nth_element.h"

Nth_Element::Nth_Element(){}

int Nth_Element::selectMedian(std::vector<int>& vec)
{
    std::nth_element(vec.begin(), vec.begin() + vec.size()/2, vec.end());
    return vec[vec.size()/2];
}

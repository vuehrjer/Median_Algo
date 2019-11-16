

#include "nth_element.h"

Nth_Element::Nth_Element(){}

int Nth_Element::selectMedian(std::vector<int>& vec)
{
    std::nth_element(vec.begin(), vec.begin() + vec.size()/2, vec.end());
    if(vec.size() % 2 == 0)
    {
        return (vec[vec.size()/2] + vec[vec.size()/2 - 1])/2;
    }
    else
    {
        return vec[(vec.size()-1)/2];
    }
}

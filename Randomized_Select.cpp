

#include "Randomized_Select.h"


Randomized_Select::Randomized_Select(){}

void Randomized_Select::swap(std::vector<int>& vec, int a, int b)
{
            int temp = vec[a];
            vec[a] = vec[b];
            vec[b] = temp;
}

int Randomized_Select::partition(std::vector<int>& vec, int p, int r){
    int x = vec[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(vec[j] <= x){
            i++;
            swap(vec, i, j);
        }
    }
    swap(vec, i+1, r);
    return i+1;
}

// Select random element and return the correct position of the element

int Randomized_Select::Randomized_Partition(std::vector<int>& vec, int p, int r){
    srand(time(NULL));
    int i = p + rand() % (r - p + 1);
    swap(vec, i, r);
    return partition(vec, p, r);
}

// Implementation of the pseudo code as shown in the course

int Randomized_Select::Randomized_Selection(std::vector<int>& vec, int p, int r, int i)
{
    if(p==r)
    return vec[p];
    int q = Randomized_Partition(vec,p,r);
    int k = q-p+1;
    if(i == k)
    return vec[q];
    else if(i < k)
    return Randomized_Selection(vec, p, q-1, i);
    else return Randomized_Selection(vec, q+1, r, i-k);
}

// Hardcoded median selection

int Randomized_Select::Randomized_Select_Median(std::vector<int>& vec, int p, int r)
{
    int i = static_cast<int>(vec.size());
    if(i % 2 == 0)
    {
        return Randomized_Selection(vec, p, r, i/2);
    }
    else
    {
        return Randomized_Selection(vec, p, r, (i+1)/2);
    }
}

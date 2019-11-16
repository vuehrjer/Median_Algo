#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>

class Randomized_Select{
    
public:
    
    Randomized_Select();
    
    int partition(std::vector<int>& vec, int p, int r);

    int Randomized_Partition(std::vector<int>& vec, int p, int r);
    
    int Randomized_Selection(std::vector<int>& vec, int p, int r, int i);
    
    void swap(std::vector<int>& vec, int a, int b);
    
    int Randomized_Select_Median(std::vector<int>& vec, int p, int r);
};

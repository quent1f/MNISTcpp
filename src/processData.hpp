#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using std::cout, std::vector, std::string;

vector<double> parseLine(string s);

vector<vector<double>> dataProcess(string f);

vector<int> labelProcess(string f);

vector<int> labelConfig(vector<int> labels); 

double testPerf(vector<vector<double>>& data, vector<int>& labels, vector<int>& prediction);

#ifndef DISPLAY_VECTOR_HPP
#define DISPLAY_VECTOR_HPP

template<typename T> 
void displayVector(vector<T>& vec) {
    for (T elem : vec) { 
        cout << elem << " ";    
    }
    cout << "\n";               
}

#endif // DISPLAY_VECTOR_HPP

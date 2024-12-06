#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using std::cout, std::vector, std::string;

vector<double> parseLine(string s);

vector<vector<double>> dataProcess(string f);

vector<double> labelProcess(string f);

double testPerf(vector<vector<double>>& data, vector<double>& labels, vector<double>& prediction);

void displayVector(vector<double>& vec);
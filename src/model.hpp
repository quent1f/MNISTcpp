#include "processData.hpp"
#include "logistic_regression.hpp"

using std::vector; 

vector<double> trainModel(double lrate, vector<vector<double>>& data, vector<int>& labels, vector<double>& w_init);

void saveModel(vector<double> weights); 

vector<double> importModel(string file); 


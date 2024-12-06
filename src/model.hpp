#include "processData.hpp"

vector<double> trainModel(double lrate, vector<vector<double>>& data, vector<double>& labels, vector<double>& w_init);

void saveModel(vector<double> weights); 

vector<double> importModel(string file); 


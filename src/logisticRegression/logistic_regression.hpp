#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <ranges>

using std::cout, std::vector, std::string;


double sigmoid(double x);

double predictor(vector<double>& w, vector<double>& x);

int prediction(vector<double>& w, vector<double>& input);

vector<int> multiplePrediction(vector<vector<double>>& data, vector<double>& weights);

void update_weights(vector<double>& w, vector<double>& x, int label, double lrate);
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <ranges>

#include "processData.hpp"

using std::cout, std::vector, std::string;

// Implementation of logistic regression without bias
// We want to predict 0 if the image is an even number and 1 if it's an odd number

double sigmoid(double x) {
    return 1/(1+exp(-x));
}

double predictor(vector<double>& w, vector<double>& x) {
    return sigmoid(std::inner_product(w.begin(), w.end(), x.begin(), 0.0));
}

int prediction(vector<double>& w, vector<double>& input) {
    double prob = predictor(w, input); 
    if (prob > 0.5) return 1; 
    return 0; 
}

vector<int> prediction(vector<vector<double>>& data, vector<double>& weights) { 
    size_t dataSize = data.size();
    vector<int> res(dataSize);
    for (size_t i = 0; i < dataSize; i++) {
        res[i] = predictor(weights, data[i]);
    }
    return res; 
}

void update_weights(vector<double>& w, vector<double>& x, double label, double lrate) {
    double prediction = predictor(w, x); 
    double error = prediction-label;
    for (int i = 0; i < (int)w.size(); i++) {
        w[i] -= lrate*error*x[i];
    }
}



int main() {

    vector<double> w(724, 0); 
    vector<vector<double>> data_train = dataProcess("../data/x_train.csv");
    vector<double> labels_train = labelProcess("../data/y_train.csv");
    w = train_model(0.01, data_train, labels_train, w);



    vector<vector<double>> data_test = dataProcess("../data/x_test.csv");
    vector<double> labels_test = labelProcess("../data/y_test.csv");

    // testPerf(data_test, labels_test, labels_test);


    // tests(w, data_test);

    return 0;
}
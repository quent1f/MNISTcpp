#include "logistic_regression.hpp"

// Implementation of logistic regression without bias
// We want to predict 0 if the image is an even number and 1 if it's an odd number

double sigmoid(double x) {
    return 1/(1+exp(-x));
}

double predictor(vector<double>& w, vector<double>& x) {
    return sigmoid((double)std::inner_product(w.begin(), w.end(), x.begin(), 0.0));
}

int prediction(vector<double>& w, vector<double>& input) {
    double prob = predictor(w, input); 
    if (prob > 0.5) return 1; 
    return 0; 
}

vector<int> multiplePrediction(vector<vector<double>>& data, vector<double>& weights) { 
    size_t dataSize = data.size();
    vector<int> res(dataSize);
    for (size_t i = 0; i < dataSize; i++) {
        res[i] = prediction(weights, data[i]);
    }
    return res; 
}

void update_weights(vector<double>& w, vector<double>& x, int label, double lrate) {
    double prediction = predictor(w, x); 
    double error = prediction-label;
    for (size_t i = 0; i < w.size(); i++) {
        w[i] -= lrate*error*x[i];
    }
}



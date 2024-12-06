#include "model.hpp"
#include "logistic_regression.cpp"

vector<double> train_model(double lrate, vector<vector<double>>& data, vector<double>& labels, vector<double>& w_init) {
    int n = data.size();
    vector<double> w = w_init;
    for (int i=0; i<n; i++) {
        update_weights(w, data[i], labels[i], lrate);
    }
    return w; 
}

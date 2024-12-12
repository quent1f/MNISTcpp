#include "model.hpp"

vector<double> trainModel(double lrate, vector<vector<double>>& data, vector<int>& labels, vector<double>& w_init) {
    int n = data.size();
    vector<double> w = w_init;
    for (int i=0; i<n; i++) {
        update_weights(w, data[i], labels[i], lrate);
    }
    return w; 
}

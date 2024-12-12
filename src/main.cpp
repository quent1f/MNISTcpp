#include "logisticRegression/model.hpp"
#include "processData.hpp"
#include "logisticRegression/logistic_regression.hpp"


int main() {

    vector<double> w(724, 0); 
    vector<vector<double>> data_train = dataProcess("data/x_train.csv");
    vector<int> labels = labelProcess("data/y_train.csv"); 
    vector<int> labels_train = labelConfig(labels);

    w = trainModel(0.01, data_train, labels_train, w);


    vector<vector<double>> data_test = dataProcess("data/x_test.csv");
    vector<int> labels_test = labelConfig(labelProcess("data/y_test.csv"));

    vector<int> pred = multiplePrediction(data_test, w);
    testPerf(data_test, labels_test, pred);


    return 0;
}


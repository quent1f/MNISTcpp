#include "processData.hpp"

// Processing data from a CSV file 

vector<double> parseLine(string s) {
    string tmp;
    vector<double> res;
    for (char c : s) {
        if (c != ',') {
            tmp += c;
        }
        else {
            res.push_back(stoi(tmp)/256.);
            tmp = "";
        }
    }
    return res;
}

vector<vector<double>> dataProcess(string f) {
    std::ifstream file(f);
    string line; 
    vector<vector<double>> data;
    while(std::getline(file, line)) {
        data.push_back(parseLine(line));
    }
    return data;
}

vector<double> labelProcess(string f) {
    std::ifstream file(f); 
    string line; 
    vector<double> labels;
    while(std::getline(file, line)) {
        int x = std::stoi(line);
        // 0 if it's an even number and 1 if it's an odd number
        x%2 == 0 ? labels.push_back(0) : labels.push_back(1);
    }
    return labels;
}

double testPerf(vector<vector<double>>& data, vector<double>& labels, vector<int>& prediction) {
    double pass = 0; 
    for (size_t i = 0; i < labels.size(); i++) {

        if (labels[i] == prediction[i]) {
            pass++; 
        }
    }
    cout << "Taille de l'ensemble de test : " << labels.size() << "\n"; 
    cout << "Nombre de bonnes prédictions : " << pass << " sur " << labels.size() << "\n";
    cout << "Accuracy : " << pass/data.size() << "\n";
    return pass;
}


void displayVector(vector<double>& vec) {
    for (double elem : vec) {
        cout << elem << " "; 
    }
    cout << "\n"; 
}
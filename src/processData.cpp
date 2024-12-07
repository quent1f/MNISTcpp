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

vector<int> labelProcess(string f) {
    std::ifstream file(f); 
    string line; 
    vector<int> labels;
    while(std::getline(file, line)) {
        int x = std::stoi(line);
        labels.push_back(x); 
    }
    return labels;
}

vector<int> labelConfig(vector<int> labels) {
    vector<int> newLabels; 
    for (size_t i = 0; i < labels.size(); i++) {
        int x = labels[i]; 
        // 0 if it's an even number and 1 if it's an odd number
        x%2 == 0 ? newLabels.push_back(0) : newLabels.push_back(1);
    }
    return newLabels; 
}


double testPerf(vector<vector<double>>& data, vector<int>& labels, vector<int>& prediction) {
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


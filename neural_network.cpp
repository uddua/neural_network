#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

#define n_features 4
#define n_layers 2
#define n_classes 3

typedef float FF;
typedef int II;
typedef vector<vector<FF>> matrix;


FF sigmoid_function(FF x){
    return 1 / ( 1+exp(-x) );
}

matrix sigmoid(matrix ms){
    for(unsigned i; i<ms.size(); ++i){
        for(unsigned j; j<ms[0].size(); ++j){
            ms[i][j] = sigmoid_function(ms[i][j]);
        }
    }
    return ms;
}

void print_matrix(matrix ms){
    cout << "[ " << ms.size() << " x " << ms[0].size() << " ]" <<endl;
    for(auto i : ms){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}

matrix create_layer(II n_inputs, II n_neurons){
    matrix layer;
    for(unsigned i=0; i<n_inputs; ++i){
        vector<FF> tmp;
        for(unsigned j=0; j<n_neurons; ++j){
            tmp.push_back( (FF) rand() / (RAND_MAX) );
        }
        layer.push_back(tmp);
        tmp.clear();
    }
    return layer;
}


int main(){

    auto ms = create_layer(5,8);
    auto ra = sigmoid(ms);
    print_matrix(ms);
    print_matrix(ra);
    

    return 0;
}

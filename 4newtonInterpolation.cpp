#include<fstream>
#include<vector>
using namespace std;

void inter(string file){
    //input:
    vector<double> xin, yin;
    ifstream fin{file};
    for(double v1,v2; fin>>v1>>v2;){
        xin.push_back(v1);
        yin.push_back(v2);
    }
    fin.close();

    //finite divided differences:
    int n = xin.size();
    vector<vector<double>> M(n, vector<double>(n));
    for(int i{}; i<n; i++)
        M[i][0] = yin[i];
    for(int j{1}; j<n; j++)
        for(int i{}; i<n-j; i++)
            M[i][j] = (M[i+1][j-1] - M[i][j-1]) /
                (xin[i+j] - xin[i]);

    //interpolation:
    vector<double> x, y, factor;
    for(double i{xin[0]}; i<xin.back(); i+=0.01){
        x.push_back(i);
        y.push_back(M[0][0]);
        factor.push_back(1);
    }
    for(int j{1}; j<n; j++)
        for(int i{}; i<x.size(); i++){
            factor[i] *= x[i]-xin[j-1];
            y[i] += factor[i]*M[0][j];
        }

    //output:
    ofstream fout{"out1.txt"};
    for(int i{}; i<x.size(); i++)
        fout<<x[i]<<'\t'<<y[i]<<endl;
    fout.close();
}

int main(){
    inter("data.txt");
}

#include<iostream>
#include<fstream>
using namespace std;

double trapezoidal(string file){
    double x0{}, y0{}, I{};
    ifstream fin{file};
    fin>>x0>>y0;
    for(double x, y; fin>>x>>y;){
        I += (x-x0)*(y+y0)/2;
        x0 = x;
        y0 = y;
    }
    fin.close();
    return I;
}

int main(){
    double I = trapezoidal("data.txt");
    cout<<"Integral = "<<I<<endl;
}

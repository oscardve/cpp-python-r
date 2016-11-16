#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

void out(string s1, string s2, string s3){
    cout<<setw(15)<<s1
        <<setw(15)<<s2
        <<setw(15)<<s3<<endl;
}

typedef double Function(double);
double newtonRaphson(Function F, double r0, double dr=1e-8, double tolerance=1e-8, double steps=1000);
double newtonRaphson(Function F, double r0, double dr, double tolerance, double steps){
    double r{}, slope{}, error{100};
    out("iteration", "root", "% rel. error");
    out("0", to_string(r0), to_string(error));
    for(int i{1}; i<=steps; i++){
        slope = (F(r0+dr) - F(r0-dr)) / (2*dr);
        r = r0 - F(r0) / slope;
        error = abs((r - r0) / r);
        out(to_string(i), to_string(r), to_string(error));
        r0 = r;
        if(error < tolerance)
            break;
    }
    return r;
}

double f1(double x){
    return exp(-x)*x + 10;
}

int main(){
    double r = newtonRaphson(f1, 0);
}

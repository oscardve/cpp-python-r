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
double newton(Function F, double o0, double dx=1e-6, double tolerance=1e-6, double steps=1000);
double newton(Function F, double o0, double dx, double tolerance, double steps){
    double o{}, first{}, second{}, error{100};
    out("iterations", "optimum", "%rel. error");
    out("0", to_string(o0), to_string(error));
    for(int i{1}; i<=steps && error > tolerance; i++){
        first = (F(o0+dx) - F(o0-dx)) / (2*dx);
        second = (F(o0+dx) - 2*F(o0) + F(o0-dx)) / pow(dx, 2);
        o = o0 - first/second;
        error = abs((o-o0)/o)*100;
        out(to_string(i), to_string(o), to_string(error));
        o0 = o;
    }
    return o;
}

int main(){
    double o = newton([](double x){return log(exp(x+3) + exp(-2*x+2));}, 0);
}

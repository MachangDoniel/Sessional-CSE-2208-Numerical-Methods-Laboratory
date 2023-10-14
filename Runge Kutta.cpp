//Runge Kutta Method

#include<bits/stdc++.h>
using namespace std;


double given_func(double x, double y) {
    return x+y;
}

int main() {
    double x, y, h, n, x1, x2;
    cout<<"x0 = ";
    cin>>x;
    cout<<"y0 = ";
    cin>>y;
    cout<<"N = ";
    cin>>n;
    cout<<"x1 = ";
    cin>>x1;
    cout<<"x2 = ";
    cin>>x2;
    h = (x2-x1)/(n-1);
    for(int i = 1; i<=n; i++) {
        cout<<"Step : "<<i<<endl;
        double k1, k2, k3, k4;
        k1 = h * given_func(x, y);
        k2 = h * given_func(x + h/2, y + k1/2);
        k3 = h * given_func(x + h/2, y + k2/2);
        k4 = h * given_func(x + h, y + k3);

        double del_y = (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
        y = y + del_y;
        cout<<"x = "<<x<<", y = "<<y<<endl;
    }
}

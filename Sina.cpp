
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <unordered_map>
using namespace std;

void file_write() {
    ofstream outf("Equation.txt");
    char s[50];
    for(int i = 1; i<=3; i++) {
        cin>>s;
        outf<<s<<endl;
    }
    outf.close();
}

void file_read() {
    ifstream inf("Equation.txt");
    double mat[3][4];
    string s;
    int r = 0;
    while(inf) {
        getline(inf, s);
        int c = 0;
        for(int i = 0; i<s.size(); i++) {
            int num=0, cou = 0, j = i, b, a=0;
            while(s[i]>='0' && s[i]<='9') {
                if(s[i-1]=='-' && cou == 0)
                {
                    a = -1;
                }
                cou++;
                i++;
            }
            while(cou) {
                if(a==-1)
                    b = -1*(s[j] - '0');
                else
                    b = s[j] - '0';
                num+=b*pow(10, cou-1);
                j++;
                cou--;
            }
            if(num!=0) {
                mat[r][c] = num;
                c++;
            }

        }
        r++;
    }
    cout<<endl<<"Matrix : "<<endl;
    for(int r = 0; r<3; r++) {
        for(int c = 0; c<4; c++)
        {
            cout<<mat[r][c]<<" ";
        }
        cout<<endl;
    }
    double L[3][3], U[3][3];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            U[i][j] = 0;
            L[i][j] = 0;
        }
    }
    L[0][0] = 1;
    L[1][1] = 1;
    L[2][2] = 1;
    U[0][0] = mat[0][0];
    U[0][1] = mat[0][1];
    U[0][2] = mat[0][2];
    L[1][0] = mat[1][0] / U[0][0];
    U[1][1] = mat[1][1] - L[1][0] * U[0][1];
    U[1][2] = mat[1][2] - L[1][0] * U[0][2];
    L[2][0] = mat[2][0] / U[0][0];
    L[2][1] = (mat[2][1] - L[2][0] * U[0][1]) / U[1][1];
    U[2][2] = mat[2][2] - L[2][0] * U[0][2] - L[2][1] * U[1][2];
    cout<<endl<<"L : "<<endl;
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"U : "<<endl;
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cout<<U[i][j]<<" ";
        }
        cout<<endl;
    }

    double y1, y2, y3;
    y1 = mat[0][3];
    y2 = mat[1][3] - L[1][0] * y1;
    y3 = mat[2][3] - L[2][0] * y1 - L[2][1] * y2;
    cout<<endl<<"y1 = "<<y1<<", y2 = "<<y2<<", y3 = "<<y3<<endl;

    double x, y, z;
    z = y3 / U[2][2];
    y = (y2 - z * U[1][2] ) / U[1][1];
    x = (y1 - z * U[0][2] - y * U[0][1]) / U[0][0];
    cout<<"x = "<<x<<", y = "<<y<<", z = "<<z<<endl;

}

int main() {
    file_write();
    file_read();
}

//2x+3y+1z=9
//1x+2y+3z=6
//3x+1y+2z=8

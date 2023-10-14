//Coefficient Matrix from 3 Complex Equation
//27x+6y-z=85
//6x+15y+2z=72
//x+y+54z=110

#include<bits/stdc++.h>
using namespace std;

#define N 3 //Number of Equation/row in coefficient matrix
#define M 4 //Number of column in coefficient matrix

bool isDigit(char c)
{
    if(c>='0' && c<='9') return 1;
    else return 0;
}
int isOperator(char c)
{
    if(c=='+') return 1;
    else if(c=='-') return 2;
    else return 0;
}
void file_read()
{
    ifstream in;
    in.open("input.txt");
    fstream out("output.txt");
    int i,j;
    string s;
    //while(getline(in,s))
    while(in>>s)
    {
        char c;
        int number=0,a[4]={0};
        bool sign=0;
        for(i=0;i<s.size();i++)
        {
            if(isDigit(s[i]))
            {
                if(number==0) number=s[i]-48;
                else number*=10,number+=s[i]-48;
            }
            else if(isOperator(s[i]))
            {
                sign=((isOperator(s[i])==1)?0:1);
            }
            else if(s[i]=='=')
            {
                continue;
            }
            else
            {
                int index;
                if(number==0) number=1;
                if(sign) number*=-1;
                if(s[i]=='x') index=0;  //for co_efficient of x
                else if(s[i]=='y') index=1; //for co_efficient of y
                else if(s[i]=='z') index=2; //for co_efficient of z
                a[index]=number;
                sign=0;
                number=0;
            }
        }
        if(sign) number*=-1;
        a[3]=number;    //for constant
        int sum=0;
        for(i=0;i<M;i++) sum+=a[i],cout<<a[i]<<" ",out<<a[i]<<" ";

        cout<<"Sum: "<<sum<<endl,out<<endl;
    }
}

int main()
{
    int i,j;
    file_read();
}

//False Position Method
//required formula x2-x-2=0
#include<bits/stdc++.h>

using namespace std;

float err=0.0001;
float f(float x)
{
    return 3*x+4;
}
void FB(float a, float  b)
{
    if(f(a)*f(b)>=0)
    {
        cout<<"No Solution!"<<endl;
        return ;
    }

    float x0;
    float x1=a;
    float x2=b;
    int i=0;
    while(abs(f(x1))>err)
    {
        cout<<i++<<endl;
        x0=x1-f(x1)*((x2-x1)/(f(x2)-f(x1)));
        if(f(x0)*f(x1)<0)
        {
            x2=x0;
        }
        else
        {
            x1=x0;
        }

    }

    cout<<"Root:"<<x0<<"\n"<<"Iterations:"<<i<<endl;
}
int main()
{
    float a =-20, b = 30;
    FB(a,b);
    return 0;
}

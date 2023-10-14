//Gauess seidal method

#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a[10][10],b[10],x[10];
    int p=0,q=0,i=0,j=0,n;
    cout<<"Enter size of 2D array : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {

            cin>>a[i][j];
        }
    }

    for(i=0; i<n; i++)
    {
        cout<<"Enter constant for equation "<<i+1;
        cin>>b[i];
        cout<<endl;
    }
    cout<<"Inter initial values of x "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"x["<<i<<"] ";
        cin>>x[i];
    }
    float sum=0,l;
    int maxitter ;
    cout<<"Enter the number of iterations :"<<endl;
    cin>>maxitter;
    for(l=0; l<maxitter; l++)
    {
        for(i=0; i<n; i++)
        {
            sum=0;
            for(j=0; j<n; j++)
            {
                if(i!=j)
                {
                    sum+=(a[i][j]*x[j]);
                }
            }
            x[i]=(1/a[i][i])*(b[i]-sum);
            cout<<x[i]<<endl;//print x[i] after every iteration


        }


    }
    for(i=0; i<n; i++)
    {
        cout<<"values of x["<<i<<"] is";
        cout<<x[i]<<endl;
    }
}

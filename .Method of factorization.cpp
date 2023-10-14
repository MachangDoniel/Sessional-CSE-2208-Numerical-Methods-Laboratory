//Method of Factorization
//Showing Upper and Lower Matrix
//2x+3y+z=9
//x+2y+3z=6
//3x+y+2z=8


#include<bits/stdc++.h>
using namespace std;

#define N 3
#define M 4
#define iteration 5
#define pb push_back

int A[3][3];
float U[3][3]={0},L[3][3]={0},k[3];
vector<float>constant;

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
    int count=0;
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
                sign=0;
            }
            else
            {
                int index;
                if(number==0) number=1;
                if(sign) number*=-1;
                if(s[i]=='x') index=0;
                else if(s[i]=='y') index=1;
                else if(s[i]=='z') index=2;
                a[index]=number;
                sign=0;
                number=0;
            }
        }
        if(sign) number*=-1;
        a[3]=number;
        for(i=0;i<M;i++)
        {
            cout<<a[i]<<" ",out<<a[i]<<" ";
            if(i<M-1) A[count][i]=a[i];
            else constant.pb(a[i]);
        }
        cout<<endl,out<<endl;
        count++;
    }
}
void matrix()
{
    int i,j;
    L[0][0]=L[1][1]=L[2][2]=1;

    U[0][0]=A[0][0];
    L[1][0]=A[1][0]/U[0][0];
    L[2][0]=A[2][0]/U[0][0];

    U[0][1]=A[0][1];
    U[1][1]=A[1][1]-L[1][0]*U[0][1];
    L[2][1]=(A[2][1]-L[2][0]*U[0][1])/U[1][1];

    U[0][2]=A[0][2];
    U[1][2]=A[1][2]-L[1][0]*U[0][2];
    U[2][2]=A[2][2]-L[2][0]*U[0][2]-L[2][1]*U[1][2];

    cout<<"Upper Matrix:"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) printf("%10f ",U[i][j]);
        cout<<endl;
    }
    cout<<"Lower Matrix:"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) printf("%10f ",L[i][j]);
        cout<<endl;
    }
}

void solution()
{
    int i,j;
    float x,y,z;

    k[0]=constant[0]/L[0][0];
    k[1]=(constant[1]-L[1][0]*k[0])/L[1][1];
    k[2]=(constant[2]-L[2][0]*k[0]-L[2][1]*k[1])/L[2][2];
    //for(i=0;i<3;i++) cout<<k[i]<<" ";
    //cout<<endl;
    z=k[2]/U[2][2];
    y=(k[1]-U[1][2]*z)/U[1][1];
    x=(k[0]-U[0][1]*y-U[0][2]*z)/U[0][0];
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
}

int main()
{
    int i,j;
    file_read();
    matrix();
    solution();
}

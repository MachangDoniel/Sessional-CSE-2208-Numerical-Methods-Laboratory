#include<bits/stdc++.h>
using namespace std;

float trapezoidal_Rule(float l_limit, float u_limit)
{

    int n;
    cin>>n;
    float h = (u_limit-l_limit) / n;

    float ans = .5 * (log(l_limit) + log(u_limit));


    for(int i = 1; i<n; i++)
    {
        ans += log(l_limit + h * i);
    }
    ans *= h;
    return ans;
}

float simpsons_one_third_rule(float l_limit, float u_limit)
{
    int n;
    cin>>n;
    float h = (u_limit-l_limit) / n;

    float ans = log(l_limit) + log(u_limit);

    for(int i = 1; i<=n-1; i+=2)
    {
        ans += 4*log(l_limit + h * i);
    }
    for(int i = 2; i<=n-2; i+=2)
    {
        ans += 2*log(l_limit + h * i);
    }
    ans *= h;
    ans /= 3;
    return ans;
}

float simpsons_three_eights_rule(float l_limit, float u_limit)
{
    int n;
    cin>>n;
    float h = (u_limit-l_limit) / n;

    float ans = log(l_limit) + log(u_limit);

    for(int i = 1; i<=n-1; i++)
    {
        if(i%3!=0)
            ans += 3*log(l_limit + h * i);
    }
    for(int i = 3; i<=n-3; i++)
    {
        if(i%3==0)
            ans += 2*log(l_limit + h * i);
    }
    ans *= h * 3;
    ans /=8;
    return ans;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    float l_limit, u_limit, y;
    cin>>l_limit>>u_limit;
    printf("%.10f\n", trapezoidal_Rule(l_limit, u_limit));
    printf("%.10f\n", simpsons_one_third_rule(l_limit, u_limit));
    printf("%.10f\n", simpsons_three_eights_rule(l_limit, u_limit));

}

/*
4 5.2
6
*/

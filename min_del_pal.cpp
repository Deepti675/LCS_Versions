//minimum number of deletion in a string to make it a palindrome
#include <bits/stdc++.h>
using namespace std;
int static t[1002][1002];

int LCS(string x,string y,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
            t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(x[i-1]==y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    return t[n][n];
}
int main()
{
    string x,y;
    cin>>x;
    y=x;
    int n=x.size();
    reverse(x.begin(),x.end());
    int n1=LCS(x,y,n);
    int n2=n-n1;
    cout<<n2;
    return 0;
}

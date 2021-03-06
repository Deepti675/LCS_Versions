//Longest Palendromic Subsequence
//funda is like in LCS in place of first string take main string and for second string take reverse of main string and apply simple lcs and we will get the longest palendromic subsequence for a given string

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
    cout<<t[n][n];
    return 0;
}
int main()
{
    string x,y;
    cin>>x;
    y=x;
    int n=x.size();
    reverse(x.begin(),x.end());
    LCS(x,y,n);
    return 0;
}

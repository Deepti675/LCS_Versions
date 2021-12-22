// longest repeating subsequence 
#include <bits/stdc++.h>

using namespace std;
int t[1002][1002];
int longest_repeating_seq(string x,string y,int n)
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
        for(int j=0;j<n+1;j++)
        {
            if(x[i-1]==y[j-1]&&i!=j)
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
             t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][n];
}
int main()
{
    string x;
    cin>>x;
    string y;
    y=x;
    int n=x.size();
    cout<<longest_repeating_seq(x,y,n);
    return 0;
}

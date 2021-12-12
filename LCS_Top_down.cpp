//top down code *****************
#include <bits/stdc++.h>

using namespace std;
int static t[1001][1001];
int LCS(string x,string y,int n,int m)
{
    //initialization 
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
            t[i][j]=0;
        }
    }
    //choice code
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
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
    return t[n][m];
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n= x.size();
    int m= y.size();
    //cout<<m<<" "<<n;
   // memset(t,-1,sizeof(t));
    cout<<LCS(x,y,n,m);
    return 0;
}

//sequence pattern matching(two string given x and y check if x is the subsequnce of y and )
#include<bits/stdc++.h>
using namespace std;
int t[1002][1002];
bool fun(string x,string y,int n,int m)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
            t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    int k=t[n][m];
    if(k==n)
    return true;
    else
    return false;
  //return false;    
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    cout<<fun(x,y,n,m); 
    return 0;
}

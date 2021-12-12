//shortest common supersequence m dono string ko merge karna hai or merge krne k bad dono string us nayi string ki substring ho or shortest bhi ho 
#include<bits/stdc++.h>
using namespace std;
int t[1001][1002];
int SC_supersequence(string x,string y,int n,int m)
{
    for(int i=0;i<n+1;i++)
    for(int j=0;j<m+1;j++)
    {
        if(i==0||j==0)
        t[i][j]=0;
        
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<m+1;j++)
    {
        if(x[i-1]==y[j-1])
        {
            t[i][j]=1+t[i-1][j-1];
        }
        else
        {
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    //shortest common subsequence ki length ko minus kar diya kyu ki wo dono m common hogi
    int temp=t[n][m];
    int tt=n+m-temp;
    return tt;
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    cout<<SC_supersequence(x,y,n,m);
}

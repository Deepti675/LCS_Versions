//shortest common supersequence print 
//for superstring common char write once
#include <bits/stdc++.h>

using namespace std;
int t[1002][1002];
string SCS_Print(string x,string y,int n,int m)
{
    string s;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
        }
    }
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
    int k=n;
    int l=m;
    while(k>0&&l>0)
    {
        if(x[k-1]==y[l-1])
        {
            s.push_back(x[k-1]);
            k--;
            l--;
        }
        else
        {
            if(t[k][l-1]>t[k-1][l])
            {
                s.push_back(y[l-1]);
                l--;
            }
            else
            {
                s.push_back(x[k-1]);
                k--;
            }
        }
    }
    while(k>0)
    {
        s.push_back(x[k-1]);
        k--;
    }
    while(l>0)
    {
        s.push_back(y[l-1]);
        l--;
    }
    
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    cout<<SCS_Print(x,y,n,m);

    return 0;
}

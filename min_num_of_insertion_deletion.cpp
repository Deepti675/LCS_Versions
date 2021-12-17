
#include <bits/stdc++.h>

using namespace std;
int static t[1002][1002];
void Minimum_num_of_insertion_deletion(string x,string y,int n,int m)
{
    for(int i=0;i<n+1;i++)

    {
        for(int j=0;j+1<m;j++)
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
            t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    int temp=t[n][m];
    int n1=n-temp;
    int m1=m-temp;
    cout<<"Deletion is "<<n1<<"  Insertion is "<<m1;
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    Minimum_num_of_insertion_deletion(x,y,n,m);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,least=INT_MAX;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+m);
    for(int i=0;i<=m-n;i++)
    {
        least=min((a[i+n-1]-a[i]),least);
    }
    cout<<least;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count=0;
    int n;
    cin>>n;
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    sort(s.begin(),s.end());
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])
            count++;
    }
    if(count>=25)
        cout<<"YES";
    else
        cout<<"NO";
}
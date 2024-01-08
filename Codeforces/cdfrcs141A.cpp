#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    string a,b,check1="",check2;
    cin>>a>>b>>check2;
    check1=a+b;
    sort(check1.begin(),check1.end());
    sort(check2.begin(),check2.end());
    if(check1==check2)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
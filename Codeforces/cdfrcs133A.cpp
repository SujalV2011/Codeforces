#include <iostream>
using namespace std;
int main() 
{
	string p;
	cin>>p;
	bool check=false;
	for(int i=0;i<p.size();i++)
	{
	    if(p[i]>=33 && p[i]<=126)
	    {
	        if(p[i]=='H' || p[i]=='Q' || p[i]=='9')
	        {
	            check=true;
	        }     
	    }
	}
	if(check)
	{
	    cout<<"YES";
	}
	else
	{
	    cout<<"NO";
	}
	return 0;
}
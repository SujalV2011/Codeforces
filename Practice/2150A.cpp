#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int t;
	cin >> t;
	while(t--) 
    {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		set<int> black;
		for(int i=0;i<m;i++) 
        {
			int a;
			cin >> a;
			black.insert(a);
		}
		int pos = 1;
		for(int i=0;i<n;i++) 
        {
			if(i && s[i-1] == 'B')
				while(black.find(pos) != black.end())
					pos++;
			pos++;
			if(s[i] == 'B')
				while(black.find(pos) != black.end())
					pos++;
			black.insert(pos);
		}
		cout << black.size() << endl;
		for(auto i: black)
			cout << i << " ";
		cout << endl;
	}
}
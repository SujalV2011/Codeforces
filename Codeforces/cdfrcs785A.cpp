#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int facecnt=0;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s=="Tetrahedron")
            facecnt+=4;
        else if(s=="Cube")
            facecnt+=6;
        else if(s=="Octahedron")
            facecnt+=8;
        else if(s=="Dodecahedron")
            facecnt+=12;
        else
            facecnt+=20;
    }
    cout<<facecnt;
}
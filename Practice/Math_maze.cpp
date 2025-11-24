#include<bits/stdc++.h>
using namespace std;
/*
        this is the maze:

        6 / 5 + 9 *
        + 7 * 8 - 4
        2 - 1 + 3 +
        * 4 + 2 / 6
        9 - 8 * 7 +
        + 3 / 5 - 1

        we have to start from (0,0) and reach to the (n-1,n-1) cell and in the path we have to achieve the target number
        we can move in all four directions (up,down,left,right) and we can not visit a cell more than once in a single path
        the operators are: +,-,*,/

        4 - 7 * 7 *
        + 2 * 5 / 5
        3 / 4 + 5 -
        - 5 + 7 / 6
        3 + 9 * 2 -
        + 8 / 1 + 1

*/

int n,m;
vector<vector<char>>maze;
vector<vector<bool>>visited;

void get_path(int x,int y,double target,double current_value,char prev_op,string path,bool &found)
{
    // if(found) return;
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(visited[x][y]) return;

    path += string(1, maze[x][y]) + " ";

    char c = maze[x][y];
    double val = current_value;
    char op = prev_op;

    if(c>='0' && c<='9')
    {
        double num = c - '0';
        if(op=='N') val = num;
        else
        {
            if(op=='+') val += num;
            else if(op=='-') val -= num;
            else if(op=='*') val *= num;
            else if(op=='/')
            {
                if(num == 0) return;
                val /= num;
            }
        }
    }
    else op = c;

    if(x==n-1 && y==m-1)
    {
        if(val == target)
        {
            cout<<"Path to reach the target "<<target<<": "<<path<<endl;
            found=true;
        }
        return;
    }

    visited[x][y] = true;

    get_path(x+1,y,target,val,op,path,found);
    get_path(x-1,y,target,val,op,path,found);
    get_path(x,y+1,target,val,op,path,found);
    get_path(x,y-1,target,val,op,path,found);

    visited[x][y] = false;
}

int main()
{
    cin>>n>>m;

    maze.assign(n, vector<char>(m,'.'));
    visited.assign(n, vector<bool>(m,false));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
        }
    }

    double target;
    cin>>target;

    bool found=false;
    get_path(0,0,target,0,'N',"",found);

    if(!found)
    {
        cout<<"No path found to reach the target "<<target<<endl;
    }
}


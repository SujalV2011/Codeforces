#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Observations:

        so here i have convert the given graph to a tree struct so that each vertex have <=2 edges
            so first chck that the graph is a tree or not 
                if yes no need for any operations

        Output
            For each test case:

            If no operations are required (that is, the input tree is already a path graph), output −1
            .
            Otherwise, output three distinct integers a
            , b
            , and c
            (1≤a,b,c≤n
            ) — the chosen vertices for the first sliding operation in an optimal sequence.
            If there are multiple valid choices for the first operation, you can output any of them.

            so now according the move i nedd to peint only obe optimal move so i need to select an vertex who has max edges and try to make a otimal move

                    will this always work
                        no 
                            counter exmaple 
                                6
                                1 2
                                1 3
                                2 4
                                2 5
                                3 6

                                here the ans is 4 2 5 or 5 2 4 or 4 2 1 or 5 2 1

                                here i will select 1 2 5  
*/


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        vector<vector<ll>> adj(n+1);
        for(int i=0;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll mxdeg=-1;
        ll node=-1;
        for(int i=1;i<=n;i++)
        {
            if((ll)adj[i].size()>mxdeg)
            {
                mxdeg=adj[i].size();
                node=i;
            }
        }

        if(mxdeg<=2)
        {
            cout<<-1<<"\n";
        }
        else
        {
            vector<ll> leaves, others;
            for(auto v: adj[node])
            {
                if(adj[v].size()==1) leaves.push_back(v);
                else others.push_back(v);
            }

            if(leaves.size()>=2)
            {
                cout<<leaves[0]<<" "<<node<<" "<<leaves[1]<<"\n";
            }
            else if(leaves.size()>=1)
            {
                cout<<leaves[0]<<" "<<node<<" "<<others[0]<<"\n";
            }
            else
            {
                cout<<adj[node][0]<<" "<<node<<" "<<adj[node][1]<<"\n";
            }
        }
    }
}
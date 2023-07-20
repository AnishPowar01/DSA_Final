#include<bits/stdc++.h>
using namespace std;

class DISJOINT_SET{

    vector<int> parent, rank;

    public:
    DISJOINT_SET(int n )
    {
        rank.resize(n+1, 0);

        parent.resize(n+1);

        for(int i = 0; i<=n; i++)

        {
            parent[i] = i;
        }
    }

    int getparent(int node)
    {
        if(node == parent[node])
        {
            return node;
        }

        return parent[node] = getparent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultimate_parent_u = parent[u];
        int ultimate_parent_v = parent[v];

        if(ultimate_parent_u == ultimate_parent_v)
        {
            return ;
        }

        if(rank[ultimate_parent_u] < rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
        }
        else if(rank[ultimate_parent_v] < rank[ultimate_parent_u])
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            // if same the change the parent and increase the rank

            rank[ultimate_parent_u]++;
        }

    }

};

int main()
{
    DISJOINT_SET ds(7);

    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.getparent(3) == ds.getparent(7))
    {
        cout<<"Same Bro/"<<endl;
    }
    else{
        cout<<"Pain"<<endl;
    }

    ds.unionByRank(3,7);

    if(ds.getparent(2) == ds.getparent(7))
    {
        if(ds.getparent(3) == ds.getparent(7))
    {
        cout<<"Same Bro/"<<endl;
    }
    else{
        cout<<"Pain"<<endl;
    }

    }

    return 0;
}
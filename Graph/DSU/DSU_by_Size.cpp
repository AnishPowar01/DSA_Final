#include<bits/stdc++.h>
using namespace std;

class DSU_SIZE{

    vector<int>parent, size;

    public:

    DSU_SIZE(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 0);

        for(int i = 0; i<=n; i++)
        {
            parent[i] = i;
            size[i] = 1;
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

    void unionBySize(int u, int v)
    {
        int ultimate_parent_u = parent[u];
        int ultimate_parent_v = parent[v];

        if(ultimate_parent_u == ultimate_parent_v)
        {
            return;
        }

        if(size[ultimate_parent_u] < size[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;

            size[ultimate_parent_v] += size[ultimate_parent_u];
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
     }
};

int main()
{
    DSU_SIZE ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.getparent(3) == ds.getparent(7))
    {
        cout<<"Same same same"<<endl;
    }else{
        cout<<"Pain"<<endl;
    }

    ds.unionBySize(3,7);

     if(ds.getparent(3) == ds.getparent(7))
    {
        cout<<"Same same same"<<endl;
    }else{
        cout<<"Pain"<<endl;
    }




    return 0;
}
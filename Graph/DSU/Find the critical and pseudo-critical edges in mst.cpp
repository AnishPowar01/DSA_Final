class Solution {
public:
    class DSU{
        public : 
        vector<int>parent;
        vector<int>rank;

        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);


            for(int i =0; i<n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int p)
        {
            if(p == parent[p])
            {
                return p;
            }

            return parent[p] = findParent(parent[p]);
        }

        void Union(int u, int v)
        {
            int u_parent = findParent(u);
            int v_parent =findParent(v);

            if(rank[u_parent] > rank[v_parent])
            {
                parent[v_parent] = u_parent;
            }
            else
            {
                parent[u_parent] = v_parent;
                rank[v_parent]++;
            }
        }


    };
    int N;
    int KruskalAlgo(vector<vector<int>>& edges, int skip_edge, int add_edge)
    {
        DSU dsu(N);

        int sum = 0;

        int e_count =0;

        if(add_edge != -1)
        {
            // join the edge
            dsu.Union(edges[add_edge][0], edges[add_edge][1]);
            // add the weight
            sum += edges[add_edge][2];

            e_count++;
        }


        for(int i =0; i<edges.size(); i++)
        {
            if(i == skip_edge)
            {
                continue;
            }


            int u  = edges[i][0];
            int v  = edges[i][1];
            int w  = edges[i][2];

            int parent_u = dsu.findParent(u);
            int parent_v = dsu.findParent(v);

            if(parent_u != parent_v )
            {
                dsu.Union(u,v);
                sum += w;
                 e_count++;
            }
        }
        /*
        Catch he BHAI 
        [[0,1,1],[1,2,1],[0,2,1],[2,3,4],[3,4,2],[3,5,2],[4,5,2]]
        MST never find in this case... disconneted graph;
        // we can check if it is valid mst or not by just counting edges... if it is not equal to v-1 then we have a problem
        */

        // if we skip that one particular edge then mst is not possible .. so we have to include that edge in critical.. 
        // to make our condition valid in main function we are return very high value;

        if( e_count != N-1)
        {
            return INT_MAX;
        }

        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) { 
      N = n;
      
    //   1)  Add index
      for(int i =0; i<edges.size(); i++)
      {
          edges[i].push_back(i);
      }

    //   2 sort according to weights.
     
    auto cmp = [&](vector<int>&v1, vector<int>&v2)
    {
        return v1[2] < v2[2];
    };
    sort(edges.begin(), edges.end(), cmp);

    // 3 . Find MST weights.

    int weight = KruskalAlgo(edges, -1, -1);   // modified kruskal.. extra parament add edge and skip edge;

    vector<int>critical;
    vector<int>pseudo_critical;

    //4. now check the each edge
    /*
    if skipping that edge will increase the int MST weight then that edge is critical..
    And if the particular edge is present in some MST and absent in some MST then it will treated as pseudo-critical

    this much is only solution.. Add already implemented DSU and kruskal function
    */

    for(int i =0; i<edges.size(); i++)
    {
        if(KruskalAlgo(edges, i, -1) > weight)
        {
            critical.push_back(edges[i][3]);  // critical edge
        }
        else if(KruskalAlgo(edges, -1, i) == weight)
        {
            pseudo_critical.push_back(edges[i][3]);
        }

    }

    vector<vector<int>>ans;

    ans.push_back(critical);
    ans.push_back(pseudo_critical);

    return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>vec;

    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(3);

    stack<int>st;

    vector<int>ans(vec.size());

    st.push(-1);

    for(int i = vec.size()-1; i>=0; i--)
    {
        int num = vec[i];

        while(st.top() >= num)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(num);
    }


    for(auto it : ans)
    {
        cout<<it<<" ";
    }

    return 0;
}
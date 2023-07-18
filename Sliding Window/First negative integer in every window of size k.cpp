
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int k) {
                                                 
        
        vector<long long>list;
        vector<long long>ans;
        
        int i = 0;
        
        int j = 0;
        
        while(j<N)
        {
            if(arr[j] < 0)
            {
                list.push_back(arr[j]);
            }
            
            if(j - i + 1 < k)
            {
                j++;
            }
            else if( j - i + 1 == k)
            {
                if(list.size() == 0)
                {
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(list.front());
                    
                    if(arr[i] == list.front())
                    {
                        list.erase(list.begin());
                    }
                    
                    
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
                                                 
 }
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int n = coordinates.size();

        int dy_0 = coordinates[1][1] - coordinates[0][1] ;  // y2 - y1
        
        int dx_0 = coordinates[1][0] -  coordinates[0][0];   //x2-x1


         for(int i = 2; i<n; i++)
         {
             int dy_i = coordinates[i][1] - coordinates[0][1] ;


             int dx_i = coordinates[i][0] -  coordinates[0][0]; 


            //  now check the slope    dy_0 / dx_0  == dy_i / dx_i;

            if(dy_0 * dx_i != dy_i * dx_0)
            {
                return 0;
            }
         }

         return 1;
    }
};
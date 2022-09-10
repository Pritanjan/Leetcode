//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(),potions.end());
        vector<int> v(spells.size());
        
        for(int i=0; i<spells.size(); i++)
        {
            int L = 0;
            int R = potions.size()-1;
            int mid;
            
            while(L <= R)
            {
                mid = L + (R - L)/2;
                if((long long int)spells[i] * (long long int)potions[mid] >= success)
                    R = mid - 1;
                else
                    L = mid + 1;
                
            }
            v[i] = potions.size()-R-1;
        }
        return v;
    }
};

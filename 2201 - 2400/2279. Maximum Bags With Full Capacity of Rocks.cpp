class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v;
        int n = capacity.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            v.push_back(capacity[i] - rocks[i]);
        }

        sort(v.begin(), v.end());
        
        for(int i=0; i<n; i++){
            if(v[i] == 0)
               cnt++;
            else{
                if(additionalRocks >= v[i]){
                    cnt++;
                    additionalRocks -= v[i];
                }            
            }
        }
        return cnt;
    }
};


// v = 1 1 0 1


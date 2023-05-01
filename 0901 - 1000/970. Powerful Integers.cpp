class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        int i = 0;
        int j = 0;
        
        while(pow(x, i) <= bound) {
            j = 0;
            while(pow(x, i) + pow(y, j) <= bound) {
                s.insert(pow(x, i) + pow(y, j));
                j++;
            }
            i++;
        }

        vector<int> result;
        for(auto n : s) {
            result.push_back(n);
        }
        return result;
    }
};



class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i=1;i<bound;i*=x){
            for(int j=1;j<bound;j*=y){
                if(i+j<=bound)
                    s.insert(i+j); 
                if(y==1)  break;
            }
            if(x==1) break;
        }
        return {s.begin(),s.end()};
    }
};





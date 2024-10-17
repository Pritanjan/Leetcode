// A 0 

class Solution {
public:
    int maximumSwap(int num) {
        auto s = to_string(num);
        int n = s.size();
        int mxNum = num;

        for(int i=0; i<s.size(); i++){
            for(int j=i+1; j<n; j++){
                swap(s[i],s[j]);
                mxNum = max(mxNum,stoi(s));
                swap(s[i], s[j]);
            }
        }
        return mxNum;
    }
};




// A 1 

class Solution {
public:
    int maximumSwap(int num) {
        auto s = to_string(num);
        for(int i=0; i<s.size(); i++){
            auto a = max_element(s.rbegin(),s.rend()-i);
            if(s[i] != *a){
                swap(s[i], *a);
                break;
            }
        }
        return stoi(s);
    }
};

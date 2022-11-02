
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for(string s : sentences){
            int cnt = 1;
            for(int i=0; i<s.size(); i++){
                if(s[i] == ' ')
                    cnt++;
            }
            if(cnt >= max)
                max = cnt;
        }
        return max;
    }
};




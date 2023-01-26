class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> v(26, 0);
        for(int i=0; i<brokenLetters.size(); i++){
            v[brokenLetters[i] - 'a'] = true;
        }

        bool flag = true;
        int cnt = 0;

        for(int i=0; i<text.size(); i++){
            if(isspace(text[i])){
                if(flag == true)
                    cnt++;
                
                flag = true;
            }
            else if (v[text[i] - 'a'])
                flag = false;
        }
        if(flag)
            cnt++;

        return cnt;
    }
};




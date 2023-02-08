// R L R S L L
// 0 1 2 3 4 5

class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;
        char left = '\0';
        int count = 0;
        for(char ch : directions) {
            if(left == '\0') {
                left = ch;
                if(ch == 'R'){
                    count++;
                }
            }
            else{
                if(ch == 'L'){
                    if(left == 'R'){
                        collisions += count + 1;
                        left = 'S';
                        count = 0;
                    }else if(left == 'S'){
                        left = 'S';
                        collisions += 1;
                    }
                }else if(ch == 'R'){
                    left = 'R';
                    count += 1;
                }else{
                    if(left == 'R'){
                        collisions += count;
                        count = 0;
                    }
                    left = 'S';
                }
            }
        }
        return collisions;
    }
};

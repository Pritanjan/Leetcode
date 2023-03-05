class Solution {
public:
    int passThePillow(int n, int time) {
        int holder = 1;
        int direction = 1;
        for(int t=0; t<time; t++){
            if(holder == 1 && direction == -1) {
                direction = 1;
                holder += direction;
            }        
            else if(holder == n && direction == 1) {
                direction = -1;            
                holder += direction;
            }
            else             
                holder += direction;
        }    
        return holder;
    }
};

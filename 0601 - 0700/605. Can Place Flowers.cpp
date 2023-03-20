class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int m) {
        int n=f.size();
        for(int i=0;i<n;i++){
            if(f[i]==1)continue;
            else{
                if((i==0||f[i-1]==0)&&(i==n-1||f[i+1]==0)){f[i]=1;m--;}
            }
        }
        return m<=0;
    }
};







class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int cnt = 0;
        for(int i=0; i<f.size(); i++){
            if(f[i] == 0){
                bool emptyLeftPlot = (i == 0) || (f[i - 1] == 0);
                bool emptyRightPlot = (i == f.size() - 1) || (f[i + 1] == 0);

                if(emptyLeftPlot && emptyRightPlot) {
                    f[i] = 1;
                    cnt++;
                }
            }
        }
        return cnt >= n;
    }
};




// bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);

// OR 

// bool emptyLeftPlot;
// if (i == 0 || flowerbed[i - 1] == 0) {
//     emptyLeftPlot = true;
// } else {
//     emptyLeftPlot = false;
// }








class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = 0;
        int size = flowerbed.size();
        int lh = -1;
        for(int i = 0; i < size; ++i){
            if(flowerbed[i] == 1){
                if(lh == -1){
                    num += i/2;
                }
                else{
                    num += (i - lh - 2)/2;
                }
                lh = i;
            }
        }
        if(lh == -1)
            num += (size + 1) / 2;
        else
            num += (size - lh - 1) / 2;
        return num >= n;
    }
};







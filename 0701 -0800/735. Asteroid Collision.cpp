// \\ APPROACH 1 (USING STACK)
      
// 1. If the current asteroid is positive, it is pushed onto the stack.

// 2. If the current asteroid is negative, the stack is checked for any positive
//    asteroids that the current asteroid might collide with.

// 3. If the absolute value of the current asteroid is greater than the top of the stack,
//    the top asteroid is popped from the stack and the current asteroid is checked again.

// 4. If the absolute value of the current asteroid is equal to the top of the stack, 
//    both asteroids are popped. 

// 5. If the absolute value of the current asteroid is less than the top of the stack, 
//    the current asteroid is not added to the stack. 

// 6. If the stack is empty, the current asteroid is added to the result vector.

// 7. After processing all asteroids, the remaining asteroids in the stack are added to the 
//    result vector. 

// 8. Finally, the result vector is returned.



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack <int> s;
        int n = a.size();
        for(int i = 0;i<n;i++){
            if(s.empty())
            {
                s.push(a[i]);
            }
            else{
                while( !s.empty() and s.top()>0 and a[i]<0){
                    if(abs(s.top())<abs(a[i])){
                        s.pop();
                    }
                    else {
                        break;
                    }

                 
                }
                if(!s.empty() and s.top() >0 and a[i]<0){
                    if(abs(s.top())==abs(a[i])){
                        s.pop();
                        continue;
                    }
                    else {
                        continue;
                    }
                }
                else{
                    s.push(a[i]);
                }                
            }

        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin() ,ans.end());
        return ans;
       
    }
};

// Time complexity : O(n) where n is the number of elements in the asteroids vector.
// Because each asteroid is processed once and at most once push and pop operation is done
// for each asteroid. 

// Space complexity : O(n)
// as the maximum number of elements in the stack is equal to the number of elements in the 
// asteroids vector.


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> ans;
        for(int i : A) {
            while(!ans.empty() and ans.back() > 0 and ans.back() < -i){
                ans.pop_back();
            }
            if(ans.empty() or ans.back() < 0 or i > 0){
                ans.push_back(i);
            }
            else if(i < 0 and ans.back() == -i){
                ans.pop_back();
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(auto it: asteroids){
            if(it>=0) st.push(it);
            else{
                while(st.size() && st.top()<abs(it) && st.top()>=0){
                    st.pop();
                }

                if(st.size()==0){
                    st.push(it);
                }
                else{
                    if(st.top()==abs(it)){
                        st.pop();
                    }
                    else if(st.top()<0){
                        st.push(it);
                    }
                }
            }
        }

        vector<int> ans;
        while(st.size()){
            ans.emplace_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};


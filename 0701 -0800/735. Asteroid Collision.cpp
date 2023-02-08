// APPROACH 1 (USING STACK)

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
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int n = asteroids.size();
        vector<int> v;
        stack<int> st;
        
        for(int i=0; i<n; i++){
            if(asteroids[i] > 0)  
                st.push(asteroids[i]);
            else{
                while(!st.empty() && (-1 * asteroids[i]) > st.top())
                    st.pop();
                if(!st.empty() && (-1 * asteroids[i]) == st.top()) 
                    st.pop();
                else if(st.empty())
                    v.push_back(asteroids[i]);
            } 
        }
        
        vector<int> p;
        while(!st.empty()){
            p.push_back(st.top());
            st.pop();
        }
        
        reverse(p.begin(), p.end());
        v.insert(v.end(), p.begin(), p.end());
        
        return v;
    }
};



// Time complexity : O(n) where n is the number of elements in the asteroids vector.
// Because each asteroid is processed once and at most once push and pop operation is done
// for each asteroid. 

// Space complexity : O(n)
// as the maximum number of elements in the stack is equal to the number of elements in the 
// asteroids vector.




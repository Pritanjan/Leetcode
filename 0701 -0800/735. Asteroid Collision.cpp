// A 1 (USING STACK)   

// 1. If the current asteroid is positive, it is pushed onto the stack.
// 2. If the current asteroid is negative, the stack is checked for any positive asteroids that
//    the current asteroid might collide with.
// 3. If the absolute value of the current asteroid is greater than the top of the stack,
//    the top asteroid is popped from the stack and the current asteroid is checked again.
// 4. If the absolute value of the current asteroid is equal to the top of the stack, 
//    both asteroids are popped. 
// 5. If the absolute value of the current asteroid is less than the top of the stack, 
//    the current asteroid is not added to the stack. 
// 6. If the stack is empty, the current asteroid is added to the result vector.
// 7. After processing all asteroids, the remaining asteroids in stack are added to the result vector. 
// 8. Finally, the result vector is returned.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack <int> s;
        int n = a.size();
        for(int i=0; i<n; i++){
            if(s.empty()) s.push(a[i]);
            else{
                while(!s.empty() and s.top() > 0 and a[i] < 0){
                    if(abs(s.top())<abs(a[i])) s.pop();
                    else break;                
                }
                if(!s.empty() and s.top() > 0 and a[i] < 0) {
                    if(abs(s.top())==abs(a[i])) {
                        s.pop();
                        continue;
                    }
                    else continue;
                }
                else s.push(a[i]);            
            }
        }
        
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};


// OR


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> ans;
        for(int i : A) {
            while(!ans.empty() and ans.back() > 0 and ans.back() < -i) ans.pop_back();
            if(ans.empty() or ans.back() < 0 or i > 0) ans.push_back(i);
            else if(i < 0 and ans.back() == -i) ans.pop_back();
        }
        return ans;
    }
};

// Time complexity : O(n) where n is the number of elements in the asteroids vector.
// Because each asteroid is processed once and at most once push and pop operation is done
// for each asteroid. 

// Space complexity : O(n)
// as the max np of elements in the stack is equal to the number of elements in the asteroids vector.






// A 2

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int n = asteroids.size();
        vector<int> v;
        stack<int> st;        
        for(int i=0; i<n; i++){
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else {
                while(!st.empty() && (-1 * asteroids[i]) > st.top()) st.pop();
                if(!st.empty() && (-1 * asteroids[i]) == st.top()) st.pop();
                else if(st.empty()) v.push_back(asteroids[i]);
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





// A 3

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        deque<int> dq;        
        for(int asteroid : asteroids) {
            // Asteroid moving right, just push it
            if(asteroid > 0) dq.push_back(asteroid);
            else {
                // Asteroid moving left
                bool collision = false;
                while(!dq.empty() && dq.back() > 0) {
                    int prev = dq.back();
                    dq.pop_back();
                    
                    // Compare sizes of asteroids
                    if(prev + asteroid < 0) {
                        // The smaller asteroid explodes
                        continue; // Check the next right-moving asteroid
                    }
                    else if(prev + asteroid == 0) {
                        // Both asteroids explode
                        collision = true;
                        break; // Stop checking
                    } 
                    else {
                        // Left-moving asteroid survives
                        collision = true;
                        dq.push_back(prev);
                        break; // Stop checking
                    }
                }

                // No collision with right-moving asteroids
                if(!collision && (dq.empty() || dq.back() < 0)) {
                    dq.push_back(asteroid);
                }
            }
        }
        return vector<int>(dq.begin(), dq.end());
    }
};






// A 4

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int asteroid : asteroids) {
            if(res.empty() || asteroid > 0) res.push_back(asteroid);
            else {
                bool collision = false;
                while(!res.empty() && res.back() > 0) {
                    int prev = res.back();
                    res.pop_back();
                    if(prev + asteroid < 0) continue;
                    else if(prev + asteroid == 0) {
                        collision = true;
                        break;
                    } 
                    else {       
                        res.push_back(prev);
                        collision = true;
                        break;
                    }
                }
                if(!collision && (res.empty() || res.back() < 0)) {
                    res.push_back(asteroid);
                }
            }
        }        
        return res;
    }
};






// A 5

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> LAsteroids;
        stack<int> RAsteroids;
        
        for(int asteroid : asteroids) {
            // Asteroid moving right, push it to the right stack
            if(asteroid > 0) RAsteroids.push(asteroid);
            else {
                // Asteroid moving left
                bool collision = false;
                while(!RAsteroids.empty()) {
                    int RAsteroid = RAsteroids.top();
                    // Compare sizes of asteroids
                    if(RAsteroid < abs(asteroid)) {
                        // The right-moving asteroid is smaller and explodes
                        RAsteroids.pop();
                    }
                    else if(RAsteroid == abs(asteroid)) {
                        // Both asteroids explode
                        RAsteroids.pop();
                        collision = true;
                        break;
                    } 
                    // The left-moving asteroid is smaller or equal, no collision
                    else {            
                        collision = true;
                        break;
                    }
                }
                
                // No collision with right-moving asteroids, push the left-moving asteroid
                if(!collision) LAsteroids.push(asteroid);
            }
        }
        
        // Combine the left and right asteroids from the stacks
        vector<int> res;
        while(!LAsteroids.empty()) {
            res.push_back(LAsteroids.top());
            LAsteroids.pop();
        }
        while(!RAsteroids.empty()) {
            res.push_back(RAsteroids.top());
            RAsteroids.pop();
        }
        
        // Reverse to maintain correct order
        reverse(res.begin(), res.end()); 
        return res;
    }
};






// A 6


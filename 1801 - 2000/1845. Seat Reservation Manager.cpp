// A 1 - Using PQ

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i=1; i<=n; i++) {
            pq.push(i);
        }
    }
    
    int reserve() {
        int tmp = pq.top();
        pq.pop();
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};






// A 2 - Min Heap (without pre-initialization)

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat;
public:
    SeatManager(int n) {
        seat = 1;
    }
    
    int reserve() {
        if(!pq.empty()) {
            int tmp = pq.top();
            pq.pop();
            return tmp;
        }
        int tmp = seat;
        seat++;
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};






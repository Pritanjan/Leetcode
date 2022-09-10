//Explationation 
//step 1  : - In ParkingSystem initialize all the element in vector car
//step 2  : - In addcar check wheteher it is type 1, type 2, or type 3 and decerease the respective car vector at its index

	
	//https://leetcode.com/problems/design-parking-system/

	class ParkingSystem {
	public:
		vector<int> car;
    
		ParkingSystem(int big, int medium, int small) {
			car = {big, medium, small};
		}
    
		bool addCar(int carType) {
			if(carType == 1){
				if(car[0] > 0){
					car[0]--;
					return true;
				}
			}
			
			if(carType == 2){
				if(car[1] > 0){
					car[1]--;
					return true;
				}
			}
        
			if(carType == 3){
				if(car[2] > 0){
					car[2]--;
                return true;
				}
        }
			return false;
		}
	};
	
	/**
	 * Your ParkingSystem object will be instantiated and called as such:
	 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
	 * bool param_1 = obj->addCar(carType);
	 */

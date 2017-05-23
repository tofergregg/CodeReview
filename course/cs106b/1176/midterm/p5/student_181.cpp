static const int DBL_MAX; 

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	int maxDistance = DBL_MAX // have to check if a certain path is below this in the recursive step 
	return bestRouteHelper(distance, startCity, route, maxDistance); 
	
} 

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int>& route, int& maxDistance)
	int totalDistance =0; //Will keep track of each path and see if it is less than the value of max Distance. 
	if (route[0] == route[route.size()-1] && totalDistance<maxDistance) { // if starting position == end 						position. Base case 
				return route; 
	} else {
		for (int i =0; i<grid.size()-1; i++) {
			
			route += i; 
			totalDistance = totalRouteDistance(distance, route);
			bestRouteHelper(distance, startCity + i, route, totalDistance);
			bestRouteHelper(distance, startCity -i, route, totalDistance); ///Goes backwards 
			route.remove(route.size() -1); 
			totalDistance = totalRouteDistance(distance, route);
		} 
		//recalculates total distance of the route 
			
		} 
	}
} 

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//Pseudocode: decrease from a max value, set equal to double at beginning, create a helper function. 
	//Base case: when position at the end equals position at the beginning. 
	//On every iteration, try a new path, recurse again, remove and go back to previous space. 
	//If total route less than max, we can assume recursion was successful. Since we are backtracking, base case is when the salesman ends back at the same place he started. Call total route distance in recursive step. We know that the starting location has been reached when the first element in the vector == last element in the vector. Needs to take in the distance with the 
// function provided? decrement max distance on every recurive call in order to find the best solution possible. On every iteration, pass in new start city. Not just n-1 times since we also have to get back to starting position. 
		
//Start at 0,0, go to 0,1 or 1,0 or 0,2 or 2,0 or 0,3 or 3,0. 
//Recursive backtracking to remove the last element from the vector
		// on every iteration 

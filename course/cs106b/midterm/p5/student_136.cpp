Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	Vector<int> bestRoute; 
	bestRoute.add(DBL_MAX); 
	
	for(int i = 0; i < distance.numRows(); i++) { 
		Vector<int> currentRoute = helperFunction(distance, i); 
		if(totalRouteDistance(distance, currentRoute) < 
		totalRouteDistance(distance, bestRoute)) {
			bestRoute = currentRoute; 
		}
	}
	return bestRoute; 
}


Vector<int> helperFunction(Grid<double> &distance, int nextCity)  { 
	Vector<int> route; 
	Vector<bool> usedCities;
	if(route.size == distance.numRows()){
		return route; 
	} else {  
		for(int n = 0; n < distance.numRows(); n ++) { 
			if(!usedCities.get(n)){
		   		route.add([nextCity][n]); 
				usedCities.set(n, true); 
			} 
		}
		helperfunction(distance, (nextCity + 1)); 
		
		
}
			
	

	

	
//psuedo code: 
		
//the recursive part of this function should take in a starting city and find all of the routes to the other cites in the grid except for the city that it just came from (unless it is the starting city). From there each new city becomes the starting city (recursion) and the process starts over again- the new city looks to connect to citites that have not been used yet. 
	
//base case is when all the cities have been used
	

			
		
	
	
	
	
	



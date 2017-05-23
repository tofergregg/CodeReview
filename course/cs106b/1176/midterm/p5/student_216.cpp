Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> bestRoute;
	HashSet<int> usedCities;
	// Must visit the number of cities plus 1
	int numCities = distance.numRows();
	
	// The route always begins with the starting city
	route.add(startCity);
	// The initial city is of course already visited and only should be added at the end
	usedCities.add(startCity);
	// Calls recursive function to test all possible routes
	recurseBestRoute(distance, startCity, route, usedCities, bestRoute); 
	
	// Returns the best route following the recursive calls
	return bestRoute;
	
}

// Perhaps used a few too many parameters, sorry!
void recurseBestRoute(Grid<double> &distance, int startCity, Vector<int>route, HashSet<int> usedCities, int numCities, Vector<int> &bestRoute){
	// Base Case of when the number of cities left to visit is 0
	if(numCities == 0){
		double routeDist = totalRouteDistance(distance, route);
		double bestDist = totalRouteDistance(distance, bestRoute);
		if(routeDist < bestDist){
			bestRoute = route;
		}
		return;
		
	// Recursive case to find all possible paths	
	}else{
		for(int i = 0; i < distance.numRows - 1; i++){
			// Recursively calls this function to find all possible routes, using a HashSet to guarantee no city is chosen twice
			if(!usedCities.contains(i){
				route.add(i);
				usedCities.add(i);
				numCities--;
				recurseBestRoute(distance, startCity, route, usedCities, numCities, bestRoute);			
			
		}
		// Adds the final city to the route	
		if(usedCities.length() == distance.numRows() - 1){
			route.add(startCity);
			numCities--;
			recurseBestRoute(distance, startCity, route, usedCities, numCities, bestRoute);
		}
			  	
		
	}
	
	
}


Vector<int> bestRouteIterator(Grid<double>& distance, 
							  int &startCity, int &currCity, 
							  Vector<int> &remainingCities, 
							  Vector<int>& currRoute, 
							  double &shortestDist, 
							  Vector<int>& bestRoute);


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// number of cities in total
	int numCities = distance.numCols(); 
	Vector<int> remainingCities;
	// have a vector of total number of cities from 0 to n-1
	// the start city will be added back at the end of recursion
	for (int i = 0; i < numCities;i++){
		remainingCities.add(i);
	}
	
	Vector<int> bestRoute;
	Vector<int> currRoute;
	bestRoute = bestRouteIterator(distance, startCity, startCity,remainingCities,currRoute, DBL_MAX, bestRoute);
	
	return bestRoute;
}

// helper function
Vector<int> bestRouteIterator(Grid<double>& distance, 
							  int &startCity, int &currCity, 
							  Vector<int> &remainingCities, 
							  Vector<int>& currRoute, 
							  double &shortestDist, 
							  Vector<int>& bestRoute){
	// base case
	// if iterated through all cities
	if (remainingCities.isEmpty()){
		// need to go back to the start city
		currRoute.add(startCity);
		double dist = totalRouteDistance(distance, currRoute);
		if (dist < shortestDist){
			shortestDist = dist;
			bestRoute = currRoute;
		}
	} else {
		// recursive case
		// find the next city so that the route distance is the shortest
		localShortestDist = DBL_MAX;
		for (int city:remainingCities){
			currRoute.add(city);
			double currDistance = totalRouteDistance(distance, currRoute);
			if (currDistance < localShortestDist){
				double nextCity = city;
			}
			// need to remove the city from currRoute
			currRoute.remove(city);
		}
		// upon exit the for loop - found the closest next city
		// remove the next city from the remaining city
		remainingCities.remove(nextCity);
		// add to the route
		currRoute.add(nextCity);
		// recursion : currCity is now nextCity
		bestRouteIterator(distance, startCity, nextCity, remainingCities, currRoute,shortestDist, bestRoute);
	}
	return bestRoute;
}
		
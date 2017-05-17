void bestRouteHelper(Grid<double> &distance, int startCity, int currCity, int numCityLeft, Set<int>& visitedCities, Set<Vector<int>>& allRoutes, Vector<int>& currRoute);
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// initialize the shortest distance as infinite, update when we find 
	// a shorter one
    double shortestDistance = DBL_MAX;
	// initialize an empty best route
    Vector <int> bestR;
	Vector<int> route;
	Set<int> visitedCities;
	Set<Vector<int>> allRoutes;
	Vector<int> currRoute;
	// use helper function to calculate all the routes;
	bestRouteHelper(distance, startCity, startCity, distance.numRows()- 1, visitedCities, allRoutes,currRoute);
	// loop to find shortest distance
	for(route:allRoutes){
	   double curr_dist = totalRouteDistance(distance, route);
	   if(curr_dist < shortestDistance){
		shortestDistance = curr_dist;
		bestR = route;
	    }
	}
	return bestR;
}

void bestRouteHelper(Grid<double> &distance, int startCity, int currCity, int numCityLeft, Set<int>& visitedCities, Set<Vector<int>>& allRoutes, Vector<int>& currRoute){
	// base case: number of city left is zero
	if(numCityLeft == 0){
		// if we return to the start, then add that route to allRoutes;
		if(startCity == currCity){
		allRoutes.add(currRoute);
		}
		// clear the currRoute and visitedCities to avoid endless adding
		currRoute.clear();
		visitedCities.clear();
	    return;
    // add nothing if number of city left is zero and we are not returning the start
    // recursive case: currCity is the index of row, loop around colomns to find next city to go
	}else if (numCityLeft != 0){
		for(int i = 0; i < distance.numCols(); i++){
			//add current city to the visited cities
			visitedCities.add(currCity);
			int newCity = distance[currCity][i];
			// if the next city has never been visited
			if(!visitedCities.contains(newCity)){
				vitiedCities.add(newCity);
				currRoute.add(newCity);
				bestRouteHelper(distance, startCity, newCity, numCityLeft - 1, visitedCities, allRoutes, currRoute);
			}
		}
	}
}



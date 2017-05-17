/* To find the best route, this function first finds all possible 
 * routes to get from and back to the city. Then, it determines 
 * which of the possible routes has the shortest distance.
 */
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<Vector<int>> allRoutes;
 	// finds all routes
	findRoutes(allRoutes, startCity, startCity);
	
	// finds and returns shortest route 
	return findShortest(distance, allRoutes);
}


void findRoutes(Grid<double> &distance, 
				Vector<Vector<int>> allRoutes, int currCity,
				int endCity, Vector<int> currRoute) {
	
	if (currCity == endCity) { // base case
		currRoute.add(endCity);
		routes.add(currRoute);
	}
	
	for (int i = 0; i < distance.numRows(); i++) {
		if (!visited(i, currRoute)) {
			currRoute.add(i);
		}
		
		findRoutes(distance, allRoutes, i, endCity, currRoute);
	} 
	
	return routes;
}

// helper function to see if the salesman has already visited a city
bool visited(int currCity, Vector<int> currRoute) {
	for (int i : currRoute) {
		if (i == currCity) {
			return true;
		}
	}
	
	return false;
}

Vector<int> findShortest(Grid<double> &distance, 
						 Vector<Vector<int>> allRoutes){
	double bestDist = DBL_MAX;
	Vector<int> bestRoute;
	
	for (Vector<int> currRoute : allRoutes) {
		double currDistance = totalRouteDistance(distance, 
												 currRoute);
		if (currDistance < bestDist) {
			bestDist = currDistance;
			bestRoute = currRoute;
		}
	}
	
	return bestRoute;
}



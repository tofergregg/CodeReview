Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// number of cities to visit
	int numCities = distance.numRows();
	Set<int> possibleCities;
	// creates a set of all the cities
	for(int k = 0; k < numCities; k++) {
		possibleCities.add(k);
	}
	// creates a vector of all the potential routes
	Vector<Vector<int> > possibleRoutes;
	// initializes the shortest distance
	double shortestDistance = DBL_MAX;
	Vector<int> shortestRoute;
	// removes the start city from possible destinations
	possibleCities.remove(startCity);
	// start recursion
	routes(startCity, possibleCities, numCities, currentRoute, possibleRoutes);
	// checks all possible routes
	for(int i = 0; i < possibleRoutes.size(); i++) {
		currRoute = possibleRoutes(i);
		double currRouteDist = totalRouteDistance(distance, currRoute);
		if(currRouteDist < shortestDitance) { // checks if this route is shorter than the current shortest route
			// saves shortest route
			shortestDistance = currRouteDist;
			shortestRoute = currRoute;
		}
	}
	return shortestRoute;
}

void routes(int startCity, Set<int> &possibleCities, int numCities, Vector<int> currentRoute, Vector<Vector<int> > &possibleRoutes) {
	if(citiesVisited.size() == numCities) { //all cities visited
		currentRoute.add(currentRoute(0)); //return to starting city
		possibleRoutes.add(currentRoute);
	} else {
		for(int j = 0; j < numCities; j++) { // iterates through all cities
			if(possibleCities.contains(j)) { //if the city hasn't been visited on the current route
				startCity = j; // choose a city
				currentRoute.add(j);
				possibleCities.remove(j); // remove this city from possible travel in future routes
				// recursive call
				routes(citiesVisited, numCities, currentRoute, possibleRoutes);
				possibleCities.add(j) // unchoose city for future routes
			}
		}
	}
}
		


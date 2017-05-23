Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// Populate HashSet with all cities to visit (all but starting)
	HashSet<int> citiesToVisit;
	for (int i = 0; i < distance.numRows(); i++) {
		if (i != startCity) {
			citiesToVisit.add(i);
		}
	}	
	
	int currentBestPath = DBL_MAX; // Current best path
	int currentCity = startCity;   // Current city
	Vector<int> route;             // Output vector for current route
	route.add(startCity);
	Vector<int> bestRoute;         // Output vector for solution
	
	bestRoute(distance, startCity, citiesToVisit, route, bestRoute, currentBestPath)

	return bestRoute;
}

void bestRoute(Grid<double> &distance, int startCity, HashSet<int>& citiesToVisit, Vector<int>& route, Vector<int>& bestRoute, int& currentBestPath) {
	double currentPathDistance = 0;
	// Base case: no more cities to visit. Add start city, calculate distance and compare to 
	if (citiesToVisit.size == 0) {
		route.add(startCity);
		currentPathDistance = totalRouteDistance(distance, route);
		if (currentPathDistance < currentBestPath) {
			currentBestPath = currentPathDistance;
			bestRoute = route;
		}
		return;
	}
	
	// Recursive case: more than one city to visit, recurse.
	if (citiesToVisit.size > 0) {
		for (int city : citiesToVisit) {
			citiesToVisit.remove(city);
			route.add(city);
			bestRoute(distance, startCity, citiesToVisit, route, bestRoute, currentBestPath);
			route.remove(city);
			citiesToVisit.add(city);
		}
	}
	
	return;
}

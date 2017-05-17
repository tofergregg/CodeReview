Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route.add(startCity);
	Set<int> numCities;
	Vector<Vector<int>> allRoutes;
	for (int i = 1; i < distance.numRows(); i++) {
		numCities.add(i);
	}
	return recursiveHelper(distance, startCity, route, numCities, allRoutes);
}

Vector<int> recursiveHelper(Grid<double> &distance, int start, Vector<int> route, Set<int> numCities, Vector<Vector<int>> &allRoutes) {
	if (numCities.size() == 0) {
		route.add(start);
		allRoutes.add(route);
		return route;
	}
	for (int city: numCities) {
		Vector<int> currentRoute = recursiveHelper(distance, start, route + city, numCities.remove(city), allRoutes);	 
	}
	double shortest = DBL_MAX;
	Vector<int> bestPath;
	for (Vector<int> possibleRoute: allRoutes) {
		double routeDistance = totalRouteDistance(distance, possibleRoute);
		if (routeDistance < shortest) {
			shortest = routeDistance;
			bestPath = possibleRoute;
		}
	}
	return bestPath;
}
												   
												   	
	

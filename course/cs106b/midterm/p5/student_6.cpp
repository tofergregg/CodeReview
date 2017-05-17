void bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &route, Set<int> &cities, double &bestDist, Vector<int> &bestRoute) {
	// base case
	if (cities.isEmpty()) {
		route.add(startCity);
		double routeDist = totalRouteDistance(distance, route);
		if (routeDist < bestDist) {
			bestDist = routeDist;
			bestRoute = route;
		}
		route.remove(route.length() - 1);
	} else {
	// recursive case
		for (int city : cities) {
			cities.remove(city);
			route.add(city);
			bestRouteHelper(distance, startCity, route, cities, bestDist, bestRoute);
			route.remove(route.length() - 1);
			cities.add(city);
		}
	}
}
		

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> bestRoute;
	double bestDist = DBL_MAX;
	route.add(startCity);
	Set<int> cities;
	int numCities = distance.numRows();
	for (int i = 0; i < numCities; i ++) {
		cities.add(i);
	}
	cities.remove(startCity);
	bestRouteHelper(distance, startCity, route, cities, bestDist, bestRoute);
	return bestRoute;
}
				
	

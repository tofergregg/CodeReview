Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> citiesLeft;
	// populate set of cities remaining - initially contains all bu the start city
	for (int i=0; i < distance.numRows(); i++) {
		if (i != startCity) {
			citiesLeft.add(i);
		}
	}
	Vector<int> route;
	return Vector<int> bestRoute(distance, startCity, citiesLeft, route);
}


Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> &citiesLeft,
					  Vector<int>route) {
	// contains possible routes mapped to their distance
	Map<Vector<int>, double> routeDists;
	
	// base case: if all cities have been visited
	if (citiesLeft.size() == 0) {
		int dist = totalRouteDistance(distance, route);
	}
	// recursive case
	else {
		for (int currentCity : citiesLeft) {
			route.add(currentCity);
			startCity = currentCity;
			citiesLeft.remote(currentCity);
			int dist = bestRoute(distance, startCity, citiesLeft, current, route);
			routeDists.put(route, dist);
			citiesLeft.add(currentCity);
		}
	}
	double min = DBL_MAX;
	Vector<int> bestPath;
	for (Vector<int> route : routeDists) {
		if (routeDists[route] < min) {
			min = dist;
			bestPath = route;
		}
	}
	return bestPath;
}



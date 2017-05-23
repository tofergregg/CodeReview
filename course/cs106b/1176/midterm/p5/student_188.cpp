Vector<int> bestRouteHelper(Grid<double> &distance, int &startCity, Vector<int> &route, Set<int> &citiesUsed, Map <double, Vector<int>> &options);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route.add(startCity);
	Set<int> citiesUsed;
	citiesUsed.add(startCity);
	Map <double, Vector<int>> options;
	return bestRouteHelper(distance, startCity, route, citiesUsed, options);
}
	
Vector<int> bestRouteHelper(Grid<double> &distance, int &startCity, Vector<int> &route, Set<int> &citiesUsed, Map <double, Vector<int>> &options) {
	if (route.size() == distance.numRows()) {
		route.add(startCity);
		double distance = totalRouteDistance(distance, route);
		options.put(distance, route);
		return route;
	}
	for (int r = 0; r < distance.numRows(); r++) {
		if (!citiesUsed.contains(r)) {	
			route.add(r);
			citiesUsed.add(r);
			bestRouteHelper(distance, startCity, route, citiesUsed, options);
			route.remove(route.size() - 1);
		}
	}
	Vector<int> bestRoute;
	double leastDistance = DBL_MAX; 
	for (double distance : options) {
		if (distance < leastDistance) {
			leastDistance = distance;
			bestroute = options[distance];
	    }
	}
	return bestRoute;
}
		
			

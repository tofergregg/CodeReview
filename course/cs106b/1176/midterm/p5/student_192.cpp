Vector<int> bestRouteHelper(Grid<double>& distance, int start, int startCity, Vector<int> route, double total) {
	if (start == startCity && route.contains(start)) {
		route.add(startCity);
		int newTotal = totalRouteDistance(distance, route);
		if (newTotal < total) {
			total = newTotal;
			return route;
		}
		return //old 
	}
	for (int c = 0; c < grid.numCols(); c++) {
		if (startCity != c && !route.contains(c)) {	
			route.add(startCity);
			nextCity = c;
			bestRouteHelper(distance, start, nextCity, route);
			route.remove(route.size() - 1);
			}
		}
	}
}


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int start = startCity;
	double total = DBL_MAX;
	return bestRouteHelper(distance, start, startCity, {}, total);
}

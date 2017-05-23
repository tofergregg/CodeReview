Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route.add(startCity);
	Vector<int> bestR;
	return Vector<int> bestRoute(distance, startCity, route, bestR, DBL_MAX);
}



Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> &route, Vector<int> &bestR, int &shortest) {
	//base case: if a route has visited all cities
	if (route.size() == distance.width()) {
		route.add(startCity);
		int thisRouteDist = totalRouteDistance(distance, route);
		if (thisRouteDist < shortest) {
			shortest = thisRouteDist;
			return bestR;
		}
	}
	
	//recursive case
	for (int i = 0; i < distance.width()); i++) {
		if (!route.contains(i)) {
			route.add(i);
			bestR = bestRoute(distance, startCity, route, bestR, shortest);
			route.remove(route.size() - 1);
		}
	}
	
	return bestR;
}
		
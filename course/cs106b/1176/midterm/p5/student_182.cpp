void helper(Grid<double> &distance, int startCity, int currentCity, Vector<int>& route, Vector<Vector<int>>& routes) {
	if (currentCity == startCity) {
		routes.add(route);
	} else {
		for (int nextCity = 0; nextCity < distance.numCols(); nextCity++) {
			if (nextCity != currentCity) {
				route.add(nextCity);
				helper(distance, startCity, nextCity, route, routes);
			}
		}
	}
}

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<Vector<int>> routes;
	Vector<int> route;
	for (int nextCity = 0; nextCity < distance.numCols(); nextCity++) {
		if (nextCity != startCity) {
			route.add(startCity);
			helper(distance, startCity, nextCity, route, routes);
		}
	}
	double minTotalDistance = DBL_MAX;
	int shortestRoute = 0;
	for (for i = 0; i < routes.size(); i++) {
		double totalDistance = totalRouteDistance(distance, routes[i]);
		if (totalDistance < minTotalDistance) {
			shortestRoute = i;
			minTotalDistance = totalDistance;
		}
	}
	return routes[shortestRoute];
}

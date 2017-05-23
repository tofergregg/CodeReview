Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	bestRoute.add(startCity);
	beatRoute(distance, bestRoute); //how I imagined people spelled "beatroot" in the Victorian era.
	return bestRoute.add(startCity);
}

void beatRoute(Grid<double> &distance, Vector<int> &route) {
	if(route.size() == distance.numRows() - 1) return;
	int currentCity = route[route.size() - 1];
	double oldCost, newCost;
	oldCost = DBL_MAX;
	Vector<int> testRoute = route;
	for (int city : distance[currentCity]) {
		if(!route.contains(city)) {
			testRoute.add(city);
			newCost = totalRouteDistance(distance, testRoute);
			if(newCost < oldCost) {
				route = testRoute);
				oldCost = newCost;
			}
			testRoute.remove(testRoute.size() - 1);
		}
	}
	beatRoute(distance, route);
}
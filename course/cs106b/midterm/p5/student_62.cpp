Vector<int> bestRoute(Grid<double> &distance, int startCity
{	
	Vector<int> route;
	int shortest;
	int citiesLeft = distance.numRows();
	Set<Vector<int>> allRoutes;
		for (int i=0; i < distance.numRows() -1; i++) {
			route.add(i);
			allRoutes.add(route)
	}
	return bestHelper(distance, startCity, citiesLeft, route, allRoutes);
}

Vector<int> bestHelper(Grid<double> &distance, int startCity, int citiesLeft, Vector<int> route, Set<Vector<int>> allRoutes) {
	int shortest = DBL_MAX;
	if (distance <= shortest) {
		return route;
	} else {
		for (Vector<int> : allRoutes ) {
			distance = totalRouteDistance(distance, route);
			bestHelper(distance, i, citiesLeft - 1, route, allRoutes);
}
	



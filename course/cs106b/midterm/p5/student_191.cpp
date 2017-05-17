void bestRouteHelper(Grid<double> &distance, int startCity, int fromCity, Vector<int> route, Vector<Vector<int>> &routesVec);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
		
	Vector<Vector<int>> routesVec;
	
	int fromCity = startCity;
	Vector<int> startingRoute;
	startingRoute.add(startCity);
	bestRouteHelper(distance, startCity, fromCity, startingRoute, routesVec);
	
	Vector<int> bestRoute;
	double minDistance = DBL_MAX;
	for (Vector<int> route : routesVec) {
		if (totalRouteDistance(distance, route) < minDistance) {
			minDistance = totalRouteDistance(distance, route);
			bestRoute = route;
		}
	}
	return bestRoute;
}
		 
void bestRouteHelper(Grid<double> &distance, int startCity, int fromCity, Vector<int> route, Vector<Vector<int>> &routesVec) {
	// base case:
	if (fromCity == startCity) {
		routesVec.add(route);
	} else { //recursive case: fromCity != startCity
		for (int i = 0; i < distance.numCols(); i++) {
			if (i != fromCity) {
				Vector<int> newRoute = route;
				newRoute.add(i);
				bestRouteHelper(distance, startCity, i, newRoute, routesVec);
			}
		}
	}
}

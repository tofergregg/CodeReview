Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// routeLength is the # of cities in the route
	int routeLength = distance.numRows();
	// the route is initially just the start city
	Vector<int> route = {startCity};
	return bestRoute(distance, route, routeLength);
}

Vector<int> bestRoute(Grid<double &distance, Vector<int> route, int routeLength) {
	// base case: complete route - just add back start city
	if(route.size() == routeLength){
		route.add(route[0]);
		return route;
	}
	
	// recursive case: incomplete route -- test route for all cities 	 // left to be added next
	Vector<int> bestRoute;
	Vector<int> testRoute;
	double bestRouteDistance = DBL_MAX;
	for(int city = 0; city < routeLength; city++){
		testRoute = route;
		if(!route.contains(city)){
			testRoute.add(city);
			testRoute = bestRoute(distance, testRoute, startCity);
			if(totalDistance(distance, testRoute) < bestRouteDistance) {
				bestRoute = testRoute;
				bestRouteDistance = totalDistance(distance, bestRoute);
			}
		}
	}
	return bestRoute;
}	

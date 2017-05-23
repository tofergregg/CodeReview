double totalRouteDistance(Grid<double> &distance, Vector<int> &route);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> cityStopsLeft;
	cityStops.add(startCity);
	// 4 rows, 4 cities, 4 stops ex. {0,1,2,3}
	// add extra for the startCity (start and end there, so use twice)
	for (int i = 0; i < distance.numRows(); i++) {
		stops.add(i);
	}
	double distTraveled = DBL_MAX;
	Vector<int> currentRoute = {startCity};
	return bestRouteHelper(distance, startCity, cityStopsLeft, distTraveled, currentRoute);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &cityStopsLeft, double &distTraveled, Vector<int> currentRoute) {
	// start with infinite distance. at end, return path with lowest dist
	// if out of stops, return the path
	// otherwise, go to the next city
	// calculate distance
	// if dist < lowestDist
	
	if (cityStops.isEmpty()) return currentRoute;
	
	for (int i = 0; i < distance.numRows(); i++) {
		double distBWCities = distance[startCity][i];
		cityStops.remove(i);
		currentRoute.add(i);
		double calcDist = totalRouteDistance(distance, currentRoute);
		if (calcDist < distTraveled) {
			distTraveled = calcDist);
		}
		bestRouteHelper(distance, i, cityStopsLeft, distTraveled, currentRoute);
		cityStops.add(i); // add original checked one back in
	}
}
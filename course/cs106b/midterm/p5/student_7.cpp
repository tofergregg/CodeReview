Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Map<int, Vector<int>> allRoutes;
	for (int i=0; i<distance.numCols(); i++) {
		// Based on way the helper is structured, I need to make sure that the input for currentCity is not startCity, thus the following if statement:
		if (i != startCity) {
			Vector<int> route;
			route.add(startCity);
			Set<int> visitedCities;
			visitedCities.add(startCity);
			route.add(findaroute(distance, startCity, i, route, visitedCities));
			allRoutes.put(totalRouteDistance(distance, route), route);
		}
	}
	//Assuming (potentially incorrectly) that 'Map' Class automatically orders all its keys by ascending numerical value. If this is true, Map @ index (0) should be the lowest distance route... Lets hope I assumed correctly :)
	return Map[0];
}

Vector<int> findaroute(Grid<double> &distance, int startCity, int currentCity, Vector <int> &route, Set<int> &visitedCities) {
	int dist;
	//basecase, if you have reached beginning city and traveled to each city at least once (can have traveled to cities multiple times, including start city)
	if (startCity == currentCity && checkSet(visitedCities, distance)) return route;
	else {
		route.add(currentCity);
		visitedCities.add(currentCity);
		for (i=0; i<distance.numCols; i++) {
			if (i != currentCity) {
				route.add(findaroute(distance, startCity, currentCity, route);
			}
		}
	}
	return route;
}
 /** This function checks to see if each city has been traveled to at least once */
bool checkSet (Set<int> &visitedCities, Grid<double> &distance) { 
	bool fullset = true;
	for (int i=0; i<distance.numCols(); i++) {
		if (!visitedCities.contains(i)) {
			fullset = false;
		}
	}
	return fullset;
}
		
	

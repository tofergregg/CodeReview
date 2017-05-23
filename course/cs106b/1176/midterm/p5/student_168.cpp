Vector<int> routeHelper(Grid<double> &distance, int startCity, Vector<int> &route, int miles, int numCities, Vector<int> &bestRoute, int bestMiles) {
	//base case: validate solution; otherwise, return default/empty solution
	if (numCities == 0) {
		return bestRoute;
	}
	//recursive case: make all recursive calls, then output shortest distance
	for (int i = 0; i < numCities; i++) {
		//choosing a city
		if (i != startCity) {
			int dist = distance[startCity][i];
			route.add(i);
			routeHelper(distance, i, route, miles + dist, numCities-1);			
			//finding the best solution
			if (miles < bestMiles) {
				bestRoute = route;
			//unchoosing
			route.remove(route.size()-1);
		}
	}
}

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> bestRoute;
	int miles;
	int bestMiles;
	int numCities = distance.numCols();
	return routeHelper(distance, startCity, route, miles, numCities, bestRoute, bestMiles);

	
	
	/* First step: move from the starting city to the City 2.
		Call recursion on that.  Complete that path.
		
		Then: unchoose City 2 and try City 3
		Call recursion on that.  Complete that path.
		
		Continue for all city choices.  Get numCity paths.
		
		Return the path that is the shortest.
	*/

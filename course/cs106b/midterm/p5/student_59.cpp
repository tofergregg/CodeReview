Vector<int> bestRoute(Grid<double>& distance, int startCity) {
	// keeps track of all possible routes
	Vector<Vector<int>> routes;
	Set<int> visitedCities;
	visitedCities.add(startCity);
	bestRouteHelper(distance, startCity, routes, visitedCities);
	int bestRouteIndex = 0;
	int minDist = totalRouteDistance(distance, routes[0];
	for(int i = 1; i < routes.length(); i++) {
		int currDist = totalRouteDistance(distance, routes[i]);
		if(currDist < minDist) {
			bestRouteIndex = i;
		}
	}
	return routes[i];
}

Vector<int> bestRouteHelper(Grid<double>& distance, int startCity, Vector<Vector<int>>& routes, Set<int>& visitedCities) {
	// base case: if route complete, add to vector of possible routes
	if(possible.length() == distance.numRows()+1) {
		routes.add(possible);
	}
	// recursive case
	else {
		Vector<int> possible;
		possible.add(startCity);
		for(int i = 0; i < distance.numRows(); i++) {
			if(!(visitedCities.contains(i))) {
				possible.add(i);
				visitedCities.add(i);
				bestRouteHelper(distance, startCity, routes, visitedCities);
				possible.remove(i);
		}
		// adds start city as final destination
		possible.add(startCity);
	}
}
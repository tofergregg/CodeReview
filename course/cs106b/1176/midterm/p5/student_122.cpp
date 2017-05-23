Vector<int> bestRoute(Grid<double> &distance, int startCity) {

	// class of problem: best possible solution
	// want to keep track of cities already traveled to - can only go to each city once
	// want to keep track of distance
	
	// base case: start city equals end city and have been to every city
	// base case: 
	// recursive case: build up or tear down?
	
	// check knapsack problem
	// should I make a set of cities already traveled to?
	Vector<int> soFar;
	bestRoute(distance, startCity, soFar, 0);
}

Vector<int> bestRoute(Grid<double> & distance, int startCity, Vector<int> soFar, int shortestDistance) {
	// Set<int> citiesVisited;
	
	// base case: start city equals end city and have been to every city
	if ((startCity == soFar[soFar.length() - 1]) && soFar.length() == distance.nCols()) {
		return soFar;
	} else {
		
		int localShortestDistance = shortestDistance;
		
		// loop through list of cities
		for (int i = 0; i < distance.nCols(); i++) {
			// check if a new city should be added
			Vector<int> localRoute = bestRoute(distance, startCity, soFar.add(i), shortestDistance);
			if (totalRouteDistance(distance, route) < shortestDistance) {
				shortestDistance = totalRouteDistance(distance, route);
			}
		}
	}
}
								   
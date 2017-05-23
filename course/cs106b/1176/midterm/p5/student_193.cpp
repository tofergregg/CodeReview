Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int nCities = distance.nRows();
	Vector<int> currentRoute;
	currentRoute.add(startCity);
	int currentCity = startCity;
	Vector<int> bestRoute;
	int bestDistance = DBL_MAX;
	Set<int> citiesVisited;
	// Base case: we have traveled to all cities and returned to the starting city
	if (distance[currentCity][startCity] == 0 &&
		currentRoute.size == nCities + 1) {
		return bestRoute;
	// Recursive case: we have more traveling to do
	} else {
		// Find new route
		for(int nextCity = 0; nextCity < nCities; nextCity++) {
			if(!citiesVisited.contains(nextCity)) {
				// Choose
				distance += [currentCity][nextCity];
				currentRoute.add(nextCity);
				currentCity = nextCity;
			}
		}
	}
}

// Mess. Sorry.


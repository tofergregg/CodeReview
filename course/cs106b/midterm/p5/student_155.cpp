Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> best;
	best.add(startCity);
	Set<int> citiesLeft;
	for(int i = 0; i < distance.numRows() - 1; i ++) {
		citiesLeft += i;
	}
	citiesLeft -= startCity;
	
	return routeRecurse(distance, startCity, best, citiesLeft);
}


Vector<int> routeRecurse(Grid<double>& distance, int startCity,
						 Vector<int>& best, Set<int>& citiesLeft) {
	citiesLeft.remove(best[best.size() - 1]);
	// base case:
	if(citiesLeft.isEmpty()) {
		if(best[best.size() - 1] != startCity) best.add(startCity);
		return best;
	}

	// recursive case:
	Vector<int> shortest;
	shortest.add(DBL_MAX);
	for(int city: citiesLeft) {
		best.add(city);
		if(totalRouteDistance(distance,
							  routeRecurse(distance, startCity,
							best, citiesLeft)) < totalRouteDistance(distance, shortest)){
			shortest = best;
		}
		best.remove(best.size() - 1);
	}
	return shortest;
	
}


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> cities;
	for (int i = 0; i < distance.numRows(); i++) {
		cities.add(i);
	}
	Vector<int> currRoute;
	currRoute.add(startCity);
	return bestRouteHelper(distance, startCity, DBL_MAX, cities, currRoute);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int bestDistance, Vector<int> &cities, Vector<int> &currRoute) {
	// base case: no cities left to travel
	if (cities.isEmpty()) return currRoute;
	Vector<int> bestRoute;
	// recursive case: still have cities to explore
	for (int i : cities) {
		int city = cities[i];
		// only want to go back to start city at the very end
		if (city != startCity || cities.size() == 1) {
			// choose
			cities.remove(i);
			currRoute.add(city);
			// recurse
			currRoute = bestRouteHelper(distance, startCity, 
							bestDistance, cities, currRoute);
			// calculate distance
			double currDistance = totalRouteDistance(distance, currRoute);
			// compare and select min
			if (currDistance < bestDistance) {
				bestDistance = currDistance;
				bestRoute = currRoute;
			}
			// unchoose
			cities.insert(i, city);
			currRoute.remove(city);
		}
	}
	return bestRoute;
}
	
			

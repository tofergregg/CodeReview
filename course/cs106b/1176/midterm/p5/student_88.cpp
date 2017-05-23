Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// The vector to eventually return. Initially populate it with
	// the startCity.
	Vector<int> solution;
	solution.add(startCity);
	
	// The initial route
	Vector<int> initial;
	initial.add(startCity);
	
	// The vector of cities that is not startCity.
	Vector<int> cities;
	for (int i = 0; i < distance.numCols(); i++) {
		if (i != startCity) {
			cities.add(i);
		}
	}
	
	bestRoute(distance, startCity, cities, initial, solution, DBL_MAX);
	
	return solution;
}

void bestRoute(const Grid<double>& distance, int startCity, Vector<int>& remainingCities,
			   Vector<int>& routeSoFar, Vector<int>& bestRoute, double bestDistance) {
	// If the distance so far exceeds the best distance, why bother?
	if (totalRouteDistance(distance, routeSoFar) > bestDistance) {
		return;
	}
	
	// We've visited all cities
	if (remainingCities.isEmpty()) {
		// Need to complete the loop
		routeSoFar.add(startCity);
		double distanceOfRoute = totalRouteDistance(distance, routeSoFar);
		
		if (bestDistance > distanceOfRoute) {
			// If I'm not mistaken, doing bestRoute = routeSoFar
			// will actually "tie" them together such that any changes to
			// routeSoFar will affect bestRoute. That is not desirable.
			copyRoute(routeSoFar, bestRoute);
			bestDistance = distanceOfRoute;
		}
		
		// Need to remove the added startCity
		routeSoFar.remove(routeSoFar.size() - 1);
		return;
	}
	
	for (int i = remainingCities.size() - 1; i >= 0; i--) {
		int removedCity = remainingCities[i];
		
		remainingCities.remove(i);
		routeSoFar.add(removedCity);
		
		bestRoute(distance, startCity, remainingCities, routeSoFar, bestRoute, bestDistance);
		
		// Add back the removed city, but remove it from the routeSoFar
		routeSoFar.remove(routeSoFar.size() - 1);
		remainingCities.insert(i, removedCity);
	}
}

// Copies the members of source into dest.
void copyRoute(const Vector<int>& source, Vector<int>& dest) {
	dest.clear();
	
	for (int number : source) {
		dest.add(number);
	}
}
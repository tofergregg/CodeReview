

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// vector to track the best route
	Vector<int> best;
	Vector <int> best.add(startCity);
	// number of cities to travel is the height of grid
	int remainingCities = distance.numRows();
	// get vector with all cities
	Vector<int> allCities;
	for (int i = 0; i < distance.numRows(); i++) {
		allCities.add(i);
	}
	// keep track of where we've been
	Set<int> visitedCities;
	// initialize next city to something
	int nextCity = startCity;
	// recurse
	bestRouteHelper(distance, 
					startCity, 
					nextCity,
					allCities,
					visitedCities,
					remainingCities, 
					best);
	return best;
}

Vector<int> bestRouteHelper(Grid<double> &distance, 
							int startCity, 
							int nextCity,
							Vector<int>& allCities,
							Set<int> visitedCities,
							int remainingCities,
							Vector<int>& best) {
	// just set the best distance to something
	int bestDistance = DBL_MAX;
	// base case: if there are remaining cities and we're back home
	if (remainingCities != 0 && startCity == nextCity) {
		return;
	}
	// if we've run out of cities, just return 
	} else if (remainingCities == 0 && startCity == nextCity) {
		if (isBest(best, bestDistance)) {
			return best
		}		
	} else {
		for (int city : allCities) {
			// if we have not already visited that city
			if (!visitedCities.contains(city)) {
				// choose a city 
				allCities.remove(city);
				best.add(city);
				visitedCities.add(city)
				// explore the paths from that city
				bestRouteHelper(distance, 
						startCity, 
						city,
						allCities,
						visitedCities,
						remainingCities, 
						best);
				// unchoose that city
				allCities.add(city);
				best.remove(city);
			}	
		}
	}
}

// check if the current route is the best
bool isBest(Vector<int> route, int bestDistance) {
	int currentDistance = totalRouteDistance(route);
	if (currentDistance < bestDistance) {
		bestDistance = currentDistance;
		return true
	} else {
		return false
	}
}


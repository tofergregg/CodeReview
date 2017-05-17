Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numCities = distance.numCols();
	Vector<int> bestRoute;
	bestRoute.add(startCity);
	Vector<int> cities;
	for (int i = 0; i < numCities; i++) {
		cities.add(i);
	}
	if (cities.isEmpty()) { // base case
		return bestRoute;
	}
	for (int city: cities) {
		// if it's the shortest distance, add it to bestRoute
		// and remove the end city from Vector<int> cities
		int shortestCity = findShortestDistance(distance, 
												startCity, cities)
			bestRoute.add(shortestCity);
		}
		for (int i = 0; i < cities.size(); i++) {
			if (cities[i] = shortestCity) {
				cities.remove(i);
			}
		}
		int newStartCity = bestRoute[bestRoute.size() - 1];
		bestRoute(distance, newStartCity);
		return bestRoute;
		}
}
			

int findShortestDistance(Grid<double> &distance, int startCity, 
						Vector<int> &cities) {
	int currDistance = DBL_MAX;
	int shortestCity = 0; 
	for (int city : cities) {
		if (distance[startCity][city] != 0) {
			int distance = distance[startCity][city];
			if (distance <= currDistance) {
				currDistance = distance;
			}
		}
	}
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i] == currDistance) {
			shortestCity = i; 
		}
	}
	return shortestCity; 
}




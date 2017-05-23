/** utility function. Returns the shortest part from currentCity to endCity, visiting all the remaining cities */
Vector<int> shortestPath(const Grid<double>& distance, HashSet<int>& remaining, int currentCity, int endCity) {
	if (remaining.isEmpty()) {
		/* no more remaining cities, going straight from currentCity to endCity */
		Vector<int> path;
		path.add(endCity);
		path.add(currentCity);
		return path;
	}
	
	double shortest = DBL_MAX; // stores shortest distance from currentCity to endCity
	Vector<int> bestPath; // stores shortest path from currentCity to endCity
	
	for (int city: remaining) {
		// try out visiting one of the remaining cities
		HashSet<int> newRemaining = remaining;
		// we create a new HashSet to avoid interference with for loop (might be possible to do more elegantly)
		newRemaining.remove(city);
		Vector<int> restOfPath = shortestPath(distance, newRemaining, city, endCity);
		// recursively find shortest path from city to endCity, now with one fewer remaining city
		double newDist = totalRouteDistance(distance, restOfPath) + 
						distance[currentCity][city];
		// compute distance currentCity -> city -> restOfPath
		if (newDist < shortest) {
			// found a new candidate for shortest
			shortest = newDist;
			bestPath = restOfPath;
		}
	}
	bestPath.add(currentCity);
	return bestPath;
}	

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int n = distance.numRows(); // number of cities
	HashSet<int> remaining;
	// initialize remaining set to be everything except startCity
	for (int i = 0; i < n; ++i) {
		if (i != startCity) {
			remaining.add(i);
		}
	}
	// find shortestPath from startCity back to startCity, visiting all other cities exactly once
	return shortestPath(distance, remaining, startCity, startCity); 
}

void bestRoute(Grid<double> &distance, int startCity, set<int> remainingCities, Vector<int> &bestPath, Vector<int> currentPath, double pathDistance, double &shortest)
	
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// create data structure with all of the cities but the start one
	set<int> allCities;
	for (int i = 0; i < distance.numCols(); i++) {
		allCities.add(i);
	}
	allCities.remove(startCity);
	Vector<int> path;
	path.add(startCity);
	bestRoute(distance, startCity, allCities, path, path, 0, DBL_MAX);
	return path;
}

void bestRoute(Grid<double> &distance, int startCity, set<int> remainingCities, Vector<int> &bestPath, Vector<int> currentPath, double pathDistance, double &shortest) {
	int lastVisited = currentPath[currentPath.size() - 1];
	// base case of finished path, could edit bestPath and shortest
	if(remainingCities.isEmpty()) {
		if (pathDistance + distance[lastVisited][startCity] < shortest) {
			shortest = pathDistance + distance[lastVisited][startCity];
			bestPath = currentPath;
		}
		return;
	} 
	// recursive case to test all possible paths to another city
	else {
		for (int city : remainingCities) {
			pathDistance += distance[lastVisited][city];
			currentPath.add(city);
			remainingCities.remove(city);
			bestRoute(distance, startCity, reaminingCities, bestPath, currentPath, pathDistance, shortest);
		}
	}
}

								   
		


	


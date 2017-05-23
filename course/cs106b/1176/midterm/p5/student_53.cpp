Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> currentPath;
	Vector<int> citiesLeft;
	//this is a random path to pass into the recursive method
	Vector<int> intialPath;
	for(int i = 0; i < distance.numCols(); i++) {
		citiesLeft.add(i);
	}
	currentPath.add(startCity);
	citiesLeft.remove(startCity);
	return bestRouteHelper(distance, currentPath, citiesLeft, DBL_MAX, intialPath);
}

Vector<int> bestRoute(Grid<double> &distance, Vector<int>& currentPath, Vector<int>& citiesLeft, double distance, Vector<int>& bestPath) {
	if(citiesLeft.size() == 1) {
		currentPath.add(citiesLeft[0]);
		if(totalRouteDistance(distance, currentPath) < distance) {
			bestPath = currentPath;
		}
		return bestPath;
	} else {
		Vector<int> pathBeforeAdding = currentPath;
		for(int i = 0; i < citiesLeft.size(); i++) {
			int city = citiesLeft[i];
			currentPath.add(city);
			citiesLeft.remove(i);
			return bestRoute(distance, currentPath, citiesLeft);
			//backtrack
			citiesLeft.insert(city, i);
			currentPath = pathBeforeAdding;
		}
	}
}
		
		
		
		
		
		

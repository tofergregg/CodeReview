Set<Vector<int>> generateSubPaths(Vector<int> otherCities, int startCity) {
	Set<Vector<int>> subPaths;
	if (otherCities.isEmpty()) {
		// do nothing	
	}
	else {
		// generate "permutations" with all cities after startCity
		for (int i = 0; i < otherCities.size(); i++) {
			int city = otherCities[i];
			Vector<int> path = otherCities.remove(i);
			for (int cities : generateSubPaths(path)) {
				subPaths += city + cities;	
			}
		}
	}
	return subPaths;
}



Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> otherCities;
	for (int i = 0; i < distance.numRows(); i++) {
		if (i != startCity) otherCities.add(i);	
	}
	
	Set<Vector<int>> paths;
	paths = generateSubPaths(otherCities, startCity);
	// insert start city to beginning of all sub paths
	Vector<int> bestPath;
	double minDistance = DBL_MAX;
	for (Vector<int> path : paths) {
		path.insert(0, startCity); // insert start city at beginning
		path.add(startCity); // add start city to end of path
		double pathLength = totalROuteDistance(distance, path);
		// update best path (minimum path lenth)
		if (pathLength < minDistance) {
			minDistance = pathLength;
			bestPath = path;
		}
	}
	return bestPath;
}




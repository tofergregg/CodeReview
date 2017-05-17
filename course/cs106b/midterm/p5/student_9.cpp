Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> path;
	Set<int> usedCities;
		
	path.add(startCity);
	
	return helper(distance, startCity, path, usedCities);
}



Vector<int> helper(Grid<double> &distance, int startCity, Vector<int> path, Set<int> &usedCities) {
	
	if(path.size() == distance.numCols() + 1) {
		return path;
	} else {
		
		double shortest = DBL_MAX;
		int used;
		
		for(int i = 0; i < distance.numCols(); i++) {
			if(i != startCity && !usedCities.contains(i)) {
				Vector<int> check = helper(distance, i, path, usedCities);	
				
				int pathDist = totalRouteDistance(distance, check);
				
				if(pathDist < shortest) {
					shortest = pathDist;
					used = i;
				} 
			}
		}
		
		path.add(distance[startCity][used]);
		usedCities.add(used);
		
		return path;
	}
}
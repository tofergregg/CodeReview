Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// base case: if no city un-explored, return best value
	Set<int> unexplored;
	numCity = distance.numCols();
	for (int i = 0; i < numCity; i++) { // add all but starting city to unexplored list
		if (i != startCity) {
			unexplored.add[i];
		}
	}
	double best = DBL_MAX;
	Vector<int> currVec;
	currVec.add(startCity);
	currVec.add(startCity);
	bestRouteHelper(distance, startCity, best, unexplored, currVec);
	
}
	

// Starting from a vector (start city, start city)
// insert unexplored city to in front of the last index
// 

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, double bestDist, 
							Set<int> &unexplored, Vector<int> currVec) ute
	// base case: all cities explored: return vector w/ best distance
	if (unexplored.isEmpty()) {
		return currVec;
	}
	else {
		Map<Vector<int>, int> distMap;
		for (int city : unexplored) {
			unexplored.remove(city);
			distMap.put(bestRouteHelper(&distance, startCity, bestDist, &unexplored, currVec),
						totalRouteDistance(distance, bestRouteHelper(&distance, startCity,
						bestDist, &unexplored, currVec);
			unexplored.add(city);
		}
		for (Vector<int> key : distMap) {
			if distMap[key] < bestDist;
			bestDist = distMap[key];
			Vector<int> solution = key
		}
		return key;
	}	
	
}
			
			
		
		
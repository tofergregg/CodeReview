Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int i = 0;
	Vector<int> vec;
	Vector<int> shortestRoute;
	Map<int, Vector<int>> routeOptions;
	double minDistance = DBL_MAX;
	int rowNum = 0;
	int colNum = 0;
	
	helper(startCity, vec, distance, routeOptions, i);
	
	// finds the best route at the end
	for(int key: route) {
		double distance = totalRouteDistance(distance, route);
		if(distance < minDistance) {
			minDistance = distance;
			best = route;
		}
	}
	// adds the city to return to
	best.add(0);
	return best;
}

Vector<int> helper(int startCity, Vector<int> &route, Grid<double> &distance, Map<int, Vector<int>> &routeOptions, int i) {
	int colNum = startCity;
	int rowNum = 0;
	
	for(loop over grid) {
		// last city has been checked
		if(!distance.inBounds(rowNum, colNum + 1) and !distance.inBounds(rowNum + 1, colNum)) {
			routeOptions.add(i, route);
			i++;
			return route;
		} else if(colNum != rowNum) {
			route.add(distance[rowNum][colNum]);
			colNum++;
			if(!distance.inBounds(rowNum, colNum) && distance.inBounds(rowNum + 1, colNum)) {
				// moves to the next row if it exists
				rowNum++;
				colNum--;
			}
			// creates a new route to be added to the map containing all routes
			helper(colNum + 1, route, distance);
		}
	}
}
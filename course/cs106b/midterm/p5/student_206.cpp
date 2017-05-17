Vector<int> bestRouteHelper(Grid<double> &distance, int currCity, int endCity, Set<int> &allCities, int dTraveled, Vector<int> &route) {
	
	route.add(currCity);
	
	if (currCity == endCity) {
		numCities = 0;
		for (int i = 0; i < route.size(); i++) {
			if (allCities.contains(route[i])) {
				numCities++;
			}
		}
		if (numCities == allCities.size()) {
			double totalRouteDistance = totalRouteDistance(distance,route);
			if (dTraveled < totalRouteDistance) {
				totalRouteDistance = dTraveled;
			}
		}
	}	
	
	if (dTraveled > 0) {
		for (int r = 0; r < distance.numRows(); r++) {
			for (int c = 0; c < distance.numCols(); c++) {
				// choose [r][c]
				length = distance[r][c];
				dTraveled += length;
				if (!route.contains(c)) {
					bestRouteHelper(distance,c,endCity,allCities,dTraveled, route);
					
				}
			}
		}
	} else {
		for (int cols; cols < distance.numCols(); cols++) {
			length = distance[currCity][cols];
			dTraveled += length;
			if (!route.contains(c)) {
					bestRouteHelper(distance,c,endCity,allCities,dTraveled, route);
			}
		}
	}
	return route;
}


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int rows = distance.numRows();
	Set<int> allCities;
	for (int i = 0; i < rows; i++) {
		allCities.add(i);
	}
	Vector<int> route;
	int dTraveled = 0;
	bestRouteHelper(distance,startCity,startCity, allCities,dTraveled,route);
	return route;
}

	
		


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numCities = distance.width();
	Vector<int> route();
	return bestRouteHelper(distance, startCity, route, numCities, 0, 	 0);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &route, int currRow, int currCol) {
	if (currRow = distance.numRows()) {
		return route;
	} else if (currCol == distance.numRows){
		bestRouteHelper(distance, startCity, route, numCities, 				currRow + 1, 0);
	} else {
		for (i = 0; i < distance.numCols(); i++) {
			route.add(distance[currRow, i]);
		}
		bestRouteHelper(distance, startCity, route, numCities, 				currRow, currCol + 1);	
	}
}
			
		
		

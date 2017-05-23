Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route = findRoutes(distance, startCity, distance.numRows());
	route.add(startCity);
	
	return route;
	
		
}


Vector<int> findRoutes(Grid<double> &distance, int startCity, int numCitiesLeft){
	Vector<int> citiesTraveled;
	citiesTraveled.add(startCity);
	
	if (numCitiesLeft == 0) return citiesTraveled;
	double totalDistance = DBL_MAX;
	for (int r = 0; r < distance.numRows-1; r++) {
		
		int min = DBL_MAX;
		int nextStart; 
		
		for (int c = 0; c < distance.numCols; c++) { 
			if (distance[r][c] < min && distance[r][c]>0 && !citiesTraveled.contains(c)) {
				min = distance[r][c];
				nextStart = c;
				
		}
		citiesTraveled.add(c);
		int distance = totalRouteDistance(distance, findRoutes(distance, nextStart, numCities-1);
		if (ditance < totalDistance){
			return citiesTravled + findRoutes(distance, nextStart, numCities-1);
		}
		distance = totalDistance;
										  
										  
										  
	}
		
}

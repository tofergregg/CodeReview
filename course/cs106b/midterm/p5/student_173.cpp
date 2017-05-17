Vector<int> helperBestRoute(Grid<double>&distance, int startCity, Vector<int> routeSoFar, int numCities){
	if(numCities==0){
		double minDistance = DBL_MAX;
		double currentDistance = totalRouteDistance(distance,
													routeSoFar);
		// compare the currentDistances
		return routeSoFar;
	}else{
		for(int i=0; i<numCities; i++){
			//if routeSoFar doesn't already contain i
			routeSoFar.add(i);
			helperBestRoute(distance,startCity, routeSoFar, 
							cities, numCities-1);
			routeSoFar.remove(routeSoFar.size()-1);
		}
	}
}

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numCities = distance.numCols();
	Vector<int> routeSoFar;
	Vector<int> cities;
	routeSoFar.add(startCity);
	for(int i=0; i<numCities; i++){
		cities.add(i);
	}
	helperBestRoute(distance, startCity, routeSoFar, numCities);
}


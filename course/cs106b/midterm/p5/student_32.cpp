//Assumption: If two routes are of equal distance, we only use the first calculated route.

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> minRoute;
	double minRouteDistance = DBL_MAX;
	Vector<int> currentRoute;
	Vector<int> citiesLeft;
	
	for(int i = 0; i < distance.numRows; i++){
		citiesLeft.add(i);
	}
	currentRoute.add(startCity);
	citiesLeft.remove(startCity);
	
	bestRouteHelper(distance, startCity, currentRoute, citiesLeft, minRoute, minRouteDistance);
	return minRoute;
}

void bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> ¤tRoute, Vector<int> &citiesLeft, Vector<int> &minRoute, double &minRouteDistance){
	if(citiesLeft.isEmpty()){
		currentRoute.add(startCity);
		double currentDistance = totalRouteDistance(distance, currentRoute)
		if(currentDistance < minRouteDistance){
			minRoute = currentRoute;
			minRouteDistance = currentDistance;
		}
	} else {
		for(int i = 0; i < citiesLeft.size(); i++) {
			int currentCity = citiesLeft[i];
			currentRoute.add[currentCity];
			citiesLeft.remove[currentCity];
			bestRouteHelper(distance, startCity, currentRoute, citiesLeft, minRoute, minRouteDistance);
			currentRoute.remove[currentCity];
			citiesLeft.add[currentCity];
		}	
	}
	
}

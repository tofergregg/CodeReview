Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double currMin = DBL_MAX;
	HashSet<int> citiesBeenTo;
	citiesBeenTo.add(startCity);
	Vector<int> myRoute;
	Vector<int> thisRoute;
	thisRoute.add(startCity);
	bestRouteHelper(distance, startCity, citiesBeenTo, currMin, myRoute, thisRoute);
	return myRoute;
}

// Helper function
void bestRouteHelper(Grid<double> &distance, int startCity, HashSet<int> &citiesBeenTo, double& currMin, Vector<int> &myRoute, Vector<int>&thisRoute) {
	
	// Base case
	if (thisRoute.size() == distance.numRows()){
		thisRoute.add(startCity);
		double thisDistance = totalRouteDistance(distance, thisRoute);
		if (thisDistance < currMin) {
			myRoute == thisRoute;
			currMin = thisDistance;
		} 	
	} else {
		for (int r = 0; r < distance.numRows(); r++) {	
			if (!citiesBeenTo.contains(r)){
				thisRoute = thisRoute.add(r);
				citiesBeenTo.add(r);
				bestRouteHelper(distance, startCity, citiesBeenTo, currMin, myRoute, thisRoute);
				thisRoute.remove(r);
				citiesBeenTo.remove(r);
			}	
		}
	}		
}	
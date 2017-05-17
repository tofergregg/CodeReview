Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> remainingCities;
	for (int i = 0; i < distance.numRows(); i++){
		remainingCities.add(i);
	}
	int minDistance = DBL_MAX;
	int numRemaining = remainingCities.size();
	Vector<int> currentRoute, finalRoute;
	finalRoute = generateRoute(distance, remainingCities, numRemaining, currentRoute, minDistance);
	return finalRoute;
}

//helper, takes in additional inputs
Vector<int> generateRoute (Grid<double> &distance, Vector<int> &remainingCities, int numRemaining, Vector<int> ¤tRoute, int minDistance) {
	//base case
	if (numRemaining == 0){
		return currentRoute;
	//recursive case
	} else {
		for (int i = 0; i < remainingCities.size; i++) {
			//checks to see if current path is shorter than the 			already stored minimum distance
			if (totalRouteDistance(distance, currentRoute) < minDistance){
				//memoizes for efficiency
				minDistance = totalRouteDistance(distance, currentRoute;
				currentRoute.add(i);
				remainingCities.remove(i);
				currentRoute = generateRoute(distance, remainingCities, numRemaining-1, currentRoute, minDistance);
			}
		}
	}
	return currentRoute;	 
}
				
				
			
		
	

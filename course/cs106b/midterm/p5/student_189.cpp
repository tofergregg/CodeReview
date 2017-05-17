Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	bestRoute.add(startCity);
	Vector<int> availCities;
	for (int i = 0; i< distance.numRows(); i++) {
		if (i != startCity) {
			availCities.add(i);
		}
	}
	int mindistance = helper(distance, bestRoute, 0, availCities, startCity);
	return bestRoute;
}

int bestRoute helper(Grid<double> &distance, Vector<int> &bestRoute,
			double currentdistance, Vector<int> availCities, int startCity) {

	// base case:if we've used all the cities in the vector of available cities, add start city to that vector
	if (availCities.size() == 0) {
	  bestRoute.add(startCity);
	} else {
	// recursive case
	// loop through the vector of available cities, calculate distance
	for (int i =0; i < availCities.size(); i++) {
		int newcity = availCities[i];
		int localdistance = currentdistance + distance[currentCity][availCities[i]];
		availCities.remove[i];
		int newdistance = helper(distance, bestRoute, localdistance, availCities, newcity);
		if (newdistance < localdistance) {
			localdistance = newdistance;
			bestRoute.add[availCities[i]];
		}
		availCities.add[i];
			
	}	
	
}
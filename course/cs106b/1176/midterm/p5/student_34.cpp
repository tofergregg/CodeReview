Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> best;
	best.add(startCity);
	int nextCity = startCity;
	double bestDistance = DBL_MAX;
	Set<int> cities = {0, 1, 2, 3};
	return bestHelper(distance, startCity, nextCity, best, 							bestDistance, cities);
}

Vector<int> bestHelper(Grid<double> &distance, int startCity,
					   int nextCity, Vector<int> best, 								   double bestDistance, Set<int> cities) {
	//base case - all cities have been visited
	if(cities.isEmpty()) {
		//finish the round trip 
		localBest.add(startCity);
		double distance = totalRouteDistance(Grid<double> 									&distance,Vector<int> &localBest); 
		//update new distance if shorter 
		if (distance < bestDistance) best = localBest;
	}
	Vector<int> localBest;
	localBest.add(nextCity);
	//build vector up
	for (int i = 0; i < 3; i++) {
		cities.remove(nextCity);
		bestHelper(distance, startCity, i, localBest, 								bestDistance, cities);
		//re-insert city for backtracking
		cities.add(nextCity);
	}		 		 		 
	//final return
	return best;
}

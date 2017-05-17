Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int bestDistance = DBL_MAX;
	nextRouting(distance, startCity, best);
	int numberCities = distance.numRows();
	SSet<int> citiesLeft;
	for(int i = 0; i < numberCities; i++){
		citiesLeft.add(i);
	}
	Vector<int> currentRoute;
	return nextRouting(distance, startCity, bestDistance, currentRoute, citiesLeft, startCity);
}

Vector<int> nextRouting(Grid<double> &distance, int begin, int best, Vector<int>& currentRoute, Vector<int>& bestRoute, Set<int>& citiesLeft, int const ultimateStartEnd){
	if(citiesLeft==0){
		currentRoute.add(ultimateStartEnd);
		int distance = totalRouteDistance(distance, currentRoute);
		
		if(distance<best){
			best=distance;
			bestRoute=currentRoute;
		}
		return bestRoute;
	}
	else{
		currentRoute.add(begin);
		citiesLeft.remove(begin);
		for(int nextCity : citiesLeft){
			nextRouting(distance, nextCity, best, currentRoute, citiesLeft, ultimateStartEnd);
		}
	}
	
}

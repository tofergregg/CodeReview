Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vect<int> remainingCities;
	for(int i = 0; i < distance.numCols(); i++) {
		remainingCities.add(i);
	}
	Vector<int> visited;
	visited.add(startCity);
	bestDistance = DBL_MAX;
	Vector<int> currentBestRoute;
	return bestRouteHelper(distance, startCity, remainingCities, visited, 		bestDistance, currentBestRoute);
}
	
	
	
	
	
	
	
	
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &remainingCities, Vector<int> &visited, int bestDistance Vector<int> ¤tBestRoute) {
	//base case if we have traveled to all of the ciites except the final
	//path to the start city
	if(remainingCities.size() == 1) {
			visited.add(startCity);
			int currDistance = totalRouteDistance(distance, visited);
			//if this is the best route it will change the stored best 				//route to this one
			if(currDistance < bestDistance) {
				bestDistance = currDistance;
				bestRoute = visited;
			}
			return bestRoute;
		}
	//cycles through vector until it reaches a city that is not the start
	//city, if only the start city is left, it will have returned in the
	//base case, chooses when it gets to that city
	while(true) {
			int n = remainingCities[0];
			remainingCities.remove(0);
			if(n == startCity) {
				remainingCities.add(n);
			} else break;
		}
		//explores traveling to that city
		visited.insert(0,n);
		Vect<int> solution = bestRouteHelper(distance, startCity, 					remainingCities, visited, bestDistance, bestRoute);			
		//unchooses that city
		remainingCities.add(0,n);	
		return solution;
}


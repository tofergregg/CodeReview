Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numCities = distance.numRows();
	Vector<int> citiesRemaining;
	Vector<int> route;
	Vector<int> bestRouteSoFar;
	for(int i=0; i<numCities; i++){
		if(i==startCity){
			continue;
		}
		citiesRemaining.add(i);
	}
	route.add(startCity);
	bestRouteSoFar = citiesRemaining.insert(startCity,0); // cities in order of numbering
	return bestRouteHelper(distance, citiesRemaining, route, bestRouteSoFar);
}

Vector<int> bestRouteHelper(Grid<double> &distance, Vector<int> citiesRemaining, Vector<int> route, Vector<int> bestRouteSoFar){
	// base case: no more cities to visit, go back to starting city
	if(citiesRemaining.isEmpty()){
		route.add(route[0]); // append first city to route
		// compare distances
		if(totalRouteDistance(distance, route)<totalRouteDistance(distance, bestRouteSoFar){
			// we found a new best route
			bestRouteSoFar = route;
			return bestRouteSoFar;
		} else {
			return bestRouteSoFar; // old best route
		}
	} else {
	// recursive case: loop through remaining cities and recurse
		int numCitiesRemaining = citiesRemaining.size();
		for(int i=0; i<numCitiesRemaining; i++){
			int nextCity = citiesRemaining[i];
			route.add(nextCity);
			citiesRemaining.remove(i); // remove next city
			Vector<int> newRoute = bestRouteHelper(distance, citiesRemaining, route, bestRouteSoFar);
			if(totalRouteDistance(distance, newRoute)<totalRouteDistance(distance, bestRouteSoFar)){
				bestRouteSoFar = newRoute;
			}
			citiesRemaining.insert(i,nextCity); // restore next city
		}		
	}
	return bestRouteSoFar;
}


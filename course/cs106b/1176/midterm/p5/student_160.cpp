Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	//First create a dummie vector containing the
	// "names" of the cities
	Vector<int> cities;
	for(int i=0; i<distance.numCols(); i++)
		if ( i != startCity) // not including the start city
			cities.add(i);
	
	// Now use a helper function tha does
	// the backtracking recursion -- similar to the permutation
	// recursion
	Vector<int> soFarCities;
	
	Vector<int> result = bestRoute(distance, startCity, soFarCities, cities, DBL_MAX);
}


Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> soFarCities, Vector<int> cities, int bestDistance) {
	
	//Base case Finish the permutation
	if (cities.isEmpty()){
		//Adds the start city at beginning and end of route
		Vector<int> finalRoute = soFarCities.insert(0,startCity);
		finalRoute = finalRoute.add(startCity);
		
		return totalRouteDistance(distance, finalRoute);
	
	//Traversing the tree (getting all diferent combinations
	} else {
		for (int i = 0; i < cities.length(); i ++) {
			soFarCities.add(cities[i]);
			Vector<int> remaining =  cities.remove(i);
			int currentDistance = bestRoute(distance, startCity, soFarCities, remaining, bestDistance);
			
			if (currentDistance < bestDistance)
				bestDistance = currentDistance
		}
		return bestDistance;
	}
}


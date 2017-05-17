Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int localDistance;
	Vector<int> localRoute;
	return bestRouteHelper(distance, startCity, 0, localRoute);
}


Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int bestDistance, int localDistance, Vector<int> localRoute){
			
	// base case
	if (localRoute.size() == distance.numRows() + 1) {
		return; 
	}
	
	// add the start city to the current local route; 
	localRoute.add(startCity);
	
	// iterate through total # of cities (equal to # rows or # columns)
	for (int city = 0; city < distance.numRows(); i++) {
		// do not want to add the startCity prematurely
		if (!city == startCity) {
			// choose a city
			localRoute.add(city);
			
			// recurse and explore that city
			localRoute = bestRouteHelper(distance, city + 1, bestDistance);
			
			localRoute.remove(city); 
			// add the start city to the end of the vector
		}			
	}
	
	// add the start city to the end because we return there
	localRoute.add(startCity);
	
	// compute the distance of that route
	localDistance = totalRouteDistance(distance, localRoute);
	if (localDistance < bestDistance) {
		bestDistance = localDistance);
		Vector<int> bestRoute = localRoute;
	}
	
	return bestRoute; 
}

// choose: a city
// explore: all the potential possible routes from 0 to numCities
// add on startCity
// unchoose that city
		
						
// reasoning: need to keep a Vector of a route at all times. a localRoute Vector. Update that vector with a new route at each recursive step. Compute the totalRouteDistance and then check and see if that route is shorter than the localRoute.


Vector<int> bestRoute(Grid<double> &distance, int startCity
						int endCity, Set<int> &remaining);
	

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	Set<int> remaining;
	int numCities = distance.numRows();
	
	for(int city = 0; city < numCities; city++){
		remaining.add(city);
	}
	remaining.remove(startCity);

	Vector<int> result = bestRoute(distance, startCity,
								   startCity, remaining);
	
	return result;
}

/* This method returns the vector of integers, which indicate the best
 * route between the starting city, the end city. The set of
 * remaining cities that the salesman should visit between the two
 * cities is also specified as a parameter.
 */
Vector<int> bestRoute(Grid<double> &distance, int startCity
						int endCity, Set<int> &remaining)
{
	Vector<int> result;
	
	// Base case: if there are no more remaining cities to visit in
	// between, the best route is simply the direct route from the
	// start city to the end city.
	if(remaining.isEmpty()){
		
		result.add(startCity);
		result.add(endCity);
		
	} else {
		// Recursive case: there are still remaining cities to visit,
		// we consider all of the cities that we can visit next.
		
		double shortest = DBL_MAX;
		Vector<int> shortestRoute;
		
		for(int nextCity : remaining){
			remaining.remove(nextCity);
			Vector<int> route = bestRoute(distance, nextCity,
										  endCity, remaining);
			remaining.add(nextCity);
			
			double currentDis = distance[startCity][nextCity]
						+ totalRouteDistance(distance, route);
			
			if(currentDis <= shortest){
				shortest = currentDis;
				shortestRoute = route;
			}
		}
	
		result = shortestRoute;
		result.insert(0, startCity);
	}
	
	return result;
}
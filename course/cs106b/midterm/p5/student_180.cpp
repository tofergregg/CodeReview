Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numCities = distance.numRows();
	Vector<int> cities;
	Vector<int> route;
	
	//Add start city to route
	route.add(startCity);
	
	//Fill a vector with other cities
	for(int i = 0; i < numCities - 1; i++){
		if(i != startCity) cities.add(i);
	}
	
	
	return bestRoute(distance, start, cities, route);
}


Vector<int> bestRoute(Grid<double> &distance, int start,
				Vector<int>& cities, Vector<int>& route) {
	
	if(cities.isEmpty()){
		route.add(route[0]);
		return route;
	}
	
	//int for size of vector
	int citiesLeft = cities.size();
	
	//ints for recording best
	double shortestDist = DBL_MAX;
	Vector<int> bestRoute;
	
	
	for(int i = 0; i < citiesLeft; i++) {
		
		//adding next city to possible route
		int nextCity = cities[i];
		Vector<int> copyRoute = route;
		copyRoute.add(i);
		cities.remove(i);
		
		//Recursion
		Vector<int> curRoute = bestRoute(distance, nextCity, cities, copyRoute);
		
		//Calculating distance travelled
		double TravelDist = totalRouteDistance(distance, curRoute);
		
		//Comparing
		if(TravelDist < shortestDist) {
			bestRoute = curRoute;
			shortestDist = TravelDist;
		}
		
		//Replace
		cities.insert(i, nextCity);
	}
	
	return bestRoute;
}
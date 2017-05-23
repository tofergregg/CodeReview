Vector<int> bestRoute(Grid<double> &distance, int startCity) {

	//return all possible routes
	//compare the distances of each route and select the best route
	
	int numCities = distance.numCols() - 1;
	int currCity = startCity;
	Vector<int> route;
	Set<int> cities;
	double bestDistance = DBL_MAX;
	Vector<int> bestRoute;
	for(int i = 0; i < numCities*numCities; i++) {
		//for all possible combinations of cities 
		Vector<int> route = findRoute(numCities, route, startCity, distance, cities, currCity)
		double distance = totalRouteDistance(distance, route);
		if (distance < bestDistance) {
			bestDistance = distance;
			bestRoute = route;
		}
	}
	return bestRoute;
	

Vector<int> findRoute(int numCities, Vector<int> route, int startCity, Grid<double> distance, Set<int> cities, int currCity)
	if (cities.isEmpty()) {
		route.add(startCity);
		return route;
	} else {
		for(int city: cities) {
			 //go to a city you haven't been to
			route.add(city);
			cities.remove(city);
			int currCity = city;
			findRoute(numCities, route, startCity, distance, cities, currCity);
			
			
			
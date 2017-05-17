
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
//return shortest distance
//base case: have reached destination: origin = destination
	Vector<int> cities;
	for(int i = 0; i < distance.numCols(); i++) {
		cities[i] = i;
	}
	// -1 passed in as currCity initially; is never valid index
	return bestRouteHelper(distance, cities, -1, startCity);
}

Vector<int> bestRouteHelper(Grid<int> &distance, Vector<int> &cities, int currCity, int startCity) {
	if(cities.size() == 0) {
		cities.add(startCity);
		return cities;
	}
	int minDist = DBL_MAX;
	Vector<int> minRoute;
	for(int i = 0; i < cities.size(); i++) {
		Vector<int>route = bestRoute(distance,cities, currCity, startCity);
		currCity = cities[i];
		route.add(currCity);
		cities.remove(i);
		int currDist =
			totalRouteDistance(distance, 		bestRoute(distance,cities, currCity, startCity)) + distance[startCity, currCity];
		if(currDist < minDist) {
			minRoute = route;
		}
		cities.insert(i, currCity);
	}
	return minRoute;
}
			
		
		
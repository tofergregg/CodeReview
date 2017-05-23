Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	//store the current shortest distance
	Vector<int> route;
	route += startCity; //add the starting city to the route
	Vector<int> cities;
	for (int i = 0; i < distance.numCols(); i++) {
		cities.add(i); //this creates a vector of all the cities
	}
	cities.remove(startCity); //this eliminates the possibility of going back to the starting city
	int bestDistance = 0;
	Vector<int> shortestRoute = bestRouteHelper(Grid<double> &distance, route, cities, bestDistance);
	return shortestRoute;
}

Vector<int> bestRouteHelper(Grid<double> &distance, Vector<int> route, Vector<int> cities, int bestDistance) {
	//base case: starting city is the ending city AND the route is complete
	if (route[0] == rout[rout.size()-1] && route.size() == cities.size()) {
		return route;
	} else {
	//recursive step
	//return the shortest distance among possible paths
		int nextCity = cities[0];
		cities.remove(0);
		for (int i = 0 ; i < cities.size(); i++) { //all possible cities
			route += nextCity;
			double currentDistance = totalRouteDistance(distance,route);
			bestRouteHelper(distance, route, cities, bestDistance);
		}
		cities.insert(0,nextCity); //backtracking
	}
}

// Note: I didn't determine how to iterate bestDistance
			
			
	


//function prototypes
Vector<int> routeHelper(Grid<double> &distance, int startCity, Vector<int> cities, Map<double, Vector<int>> paths, Vector<int> route);
Vector routeCalc(Map<double, Vector<int>> paths);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	//create the vector of possible routable cities not counting the origin 
	Vector<int> cities;
	for (int i = 0; i < distance.numCols(); i++) {
		if (i != startCity) {
			cities.add(i);
		}
	}
	Vector<int> route; //Vector of the path taken
	Map<double, Vector<int>> paths; //will keep track of route and trip distance
	routeHelper(distance, startCity, cities, paths, route);
	Vector<int> best = routeCalc
	return best;
}

//recursively explores all paths using possible cities as the "choice"
Vector<int> routeHelper(Grid<double> &distance,int startCity, Vector<int> cities, Map<double, Vector<int>> paths, Vector<int> route) {
	//base case, back at origin, all cities used
	if (cities.isEmpty()) {
		route.add(int startCity);
		double tripDistance = totalRouteDistance(Grid<double> &distance, Vector<int> &route);
		paths[tripDistance][route]; //store this 
		return route;
	} else {
		for (int city : cities) {
			route.add(city); //add this as a choice
			cities.remove(city); //this city is no longer a choice
			routeHelper(distance, startCity, cities, paths, route); //explore
			cities.add(city); //undo the "choosing"
		}
	}
	return route;
}

//finds the shortest path distances and returns the associated vector
Vector routeCalc(Map<double, Vector<int>> paths) {
	Vector<int> times = paths.keys();
	int minimum;
	for (int i = 0; i < times.size(); i++) {
		if (times[i] < minimum) {
			minimum = times[i]
		}
	}
	return paths[minimum]
}
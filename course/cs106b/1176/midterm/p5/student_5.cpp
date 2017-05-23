void bestRouteHelper(int startCity, Set<Vector<int>> &allRoutes, Vector<int> currRoute, Vector<int> cities);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> chosenRoute; // what will be returned
	Set<Vector<int>> allRoutes;
	Vector<int> currRoute;
	Vector<int> cities;
	for (int i = 0; i < distance.numRows(); i++) {
		cities.add(i);
	}
	bestRouteHelper(startCity, allRoutes, currRoute, cities);
	double bestDistance = DBL_MAX;
	for (Vector<int> route : allRoutes) {
		if (totalRouteDistance < bestDistance) {
			chosenRoute = route;
		}
	}
	return chosenRoute;
}

void bestRouteHelper (int startCity, Set<Vector<int>> &allRoutes, Vector<int> &currRoute, Vector<int> &cities){
	// base case
	if (cities.isEmpty()) {
		currRoute.add(startCity);
		allRoutes.add(currRoute);
	//recursive case
	} else {
		int chosen = cities[startCity];
		currRoute.add(startCity);
		cities.remove(startCity); //choose
		//explore all options
		for (int i = 0; i < cities.size(); i++) {
			bestRouteHelper(cities[i], routes, currRoute, cities);
		}
		cities.insert(startCity, startCity) //un-choose, remains ordered
	}
}
	


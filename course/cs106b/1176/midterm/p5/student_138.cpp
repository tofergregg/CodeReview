Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double minDistance = DBL_MAX;
	Vector<int> route;
	route.add(startCity);
	
	Vector<int> citiesLeft;
	for (int i=0; i<distance.numCols(); i++) {
		if (i!= startCity) {
			citiesLeft.add(i);
		}
	}
	
	Vector<int> bestRoute;
	findBestRoute(distance, route, bestRoute, citiesLeft, minDistance, startCity);
return bestRoute;
}
		
		
void findBestRoute(Grid<double> &distance, Vector<int> &route,Vector<int> &bestRoute, Vector<int> &citiesLeft, double &minDistance, int startCity) {
	if (citiesLeft.isEmpty()) {
		route.add(route[0]);
		if (totalRouteDistance(distance, route)< minDistance) {
			minDistance = totalRouteDistance(distance, route);
			bestRoute = route;
		}
		route.remove(route.size()-1);
	} else {
		for (int i=0; i<citiesLeft.size(); i++) {
			//choose
			int currCity = citiesLeft[i];
			route.add(currCity);
			citiesLeft.remove[i};
			//recurse
			findBestRoute(distance, route, bestRoute,citiesLeft, minDistance, currCity);
			//unchoose
			route.remove(route.size()-1);
			citiesLeft.insert(i, currCity);
		}
	}
}
		
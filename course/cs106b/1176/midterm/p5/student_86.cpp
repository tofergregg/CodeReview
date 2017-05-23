Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector <int> &route, Set <int> &cities, count) {	
	if (cities.IsEmpty){
		route.add(startCity);
		if (double totalRouteDistance(distance, route) < count) {
			count = double totalRouteDistance(distance, route);
			return route;
		}	
	} else {
		for (int r = 0; r < distance.numRows(); r++) {
			if (!cities.contains(r)) {
				route.add(r);
				cities.remove(r);
				bestRouteHelper(distance, r, route)
				route.remove(r);
				cities.add(r);
			}	
		}
	}	
}


Vector<int> bestRoute(Grid<double> &distance, int startCity) {

	Vector <int> route;
	route.add(startCity);
	Set <int> cities;
	for (for (int r = 0; r < distance.numRows(); r++){
		cities.add(r)
	}
	cities.remove(startCity);
	count = DBL_MAX
	route = bestRouteHelper(distance, startCity, route, cities, count);
	return route;
}	
		
		

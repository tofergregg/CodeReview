bestRouteHelper(Grid<double> &distance, int startCity, Vectori<int> cities, Vector<int> route, double &best)

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route.add(startCity);
	Vector<int> cities;
	for(int i = 0; i < grid.numRows(); i++) {
		cities.add(i);
	}
	cities.remove(startCity);//at index of value
	bestRouteHelper(distance, startCity, startCity, cities, route, DBL_MAX);
}
bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &cities Vector<int> &route, double &best) {
	if(cities.isEmpty()) {
		route.add(startCity);
		Vector<int> finalRoute = route;
		route.remove(route.length()-1);
		return totalRouteDistance(distance, finalRoute);
	}
	for(int i = 0; i < cities.size(); i++) {
		int next = cities[i];
		cities.remove(i);
		route.add(i);
		double current = bestRouteHelper(distance, startCity, next, cities, route, best);
		if(current < best) {
			best = current;
		}
		cities.insert(i,next);
		route.remove(route.length()-1);
	}
	return best;
}
		
	
	


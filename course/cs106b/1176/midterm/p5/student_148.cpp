Vector<int> bestRoute(Grid<double> &distance, int startCity, Set<int> &cities, Vector<int> &route, Vector<int> &bestRoute);


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int N = distance.numRows();
	Vector<int> route;
	Set<int> cities;
	for(int i = 0; i < N; i++) {
		cities.add(i);
	}
	return bestRoute(distance, startCity, cities, route);
}	

Vector<int> bestRoute(Grid<double> &distance, int startCity, Set<int> &cities, Vector<int> &route, Vector<int> &bestRoute) {
	if(cities.isEmpty()) return route;
	for(int city : cities) {
		if(startCity != city) {
			route.add(distance[startCity][city]);
			cities.remove(city);
			Vector<int> newRoute = bestRoute(distance, city, cities, route) {
			if(totalRouteDistance(distance, newRoute) < totalRouteDistance(distance, bestRoute) || bestRoute.isEmpty()) {
				bestRoute = newRoute;
			}
				
		}
	}
	return bestRoute;
}
	



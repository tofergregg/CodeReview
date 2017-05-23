Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numCities = distance.numCols();
	Vector<int> citiesLeft;
	Vector<int> route;
	Vector<int> solution;
	route.add(startCity);
	int lowest = DBL_MAX;
	for(int i = 0; i < numCities; i++) {
		citiesLeft.add(i);
	}
	route(distance, startCity, startCity, startCity, citiesLeft, route, 0, lowest, solution);
	return solution;
}
	
void route(Gris<double> &distance, int const beginning, int startCity, int endCity, Vector<int>& citiesLeft, Vector<int>& route, int& lowest, Vector<int>& solution) {
	if(citiesLeft.isEmpty() && beginning==endCity && startCity==endCity) {
		total = totalRouteDistance(distance, route)
		if(total<lowest) {
			lowest = total;
			solution = route;
		}
		return;
	}
	if(cities.Left.isEmpty()) return;
	int size = citiesLeft.size();
	for(int i = 0; i < size); i++) {
		int next = citiesLeft[i];
		citiesLeft.remove(i);
		route.add(next);
		route(distance, beginning, next, endCity, route, lowest, solution);
		citiesLeft.insert(0, i);
		route.remove(route.size()-1);
	}
	return;
}
		
		
	
	
	


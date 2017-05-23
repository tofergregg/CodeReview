Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	HashSet<int> citiesLeft;
	for(int i = 0; i < distance.numCols(); i++){
		citiesLeft.add(i);
	}
	citiesLeft.remove(startCity);
	
	Vector<int> route;
	route.add(startCity);
	return helper(distance, startCity, citiesLeft, route);
}

Vector<int> helper(Grid<double> &distance, int startCity, 
				   HashSet<int> &citiesLeft, Vector <int> &route){
	if(citiesLeft.isEmpty()){
		Vector<int> solution = route;
		solution.add(startCity);
		return solution;
	}else {
		double minDist = DBL_MAX;
		Vector<int> bestRoute;
		
		for(int city : citiesLeft){
			route.add(city);
			citiesLeft.remove(city);
			Vector<int> newRoute = helper(distance, startCity, citiesLeft, route);
			if(totalRouteDistance(distance, newRoute) < minDist){
				bestRoute = newRoute;
			}
			citiesLeft.add(city);
			route.remove(city);
		}
		return bestRoute;
	}
		


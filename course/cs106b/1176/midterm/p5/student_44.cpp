Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int endCity = startCity;
	Vector<int> route;
	double best = DBL_MAX;
	Vector<int> bestRoute;
	route.add(bestRouteHelper(distance, startCity, endCity, route));
	
	if (totalRouteDistance(distance, route) < best) {
		bestRoute = route;
	}
	
	return bestRoute;
}

int bestRouteHelper(Grid<double> &distance, 
							int currentCity, int endCity,
						   Vector<int> &route) {
	//base case
	if (currentCity == endCity) {
		route.add(currentCity);
		return currentCity;
	} else {
		//recursive case
		Vector<int> cities;
		for(int i = 0; i < distance.numCols(); i++) {
			if(i != startCity) {
				cities.add(distance[startCity][i];
		    }
		}
		int currentCity = cities[0];
		cities.remove(0);
		for (int i = 0; i < cities.length(); i++) {
			return bestRouteHelper(distance, currentCity + 1,
								   endCity, route);
		}
		cities.insert(0, startCity);
		
	}
}
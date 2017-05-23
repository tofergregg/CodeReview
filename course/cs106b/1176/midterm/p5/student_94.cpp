Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double shortestDistance = DBL_MAX;
	Vector <int> route;
	route+ = startCity;
	Vector <int> bestRoute;
	Vector <int> citiesLeft;
	for(int i = 0; i < distance.getCols(); i++){
		citiesLeft.add(i);
	}
	citiesLeft.remove(startCity);
	return bestRouteHelper(distance, startCity, shortestRoute, route, bestRoute, citiesLeft);
}

Vector<int> bestRouteHelper(Grid <double> &distance, int startCity, double & shortestRoute, Vector<int> & route, Vector <int> & bestRoute, Vector <int> & citiesLeft){
	
	if(citiesLeft.isEmpty()){
		route += startCity;
		if( totalRouteDistance(distance, route) < shortestRoute){
			shortestRoute = totalRouteDistance(distance, route);
			bestRoute = route;
		}
	}else{
		for(int i = 0; i <citiesLeft.size(); i++)
		{
			int temp = citiesLeft.get(i);
			citiesLeft.remove(i);
			route += temp;
			bestRouteHelper(distance, startCity, shortestRoute, route, bestRoute, citiesLeft);
			route.remove(route.size() -1);
			citiesLeft.insert(i, temp);
		}
	}
	return bestRoute;
}
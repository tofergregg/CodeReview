double bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> route, double bestDistance, Vector<int> citiesLeft, Vector<int> bestRoute){
	//base case
	if(citiesLeft.isEmpty()){
		route.add(route[0]);
		if(totalRouteDistance(distance, route) < bestDistance){
			bestDistance = totalRouteDistance(distance, route);
			bestRoute = route;
		}
	}else{
		//recursive case
		int currCity = startCity;
		route.add(currCity);
		citiesLeft.remove(startCity);
		for(int i = 0; i < citiesLeft.size(); i++){
			route.add(citiesLeft[i];
			bestRouteHelper(distance,citiesLeft[i], route, 						bestDistance, citiesLeft, bestRoute);
			route.remove(route.size()-1);
		}
	}
	
	return bestRoute;
}




Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> citiesLeft;
	Vector<int> bestRoute;
	for(int i = 0; i < distance.numCols(); i++){
		citiesLeft.add(i);
	}
	double bestDistance = DBL_MAX;
	return bestRouteHelper(distance, startCity, route, bestDistance,citiesLeft, bestRoute);
}

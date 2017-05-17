Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<int> citiesLeft;
	for (int city = 0; city<distance.numRows();city++){
		if(city!=startCity){
			citiesLeft+=city;
		}
	}	
	Vector<int> route;
	route+=startCity
	return bestRouteHelper(distance, startCity, startCity, citiesLeft, route);
}

Vector<int> bestRouteHelper(const Grid<double> &distance, int currentCity, int endCity, 		Set<int> &citiesLeft, Vector<int> &route){
	if(citiesLeft.size()==0){
		route+=endCity;
		return route;
	}else{
		int shortestDistance=DBL_MAX;
		for(int city : citiesLeft){
			citiesLeft-=city;
			Vector<int> testRoute=route;
			testRoute+=city;
			testRoute = bestRouteHelper(distance, city, endCity, hcitiesLeft, 						testRoute);
			if(totalRouteDistance(distance, testRoute)<shortestDistance){
				route=testRoute;
				shortestDistance=totalRouteDistance(distance, route);
			}
			citiesLeft.add(city);
		}
		return route;		
}	

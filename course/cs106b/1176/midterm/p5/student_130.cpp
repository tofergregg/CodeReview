Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int citiesRemaining = distance.numCols();
	Set<int> cities;
	for(int i = 0; i < citiesRemaining; i++) {
		cities.add(i);
	}
	return bestRoute(distance, startCity, citiesRemaining, cities);
}

Vector <int> bestRoute(Grid<double> &distance, int startCity, int citiesRemaining, Set<int> & cities) {
	Vector <int> route;
	if(citiesRemaining == 0){
		route.add(startCity);
		return route;
	}
	else { 
		Map <int, double> map;
		Vector <int> vec;
		for(int nextCity: cities){
			if(nextCity != startCity) {
				cities.remove(nextCity);
				vec = bestRoute(distance,nextCity, citiesRemaining-1, cities);
				double val = distance[startCity][nextCity] + totalRouteDistance(distance, vec);
				map.put(nextCity,val);
				cities.add(nextCity);	
			}
		}
		int trueCity;
		double min = DBL_MAX
		for(int city: map){
			if(map[city] < min){
				min = map[city];
				trueCity = city;
			}
		}
		route.add(trueCity);
		return route;
}
																	   
														
																	  
															
																
																
														

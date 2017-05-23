Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	v.add(startCity);
	double sum = 0.0;
	double TopSum = 0.0;
	route = helper(distance, route, startCity, sum, topSum);
	return route;
}

Vector<int> helper(Grid<double> &distance, Vector<int> &route, int startCity, double sum, double topSum) {
	//base case
	if(startCity == route[0]){
		if(topSum > sum) {
			topSum = sum;
			return route;
		}
	}
	
	for(int i = 0; i < 4; i++) {
		int endCity = i;
		
		//loop through vector to see if contains num
		for(int j = 0; j < route.size(); j++) {
			if(endCity == route[i] && endCity != route[0]) {
				i++;
			}
		}
		
		route.add(endCity);
		sum += distance[startCity][endCity];
		
		if(helper(distance, route, endCity, sum, topSum)) return route;
		
		route.remove(route.size() - 1);
		sum -= distance[startCity][endCity];
	}
	return route;
}
		
	
	
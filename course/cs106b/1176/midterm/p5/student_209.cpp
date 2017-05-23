void bestRouteHelper(Grid<double> &distance, int startCity, 
					 Vector<int> &route, int nextCity) {
	//base case
	if (route.size() < distance.width()) {
		if (nextCity != startCity) {
			route.add(nextCity);
			bestRouteHelper(distance, startCity, route, nextCity + 1);
		}
	}
}


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> finalRoute;
	for (int i = 0; i < distance.width(); i++) {  
		route.add(startCity);
		bestRouteHelper(distance, startCity, route, i);
		double dist = totalRouteDistance(distance, route);
		if (finalRoute.isEmpty() || dist < totalRouteDistance(distance,
															  finalRoute) {
			finalRoute.clear();
			finalRoute = route; 
		}
		route.clear();
	}	
	return finalRoute;
}



	
			
			
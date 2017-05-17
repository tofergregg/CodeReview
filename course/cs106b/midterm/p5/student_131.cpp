Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> bestRouteHelper(distance, startCity, startCity, route);
}


Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int CurrentCity, Vector<int> &route){
	//base case:if total distance is shortest, return route
	if(totalRouteDistance(distance, route) < distance[currentCity][nextCity]){
		route.add(currentCity);
	// recursive case: choose most convenient route to next city
	} else {
		nextCity = (currentCity + 1) % distance.width();
		bestRouteHelper(distance, currentCity, nextCity);
	}
	return route;  
}
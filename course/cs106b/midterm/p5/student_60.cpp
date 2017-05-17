Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	double endCity = 1;
	route = bestRouteHelper(distance, startCity, endCity);
	
	return route;
}


Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, double endCity) {
	Vector<int> route;
	if(distance[startCity][endCity] == 0) {
		return route;
	}
	route += distance[startCity][endCity];
	startcity = endcity;
	route = bestRouteHelper(distance, startCity, endCity, route);
}
Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector <int> route;int destinationCity, int counter, double &shortestDistance) {
	if (counter < 0) {
	if (startCity == destinationCity) {
		route.add(destinationCity);
		double routeDistance = totalRouteDistance( &distance, &route);
		if (route.size() == distance.numRows()+1){
			if (distance < shortestDistance){
				shortestDistance = routeDistance;
			return route;
			}
		}
	}
	} else {
		for (int i = 0; i < distance.numCols(); i++){
			if (i != startCity) {
			route.add(i);
			counter--;
			return bestRoute(distance, i, route, destinationCity, counter, shortestDistance);
			}
		}
	}
	return route;
}



Vector<int> bestRoute(Grid<double> &distance, int startCity) {
Vector <int> route;
route.add(startCity);
int destinationCity = startCity;
	int counter = 0;
	double shortestDistance = DBL_MAX;
Vector<int> bestRoute(distance, startCity, Vector <int> route;int destinationCity, counter, shortestDistance);
}
Vector<int> bestRoute(Grid<double> &distance, int startCity, 		 Vector<int> route, int currentCity, int &bestDistance);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	int currentCity;
	int bestDistance;
	route = bestRoute(distance, startCity, route, currentCity, bestDistance);
	return route;
}

Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> route, int currentCity, int &bestDistance) {
	if (distance.numRows() == 1) {
		route.add(startCity);
		return route;
	}
	if (currentCity == startCity && route.size() == distance.numRows()+1) {
		if(bestDistance(distance, route, bestDistance)) return route;
	}
	for (int i = currentCity; i < distance.numRows(); i++ {
		route.add(i);
		route = bestRoute(distance, startCity, route, currentCity+1, bestDistance);
		route.remove(route.size()-1);
	}
	
	return route;
}

bool bestDistance(Grid<double> &distance, Vector<int> &route, int &bestDistance) {
	double distance = totalRouteDistance(distance, route);
	if (distance < bestDistance) {
		bestDistance = distance;
		return true;
	}
	return false;
}	
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> citiesLeft;
	for (int i = 0; i < distance.numRows(); i++) {
		citiesLeft.add(i);
	}
	citiesLeft.remove(startCity);
	return bestRouteHelper(distance, startCity, citiesLeft, {});
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, 
							Vector<int> &citiesLeft, Vector<int> ¤tRoute) {
	if (citiesLeft.isEmpty()) {
		currentRoute.add(startCity);
		return currentRoute;
	} else {
		Vector<int> best;
		double shortest = DBL_MAX;
		for (int i = 0; i < citiesLeft.size(); i++) {
			int city = citiesLeft[i];
			currentRoute.add(city);
			citiesLeft.remove(i);
			Vector<int> route = bestRouteHelper(distance, startCity, citiesLeft, currentRoute);
			double dist = totalRouteDistance(distance, route);
			if (dist < shortest) {
				shortest = dist;
				best = route;
			}
			currentRoute.remove(currentRoute.size() - 1);
			citiesLeft.insert(i, city);
		}
		return best;
	}
}
	
	
		


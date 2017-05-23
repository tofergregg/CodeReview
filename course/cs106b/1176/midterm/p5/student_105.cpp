Vector<int> bestRoute(Grid<double> &distance, int startCity) {	
	Set<int> citiesLeft;
	for (int i = 1; i < distance.numRows(); i++) {
		citiesLeft.add(i); //add all cities but City 0, which will always be the last leg.
	}
	Vector<int> route;
	route.add(0);
	Vector<int> bestRoute;
	int bestDist = DBL_MAX;
	int currentDist = 0;
	bestRouteHelper(distance, startCity, route, citiesLeft, bestDist, currentDist, bestRoute);
	return bestRoute;
}

void bestRouteHelper(Grid<double> &distance, int currentCity, Vector<int> &route, Set<int> &citiesLeft, int & bestDist, int currentDist, Vector<int> & bestRoute) {
	//Base Case:
	if (citiesLeft.isEmpty()) { 
		//adding in the trip back home to City 0.
		currentDist += distance[currentCity][0]; 
		if (currentDist < bestDist) {
			bestDist = currentDist;
			bestRoute = route;
		}
		return;
	} else (
		//Recursive Case:
		for (int i = 0; i < citiesLeft.size(); i++) {
			int pickedCity = citiesLeft[i]
			currentDist += distance[currentCity][pickedCity];
			citiesLeft.remove(pickedCity);
			route.add(pickedCity);
			bestRouteHelper(distance, pickedCity, route, citiesLeft, bestDist, currentDist, bestRoute);
			route.remove(route.size()-1);		
			currentDist -= distance[currentCity][pickedCity];
			citiesLeft.add(pickedCity);
		}
	}
}
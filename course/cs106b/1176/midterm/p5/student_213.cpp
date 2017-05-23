Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route.add(startCity);
	int counter = 0;
	Vector<int> theBestRoute = checkRoutes(counter, startCity, distance, route)
	return theBestRoute;
}

Vector<int> checkRoutes(int &counter, int &startCity, Grid<double> &distance, Vector<int> &route) {
	if(counter == distance.numRows()-1) {
		route.add(distance.get(startCity, route.get(0)); // adds the first city back at the end
		double total = totalRouteDistance(Grid<double> &distance, Vector<int> route); // calculates distances
		if(total < bestRoute) {
			bestRoute = total;
			possibleBestRoute = route;
			return possibleBestRoute;
		}
	} else {
		counter += 1; // We know that it is over when it has touched every city (but not yet returned)
		for(int i = 0; i < distance.numRows(); < i++) {
			if(startCity != i) {
				int checkDistance = distance[startCity][i];
				if(checkDistance = DBL_MAX) {
					return DBL_MAX;
				} else {
					route.add(i);
					Grid<int> holdingGrid;
					for(int z = 0; z < distance.numRows()-1; z++) {
						holdingGrid.set[z][i] = distance.get(z, i);
						distance[z][i] = DBL_MAX; // creating them as infinite means they will never be the shortest route; effectively removes them as an option
						holdingGrid.set[z][startCity] = distance.get(z, i);
						distance[z][startCity] = DBL_MAX
					}
					startCity = i;
					possibleBestRoute = checkRoutes(counter, startCity, distance, route);
					distance[z][i] = holdingGrid.set(z, startCity); //resets grid
					distance[z][startCity] = holdingGrid.set(z, startCity);
					route.remove(i);
				}
			}
		}
	}
}
	
	


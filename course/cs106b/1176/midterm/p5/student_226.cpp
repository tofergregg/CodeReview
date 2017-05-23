Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> currRoute;
	currRoute.add(startCity);
	Set<int> usedCities;
	usedCities.add(currRoute);
	Vector<int> bestRoute;
	return bestRoute(distance, startCity, DBL_MAX, currRoute, bestRoute, usedCities);
	
	

	
	
//helper function
Vector<int> bestRoute(Grid<double> &distance, int startCity, double smallestDistance, Vector<int> 						currRoute, Vector<int> bestRoute, Set<int> usedCities){
	if(currRoute.size() == distance.numRows()) {
		currRoute.add(startCity);
		return currRoute;
	} else {
		for(int i = 0; i < distance.numRows(); i++) {
			if(!usedCities.contains(i)) {
				currRoute.add(i);
				usedCities.add(i);
				Vector<int> route = bestRoute(distance, startCity, smallestDistance, currRoute, 										bestRoute, usedCities);
				currRoute.remove(currRoute().size() - 1);
				usedCities.remove(i);
				if(totalRouteDistance(distance, route) < smallestDistance){
					smallestDistance = totalRouteDistance(distance, route);
					bestRoute = route;
				}
			}
		}
	}
	return bestRoute;
}
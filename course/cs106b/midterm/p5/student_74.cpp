Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<Vector<int>> allRoutes;
	Vector<int> route;
	currentRoute.add(startCity);
	bestRoute(allRoutes, distance, startCity, route);
	Vector<int> bestRoute = findShortestRoute(allRoutes, distance);
	return bestRoute;
}

void bestRoute(Set<Vector<int>> &allRoutes; Grid<double> &distance, int startCity, Vector<int> ¤tRoute) {
	//each call checks every possible nextCity in grid
	for (int i = 0; i < distance.numCols(); i++) { 
		int nextCity = i;
		if (haveNotVisitedYet(currentRoute, nextCity) {
			currentRoute.add(nextCity); //will only add new city or start city
			
			//checks if path has visited max # of cities, not including final city
			if (currentRoute.size() + 1 == distance.numCols()) { 
				if (nextCity == startCity) {
					allRoutes.add(currentRoute); //base case, end of route
				} else { //path has reached max length, did not reach startCity	
					currentRoute.clear();
					currentRoute.add(startCity);
					bestRoute(allRoutes, distance, startCity, currentRoute);
				}
			} else {
				bestRoute(allRoutes, distance, startCity, currentRoute);
			}
			
		}
	}
}
			
Vector<int> findShortestRoute(Set<Vector<int>> &allRoutes, Grid<double> &distance) {
	Vector<int> shortestRoute;
	double shortestDistance;
	for(Vector<int> route : allRoutes) {
		double totalDistance = totalRoutedistance(distance, route);
		if (totalDistance < shortestDistance) {
			shortestDistance = totalDistance;
			shortestRoute = route;
		}
	}
	return shortestRoute;
}
			
bool haveNotVisitedYet(Vector<int> currentRoute, int nextCity) {
	for (int i = 1; i < currentRoute.size(); i++) { //no need to check start city here
		if (currentRoute[i] == nextCity) {
			return false;
		}
	}
	return true;
}
	
		


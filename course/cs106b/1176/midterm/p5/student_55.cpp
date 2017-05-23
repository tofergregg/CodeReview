Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// initizalize empty route
	// need to hit all the cities (set? how do you make sure start city is last?)
	Vector<int> route;
	bestRoute(distance, startCity, startCity, DBL_MAX, route);
	
}

// Helper
Vector<int> bestRoute(Grid<double> &distance, int targetCity, int currCity, double minDistance, Vector<int> &route) {
	// base case (also need to check if you've gone to every city)
	if ((currCity == targetCity) && (minDistance < DBL_MAX)) {
		// this is a valid solution
		return route;
	}
	else {
		// recursive case
		double localMinDist = minDist;
		Vector<int> localBestRoute = route;
		for (int r = 0; r < distance.numRows; r++) {
			if (currCity != r) {
			//  add city to route for recursion
				route.add(currCity);
			//	get best route from that city to start city
				Vector<int> currRoute = bestRoute(distance, targetCity, r, localMinDistance, route);
				currDist = totalRouteDistance(distance, currRoute)
				if (currDist < localMinDist) {
					localMinDist = currDist;
					localBestRoute = currRoute
				}
			//	remove city from route
				route.remove(roue.length()-1);
			}
		}
		return localBestRoute
	}
	
}

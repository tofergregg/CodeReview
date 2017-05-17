// function prototype
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int nextCity, Vector<int> &globalBestRoute)

// main function
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	startCity = 0;
	int nextCity = 0;
	// creat an empty global best route vector
	Vector<int> globalBestRoute;
	// every route starts with city 0
	globalBestRoute.edd(0);
	// call helper function
	Vector<int> bestRoute = bestRouteHelper(distance, startCity, 										nextCity,globalBestRoute);
	return bestRoute;
}

// helper function
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int nextCity, Vector<int> &globalBestRoute) {
	//BASE
	// once original city is reached, complete the globalBest vec
	// and return vector
	if (nextCity == 0) {
		localBestRoute.add(0); 
		return localBestRoute;
	}
	// RECURSIVE
	for (int nextCity = distance.numCols() - 1; nextCity >= 0; 														nextCity--) {
		// if a route is not already considered
		// it will not be marked as -1
		if (distance[startCity][nextCity] != -1) {
			// use location to populate a route and mark used
			double original = distance[startCity][nextCity];
			distance [startCity][nextCity] = -1;
			globalBestRoute.add(nextCity);
			startCity = nextCity;
			Vector<int> localBestRouteHelper(distance, startCity, 										nextCity, globalBestRoute);
			// undo the marking (backtrack)
			distance[startCity][nextCity] = original;
			// after a local route vector is recursed
			// calculate distance & compare w/ globalbestroute
			if (totalRouteDistance(distance, localBestRoute) < 					totalRouteDistance(distance, globalBestRoute) {
				globalBestRoute = localBestRoute;
			}
		}
	}
	return globalBestRoute;
}

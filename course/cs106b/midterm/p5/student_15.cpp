Vector<int> bestRouteHelper(Grid<double> &distance, int curr, int next, Vector<int> currRoute, Map<Vector<int>> &cache);


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> currRoute = {0};
	// store paths that have already been visited
	Map<Vector<int>> cache;
	return bestRouteHelper(distance, startCity, startCity, currRoute, cache);
}

// Starting at distance[startCity][startCity]
Vector<int> bestRouteHelper(Grid<double> &distance, int curr, int next, Vector<int> currRoute, Map<Vector<int>> &cache){
	// Base case: all cities have been visited
	if (currRoute.size() == distance.numRows()){
		return currRoute;
	}
	// Recursive case: still have to visit cities
	// Have distance.numRows() - 1 options.
	// Must consider being in a city other than 0, 
	// Then have to loop around row or column to check out cities
	// OPTIONS: for all i < currentCity, 
	// Check out city at distance[startCity][numRows % i]
	// Check distances for each and add upon return
	// Return best option
	
	
	
	


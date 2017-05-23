Vector<int> bestRoute(Grid<double> &distance, int startCity) {
//find best solution
	// base case: validate running solution
	// recursive case: make all recursive calls, output the best
	
	int nextCity = -1;
	Vector<int> route;
	return bestRouteHelper(distance, route, startCity, nextCity);
}
	
	
Vector<int> bestRouteHelper(Grid<double> &distance, Vector<int> &route, int startCity, int nextCity)	{
	
	
	if (currentCity == startCity) {
		return route;
	}
	
	
	for (int r = 0; r < distance.numRows(); r++) {
		for (int c = 0; c < distance.numCols(); ++ {
			if (c!=r) {
			int routeDistance = grid[startCity][c];
				route.add(c);
				nextCity = c;
				return bestRouteHelper(distance, route, startCity + 1,nextCity);  
	
			}
		}
	}
}
			 
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int n = distance.numRows();
	Vector<int> theBestRoute;
	Vector<int> chosen;
	theBestRoute = bestRouteHelper(distance, startCity, n);	
}
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int n, Vector<int>& chosen) {
	// base case: current position is startCity and has visited distance.numRows() cities
	if (n == 0) {
		if ((chosen[chosen.size() - 1] == startCity)) {
			return chosen; \\ return solution
		} else {
			return 0; \\ invalid solution return nothing
 		}
	} else {
		int actualDistance = 0;
		// if a city has been explored it needs to be removed from branch
		// to not visit it again
		for (int i = distance.numCols; i > distance.numCols; i--) {
			chosen = i;
			actualDistance += bestRouteHelper(distance[startCity][i], startCity, n - 1, chosen);
		}
		// check which distance is smaller
		
		
	}
	return chosen;	
}


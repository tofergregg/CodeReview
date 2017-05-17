Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	Vector<int> bestRoute;
	//adds all possible values of bestRoute
	for (int i= 0; i < distance.numCols(); i++) {
		bestRoute.add(i);
	}
	
	bestRoute = helperRoute(distance, startCity, bestRoute);
	
	return bestRoute;
}	

Vector<int> helperRoute(Grid<double> &distance, int startCity, Vector<int> bestRoute) {
	if (bestRoute.isEmpty()) {
		//calculates the total distance and checks if its the least 
		int distance = totalDistance(bestRoute);
		return bestRoute;
	} else {
		//recursively go through every path possible and returns the path that is the 
		//least distance
		//explore the options
		for (int i = 0; i < distance.numCols(); i ++) {
			bestRoute.add(i);
			bestRoute = helperRoute(distance, startCity, bestRoute);
		}
		return bestRoute;
	}
}

	
//finds the total distnce given a vector
int totalDistance (Vector<int> bestRoute, Grid<double> &distance) {
	int sum;
	for (int i= 0; i < bestRoute.size() - 1; i++) {
		int row = bestRoute[i];
		int col = bestRoute[i+1];
		sum += distance.get(row, col);
	}
	return sum;
}
	



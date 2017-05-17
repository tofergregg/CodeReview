

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> path;
	path.add(startCity);
	double best = DBL_MAX;
	Vector<int> bestRoute = bestRouteHelper(distance, startCity, 			startCity, startCity, path, best);
	return bestRoute;
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, 		int row, int col, Vector<int> path, double best) {
	
	// base case
	if(row == startCity && col == startCity) {
		if (path.size() < 4) {
			return;
		} else {
			path.add(startCity);
			return path;
		}
	}
	
	//recursive case
	Vector<int> bestRoute = path;
	Vector<int> route = bestRouteHelper(distance, startCity, 			startCity - 1, startCity, path, best);
	Vector<int> route = bestRouteHelper(distance, startCity, 			startCity, startCity +1, path, best);
	Vector<int> route = bestRouteHelper(distance, startCity, 			startCity + 1, startCity, path, best);
	Vector<int> route = bestRouteHelper(distance, startCity, 			startCity, startCity - 1, path, best);
	double distance = totalRouteDistance(distance, path);
	if(distance < best) {
		best = distance;
	}
	bestRoute = route;
	
	return bestRoute;
			
			
	
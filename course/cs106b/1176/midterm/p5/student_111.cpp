Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector <int> route;
	return helper(distance, startCity, route, startCity);
}

Vector<int> helper(Grid<double> &distance, int startCity, Vector <int> &route, int currCity) {
	//base case
	if (completeTrip(route)){
		return route;
	} else {
		int best = DEL_MAX;
		Vector <int> bestVec;
		Vector <int> attempt;
		for (int c = 0; c < distance.numCols(); c++) {
			route.add(c);
			attempt = helper(distance, startCity, route, currCity);
			if (double totalRouteDistance(Grid<double> &distance, Vector<int> &attempt < best) {
				best = totalRouteDistance(Grid<double> &distance, Vector<int> &attempt;
				bestVec = attempt;
			}	
		}
		return (bestVec);		
}
		
		
		
		
bool completeTrip (Vector <int> &route) {
	for (int c = 0; c < distance.numCols; c++) {
		if (!route.contains(c)) return false;
	}
	return true;
}
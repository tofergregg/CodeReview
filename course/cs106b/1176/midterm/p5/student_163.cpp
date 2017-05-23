Vector<int> bestRouteHelper(Grid<double> &dist, int start, double distMin, Vector<int> row, Vector<int> route);
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double distMin = DBL_MAX;
	int n = distance.numCols(); //shouldn't matter rows or cols since
	// number of cities doesn't change
	Vector<int> row;
	Vector<int> route;
	for(int i = 0; i < distance.numCols(); i++) {
		row[i] = i;
	}
	return bestRouteHelper(distance, startCity, distMax, row, route);
}
Vector<int> bestRouteHelper(Grid<double> &dist, int start, double distMin, Vector<int> row, Vector<int> route) {
	if(row.isEmpty()) {
		/*
		 * ideally, this would return the optimal route if the
		 * route is determined to have a smaller distance than the 				 * current minimum distance
		 */
		if(totalRouteDistance(distance, route) < distMin) {
			distMin = totalRouteDistance(distance, route);
			return route;
		}
	}
	for(int index = 0; index < row.size(); index++) {
		if(start != index){
			route.add(dist[start][index]);
			row.remove(start);
			return bestRouteHelper(dist, index, distMin, row, route);
			row.insert(start,start);
			route.remove(route.size()-1);
		}
	}
	return route;
}
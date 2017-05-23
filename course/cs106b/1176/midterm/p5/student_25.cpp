void bestRoute(Grid<double> &distance, int startCity, Queue<int> &unvisited, double &shortest, Vector<int> &route) {
	// base case
	if (unvisited.size() == 1) {
		route.add(unvisited[0]);
		route.add(startCity);
		double potentialShortest = totalRouteDistance(distance, route);
		if (potentialShortest < shortest) {
			shortest = potentialShortest;
			Vector<int> currentBest = route; 
		}
	}
	// recursive case
	if (unvisited.size() > 1) {
		int nextCity = unvisited.dequeue();
		route.add(nextCity); // choose
		bestRoute(distance, nextCity, unvisited, shortest, route); // recurse
		unvisited.enqueue(nextCity); // un-choose
	}
	route = currentBest;
}

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Queue<int> unvisited;
	for (int i=0; i < distance.numCols(); i++) {
		if (i != startCity) {
			unvisited.add(i);
		}
	}
	double shortest = DBL_MAX;
	Vector<int> route;
	route.add(startCity);
	bestRoute(distance, startCity, unvisited, shortest, route);
	return route;
}


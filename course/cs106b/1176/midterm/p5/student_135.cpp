Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	int shortestDist;
	route = helper(distance, route, startCity, 0, 0);
	return route;
}

Vector<int> helper(Grid<double> &distance, 
				   Vector<int> &route, int startCity, 
				   int shortestDist, int nextCity) {
	if (route.size() == grid.numRows()+1) { //  when all cities have been 													traversed once and we have 													returned to the start city
		return route;
	}
	else {
		if (nextCity < distance.numCols - 1) { 
			int currDistance = shortestDistance + distance[startCity]					[nextCity];
			route.add(nextCity);
			// in next recursive call the nextCity is the new StartCity
			helper(distance, route, nextCity, 				     	  	 										shortestDistance, nextCity+1);
			//Pseudocode: update shortestDistance if currentDistance
			//is less than the shortestDistance and return the vector
			//that yielded the shortest distance
	}
	return route;
}
	

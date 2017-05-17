Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	// create vector to choose filled with distance values
	Vector<int> chosen;
	for (int i = 0; i < distance.numCols(); i++) {
		for (int j = 0; j < distance.numRows(); j++) {		
		chosen.set(i*j,distance[i][j]); //fill
	}
}
	return Vector<int> bestRouteHelper(distance, startCity, 0, 0, DBL_MAX, route, chosen);	//call helper function
}



Vector<int> bestRouteHelper(Grid<double> &distance, int row, int column, double sum, double maxSum, Vector<int> &route, , Vector<int> &chosen) {
	//base case
	
	if (chosen.isEmpty()) {	
		return route;		
	} else {	
	//recursive case 
	double temp = distance[startCity][column];	//store distance
	route.add(temp);	//add to route to be returned
	chosen.remove(row*column);	//choose
	//explore recursively
	double totalDistance = totalRouteDistance(distance, route);
	bestRouteHelper(distance, row, column + 1, totalDistance, maxSum, route, chosen);
	bestRouteHelper(distance, row + 1, column, totalDistance, maxSum,  route, chosen);
	bestRouteHelper(distance, row - 1, column, totalDistance, maxSum,  route, chosen);
	bestRouteHelper(distance, row, column - 1, totalDistance, maxSum,  route, chosen);
		
	if (maxSum > sum) {
		maxSum = sum;	//check for shortest distance
	}
		
	chosen.add(temp);	// restore chosen vector
	return route;	//return route vector
	}
}
	

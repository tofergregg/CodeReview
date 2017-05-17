Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	Vector<int> currentRoute;
	int startRow = startCity;
	int startCol = startCity;
	double bestDistance = 0;

	for(int startRow; startRow < distance.numRows(); startRow++) {
		for(startCol; startCol < distance.numCols(); startCol++) {
				
		bestRoute[startRow][startCol] = findBestRoute(distance, startCity, currentRoute);
		}
	}
}

int findBestRoute(Grid<double> &distance, int startCity) {
	//base case
	if(distance[r][c] == distance[startCity][startCity]) {
		double totalDistance = totalRouteDistance(distance, route);
		return totalDistance;
	} else {
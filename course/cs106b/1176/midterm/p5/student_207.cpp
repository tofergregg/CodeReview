// We will use recursive backtracking for this problem. There will be a calculateDistance helper function that adds all possible routes from a given start city and then stores the minimal value in a variable named minimumDistance. minimumDistance is then used to identify the shortest route, which is stored in a Vector and passed from bestRoute. 

Vector<int> bestRoute(Grid<double> &distance, int startCity) 
	double maximumDistance = DBL_MAX;
	int betweenDistance;
	for (int r = 0; r < distance.numRows(); r++) {
		for (int c = 0; c < distance.numCols(); c++) {
			betweenDistance = distance[startCity][c];
			int nextDistance = 
		}
	}
	return bestDistance;
}

int calculateDistance(Grid<double> & distance, int startCity) {
	double minimumDistance = DBL_MAX;
	if calculateDistance(distance[r+1][c+1],startCity+1) < minimumDistance {
		calculateDistance(distance[r+1][c+1],startCity+1) = minimumDistance;
	}
	int totalDistances = 0;
	for (int r = 0; r < distance.numRows(); r++) {
		for (int c = 0; c < distance.numCols(); c++) {
			totalDistances= distance[r][c] + distance[r+1][c+1] + distance[r+2][c+2] + distance [r+3][c+3] + distance[r+4][c+4];
		}
	}
	return totalDistances;
}

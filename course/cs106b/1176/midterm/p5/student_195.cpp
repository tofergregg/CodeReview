Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> currPath; 
	currPath.add(startCity);
	double minDistance = 0; 
	Set<int> visited; 
	visited += startCity; 
	minDistance = recBestRoute(distance, startCity, currPath, minDistance, 0, visited);
	return currPath; 
}
/* base case: if the currentPath size = the number of rows in the currGrid (the number of cities)
	recursive case: iterate through all the possible next locations (except ones that have already been visited or the current one you're exploring get the current distance of the next step in the past with recursively finding subpaths. check if the current distance is less than the current min distance. if so, add that location to the current path and make min distance that distance. 
*/
double recBestRoute(Grid<double>& distance, int startCity, Vector<int>& currPath, 
						 double& minDistance, double currDistance, Set<int>& visited) {
	if(currPath.size() == distance.numRows()){
		currPath.add(currPath[0]); 
		return currDistance; 
	} 
	
	for (int r = 0; r < distance.numRows(); r ++) {
		if(r == startCity || visited.contains(r)) continue; 
		double localDistance = grid[startCity][r]; 
		
		currDistance = recBestRoute(distance, r, currPath + r, minDistance, 
							dist + localDistance, visited + r); 
		if(currDistance < minDistance) {
			minDistance = currDistance; 
			currPath += r; 
		}
		visited.clear(); 
		
	}
		
	return minDistance; 
}

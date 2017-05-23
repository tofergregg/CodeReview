Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<int> visited;
	Vector<int> route;
	return bestRoute(distance, startCity, route, currentBest, visited);
}

Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> route, Vector<int>& currentBest, Set<int>& visited) {
	//Checks if every city has been visited, the path size is actually shorter, and that the 
	//last city visited is the starting city.
	if (route.size() == distance.nRows()+1 && route[distance.nRows()] == 0 && 	getPathSize(distance, route)< getPathSize(currentBest)) {
		currentBest = route;
	}
	else {
		if (!route.isEmpty()) {
			//Set up the starting case.
			route += 0;			
		} else {			
			for (int i = 0; i < distance.nRows(); i++) {
				if (!visited.contains(i)) {
					visited += i;
					route.add(i);
					bestRoute(distance, i, route, currentBest, visited);
					//backtrack
					route.remove(i);
					visited.remove(i);
				}
			}
		}
	}
	return currentBest;
}


double getPathSize(Grid<double> &distance, Vector<int> route) {
	double size;
	for (int i = 0; i < route.size()-1; i++) {
		int cityOne = route[i];
		int cityTwo = route[i+];
		double pathLength = distance[cityOne][cityTwo];
		size += pathLength;
	}
	return size;
}
							  
		
		
		
	

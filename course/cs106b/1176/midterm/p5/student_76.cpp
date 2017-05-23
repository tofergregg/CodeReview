Vector <int> findBestRoute(Grid<double> &distance, int startCity, 
						   int nextCity){
	//recursive case:
	if(!distance.inBounds(startCity, startcity){
		throwExeception("Not a valid startCity");
	}
	if(distance.numRows() == 0 && distance.numCols() == 0){
		Vector<int> route;
		size.add(0);
		return size; 
	else{
		Set<Vector<>> possibleRoutes;
		for(int r = 0; r < distance.numRows(); r++){
				Vector<int> route; 
				route.add(r);
				int nextCity = c;//choose a path
				route.add(distance[r][c]);
				findBestRoute(distance, startCity, r);
				findBestRoute(distance, startCity, c);
		}
		Vector<int> bestRoute = smallestRoute(distance, possibleRoutes);
		return bestC;
}

Vector<int> smallestRoute(Grid<double> &distance, Set<Vector<int>>&possibleRoutes)
	Vector<int> minV = possibleRoutes[0];
	double min = totalRouteDistance(distance, possibleRoutes[0];
	for(Set vector: possibleRoutes){
		double next = totalRouteDistance(possibleRoutes[vector]);
		if(next < mine){
			min = next;
			minV = possibleRoutes[vector];
		}
	}
	return minV;
									}
	

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	findBestRoute(distance, startCity, startCity); 
}



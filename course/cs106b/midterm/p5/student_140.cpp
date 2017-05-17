Vector<int> helper(Grid<double> &distance, int currCity, int startCity, int nextCity, Vector<int>& bestRoute, Vector<int>& currRoute, double bestDistance, double currDistance);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int nextCity = 0;
	int currCity = startCity;
	double bestDistance;
	double currDistance;
	Vector<int> bestRoute;
	Vector<int> currRoute;
	currRoute.add(startCity);
	return helper(distance, startCity, currCity, nextCity, bestRoute, currRoute; bestDistance, currDistance);
}


//currCity is the one we are on, nextCity is the following exploration, startCity is constant for base case comparison 

Vector<int> helper(Grid<double> &distance, int currCity, int startCity, int nextCity, Vector<int>& bestRoute, Vector<int>& currRoute, double bestDistance, double currDistance){
	
	if(nextCity==startCity){
		//compare bestDistances to determine bestRoute
			if(currDistance>bestDistance){
				bestDistance = currDistance; 
				bestRoute = currRoute;	
				return bestRoute;
			}else{		
				return bestRoute;
		}
	}
	
	//go through all members if the grid
	for(int row = 0; row<distance.numRows(); row++){
		for(int col = 0; col<distance.numCols(); col++){
			nextCity = distance[row][col];
			currRoute.add(nextCity);
			//find current distance of this chosen path
			currDistance = totalRouteDistance(distance, 					currRoute);
			//remove currCity
			currRoute.remove(currCity);
			currCity = nextCity;
			helper(distance, startCity, currCity, grid[row+1][col+1], bestRoute, currRoute, bestDistance, currDistance);
				//add currCity back 
			currRoute.add(currCity);		
		}
	}
	return bestRoute;
}

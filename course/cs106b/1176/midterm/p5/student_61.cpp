void bestRouteHelper(Grid<double>& distance, int current, int goal, Vector<int>& currentRoute, double& currentDistance);

Vector<int> bestRoute(Grid<double>& distance, int startCity) {
	Vector<int> currentRoute;
	double currentDistance;
	bestRouteHelper(distance, startCity, startCity, currentRoute, currentDistance);
}

Vector<int> bestRouteHelper(Grid<double>& distance, int current, int goal, Vector<int>& currentRoute, double& currentDistance){
	if(current == goal && !currentRoute.isEmpty){
		return currentRoute; //success
	}else if(totalRouteDistance(distance, currentRoute) == DBL_MAX){
		return; //failure
	} else { //recursive case
		Vector<int> currRoute = currentRoute;
		currRoute.add(current);
		currentDistance += distance[current][current];
		for(int row = 1; row < distance.numRows(); row++){
			for(int col = 1; col < distance.numCols(); col++){
				if(distance[current + row][current] < 		distance[current][current+col]) {
					return bestRouteHelper(distance, current+row, goal, currRoute, currentDistance);
				} else {
					return bestRouteHelper(distance, current+col, goal, currRoute, currentDistance);
				}
			}
		}
	}
}
			  
				
		


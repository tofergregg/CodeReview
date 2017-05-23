
double bestRoute(Map<int,Vector<int>>& map, int& currCity, int startCity, Vector<int>&route){
	if(currCity==startCity && !route.isEmpty()) {
		return route;
	} else {
		int distanceToDestination;
		for(int destination :map[currCity]){
			if(distance[currCity][destination]<distanceToDestination){
				route.add(destination);
				bestRoute(map, destination, startCity);
			}
		}
	}
}
				
		

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	//each city is a column and a row in the grid. So it has a 
	//vector of its associated with it
	Map<int, Vector<int>> map;
	for(int city=0;city<distance.numCols();city++) {
		for(int row=0; row<distance.numRows();i++) {
			if(row!=city) {
				map.put(row);
			}
		}
	}
	Vector<int> route;
	route = bestRoute(map, startCity, startCity, route);
	double distanceTraveled = totalRouteDistance(distance,route);
		
}

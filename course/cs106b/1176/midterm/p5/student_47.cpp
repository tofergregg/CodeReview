double routeLength = 0;
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Set<int> cityPoints, Vector<int>& path);


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<int> cityPoints;
	Vec<int> path;
	return bestRouteHelper(distance, startCity, numCities, path);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Set<int> cityPoints,	Vector<int>& path) {	
	if(cityPoints.size() == distance.numRows()) {
		Vector<int> route;
		for(int i = 0; i < cityPoints.size(); i++) {
			route.add(cityPoints[i]);
			route.add(cityPoints[1]);
		}
		if(totalRouteDistance(distance,route) < routeLength) {
			size = totalRouteDistance(distance,route);
			return route;
		}
	} else {	
		int gridPlace = distance[startCity][startCity];
		cityPoints.add(gridPlace);
		for(int i = 0; i < distance.numCols(); i++) {
			if(cityPoints.contains(distance[startCity][i]) == false) {
				cityPoints.add(distance[startCity][i]);
				path.add(distance[startCity][i]);
				return bestRouteHelper(distance,distance[i][i],cityPoints);
			}
		}
		
	}
}

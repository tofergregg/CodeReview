Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	Vector<int> route;
	int tripDistance = 0;
	Map<double, routeHelper> map;
	int minDistance=DBL_MAX;
	
	map = routeHelper(distance, startCity, map);
	//loop through map to get the min distance
	for (int key:tripDistance) {
		if (key <= minDistance) {
			minDistance = key;
		}
	}
	bestRoute = map[key];
	return bestRoute;
}


//helper function to help get routes
Map<double,Vector<int>> routeHelper(Grid<double> &distance, int startCity, Map<double, routeHelper> &map) {
	Vector<int> route;
	Set<int> cityList;
	cityList.add(startCity);
	if (map.size() == factorial(distance, numRows()-1), return map;
	else {
		if (cityList.size()==distance.numCols()) {
			map.put(totalRouteDistance(distance, route);
		} else {
			for(int i=0;i<distance.numCols()-1;i++){
			if (!cityList.contains(i)) {
 				route.add(routeHelper(distance, i, distance));
				 routeHelper);
			}
			}
			return map;
		}
	}
}
	
					
//get the number of all possible routes
int factorial(int &n) {
	if (n=1) return n;
	else {
		n=n*factorial(n-1);
	}
}



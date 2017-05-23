Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> finalRoute;
	int maxCity = distance.numCols()-1;
	finalRoute.add(startCity);
	for(int i = 0; i < maxCity; i++){
		if(i != startCity){
			finalRoute.add(i);
		}
	}
	finalRoute.add(startCity);
	finalRoute = routeFinder(finalRoute, distance);
	return finalRoute;
}


Vector<int> routeFinder(Vector<int> route, Grid<double> &distance, Vector<int> tempRoute){
	int length = totalRouteDistance(distance, route);
	tempRoute = route;
	//supposed to generate the random sequences ignoring the start //cities
	for(int i = 1; i<route.size()-1;i++){
		for(int j = 1; j< route.size() -1; j++){
			int temp = tempRoute[i];
			tempRoute[i] = route[j];
		}
	}
	if(length > totalDistance(distance, tempRoute){
		return tempRoute;
	}else{
		return routeFinder(tempRoute, distance);
	}
}
	
		
	
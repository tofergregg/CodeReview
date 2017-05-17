Vector<int> bestRoute(Grid<double> &distance, Vector<double> &route, int currentCity, Set<int> &remainingCities, Set<Vector<int>> &routes){
	if(remainingCities.isEmpty()){
		route.add(distance[currentCity][0]);
		return route;
	}else{	
		for(int c : remainingCities) {
			double dis = distance[currentCity][c];
			route.add(dis);
			Set<int> newRemain = remainingCities;
			newRemain.remove(c);
			routes.add(bestRoute(distance, route, c, newRemain, routes));
		}
	
		Vector<int> finalRoute;
		int bestDist = DBL_MAX;
		
		for(Vector<int> r : routes){
			tempDist = totalRouteDistance(distance, r);
			if(tempDist<bestDist) finalRoute = r;
		}
		return finalRoute;
				


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<int> remainingCities;
	Set<Vector<int>> routes;
	for (int c=1; c<distance.numRows(); c++) {
		remainingCities.add(c);
	}
	
	Vector<int> finalRoute;
	
	return bestRoute(distance, finalRoute, 0, remainingCities, routes);


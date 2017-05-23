Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> currentRoute;
	Vector<int> remainingCities;
	Vector<int> bestRoute;
	currentRoute.add(startCity);
	int numCities = distance.numCols();
	for(int i=0;i<numCities;i++) {
		if(i!=startCity) {
			remainingCities.add(i);
		}
	}
bestRoute = findRoute(currentRoute,remainingCities,distance,startCity,DBL_MAX);
return bestRoute;
}
	
Vector<int> findRoute(Vector<int> currentRoute, Vector<int> remainingCities, Vector<int> bestRoute, Grid<double> &distance, int startCity, int bestDistance) {
	if(remainingCities.size()==0) {
		currentRoute.add(startCity);
		return currentRoute;
	}
	else {
		for(int i=0;i<remainingCities.size();i++) {
			int cityRemoved = remainingCities[i];
			currentRoute.add(cityRemoved);
			remainingCities.remove(i);
	findRoute(currentRoute,remainigCities,distance,startCity);
		if(totalRouteDistance(distance,currentRoute) < bestDistance) {				bestRoute = currentRoute;
		}
		remainingCities.add(i,cityRemoved);
		currentRoute.remove(currentRoute.size()-1);
		}
	}
	return bestRoute;
}
		   
		
			
		
		

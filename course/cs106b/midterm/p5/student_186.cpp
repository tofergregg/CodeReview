Vector<int> bestRoute(Grid<double> &distance, int startCity, double &shortestDistance);

Set<int> usedCities();
Vector<int> route();

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	return bestRoute(distance,startCity,DBL_MAX);
}

Vector<int> bestRoute(Grid<double> &distance, int startCity, double &shortestDistance){
	int localShortestTrip = shortestDistance;
	if (usedCities.contains(startCity)){
		if (usedCities.size() == distance.numCols(){
			return route;
		}
		return {};
	}
	for (int i = 0; i<distance.numCols(); i++){
		route.add(i);
		int currDist = distance[startCity][i] + shortestDistance;
		startCity = i; 
		route = bestRoute(distance,startCity,currDist);
		if (!route.isEmpty){
			if (currDist<localShortestTrip){
				localShortestTrip= currDist;
				return route;
			}
		}
		currDist = currDist - distance[startCity][i];
		route.remove(route.length()-1);
	}
	return route; 
}

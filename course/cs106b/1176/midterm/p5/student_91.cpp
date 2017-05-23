Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRouteVec;
	bestRouteVec.add(startCity);
	
	Set<int> cities;
	for (int i = 0; i < distance.numRows(); i++) {
		cities.add(i);
	}
	
	bestRouteHelper(distance, cities, bestRouteVec, startCiy, DBL_MAX); //pass in cities

}

Vector<int> bestRouteHelper(Grid<double> &distance, Set<int> cities, Vector<int> &bestRouteVec, int startCity, int shortestDistance){
	Vector<int> localBestRoute = bestRouteVec;
	int localShortestDistance = shortestDistance;
	
	if (vaildPath(distance, localBestRoute, startCity)) return localBestRoute;
	
	for (int city : cities) {
		cities.remove(city);
		Vector<int> passedInBestRoute = bestRouteVec;
		
		int currentDistance = shortestDistance + distance[city][passedInBestRoute.size() - 1];
		passedInBestRoute.add(city);
		
		Vector<int> bestOfChildren = bestRouteHelper(distance, passedInBest, startCity, currentDistance);
		
		if (currentDistance < shortestDistance) {
			localShortestDistance = currentDistance;
			localBestRoute = bestOfChildren;
		}
		
		cities.add(city);
	}
}

		
bool validPath(Grid<double> &distance, Vector<int> &bestRouteVec, int startCity) {
	if (bestRouteVec.size() == distance.numRows() + 1 && bestRouteVec[bestRouteVec.size() - 1] == startCity) return true;
	return false;
}
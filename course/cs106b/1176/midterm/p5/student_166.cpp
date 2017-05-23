Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int endCity = startCity;
	int bestRouteScore;
	Vector<int> bestRouteChoice;
	int routeScore;
	helperRoute(distance, startCity, endCity, bestRouteScore, bestRouteChoice, routeScore);
	return bestRouteChoice;
}
		
Vector<int> helperRoute(Grid<double> &distance, int &startCity, int &endCity, int & bestRouteScore, Vector<int> &bestRouteChoice, int &routeScore) {
	Vector<int> route;
	if(startCity == endCity) {
		double routeScore = totalRouteDistance(distance, route);
		if(routeScore > bestRouteScore) {
			bestRouteScore = routeScore;
			for (int i = 0; i < route.size(); i++) {
				bestRouteChoice.set(i, route[i]);
				routeScore = 0;
				return bestRouteChoice;
			}
		}
	} else {
	for (int i = 0; i < distance.numRows(); i++) {
		secondCity = 1 + i;
		if(startCity == distance.numRols()-1) {
			secondCity = 0;
		}
		route += distance[startCity][secondCity];
		return helperRoute(distance, startCity++, endCity, bestRouteScore, bestRouteChoice, routeScore);
	}
}
		

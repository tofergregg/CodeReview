Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int currDist, Vector<int> currRoute, int bestDistance, Vector<int> bestRoute int currCity);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int upperBound = 0;
	Vector<int> currRoute;
	Vector<int> bestRoute;
	for (int i = 0; i < distance.numCols(); i++) {
		upperBound += 2*distance[0][i];
	}
	return bestRouteHelper(distance, startCity, 0, currRoute, upperBound, bestRoute);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int currDist, Vector<int> currRoute, int bestDistance, Vector<int> bestRoute int currCity) {
	
	if(currDist < bestDist) {
		bestDist = currDist;
		bestRoute == currRoute;
	}
	if (currCity == startCity) {
		return bestRoute;
	} else {
		for (int i = 0; i < distance.numCols(); i++) {
			if (currCity!=i) {
				currRoute.add(i);
				currDist += distance[currCity][i];
				return bestRouteHelper(distance, startCity, currDist, currRoute, bestDistance, bestRoute, i);
			} else {
				continue;
			}
		}
		
	}
}


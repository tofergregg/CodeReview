Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> shortest;
	return bestRouteHelper(distance, startCity, 0, shortest);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int currCity, Vector<int> shortest){
	Vector<int> localShortest = shortest;
	Set<int> usedCities;
	currCity = startCity;
	//Base Case
	if (currCity == startCity && !shortest.isEmpty()){
		return shortest;
	}
	int minDistance;
	for(int r = 0; r < distance.numRows(); r++) {
		if (distance[r][currCity] <= minDistance {
			minDistance = distance[r][currCity];
		}
		localShortest += minDistance;
		for (int i = 0; i < distance.numCols(); i++) {
			distance[r][i] = DBL_MAX;
		}
		currCity = r;
		usedCities += r;
		bestRouteHelper(distance, startCity, r, shortest);
	}
	return localShortest;
}

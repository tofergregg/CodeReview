Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> best;
	Vector<int> check;
	int nextCity = startCity;
	bestRouteHelper(distance, startCity, best, check, nextCity);
	return best;
}

void bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &best, Vector<int> check, int nextCity) {
	if (check.size() == distance.numRows()-1) {
		check.add(distance[nextCity][startCity];
		if (totalRouteDistance(distance, best) == 0) {
			best = check;
		} else {
			if (totalRouteDistance(distance, best) > 
				totalRouteDistance(distance, check)) {
				best = check;
			}
		}
	} else {
		for (int i = 0; i < distance.numRows(); i++) {
			if (i == startCity) i++;
			check.add(distance[nextCity][i]);
			bestRouteHelper(distance, startCity, best, check, i);
		}
	}
}
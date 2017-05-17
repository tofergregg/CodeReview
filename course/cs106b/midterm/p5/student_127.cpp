Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	int r;
	int c;
	route = routeHelper(distance, startCity,  r, c);
}

Vector<int> routeHelper(Grid<double>&distance, int startCity, int r, int c) {
	Map<int, int> usedCity;
	if (usedCity.size() == distance.numRows() + 1) {
		return usedCity.keys();
	}
	else {
			if(!usedCity.contains(r)) {
				value = distance[r][c];
				usedCity.add(r, value);
				r = findBestRoute(usedCity, r, distance);
			}
		return routeHelper(distance, startCity, route, r, c);
}

int findBestRoute(Map<int, int>&usedCity, int r, Grid<double>&distance){
	int smallest = DBL_MAX;
	int row = 0;
	for (int c = 0; c < distance.numCols(); c++)
		if (!usedCity.contains(distance[r][c]){
			if (distance[r][c] < smallest){
			smallest = usedCity.get(dist);
			row = dist;
		}
		}
	return row;						
}
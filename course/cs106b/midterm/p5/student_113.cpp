Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route += startCity;
	route += routHelper
    return route;
	}
}
				
int routeHelper(Grid<double> &distance, int startCity, Vector<int>& route) {
   for (int r = 0; r < distance.numRows; r++ ) {
		if (r != starCity){
			route += r;
		}
		for (int c = 0; c < distance.numCols; r++) {
		    int dist = distance.get(starCity, c);
			int newDist = routeHelper(distance, startCity + 1, route;
		    if (dist < newDist) {
				return c;
			}
		}
	return 0;
}
									  
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numRows = distance.getHeight();
	int numColumns = distance.getWidth();
	Vector<int> finalRoute;
	double const minimum = DBL_MAX;
	Vector<int> currentRoute;

	
			for(int c = 0; c < numColumns; c ++) {
				if (startCity != c) {
					double check = helperFunction(Grid<double> &distance, int startCity, int c, double minimum);
			}
				if (check < minimum) {
					finalRoute.add(check);
				}
	
		}

		
	return finalRoute;
}
	
int helperFunction(Grid<double> &distance, int startCity, int nextCity, int lastMin, Vector<int> currentRoute) {
	
	
	if (nextCity = startCity) {
		double minimum = totalRouteDistance(Grid<double> &distance, Vector<int> &route);
		if (minimum < lastMin) {
		return minimum;
			}
	}
	else {
		
		currentRoute.add(distance[startCity][nextCity]);
		helperFunction(Grid<double> &distance, int nextCity, int minimum)
	}
	
	
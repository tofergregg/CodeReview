void getVector (Grid<double> &distance, Vector<int> &bestRoute, double &minRouteDist);
void calculateBestRoute(Grid<double> &distance, Vector<int> bestRoute, Vector<int> &calcRoute, double routDist, int currentCity, int numCitiesLeft);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double minRouteDist = DBL_MAX;
	Vector<int> bestRoute;
	getVector(distance, bestRoute, minRouteDist);
	return bestRoute;
}

void getVector (Grid<double> &distance, Vector<int> &bestRoute, double &minRouteDist) {
	Vector <int> calcRoute;
	int numCitiesLeft = distance.numRows();
	for(int r = 0; r < distance.numRows(); r++) {
		int currentCity = r;
		double routeDist = 0;
		double calcRouteDist = calculateBestRoute(distance, bestRoute, calcRoute, routeDist, currentCity, numCitiesLeft);
		if (calcRouteDist < minRouteDist) {
			minRouteDist = calcRoutDist;
			bestRoute = calcRoute;
		}
	}
}

double calculateBestRoute(Grid<double> &distance, Vector<int> bestRoute, Vector<int> &calcRoute, double routDist, double minRouteDist, int currentCity, int numCitiesLeft) {
	if(numCitiesLeft == 0) {
		return routeDist;
	} else {
		for(int c = 0; c < distance.numRows(); c++) {
			if (currentCity != c) {
				routeDist += distance[currentCity][c];
				calcRoute[c] = distance[currentCity][c];
				distance[currentCity][c] = DBL_MAX;
				distance[c][currentCity] = DBL_MAX;
				currentCity = c;
				calculateBestRoute(distance, bestRoute, calcRoute, routeDist, currentCity, numCitiesLeft - 1);
			}
		}
	}

}
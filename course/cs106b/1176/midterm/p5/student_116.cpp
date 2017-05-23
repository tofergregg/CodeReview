Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> soFar;
	Set<int> usedCities;
	Vector<int> shortestWay;
	
	soFar.add(startCity);
	usedCities.add(startCity);
	
	int numCities = distance.numCols();
	
	shortestRoute(soFar, usedCities, shortestWay, distance, numCities, startCity);
	
	return shortestWay;
}

void shortestRoute(Vector<int>& soFar, Set<int>& usedCities, Vector<int>& shortestWay, Grid<double> &distance, int numCities, int startCity) {
	if (soFar.size() == numCities) {
		soFar.add(startCity);
		
		if (shortestWay.isEmpty()) {
			shortestWay = soFar;
			soFar.clear();
			soFar.add(startCity);
			usedCities.clear();
			usedCities.add(startCity);
		} else {
			if (totalRouteDistance(distance, soFar) <= totalRouteDistance(distance, shortestWay)) {
				shortesWay = soFar;
				soFar.clear();
				soFar.add(startCity);
				usedCities.clear();
				usedCities.add(startCity);
			}
		}
	} else {
		for (int i=0; i < numCities; i++) {
			if (!usedCities.contains(i)) {
				soFar.add(i);
				usedCities.add(i);
				shortestRoute(soFar, usedCities, shortestWay, distance, numCities, startCity);
				usedCities.remove(i);
				soFar.remove(soFar.size()-1);
			}
		}
	}
}
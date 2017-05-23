Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> distancesTraveled;
	Set<int> citiesLeft;
	for (int i = 0; i < distance.numRows(); i++){
		citiesLeft.add(i);
	}
	int currentCity = startCity;
	bestRouteHelper(distance,distanceTraveled,citiesLeft,currentCity);
	return distancesTraveled
}

void bestRouteHelper(Grid<double> &distance, Vector<int> &distanceTraveled, Set<int> &citiesLeft, int & currentCity) {
	//base case
	if(citiesLeft.isEmpty()) {
		distancetraveled.add[currentCity][0];
	//recursive case
	} else {
		Vector<int> shortestDistance = distanceTraveled.add[DBL_MAX];
		for(int i : citiesLeft) {
			citiesLeft.remove(i);
			distanceTraveled.add(distance[currentCity][i]);
			newCurrentCity = i;
			bestRouteHelper(distance,distanceTraveled,citiesLeft,newCurrentCity);
			if(distanceTraveled[distanceTraveled.size()-1] < shortestDistance[shortestDistance.size()-1]) {
				shortestDistance = distanceTraveled;
			} else {
				distanceTraveled.remove(distanceTraveled.size()-1);
				citiesLeft.add(i)
			}
		}
	}
}
			
			
	

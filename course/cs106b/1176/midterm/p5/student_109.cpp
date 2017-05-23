Vector<int> bestRouteHelper(Grid<double> &distance, Vector<int> &remainCities, Vector<int> ¤tRoute, Vector<int>& bestRoute){
	
	Vector<int> localBestRoute;
	int minDist;
	if (bestRoute.isEmpty()) {
		minDist = DBL_MAX;
	} else {
		minDist = totalRouteDistance(distance, bestRoute);
	}
	
	if (remainCities.isEmpty()) {
		double sumDist = totalRouteDistance(distance, currentRoute);
		if(sumDist < minDist) {
			return currentRoute;
		}  else {
			return bestRoute;
		}
		
	} else {
		for (int i; i < remainCities.size() - 1; i++) {
			int city = remainCities[i];
			remainCities.remove(i);
			currentRoute.add(city);
			localBestRoute = bestRouteHelper(distance, remainCities, currentRoute, bestRoute, minDist);			
			currentRoute.remove(currentRoute.size() - 1, 1);
			remainCities.add(i, city);
		}
	}
	
	return localBestRoute;

}

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	int cities = distance.width() - 1;
	Vector<int> remainCities;
	for (i = 0; i < cities; i++) {
		remainCities.add(i)
	}
	remainCities.remove(startCity);
	Vector<int> currentRoute;
	currentRoute.add(startCity);
	Vector<int> bestRoute;
	
	return bestRouteHelper(distance, remainCities, currentRoute, bestRoute);
		
		
}
	

	

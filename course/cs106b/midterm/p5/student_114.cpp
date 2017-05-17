Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> visitedCities;
	//vector containing all of the cities
	Vector<int> remainingCities;
	for(int i = 0; i < distance.numRows(); i++) {
		remainingCities.add(i);
	}
	double distance = DBL_MAX;
	
	return bestRouteHelper(distance, startCity, visitedCities, remainingCities, distance);
	
}
	
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, 
					  Vector<int> visitedCities,
					  Vector<int>remainingCities, 
					  double distance) {
	//base case: have made it back to original city
	//(would be bigger in size bc 1 extra city)
	if (visitedCities.size() > distance.numRows()) {
		return visitedCities;
	} 
	
	//case: have visited all cities and need to return to startCity
	else if (visitedCities.size() == distance.numRows() {
		visitedCities.add(startCity);
		double newDistance = totalRouteDistance(distance, visitedCities);
		return bestRouteHelper(distance, startCity, visitedCities, remainingCities, newDistance);
	}
			 
	//otherwise...
	double localDistance = distance;
	Vector<int> bestRoute = visitedCities;
	else {
		for(int i = 0; i < remainingCities.size(); i++) {
			//choose
			int nextCity = i;
			remainingCities.remove(i);
			visitedCities.add(i);
			//explore
			double currDistance = totalRouteDistance(distance, 
												visitedCities);
			Vector<int> newRoute = bestRouteHelper(distance, startCity,visitedCities, remainingCities, currDistance);
			double newDistance = totalRouteDistance(distance,
													newRoute);
			//choose the shorter distance
			if(newDistance < currDistance) {
				bestRoute = newRoute;
			}
			//unchoose
			remainingCities.insert(i, i);
			visitedCities.remove(i);
		}
		return bestRoute;
	}
}
			

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> traveled;
	traveled.add(startCity);
	Vector<int> chooseFrom;
	for(int i = 0; i < distance.numCols(); i++) {
		if(i!=startCity) chooseFrom.add(i);
	}
	return bestRoute(distance,traveled,chooseFrom,startCity);
}

Vector<int> bestRoute(Grid<double> &distance,
					  Vector<int> &traveled,
					  Vector<int> &chooseFrom,
					  int startCity) {
	if(chooseFrom.isEmpty()) {
		Vector<int> result = traveled;
		result.add(startCity);
		return result;
	}
	double bestDistance = DBL_MAX;
	Vector<int> bestRoute;
	for(int i = 0; i < chooseFrom.size(); i++) {
		Vector<int> newTraveled = traveled;
		Vector<int> newChooseFrom = chooseFrom;
		newTraveled.add(chooseFrom[i]);
		newChooseFrom.remove(i);
		Vector<int> newRoute = bestRoute(distance,
										 newTraveled,
										 newChooseFrom,
										 startCity);
		double newDistance = totalRouteDistance(distance,newRoute);
		if(newDistance<bestDistance) {
			bestDistance = newDistance;
			bestRoute = newRoute;
		}
	}
	return bestRoute;
}
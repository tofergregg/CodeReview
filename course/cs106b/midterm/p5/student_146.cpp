Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> availableCities; //vector of cities to choose from
	for (int i = 0; i < distance.numRows(); i++) {
		if (i != startCity) availableCities[i] = i; 
		//will add startCity again at end
	}
	return bestRouteHelper(distance, startCity, startCity, availableCities)
}

Vector<int> bestRouteHelper(Grid<double> &distance, int currCity,
		int goalCity, Vector<int> &availableCities) {
	//base case: if we have gone to all available cities we must go
	//to the final city
	if (availableCities.isEmpty()) {
		return {goalCity};
	} 
	Vector<Vector<int>> routes; //vector of routes that are generated
	double shortestDistance = DBL_MAX;
	int shortestIndex = distance.numRows();
	for (int i = 0; i < availableCities.size(); i++) {
		int city = availableCities[i]; //choose city
		availableCities.remove(i)
		Vector<int> route = bestRouteHelper(distance, city, goalCity, availableCities); //recurse
		route.insert(0, currCity);
		routes.add(route);
		if (shortestDistance > totalRouteDistance(distance, route) {
			shortestDistance = totalRouteDistance(distance, route);
			shortestIndex = i;
		}
		availableCities.insert(i, currCity); //unchoose city
	}
	return routes[shortestIndex];
}
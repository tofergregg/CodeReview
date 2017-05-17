//function prototype
void bestRouteHelper(const Grid<double> &distance, int startCity, int citiesLeft, 
							Vector<int> &currRoute, Vector<int> &bestRoute);

Vector<int> bestRoute(const Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	Vector<int> currRoute;
	int citiesLeft = distance.numRows() - 1;
	bestRoute.add(startCity);
	currRoute.add(startCity);
	
	bestRouteHelper(distance, startCity, citiesLeft, currRoute, bestRoute);
	bestRoute.add(startCity);
	
	return bestRoute;
}

void bestRouteHelper(const Grid<double> &distance, int startCity, int citiesLeft, 
							Vector<int> &currRoute, Vector<int> &bestRoute) {
	if (citiesLeft == 0) {
		if (totalRouteDistance(distance, currRoute) < totalRouteDistance(distance, bestRoute) ||
				bestRoute.size() == 1) {
			bestRoute = currRoute;
		}
	} else {
		for (int cityNum = 0; cityNum < distance.numRows(); cityNum++) {
			if (!currRoute.contains(cityNum)) {
				currRoute.add(cityNum);
				bestRouteHelper(distance, cityNum, citiesLeft - 1, currRoute, bestRoute);
				currRoute.remove(cityNum);
			}
		}
	}		
}


/* //Just for fun: a pruned version of the above recursion

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute, currRoute;
	int citiesLeft = distance.numRows() - 1;
	bestRoute.add(startCity);
	currRoute.add(startCity);
	
	bestRoute = bestRouteHelper(distance, startCity, citiesLeft, currRoute, bestRoute);
	bestRoute.add(startCity);
	
	return bestRoute;
}

void bestRouteHelper(Grid<double> &distance, int startCity, int citiesLeft, 
							Vector<int> &currRoute, Vector<int> &bestRoute) {
	if (citiesLeft == 0) {
		if (totalRouteDistance(distance, currRoute) < totalRouteDistance(distance, bestRoute) ||
				bestRoute.size() == 1) {
			bestRoute = currRoute;
		}
	} else if (totalRouteDistance(distance, currRoute) < 
			   totalRouteDistance(distance, bestRoute)) { //to prune some unnecessary calls
		for (int cityNum = 0; cityNum < distance.numRows(); cityNum++) {
			if (!currRoute.contains(cityNum)) {
				currRoute.add(cityNum);
				bestRouteHelper(distance, cityNum, citiesLeft - 1, currRoute, bestRoute);
				currRoute.remove(cityNum);
			}
		}
	}		
} */
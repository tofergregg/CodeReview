Vector<int> bestRoute(Grid<double> &distance, int startCity){
	
	Vector<int> bestRoute (startCity);
	Set<string> usedCities;
	return bestRoute(Grid<double> &distance, Vector<int> bestRoute, DBL_MAX, usedCities);
	
}

Vector<int> bestRoute(Grid<double> &distance, Vector<int> bestRoute, int bestDistance, Set<string> usedCities){
	
	Vector<int> localBestRoute = bestRoute;
	int localBestDitance = bestDistance;
	for (int row = 0; row < distance.numRows() ; row++){
		for (int col = 0; col < distance.numCols(); col++){
			if (row == col) break;
			if (usedCities.contains(intergerToString(row)+intergerToString(col)))break;
			bestRoute.add(row);
			bestRoute.add(col);
			bestDistance = totalRouteDistance (Grid<double> &distance, Vector<int> &bestRoute);
	        usedCities.add(intergerToString(row)+intergerToString(col)))
			bestRoute(Grid<double> &distance, Vector<int> bestRoute, bestDistance);
			localBestRoute.add(localBestRoute.get(0));
			bestDistance = totalRouteDistance (Grid<double> &distance, Vector<int> &bestRoute);
			if (localBestDistance > bestDistance) localBestDistance = bestDistance;
			usedCities.remove(intergerToString(row)+intergerToString(col)));		}
	}
	return localBestRoute;
	
}

		
	




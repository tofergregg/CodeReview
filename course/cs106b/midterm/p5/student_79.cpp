Vector<int> bestRouteHelper(Grid<double>&distance, Vector<int>&choices, int startCity, Vector<int>&chosenRoute, Vector<int>&bestRoute, int bestDistance) { 
	if (choices.isEmpty()) {
		route.add(startCity);
		double chosenDist = totalRouteDistance(distance, chosenRoute); 
		if (bestRoute.isEmpty() || chosenDist < bestDistance) { 
			bestRoute = chosenRoute; 
			bestDistance = chosenDist;
		}		
	}
	else {
		for (int i = 0; i < distance.numRows-2; i++) { 
			int newCity = choices[i];
			choices.remove(i);
			chosenRoute.add(newCity);
			bestRouteHelper(distance, choices, startCity, chosenRoute, bestRoute, bestDistance);
			choices.add(startCity); 
		}
	}
	return bestRoute;
}					

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int>chosenRoute;
	Vector<int>bestRoute;
	Vector<int>choices;
	int bestDistance;
	for(int i = 0; i < distance.numRows()-1; i++) { 
		choices.add(i);
	}
	chosenRoute.add(startCity);
	choices.remove(startCity);
	
	return bestRouteHelper(distance, choices, startCity, chosenRoute, bestRoute, bestDistance); 
}

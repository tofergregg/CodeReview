/*

STRATEGY:

Initialize totalRouteDistance be infinity.

Recursively generate all viable possible routes.

For each viable possibleRoute:

	if (possibleRouteDistance < bestRouteDistance){
		bestRoute = possibleRoute;
	}

Return bestRoute.

*/


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	int numCities = distance.numRows();
	
	double bestRouteDistance = DBL_MAX;

	for (int i = 1; i < numCities; i++){
		Vector<int> possibleRoute;
		Set<string> citiesAlreadyVisited;
		int toCity = i;	
		if (!isViableNextCity(distance, fromCity, toCity, 
	        possibleRoute, citiesAlreadyVisited)){			
			continue;		
		}
		possibleRouteDistance = totalRouteDistance(distance,               possibleRoute);
		
		if (possibleRouteDistance < bestRouteDistance){
			bestRoute = possibleRoute;
		}
	}
	
	return bestRoute;

}

// Helper function
bool isViableNextCity(Grid<double> &distance, int fromCity, int toCity, Vector<int> &possibleRoute, Set<string> &citiesAlreadyVisited){
		
	// Base case: We've already visited toCity.
	if (citiesAlreadyVisited.contains(toCity))return false;
	
	// Base case: fromCity and toCity are the same 
	// but we have not visited every other city.
	if (fromCity == toCity && citiesAlreadyVisited.size() == 	distance.numRows()) return false;
	
	// Base case: fromCity and toCity are the same 
	// and we've visited every other city. We're done generating
	// a possible route!
	if (fromCity == toCity && citiesAlreadyVisited.size() == 	distance.numRows()) return true;
		
	// General case: 
	else {
		possibleRoute.add(toCity);
		fromCity = toCity;
		toCity = randomInteger(0, distance.numRows()-1);
		while (!isViableNextCity(distance, fromCity, toCity, 
	        possibleRoute, citiesAlreadyVisited)){
			toCity = randomInteger(0, distance.numRows()-1);
		}
	}
}




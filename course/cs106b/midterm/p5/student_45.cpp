Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	Vector<int> bestRouteFound;
	Vector<int> cities;
	double totalDist = DBL_MAX
	
	for (int i=0; i<distance.numRows, i++){
		cities.add[i];
	}

	if (distance.numRows > 1){	
		bestRouteHelper(distance, startCity, startCity, cities, totalDist, bestRouteFound);
		return bestRouteFound;	
	} else {
		return {0};
	}
}

void bestRouteHelper(Grid<double> &distance, int currentCity, int startCity, Vector<int> &cities, double totalDist, Vector<int> &route){
	
	citiesReached.add(currentCity);
		
	
	if (cities.isEmpty()){		// route finished
		route.add(startCity);		// adds endpoint at startCity
		
		if (totalRouteDistance(distance,route) < totalDist){
			totalDist = totalRouteDistance(distance,route);
		}
		
	} else {

		while (!cities.isEmpty()){ // no, want to pick any city that hasn't been reached yet
			
		// if all cities have not been reached, don't pick startCity
		// try going to the next city

			newCity = pickNewCity(startCity,cities);
			
			route.add(currentCity);
			cities.remove(newCity);
			bestRouteHelper (distance, newCity, startCity, citiesReached, totalDist, route);
			cities.add(newCity);
			route.remove(currentCity);		 
		}		
	}	
}


int pickNewCity(int startCity, Vector<int> &cities){
	
	int i = randomInteger(0,cities.size());
	
	while (newCity == startCity){
		i = randomInteger(0,cities.size());	// pick a new integer, don't want to use startCity
	}
	return newCity;	
}



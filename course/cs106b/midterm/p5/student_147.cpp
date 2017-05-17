Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	//makes a vector with all the numbers of the cities 
	Vector<int> cities; 
	for (int i = 0; i < distance.numRows; i++) {
		cities.add(i); 
	}
	cities.add(startCity) //adds the startcity another time
		
	return bestRouteHelper(distance, startCity, cities);
}	
	

Vector <int> bestRouteHelper(Grid<double> &distance, int currentCity, Vector<int>& cities) {
	
	if (cities.isEmpty()) { //if already went through all the cities, return the resulting route
		return route; 
	} else if (cities.contains(currentCity)) { //if we have not already visited the city
		
		cities.remove(startCity); //removes the visited city 
		
		Vector<int> route; //creates the resulting vector
		route.add(currentCity); //add the city to the route
		
		int distance = DBL_MAX;
		
		return route = min(double totalRouteDistance((bestRouteHelper(distance, currentCity, cities)), distance; 
			
		cities.add(startCity); //adds the city back into the vector 
	}
	
	int minDistance = DBL_MAX; 
}
	

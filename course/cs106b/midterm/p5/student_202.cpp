Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	
	Vector<int> route;
	route.set(0, startCity);
	
	//gets the size n of the given grid since it will always be nxn size.
	int n = distance.numRows(); 
	
	//set of all cities except the start, will add starting city to end of route set later
	Set<int> remainingCities;
	for(int i = 0; i < n; i++) {
		remainingCities.add(i);
	}
	remainingCities.remove(startCity); 
	
	//All possible routes created in helper function
	Vector<Vector<int>> allPossibilities;
	allPossibilities = bestRouteHelper(distance, remainingCities, route, allPossibilities);
	
	double low = 0;
	//Finds the shortest route out of all the possibilities (Vectors of ints)
	for(int i = 0; i < allPossibilities.size(); i++) {
		double dist = totalRouteDistance(distance, allPossibilities[i]);
		if(dist < low) { //if new distance is a new low
			low = dist; //make this distance the lowest
			bestRoute = allPossibilities[i] //assign new low to bestRoute
		}
	}
	return bestRoute; 
}

Vector<Vector<int>> bestRouteHelper(Grid<double> &distance, set<int> &remainingCities, Vector<int> &route, Vector<Vector<int>> &allPossibilities) {
	int n = distance.numRows(); //gets n
	
	//base case == if no remainingCities left in vector
	if(remainingCities.isEmpty()) {
		route.add(route[0]); //So the route ends with startCity
		allPossibilities.add(route); //Adds this route to allPossibilities vector
		return allPossibilities; //Returns all possible valid vectors 
	
	//recursive case
	} else {
		for(int i = 0; i < n; i++) {
			if(route[0] != i) { //So that start city isn't added to route
				route.add(i); //Adds city location int to route vector
				remainingCities.remove(i); //Takes city location int out of remaining vector
				bestRouteHelper(distance, remainingCities, route); //Recurses with new route and remainingCities vectors
				route.remove(i);
				remainingCities.add(i);
			}
		}
	}
}
			
		
	


Vector<int> helper(Grid<double> &distance,
				   int city,
				   Vector<string> thisRoute,
				   HashSet<int> remainingCities,
				   int minDist
				   ) {
	Vector<int> best;
	//check base case: have you return to the original city?
	if(remaining.isEmpty() {
		double temp = totalRouteDistance(distance,thisRoute);
		//if this is the best route, note that
		if(temp < minDist) {
			minDist = temp;
			best = thisRoute;
		}
	}
	//recursive case
	//for every remaining city
	for(int nextCity : remaining) {
		//choose: remove the city from remaining
		remaining.remove(nextCity);
		//add the city to the route
		thisRoute += nextCity;
		Vector<int> route = helper(distance,nextCity,
		thisRoute,remaining,mindDist);
		//un-choose
		remaining.add(nextCity);
	}
	return best;
}
				   

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	//make a map to keep track of the routes
	Map<int, Vector<string>> routes;
	//make a set to keep track of the cities visited
	HashSet<int> remainingCities;
	for(int i = 0; i < distance.nRows(); i++) {
		remainingCities.add(i);
	}
	remainingCities.remove(startCity);
	//initialize the minimum distance
	int minDist = DBL_MAX;
	//define your first city
	int city = startCity;
	//call helper
	return helper(distance,startCity,
	routes,remainingCities,minDist);
}


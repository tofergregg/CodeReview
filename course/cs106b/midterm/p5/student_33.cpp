// Wrapper function, will pass useful information to helper.
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	//Putting cities into vector to make it easier to permute in helper
	Vector<int> cities;
	for (int i = 0; i < distance.numCols; i++) {
		cities.add(i);
	}
	//Also gonna go ahead and create the vector and pass it over to helper.
	Vector<int> route;
	route =+ startCity;
	//Yeehaw let's go
	bestRoute(distance, route, startCity, cities, 0);
}

//Helper! Will return a vector with the best route. :)
Vector<int> bestRoute(Grid<double> &distance, Vector<int> & route, int startCity, Vector<int> &rest, int bestDistance) {
	
	//This is a local vector that will store the best route as it comes along.
	Vector<int> bestRoute = route;
	//This is the value of bestRoute. 
	int localBest = bestDistance;
	
	//base case is that there are 
	if (rest.isEmpty()) {
		return route;
	} else {	
		for (int i = 0; i < rest.size(); i++) {
			if (rest[i] == startCity) {
				rest.remove[i];
			}
			//I don't think this is how vectors work, but this is supposed to permute the vector.
			route = rest[0, i] + rest[i, rest.size-1] + startCity;
			
			//How long is the route I just frankensteined?
			double currVal = totalRouteDistance(distance, route);
			//Is this the best one???? 
			if (currVal < localBest) {
				localBest = currVal;
				bestRoute = route;
			}
			//Now we do it again!
			rest.insert(i, startCity); //Put the startCity back in there.
			bestRoute(distance, bestRoute, startCity, rest);			
			
		}
		return bestRoute;								
}	


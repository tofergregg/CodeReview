Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<Vector<int>> allRoutes;
	Vector<int> remaining;
	Vector<int> currRoute;
	
	//create a vector of all cities other than the start city
	for (int i = 0; i < distance.numRows(); i++) {
		if(i != startCity) {
			remaining += i;
		}
	}
	
	//calculate all routes			
	bestRouteHelper(distance, startCity, currRoute, remaining, allRoutes);
	
	//see which route has the shortest distance
	double dist = DBL_MAX;
	Vector<int> winningRoute;
	for(int j = 0; j < allRoutes.size(); j++){
		if(totalRouteDistance(distance, allRoutes[j]) < dist) {
			winningRoute = allRoutes[j];
		}
	}
	return winningRoute;
}

void bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> currRoute, 
							Vector<int> remaining, Vector<Vector<int>> &allRoutes) {
	
	//base case: if we have travelled to all the other cities, we must return home
	if(remaining.size() == 0){
		//add the start city to the end of the route
		currRoute += currRoute[0];
		//add the route to the vector of routes
		allRoutes.add(currRoute);
	} else {
		int r = startCity;
		//loop through the remaining cities
		for(int c = 0; c < remaining.size(); c++){
			int city = remaining[c] //choose
			currRoute.add(distance[r][city]); //add to current route
			remaining.remove(c); //remove from list of remaining cities to visit
			bestRouteHelper(distance, city, currRoute, remaining, allRoutes); //explore
			
			currRoute.remove(currRoute.size() - 1); //unchoose
			remaining.insert(c, city); //restore
		}
	}
}
			


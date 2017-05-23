Vector<int> bestRoute(Grid<double> &distance, int startCity) {
//base case: if all cities have been visited and the current city is equal to the end city, then return 
//start at first city and iterate through each city, calculate distances 
//explore each permutation of a possible path-- recursive tree 
//recurse on the route after each city is choose --> make new choice for city
//track the distance of each route as well as the new best distance
//if the current distance < best distance, reset 
//need a way of storing the route of the cities-- add to vec?
	int currentCity = startCity;
	int bestDistance = 0;
	return bestRouteHelper(distance, startCity, currentCity, bestDistance);
}
	
Vector<int> bestRouteHelper(Grid<double> & distance, int startCity, int 				currentCity, int bestDistance) {
	Vector<int> bestRoute;
	Vector<int> currentRoute;
	int numCities = distance.width();
	if ((currentRoute.size()== numCities)&& (currentCity == startCity)) { 
		//all cities have been travelled to AND currentCity == start City
		return bestRoute;
	}
	for (int city = 0; city < numCities; city++) {
		//for each city, try the next city 
		currentRoute.add(city);
		routeDistance = totalRouteDistance(distance, currentRoute);
		if (routeDistance < bestDistance){
			bestDistance = routeDistance;
			bestRoute = currentRoute; 
		}
	//NEED TO TRACK WHAT CURRENT CITY IS
		startCity = currentCity;
		bestRouteHelper(distance, startCity, currentCity, bestDistance);
	}
		
		
		
		
		
		

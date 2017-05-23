Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> remainingCities;
	Vector<int> route;
	route.add(startCity);  //route begins at the startCity
	remainingCities.remove(startCity); //total cities that need to be visited 
	int minDist = minDistance(distance, startCity, remainingCities, route);
	return route;
}

int minDistance(Grid<double> &distance, int startCity, Vector<int> &remainingCities, Vector<int> &route){
	//base case
	if(remainingCities.isEmpty()){
		route += startCity; //returns to original city
		return totalRouteDistance(distance,route); //total distance of route
	}
	//recursive
	int localMinDistance = DBL_MAX; 
	Vector<int> bestRoute;
	int size = remaingCities.size(); //total amount of cities left to visit
	for(i = 0; i < size; ++i){
		int city = remainingCities[i];
		route.add(city); //choose
		remainingCities.remove(i); //remove selected city from remaining cities to visit
		
		int travelDistance = minDistance(distance, startCity, remainingCities, route);
		
		if(travelDistance < localMinDistance){
			localMinDistance = travelDistance;	
			bestRoute = route;
		}
								   
		remainingCities.insert(i,city); //un-choose
		route.remove(route.size() - 1); // remove city and bring route to original vector
	}
	route = bestRoute; // passes the best route by reference in order to return route in original recursion function
	return localMinDistance;
}







	

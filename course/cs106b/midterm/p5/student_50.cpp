Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	//routeDistance = DBL_MAX;
	Vector<int> route;
	Vector<int> bestRoute;
	totalCities = distance.width(); //note to self: count returning to city as last visit
	Vector<int> citiesLeft;
	for (int i = 1; i++; i <= totalCities) {
		citiesLeft.add(i);	
	}	
	return bestRouteHelper(distance, startCity, citiesLeft, route, bestRoute); //old param = routeDistance
}
	
	
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> citiesLeft,
							Vector<int> route, Vector<int>& bestRoute) {
	if (citiesLeft == 1){
		route.add(citiesLeft[0])
		if (totalRouteDistance(route, startCity)< totalRouteDistance(bestRoute, startCity)) {
			bestRoute = route;
		}
		return;
	}
	else { //*****!!!! NOTE for grader - what i meant to do is create a for loop t hat iterates througuh the route. it uses index i to remove an element of the vector, call a recursive function, and then readd the element. By doing that to each element of the vector, i explore all possible subtrees.)
		int nextCityIndex == 0;
		if (citiesLeft[0] == startCity) nextCityIndex == 1;//we don't want to visit startCity again 															until its the only thing in the vector
		nextCity = citiesLeft[nextCityIndex];
		route.add(nextCity];
		citiesLeft.remove(nextCityIndex);	
		bestRouteHelper(distance, startCity, citiesLeft, route, bestRoute);
		citiesLeft.add(nextCityIndex);
		route.remove(route.size()-1);
	}	
		
	//base case: citiesToVisit = 1
	//	go home (startCity). add to vector. if it's good, update the bestRoute
	
    //iterate through first city in citiesToVisit vector (if its not the start city)
	//update route. remove city from vector. update cities to Visit.
	//call recursion
	//add city back to vector. un-update route (remove last element)
	
}	

double tot



//note to self - just take one off the citiesLeft vector, and then add it back on after the recursion.
//if we find a new bestRoute (by using the fn we are given), we update the referenced bestRoute!
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//keep track of 


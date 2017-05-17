Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> finalRoute;
	Set<int> citiesLeft;
	for (int i = 0; i < distance.numCols()-1, i++){
		citiesLeft.add(i);//makes set of all cities
	}
	//remove the starting city
	citiesLeft.remove(startCity);
	//add it to the route to begin
	finalRoute.add(startCity);
	finalRoute = makeRoute(finalRoute, distance, citiesLeft);
	//??
	return finalRoute;
	
}

Vector<int> makeRoute(Vector<int> &workingRoute, Grid<double> &distance, Vector<int> citiesLeft, int startCity) {
	double low_score = DBL_MAX; //where does this go? outside?
	Vector<int> bestPath;
	//base case
	if (citiesLeft.isEmpty()) {
		//need to add the starting city
		workingRoute.add(startCity); //do I need these lines???
		low_score = totalRouteDistance(distance, workingRoute);
		bestPath = workingRoute;
		workingRoute.remove(startCity);
		//I don't want to erase this now though!
		//the score here is lost! and I still need to compare!
		//the cost of the last transition is lost, I have that wrong!
		//BUT HOW....
		//THIS just returns every time, doesn't know how much time..
		return bestPath; //quick quit
	}
	for (city : citiesLeft){//can you do this with sets? **
		//choose
		workingRoute.add(city) 
		citiesLeft.remove(city)
		//explore
		if (totalRouteDistance(distance, workingRoute) < low_score) {
			bestPath = makeRoute(workingRoute, distance, citiesLeft, startCity);
		}
		//unchoose
		workingRoute.remove(); //should remove last index, as in section
		citiesLeft.add(city);						  					  
	}
	return bestPath;
	//at the end of this loop, end with best score maybe???
}
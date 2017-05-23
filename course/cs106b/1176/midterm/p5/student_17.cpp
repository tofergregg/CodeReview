int bestRouteRecursiveSearch(Grid<double> &distance, int startCity, Vector<int> &route, Set<int> unVisitedCities) {
    //base case: we're back to the start bc we've run out of cities, return complete distance
    if(unVisitedCities.isEmpty()){
        return totalRouteDistance(distance, route);
    }
    int currDistance = DBL_MAX;
    int bestCity;
    //check every possible city we can still visit
    for(int nextCity : unVisitedCities){
        //add for calculation
        route.add(nextCity);
		//check complete distance along this path/branch
		unVisitedCities.remove(nextCity);
        double newDistance = bestRouteRecursiveSearch(distance, bestCity, route, unVisitedCities);
        //compare the length of route for this city vs. the others
        if(newDistance < currDistance) {
            bestCity = nextCity;
            currDistance = newDistance;
        }
        //restore
		unVisitedCities.add(nextCity);
        route.remove(nextCity);
    }
	//once we've found optimal path add to route
    route.add(bestCity);
    unVisitedCities.remove(bestCity);      
}

void createUnVisitedCities(Grid<double> &distance, Set<int> unVisitedCities){
	for(int i = 0; i < distance.numCols(); i++){
		unVisitedCities.add(i);
	}
}

Vector<int> bestRoute(Grid<double> &distance, int startCity){
	Vector<int> route;
	route.add(startCity);
	Set<int> unVisitedCities;
	createUnVisitedCities(distance, unVisitedCities);
	unVisitedCities.remove(startCity);
	bestRouteRecursiveSearch( distance, startCity, route, currDistance);
	return route;
}
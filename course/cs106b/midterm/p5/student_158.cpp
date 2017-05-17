private static constant DBL_MAX = 1000;

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;	//keeps track of the route we have taken
	route.add(startCity);
	Set<int> cities; // creates a vector of cities so we can
						//keep track of where we have visited
	for (int i = 0; i < distance.numCols(); i++) {
		cities.add(i);
	}
	cities.remove(startCity);
	Map<Vector<int>, double> allRoutes;
	Vector<int> salesRoute = helperBestRoute(allRoutes, distance, 				route,cities, startCity, startCity); 
	return salesRoute;
}

Vector<int> helperBestRoute(Map<Vector<int>, double> &allRoutes, 			Grid<double> &distance, Vector<int> &route, Set<int> 					&cities,int startCity,int endCity) {
	//base case
	if (cities.isEmpty()) {
		route.add(endCity); //brings the route full circle
	//ideally, I would save this route into a map and then 
	//loop through the map to find the lowest value. 
		return saveRoute(allRoutes, distance, route);  
	} else { //recursive case
		for (string city : cities) {
			route.add(city);
			cities.remove(city);
			//"start city" is now the current city.
			helperBestRoute(distance, route, cities, city, 							endCity); 
		}
	}
}

Vector<int> saveRoute(Map<Vector<int>, double> &allRoutes, 				Grid<double> &distance,Vector<int> route) {

	double totalDistance = totalRouteDistance(Grid<double> & 				distance, Vector<int> &route); 
	routeLengths.put(route, totalDistance);
	//now I would cycle through the different routes and 
	//see whose route was the shortest. Then I would return this
	//vector as the answer route. 

}



Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	int original = startCity;
	route.add(original);
	return bestRouteHelper(&distance, startCity, &route, original);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &route, int original) {
	Vector<int> bestRoute = route;
	if(bestRoute.size() == distance.numRows()) {
		return bestRoute.add(original); 
	}
	else {
		if (totalRouteDistance(&distance, route) <= 			 					    totalRouteDistance(&distance, bestRoute){
				bestRoute = route;
		}
		if (distance.inBounds(startCity + 1, 0)){
			startCity++;
			route.add(startCity); //choose 
			bestRouteHelper(&distance, startCity, &route); //explore
			route.remove(startCity); //unchoose
		}
	}
}
		

// pseudocode: Start with startCity being added to the bestRoute vector.
// Then, check total distance from start to each city after. If it's the //shortest distance so far, bestRoute will update to match that. Then, keep //going:
// start city will then be the most recently successful city. It should keep
// recursing until the bestRoute vector is the correct size. When it is, //return bestRoute. 
			
			
		
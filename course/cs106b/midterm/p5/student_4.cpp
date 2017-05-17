Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	Vector<int> toVisit; // keeps track of unvisited cities	
	for(int i = 0; i < distance.numCols(); i++){
		toVisit.add(i); // adds all cities to the set
	}
	toVisit.remove(startCity); // removes start city from the set
	
	Vector<int> bestRoute;
	Vector<int> currentRoute;
	
	routeSearch(distance, toVisit, bestRoute, currentRoute);
	
	return bestRoute;
}
				 
Void routeSearch(Grid<double> &distance, Vector<int> &toVisit, Vector<int> &bestRoute, Vector<int> ¤tRoute){
		
	// base case
	if(toVisit.isEmpty()){
		if (bestRoute.isEmpty()){
			bestRoute = currentRoute;
		}else{
			double routeLength = totalRouteDistance(distance, currentRoute);
			double bestRouteLength = totalRouteDistance(distance, bestRoute);
			if(routeLength < bestRouteLength){
				bestRoute = currentRoute;
		}
	}
	
	for(int i = 0; i < toVisit.size(); i++){
		int city = toVisit.get(i);
		toVisit.remove(i);
		currentRoute.add(city);
		routeSearch(distance, toVisit, bestRoute, currentRoute);
		toVisit.insert(i,city);
	}
}
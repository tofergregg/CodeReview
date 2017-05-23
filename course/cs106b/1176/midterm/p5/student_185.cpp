Vector<int> bestRoute(Grid<double> &distance, int startCity) {

	Set<int> needToGO;
	int nPlaces = distance.numRows();
	// need to go to all places except start city
	for (int i=0; i<nPlaces; i++) {
		if (i != startCity ) needToGo.add(i);
	}
	return bestRoute(distance, startCity, startCity, needToGo);
	
}

// finds best route given distance grid from start city to end city having to 
// go through places in needToGo (exclusive of start and end)
Vector<int> bestRoute(Grid<double> &distance, int startCity, int endCity,
					  Set<int> &needToGo) {
	
	// base case needToGo is empty -> best solution is from start to end
	if (needToGo.isempty()) {
		// don't need to go anywhere return vector from start to end
		Vector<int> best = Vector(startCity,endCity);
		return best;
	} else {
		double bestDist = DBL_MAX;
		Vector<int> bestRoute; //initialise empty best route for now
		// try choosing next place from all in needToGo set
		for (int nextPlace : needToGo) {
			// route: start -> next -> best route without start or next
			//                         from next to end
			Vector<int> tryRoute = Vector(startCity,nextPlace);
			needToGo.remove(nextPlace); // next is chosen so dont need to go
			// add the rest of the route by recursing from next to end.
			// Not sure if you can concat. vectors using following syntax
			// but that's what I mean in the following line.
			tryRoute += bestRoute(distance,nextPlace,endCity,needToGo);
			tryRouteDist = totalRouteDistance(distance,tryRoute);
			// check if this route has best distance so far
			if (tryRouteDist < bestDist) {
				bestRoute = tryRoute;
				bestDist = tryRouteDist;
			}
			needToGo.add(nextPlace) //add trial place back for next loop
		}
		// return best route found so far
		return bestRoute;
	}
}
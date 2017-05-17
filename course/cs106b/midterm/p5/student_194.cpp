/* base case: start city is the same as end city
              return 0
   
   base case 2: the route has reached DBL_MAX; no point in
                continuing; just return DBL_MAX;
				
   recursive case: try every city as the "next hop"
                   call function again with new startcity
   
   Q: Do I allow loops? that is if I've already visited a city, 
      can I back track and visit it again
   A: Yes, because maybe the best thing to do is back track 
      therefore, I should loop through EVERY city in each
	  recursive call
   
   
*/



Vector<int> bestRoute(Grid<double> &distance, int startCity) {
		Vector<int> route; 
		bestRouteHelper(distance, startCity, startCity, route);
}



void bestRouteHelper(Grid<double> &distance, int startCity, 
					   int endCity, Vector<int> &route) {
	
	route.add(startCity); //we have now visited this city
	
	if ( startCity == endCity ) {
		return;
	}
	//this is how we terminate endless loops
	if ( computeRouteLength(route, distance) >= DBL_MAX) {
		return;
	}
	
	double bestLength = DBL_MAX;
	Vector<int> bestRoute; 
	
	for (int i = 0; i<distance.width(); i++){
		Vector<int> oldRoute = route;
		route.add(i); //choose next hop
		if ( i != startCity) {
			reached = bestRouteHelper(distance, i, endCity, route);		
		}
		if ( computeRouteLength(route, distance) < bestLength) {
			bestRoute = route;
			bestLength = computeRouteLength(route, distance);	
		}
		route = oldRoute;//revert to original route
	}
	route = bestRoute;
}


double computeRouteLength(Vector<int> &route, Grid<double> &distance) {
	double length = 0;
	for (int i = 0; i<route.size()-1; i++){
		length = length + distance[i][i+1];
	}
	return length;
}


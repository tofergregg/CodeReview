Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	 
	double bestDist = DBL_MAX;
	int n = distance.numRows(); //How many cities we need to visit
	route.add(startCity);
	return bestRoute(distance, startCity, route, n, endCity, bestDistance);
	
}

Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> &route, int n, double bestDisntance) {
	
	if(route.size() > 1 && route[0] == route[route.size() - 1]) //base case: if we make it back to original city - return that route
			return currentRoute;
	}
	
	
	
	//recursive case: go through all possible routes and find the best one
	for(int i = -n; i < n; i++){      //loops through all possbile rows and columns around start
		for(int j = -n; j < n; j++) {
			if(distance.inBounds(startCity + i, startCity + j)
			   if(!i=0 || j==0){
				   route.add(distance[startCity+i][startCity+j]);
				  
			   }
			 }
		}
		startCity = startCity + i;
			   if(bestDistance > totalRouteDistance(distance, route)){ //checks if route is shorter than previous
				   bestDistance = totalRouteDistance(distance, route);
	    			return bestRoute(distance, startCity, route, n, bestDistance);
			   }
 	}
			
				
	 
}

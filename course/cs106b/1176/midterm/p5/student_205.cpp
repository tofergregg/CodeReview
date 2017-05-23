Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> totaldistance;
	return bestRouteHelper(distance, startCity, &totaldistance);
}	
	
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector)
	<int> &totaldistance)
	// shortest possible route that visits each city exactly once and 		returns to the original city

	Vector<int> route;
	route.add(startCity); //adds the first city to the path
	
	
//biggest possible number as the beginning length of route
	double minDistance = DBL_MAX;
	
	//base case: if the trip you get is the least, then return the 	associated
	//vector
	if(startCity<0) {
		throw "Number must be 0 or greater.";	
	}
	if(distance.numCols()==1 && distance.numRows()==1) {//most basic case is there is only one city to go to
		route.add(startCity); //add it to the Vector of ints
		return route;		  //return such vector
	} 

	else if(distance.numCols()==2 && distance.numRows()==2) { //if there are 2 cities, there's only 1 path to go
		route.add(startCity);
		route.add(0);
		route.add(startCity);
	}	

	//recursively check best possible paths between cities, starting from 		first city
	else {
		//populate totaldistance the Vector<int>
		/*int numRows = distance.numRows();
		int numCols = distance.numCols();
		for(int row=0; row<numRows, row++) {
			for(int col=0; col<numCols, col++) {
					
			}	
		}
		*/
		
		//help populate route the Vector<int>
		for(int i=0; i<route.length() ; i++) {
			bestRouteHepler(distance, route(i), totaldistance);
		}	
			
		path.add(startCity); //vector ends with the original city as 			the last thing
		
			
		//this calculates the total distance of a Vector<int> route:
		double tripDistance = totalRouteDistance(distance, route);	
		}
		
		if (tripDistance < minDistance) {
			minDistance = tripDistance;
			return minDistance;
		}
		
	}
	
}
//can not choose [r][c] of original city


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> cities; 
	Vector<int> bestRoute;
	//I'm filling up a vector of the cities based on the number of rows in grid
	for (int i = 0; i < distance.size(); i++){
		cities += i;  //create a vector with a number that symbolizes each city
	}
	tempRoute += startCity; //startCity should be first element in new vector	
	double bestRouteDistance = DBL_MAX;
	bestRouteHelper(distance, startCity, cities, tempRoute, &bestRoute, bestRouteDistance);
	return bestRoute; 
}


void bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> cities, Stack<int> tempRoute, Vector<int> bestRoute, double bestRouteDistance)
	//BASE: if no more cities left the choose from, and at start city, then we've made it!
	if (cities.isEmpty() && tempRoute(tempRoute.size()-1) == startCity){
		//if this trip is shorter than best trip, replace best trip
		if (totalRouteDistance(distance,tempRoute) <= bestRouteDistance){
			bestRoute = tempRoute; 
			bestRouteDistance = totalRouteDistance(distance,tempRoute);
		}
		else {//do nothing
			return;
		}
	}
	else{	
		//for every city  
		for (int i = 0; i < cities.size (); i++){
			//CHOOSE city to add to tempRoute and remove city from cities
			tempRoute += cities[i];
			int savedCity = cities[i];
			cities.remove(i);
				
			//EXPLORE all route options 
			bestRouteHelper(distance, startCity, cities, tempRoute, bestRoute);
			
			//UNCHOOSE
			cities.insert(i, savedCity); 				
		}
		return;
	}
}
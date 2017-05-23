Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int endCity, Vector<int> &route, Vector<int>cities) {
	if (startCity == endCity && route.size()==distance.numCols()-1) {
		return route;
	}else{
		for (int i=0; i<cities.size(); i++){	
			if (//routedoesnot contain c,) {
			route.add(i);
			endCity=i;
			route.add(endCity);
		}
				//checks to see if distance is smaller than the next set of options
			if(!DBL_MAX-totalRouteDistance(distance, route)< bestRouteHelper(distance, startCity, endCity, route, cities){
				route.remove(route.size()-1);//unchoose 
				bestRouteHelper(distance, startCity, endCity, route, cities);
			}
 }
			   }		
			
	
	
Vector<int> bestRoute(Grid<double> &distance, int startCity) {	
	Vector<int> route;
	Vector<int> cities;
	//places num of cities in a vector to explore all options
	for (int i=1; i<distance.numCols(); i++){
		cities.add(i-1);
	}
	int endCity=startCity;
	route.add(startCity);
	return bestRouteHelper(distance, startCity, endCity, route, cities);
	}			
	
	
//double totalRouteDistance (Grid<double> &distance, vector<int> &route);
//calculates total distance 
	


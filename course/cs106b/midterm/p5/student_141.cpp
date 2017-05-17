Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route[0]=startCity;
	route=bestRouteHelper(distance, startCity,route,0);
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity,Vector<int> route, int bestDistance){
	int curDistance=0;
	int currentCity=startCity;
	if (route[route.size()-1]==startCity) && curDistance<bestDistance && route.size==distance.numRows+1){
			return route;
	}
 else{
					 
	 for (int r=0; r<distance.numRows(); r++){
	 for (int c=0; c<distance.numCols(); c++){
		 route.add(distance[currentCity][c]);
		 currentCity=c;
		 curDistance=totalRouteDistance(distance,route);
		 bestRouteHelper(distance, currentCity, route, curDistance);
	 }
	 }
 }
}

	
		
		
		


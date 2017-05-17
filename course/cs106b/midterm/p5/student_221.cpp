int routeHelper(Grid<double> &distance, int curCity,Vector<int>& cities/*remaining cities*/, Vector<int>& route){
	
	if(!cities.isEmpty()){
		return distance[route[0]][route[route.size-1]];
		
	} else {
		cities.remove(curCity); //go to cities not visited before
		int min = DBL_MAX;
		int current =0;
		int toAdd = 0;
		for(int c=0;c<cities.size;c++){
			current = routeHelper(distance,cities[c],cities,route);
			if(current<min){
			min = current;
			toAdd=c;			 
			}
		}
		
		sum += distance[route[route.size-1]][toAdd];
		route.add(cities[toAdd]);
		
	
		return sum;
	}	
}


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> cities;
	int sum = 0;
	Vector<int> route;
	for (int i=0;i<=distance.numCols();i++){
		cities.add(i);
	}
	
	route.add(startCity);
	sum =routeHelper(distance,startCity,cities,route);
	route.add(startCity);
	return route;
		
}


	
	
	
	


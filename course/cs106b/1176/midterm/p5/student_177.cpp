Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double dis = 0; // store the distance traveled
	int num = 0;
	Set<int> used; //store the cities visited
	used.add(startCity);
	
	Vector<int> route; //store the route
	route.add(startCity);
	double best = DBL_MAX;
	return helper(distance, startCity, best,dis, route, used);	
			
}


Vector<int> helpler (Grid<double> &distance, int startCity, double best, double dis, Vector<int> route, Set<int> used){
	//base case
	if (route.size() == distance.width()+1 && best == dis){
		return route;		
	} 
	
	if (route.size() == distance.width()){ // if all cities are visited, you need to go back
		route.add(startCity);
		dis = totalRouteDistance(distance, route);
		route = helper(distance, startCity, best,dis, route, used);				
	}	
	
	for (int i = 0; i < distance.width(); i++){ // all possible routes
		// the next city cannot be a visited one or the start city
		if (i != startCity && !used.contains(i)){ 		
			used.add(i);
			route.add(i);
			dis = totalRouteDistance(distance, route);
			route = helper(distance, startCity, best,dis, route, used);			
		}
	}
	if (route.size() == distance.width()+1 && dis < best){
		best = dis; //find the best route
	}
	return;
}
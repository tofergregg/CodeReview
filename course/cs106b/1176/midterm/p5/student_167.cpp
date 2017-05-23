void allRoutes(Grid<double> &distance, int startCity, Vector<int> &route, Set<Vector<int> & routes);
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route.add(startCity);
	Set<Vector<int> routes;
	allRoutes(distance, startCity, route, routes);
	double bestDist = DBL_MAX;	
	for(Vector<int> newRoute: routes){
		double dist = totalRouteDistance(distance, newRoute);
		if(dist < bestDist){
			bestDist = dist;
			route = newRoute;
		}
	}
	return route;		
}

void allRoutes(Grid<double> &distance, int startCity, Vector<int> &route, Set<Vector<int> & routes){
	if(route.size()==distance.numRows()){
		route.add(startCity);
		double dist = totalRouteDistance(distance, route);
		if(dist < bestDistance){
			bestDistance = dist;
			routes.add(route);
		}
	} else{
		for(int c = 0; c < grid.numCols(); c++){
			for(int i = 0; i < route.size(); i++){
				if(c != route[i]){
					route.add(c);
					break;
				}
			}
			allRoutes(distance, startCity, route, routes);
			route.remove(route.size()-1);
		}
	}
				
				
			
		

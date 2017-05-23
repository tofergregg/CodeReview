Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<Vector<int>> allRoutes;	
	int cities = distance.numRows();
	//find all possible routes
	for(int i = 0; i < cities; i++){
		Set<int> route;
		Vector<int> way;
		route.add(i);
		way.add(i);
		findRouteHelper(startCity, route, way, allRoutes);
	}
	int shortest = findShortest(distance, allRoutes);
	return allRoutes[shortest];		
}

//finds all possible routes by exploring all options
//adds a route to allRoutes
void findRouteHelper(int startCity, Set<int> route, Vector<int> way, Vector<Vector<int>> &allRoutes){
	//we still haven't found all cities
	if(route.size() < cities){
		for(int i = 0; i < cities; i++){
			if(route.contains(i)) continue;
			way.add(i);
			route.add(i);
			findRouteHelper(startCity, route, way);
		}
	}else if (route.size() == (cities)){	//found all cities
		way.add(i);
		route.add(startCity);
		allRoutes.add(way);
	}
}

//returns the index of the shortestRoute
void findShortest(Vector<double> &distance, Vector<Vector<int>> &allRoutes)
{
	double shortest = DBL_MAX;
	int index = 0;
	for(int i = 0; i < allRoutes.size(); i++){
		if(totalRouteDistance(distance, allRoutes[i]) < shortest){
			index = i;	
			shortest = totalRouteDistance(distance, allRoutes[i]);
		}
	}
	return index;
}



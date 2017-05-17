Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	route.add(startCity);
	return bestRouteRecurse(distance, startCity , route);
}

/* Helper Function */
Vector<int> bestRouteRecurse(Grid<double>& distance, int startCity, Vector<int>& route){
	//base case
	if (startCity == route[0]){
		return route;
	} else {
		//recursive case
		int newStart = 0;
		int low = DBL_MAX;
		for (int c = 0; c < distance.numCols(); c++){
			if (counter != c && distance[startCity][c] < low){
				//check to see that this city hasn't already been visited
				for (int i = 0; i < route.size(); i++){
					if (c == route[i]){
						bool equal = true;
						break;
					}	
				}
				if (bool != true){
					low = distance [startCity][c];
					newStart = c;	
				}
			}
		}
		route.add(newStart);
		return bestRouteRecurse(distance, newStart, route);
	}
}

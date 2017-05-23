

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> best_route;
	best_route.add(startCity);
	int dist = 0;
	return bestRouteHelper(distance, startCity, best_route, dist, );
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> &best_route, int &dist){
	if ((best_route[0] == best_route[best_route.size() - 1])&&( best_route.size > 1)) {
		return best_route;
	} else {
		//choose to explore cities
		for (int r = 0; r < distance.length() - 1; r++){
			int c = best_route.get(best_route.size() - 1);
			if (!best_route.contains(r)) {
				//choose
				best_route.add(r);
				int dist1 += distance[r][c];
				//explore
				return bestRouteHelper(distance, c, best_route, dist);
				dist -= distance[r][c];
				best_route.remove(r);
		}
		//comparing values
		if ((sum of best route helper vector) < dist) {
			dist = (sum of best route help vector)
		}
	}
}
		
	
			
	
			

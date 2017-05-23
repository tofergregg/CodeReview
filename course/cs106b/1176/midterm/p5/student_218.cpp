Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int>& oneRoute, int consStartCity, int dist, int minDist) {
	
	if(disc <= DBL_MAX) {
		if(startCity == consStartCity && oneRoute.size() != 1) {
			if(dist < minDist)
			  minDist = dist;
			  return oneRoute;
			}
		}
	
	
		for(int c = 0; c < distance.numCols(); c++) {
			if(c != startCity) {
				oneRoute.add(c);
				temp = startCity;
				startCity = c;
				dist += distance[temp][c];
				bestRoute(distance, startCity, oneRoute, consStartCity, dist, minDist);
				oneRoute.remove(oneRoute.size()-1);
				startCity = temp;
				dist -= distance[temp][c];
			}
		}
	}
}
	
	


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> minRoute;
	Vector<int> oneRoute;
	oneRoute.add(startCity); // add the startCity first
	int consStartCity = startCity;
	
	int dist = 0;
	int minDist = 0;
	return bestRoute(distance, startCity, oneRoute, consStartCity, dist, minDist);
}
	
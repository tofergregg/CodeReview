Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> places;
	Vector<int> trial;
	double best = DBL_MAX;
	for(int i = 0; i < distance.numRows(); i++) {
		places.add(i);
	}
	trial.add(startCity);
	places.remove(startCity);
	bestRoute(distance, route, trial, places, best);
	return route;		
}


void bestRoute(Grid<double> &distance, Vector<int> &route, Vector<int> trial, Vector<int> places, double best) {
	if(places.isEmpty()) {
		int end = trial[0];
		trial.add(end);
		double dist = totalRouteDistance(distance, trial);
		if(dist < best) {
			best = dist;
			route = trial;
		}		
	}
	for(int place: places) {
		trial.add(place);
		places.remove(place);
		bestRoute(distance, route, trial, places, best);
	}
}
	
		

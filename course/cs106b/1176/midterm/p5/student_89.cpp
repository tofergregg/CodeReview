Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> best;
	bestRoute(distance, startCity, 0, distance.numRows(), route, DBL_MAX, best);
}

//Helper function to keep track of best path, ending City, how many times looped, and minDist
Vector<int> bestRoute(Grid<double &distance, int startCity, int endCity,
					  int numCities, Vector<int> &route, double minDist, Vector<int> &best) {
	//Base Cases
	if (route.size() == numCities) {
		return;
	}
	if (startCity == distance.numRows()) {
		return;
	}
	if (endCity == distance.numCols()) {
		bestRoute(distance, startCity + 1, 0, numCities, route, minDist, best);
	} else {	
		//Recursive Calls
		for (int i = 0; i < distance.Rows(); i++) {
			Vector<int> answer = route;
			if (startCity != endCity) {
				answer += distance[startCity][endCity];
				bestRoute(distance, endCity, 0, numCities + 1, answer, best);
			} else {
				bestRoute(distance, startCity, endCity + 1, numCities, answer, best);
			}
			if (totalRouteDistance(distance, answer) < minDist) {
				minDist = totalRouteDistance(distance, answer);
				best = answer;
			}
		}
	}
	return best;
}
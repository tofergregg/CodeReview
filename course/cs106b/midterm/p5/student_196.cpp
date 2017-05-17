/*Vector<int> helper(Grid<double> &distance, int startCity, int currentCity, int nextCity, Vector<int> answer);


	Vector<int> answer;
	int currentCity = startCity;
	int nextCity = startCity ++;
	int bestDistance = DBL_MAX;
	answer = helper(ditance, startCity, currentCity, nextCity, answer);
	return answer;
	
}

Vector<int> helper(Grid<double> &distance, int startCity, int currentCity, int nextCity, Vector<int> answer) {
	
	if(nextCity == startCity && answer.size() == distance.numRows()) {
		answer.add(distance[currentCity][nextCity]);
		return answer;
	} else {
		for(int c = currentCity; c < distance.numCols(); c++) {
*/
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
double bestDist = DBL_MAX;
Grid<double> distanceCopy = distance;
Map<Vector<int>, double> mapOfDistances;
	Vector<int> route;
for(int currentCity = startCity; r < distance.numRows(); r++) {
	for(int c = 0; c < distance.numCols(); c++) {
		int d = distance[currentCity][c];
		if(d != 0 && route.size() != distance.numRows() && d!= -1) {
			route.add(d);
			distance.set(currentCity, c, -1);
			
		}
		if(c == startCity && route.size == distance.numRows()) {
			route.add(d);
			double dist = totalRouteDistance(distanceCopy, route);
			mapOfDistances.put(route,dist);
		}
	}
	distance = distanceCopy;
}

for(Vector<int> key : mapOfDistances) {
	if(map[key] < bestDist) {
		bestDist = map[key];
	}
}
return bestDist;
}
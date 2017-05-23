Vector<int> bestRoute(Grid<double> &distance, int startCity) { 
Vector<int> pathVector;
pathVector.add(startCity);
Grid<Vector<int>, int> &grid
int totalDistance;
bestRoutineHelper(distance, startCity, pathVector, map, totalDistance);
Vector<int> distances = map.values();
Vector<Vector<int>> keys = map.keys();
	int minimumDistance = 0;
	for (int i = 0; i < map.size(); i++) {
		if (map[distances[i]]< DBL_MAX) {
			minimumDistance = distances[i];
			if (map[distances[i]] < minimumDistance) {
				minimumDistance = map[distances[i]]);
		} 
			Vector<int> finalVector = keys[i];
		}
	}
return finalVector;
}
	
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int> pathVector, Map<Vector<int>, int> &map, int totalDistance) {
	int maxCityNumber = distance.numCols() - 1;
	if (startCity == pathVector[0]) {
		return pathVector;
		map.put(pathVector, totalDistance);
	}
	else {
		for (int i = 0; i < maxCityNumber; i++) {
			if (startCity != i) {
				totalDistance += distance[startCity][i];
				pathVector.add(i);
				return bestRouthHelper(distance, i, pathVector);
				totalDistance = 0;
			}
			pathVector.remove(i);
		}
	}
	return pathVector;
}
		

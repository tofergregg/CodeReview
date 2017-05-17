Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> path;
	path = bestRoute(distance, startCity, startCity, DBL_MAX, path);
	return path;
}
	
Vector<int> bestRoute(Grid<double> &distance, int startCity, int nextCity, int shortestPath, Vector<int> tentativePath){
	Vector<int> citiesDone;
	Vector<int> tentativePath;
	Vector<int> bestPath;
	if(nextCity == startCity){
		bestPath.add(startCity);
		if(totalRouteDistance(distance, tentativePath) < shortestPath) && (totalRouteDistance(distance, tentativePath) > 0){
			bestPath = tentativePath;
		}
	} else{
		tentativePath.add(nextCity);
		if(startCity < n - 1){
			tentativePath = bestRoute(distance, nextCity, nextCity + 1);
		}
		if(startCity > 0){
			tentativePath = bestRoute(distance, nextCity, nextCity - 1);
		}
	return bestPath;
}

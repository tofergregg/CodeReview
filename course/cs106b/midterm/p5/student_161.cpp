Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> path;
	int currCity;
	bestRouteHelper(distance,startCity,currCity,path,0);
}

	
	
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int currCity, Vector<int> & path, double pathLength) {
	if (startCity == currCity) {
		if (path.isEmpty()) {
		return path;
		}
	}
	Vector<int> localShortestPath1;
	Vector<int> localShortestPath2;
	double localBestDistance = distance;
	for (int i = 0; i < distance.numRows(); i++) {
		if (distance.inBounds(startCity,startCity+i){
			path += startCity + i;
			double pathL = totalRouteDistance(path);
			Vector<int> newPath = bestRouteHelper(distance,startCity,startCity+i,path,pathL);
			double currDistance = totalRouteDistance(distance,newPath);
			if (currDistance < localBestDistance) {
				localShortestPath = newPath;
		} 
		if (distance.inBounds(startCity,startCity-i){
			path += startCity + i;
			double pathL = totalRouteDistance(path);
			Vector<int> newPath = bestRouteHelper(distance,startCity,startCity+i,path,pathL);
			double currDistance = totalRouteDistance(distance,newPath);
			if (currDistance < localBestDistance) {
				localShortestPath2 = newPath;
			}
		
	}
	return localShortestPath1 < localShortestPath2 ? localShortestPath1 : localShortestPath2; //return whichever path is shorter
}
	
	
	
		
	
	
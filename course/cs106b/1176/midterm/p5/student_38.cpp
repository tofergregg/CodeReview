Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Map<int, Vector<int>> allSolutions;
	Vector<int> pathway;
	bestRouteWrapper(distance, startCity, startCity, startCity, allSolutions, pathway);
	Vector<int> bestSolution = findBest(allSolutions);
	return bestSolution;

}

double bestRouteWrapper(Grid<double> &distance, int startCity, int r, int c, Map<int, Vector<int>> &allSolutions, Vector<int> pathway){
	
	if((r == startCity || c == startCity) && totalRouteDistance(distance, pathway) != 0)){
		pathway.add(distance[r][c]);
		double sum =  totalRouteDistance(distance, pathway);
		allSolutions.add(sum, pathway);	
	} else {
		pathway.add(distance[r][c]);
		
		int up = r + 1;
		int down = r -1;
		int left = c - 1;
		int right = c + 1;
		
		//up
		if(distance.inBounds(up, c)) {
			bestRouteWrapper(distance, startCity, up, c, allSolutions, pathway);	
		}
		//down
		if(distance.inBounds(up, c)) {
			bestRouteWrapper(distance, startCity, down, c, allSolutions, pathway);	
		}
		//left
		if(distance.inBounds(up, c)) {
			bestRouteWrapper(distance, startCity, r, left, allSolutions, pathway);	
		}
		
		//right
		if(distance.inBounds(up, c)) {
			bestRouteWrapper(distance, startCity, r, right, allSolutions, pathway);	
		}
	}	
}		
		
		
Vector<int> findBest(Map<int, Vector<int>> &allSolutions) {
	int biggestKey;
	Vector<int> biggestValue;
	for(int sum : allSolutions) {
		if(sum > biggestKey) {
			biggestKey = sum;
			biggestValue = allSolutions[key];
		}
	}
	return biggestValue;
		
	
	































Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Queue<int> citiesNotVisited();
	Vector<int> path;
	for(int i = 0; i < distance.numRows; i++){
		if(i!= currentCity){
			citiesNotVisisted.enqueue(i);
		}
	}
	helper(distance, startCity, citiesNotVisited, path);
}

Vector<int> helper(Grid<double> &distance, int startCity, Queue <int> citiesNotVisited, Vector<int> path) {
	//base case vector size = distance.numRows + 1;
	if (citiesNotVisited.isEmpty()){
		path.add(startCity);
		return path();
	} else {
		int bestLength = DBL_MAX;
		Vector<int> bestVector();
		Vector<int> currentVector();
		for(int i = 0; i < citiesNotVisisted.size(); i++){
			int currentCity = citiesNotVisisted.dequeue;
			path.add(currentCity);
			currentVector =  helper(distance, startCity, citiesNotVisited, path);
			int currentLength = totalRouteDistance(path);
			if(currentLength < bestLength){
				bestVector = currentVector;
				bestLength = currentLength;
			}
			//backtracking
			citiesNotVisited.enqueue(currentCity);	
			path.remove(path.size()-1);
		}
		return bestVector;
}


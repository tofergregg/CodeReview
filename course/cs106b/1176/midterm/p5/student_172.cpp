Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> remainingCities;
	for(int i = 0; i < distance.numRows; i++){
		remainingCities.add(i);
	}
	return bestPath(distance, startCity, remainingCities);
}


Vector<int> bestPath(Grid<double> &distance, int startCity, 							 Vector<int> remainingCities){
	Vector<int> currentPath;
	double bestScore = DBL_MAX;
	if(remaingCities.size == 0){
		//if the current path score is better than the best  score then curr path score = best  score
		//return current path
		int currentScore = totalRouteDistance(&distance,
											  currentPath);
		if(currentScore < best score){
			

	}
	
	for(int i = 0; i < remainingCities.size; i++){
			remainingcities.remove(i);
			for(int i = 0; i < remainingCities.size; i++){
				currentPath.add(remainingcities[i];
			}
			bestPath(Grid<double> &distance, int startCity, 
					         Vector<int> remainingCities;
			remainingCities.add(i);
			
	}
}
	
	


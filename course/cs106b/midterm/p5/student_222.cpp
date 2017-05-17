Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int n = distance.numRows();
	Vector<int> explored;
	explored.add(startCity);
	Set<int> newCity;
	for(int i = 0; i < n; i++){
		if(i != startCity) newCity.add(i);
	}
	bestRoute(explored, newCity, distance, startCity);
	return explored.add(startCity);
}

double bestRoute(Vector<int> &explored, Set<int> &newCity, Grid<double> &distance, int startCity){
	if(newCity.isEmpty){
		Vector<int> exploredcopy = explored;
		exploredcopy.add(startCity);
		return totalRouteDistance(distance, exploredcopy);
	}else{
		double bestDistance = DBL_MAX;
		Vector<int> bestRoute;
		int mark;
		for(int i : newCity){
			if(bestRoute(explored.add(i), newCity.remove(i), distance, startCity) < bestDistance) mark = i;
			explored.remove(explored.size() - 1);
			newCity.add(i);
		}
		return bestRoute(explored.add(mark), newCity.remove(mark), distance, startCity);
	}
}
			   
			   
			   
			   

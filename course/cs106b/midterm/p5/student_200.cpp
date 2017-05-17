Vector<int> helper(Grid<double> &distance, int currentCity, Vector<int> & places, Set<int> & alreadyVisited, int totalDistance, int initialCity) { //finds and returns all possible solutions, not sure how to find the best possible solution with the totalDistance I kept track of, think it involves some kind of comparison in the recursive case but am not sure how to do this with my for loop (causing me to not be able to store distances in variables)
	if (places.size() == distance.numCols() + 1) {
		return places;
	}
	for (int i = 0; i < distance.numCols(); i++) {
		if (!alreadyVisited.contains(i)) {
			places.add(i);
			alreadyVisited.add(i);
			totalDistance += distance[currentCity, i];
			return helper(distance, i, places, alreadyVisited, totalDistance, initialCity);
		} else if (places.size() == distance.numCols()) {
			places.add(initialCity);
			alreadyVisited.add(initialCity);
			totalDistance += distance[currentCity, initialCity];
			return helper(distance, initialCity, places, alreadyVisited, totalDistance, initialCity);
		}
	}	
} 


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> places;
	Set<int> alreadyVisited;
	return helper(distance, startCity, places, alreadyVisited, 0, startCity);
}
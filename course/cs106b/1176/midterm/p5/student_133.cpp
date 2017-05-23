Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int currentcity; // initialize current city
	int newcity;
	int min;
	for (int i = 0; i < distance.numCols(); i++) { // just to establish high max value
		for (int j = 0; i < distance.numRows(); j++) {
			min = min + distance[i,j];
		}
	}
	Vector<int> help = bestRouteHelper(distance, startCity, currentcity, newcity, min, visitedcities);
	return help;
}
		
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, int currentcity, int newcity, int min, Set<int> &visitedcities; {
	int previouscity = currentcity;
	if (startCity == currentcity) {
		vector<int> currcost;
		currcost.add(0);
		return currcost;
	} else {
		for (int i = 0; i < distance.numRows(); i++) {
			for (int j = 0; j < distance.numCols(); j++) {
				if (distance.get(currentcity,i) != 0 && !visitedcities.contains(i)){
					currentcity = i;
					newcity = j;
					visitedcities.add(i);
					Vector<int> currcost = bestRouteHelper(distance, currentcity, newcity, visitedcities);
					int counter = 0;
					for (int i = 0, i < currcost.size(); i++) {
						counter = counter + distance(currentcity, currcost[i]);
					}
					if (counter < min) { //looking for best sol. so far
						min = counter;
						return currcost;
					} else {
						visitedcities.remove(i); //backtrack
						currentcity = previouscity; //backtrack
					}
				}
			}
		}
	}
}
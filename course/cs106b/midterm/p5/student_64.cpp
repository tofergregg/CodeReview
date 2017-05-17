Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int start = startCity;
	Vector<int> path;
	int length;
	int track = 0;
	if (track == 0){
		path.add(startCity);
		track++;
	}
	Vector<int> pathPermutations;
	Map<Vector, int> routes;
	
	Vector<int> bestRoute(Grid<double> &distance, Vector<int> &pathPermutations, int startCity, int currCity, int length){
		if (path.size() == distance.numCols()+1 && startCity == currCity){
			if (!map.containsKey(path){
			routes.add(path, length);
			}
		}
		else{
			 currCity = randomInteger(0, distance.numCols());
			if (track == 1){
				length+= distance[start][currCity];
			}
			if (!pathPermutations.contains(currCity){
				pathPermutations.add(currCity);
				length += [startCity][currCity];
				startCity = currCity;
				for (int i = 0; i < pathPermutations.size(); i++){
					path.add(pathPermutations[i]);
				}
	currCity = randomInteger(0, distance.numCols());
				
		bestRoute(distance, pathPermutations, startCity, currCity, length); 
		
		path.clear();
		startCity = start;
		for (Vector paths: routes){
		int greatest = 0;
		if (routes[paths] > greatest){
			Vector<int> greatest = paths;
			}
		}
			return greatest;
		
		


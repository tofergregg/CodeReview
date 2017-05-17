Vector<int> bestRoute(Grid<double> &distance, int startCity) {

	Vector<int> currentPath;
	Set<int> alreadyVisted;
	retturn bestRouteHelper(distance, startCity, alreadyVisited, currentPath);
	
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Set<int>& alreadyVisited, Vector<int>& currentPath){
	
	//Base Cases
	if ( currentPath[0] == currentPath[currentPath.size()-1] && distance.numRows()==currentPath.size()){//The case where a path is found, end city is the beginning city and all citys have been visited
		return currentPath;
		
	}else if (alreadyVisited.contains(startCity){//The case where a city was already visited. 
		
		return currentPath;
	}else{
	
	currentPath.add(startCity);
	alreadyVisted.add(startCity);
		
	Vector<int> bestPath = currentPath;
	
	//Add city to the current path to start back tracking recursion
	
		

	for (int c = 0; c < distance.numCols(); c++ {
			
		bestPath = bestRouteHelper(&distance, c , alreadyVisited, currentPath);
				
		if totalRouteDistance(distance, currentPath) < totalRouteDistance(distance, bestPath){
			
		return currentPath;
		}else{
			return bestPath;
		}

	
	}
			 
   
	//Remove city from path to complete backtracking
	currentPath.remove(currentPath.size()-1);
	alreadyVisted.add(startCity);
	}
 return currentPath;

}
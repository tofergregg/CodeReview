Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> posRoute;
	Vector<int> baseList;
	Vector<int> bestRoute;
	
	//creating a baselist so that backtracking can be enabled and code can be run effectively 
	baseList.add(startCity);
	for(int i = 0; i < distance.numRows(); i++){
		if(i == startCity) continue;
		baseList.add(i);
	}
	baseList.add(startCity);
	
	int max = totalRouteDistance(distance, baseList);
	
	
	return bestRouteHelper(distance, startCity, baseList, posRoute,bestRoute, max, 0);
	
}

Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int>& baseList,Vector<int>& posRoute, Vector<int>& bestRoute, int max, int index){

	if(totalRouteDistance(distance, posRoute) > max){ //no need to complete route if already larger. This is the backtracking condition
		return;
	} else if(baseList.isEmpty()){ //base case: a permutation of the cities has been found
		posRoute.add(startCity);
		if(totalRouteDistance(distance, posRoute) < max){
			bestRoute = posRoute;
			max = totalRouteDistance(distance, posRoute);
			index = 0;
		}
	} else{
		for(int i = 0; i < baseList.size(); i++){
			Vector <int> tmpList = baseList;
			int currCity = tmpList.remove(i);
			posRoute.add(currCity);
			if(index == 0){
				startCity = i;
			}
			totalRouteDistanceHelper(distance, startCity, tmpList, posRoute, 						bestRoute, max, index++);
			
		}
	}
	
	return bestRoute;
	
	
}
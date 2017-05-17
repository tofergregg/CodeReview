Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> remaining;
	Vector<int> route;
	Vector<int> currentBest;
	for(int i = 0; i < distance.numCols(); i++){
		remaining.add(i);
	}
	remaining.remove(startCity);
	return bestRouteHelper(distance, remaining, startCity, route,currentBest);
}
Vector<int> bestRouteHelper(Grid<double> &distance,Vector <int> &remaining, int startCity,Vector<int> route,Vector<int> &currentBest) {
		if(remaining.size()== 0){
			route.insert(0,startCity);
			route.insert(0,endCity);
			if(totalRouteDistance(ditance,route) < 				            totalRouteDistance(distance,currentBest)){
				currentBest = route;
		{ else {
			int size = remaining.size();
			int curr = remaining[0];
			remaining.remove(0);
			for(int i = 0; i < size; i ++) {
				route.add(curr);
			 bestRouteHelper(distance,remaining,startCity,route,currentBest);
			}
			remaining.add(curr);
		}
		 return currentBest;
			
			

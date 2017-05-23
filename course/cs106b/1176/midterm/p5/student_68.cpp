Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Map<Vector<int>,int> memo; //memoization could come in handy.
	int nextCity;
	int bestDist = 0;
	Set<int> alreadyDone;
	Vector<int> bestRoute (distance,startCity,nextCity,bestDist,memo,alreadyDone);
}


Vector<int> bestRoute (Grid<double> &distance, int startCity,int nextCity, int bestDist, Map<Vector<int>,int> memo,Set<int> alreadyDone){
//base case
	if (nextCity == startCity){
		return nextCity;
	}
	else{
//recursive
	for (c=0, c < distance.numCols()-1; c++){
		if (c=startCity && alreadyDone.contains(c)){}
		else{
			alreadyDone.add(c);//use set to avoid coming back to same city.
			bestDist += distance[startCity][c];
			Vector<int> route = bestRoute(distance,c,nextCity,bestDist,memo);
		}
	}
}

	
	
//i need serious help with recursive backtracking...

Vector<int> bestRoute(Grid<double> &distance, int startCity) {

	Vector<int> Visited;
	Visited.add(startcity);
	Vector<int> cities;
	Vector<int> result;
	for(int i=0;i<distance.numCols();i++) {
		cities.add(i);
	}
		
	helper(distance, startCity, Visited, cities , DBL_MAX, result);
	return result;
}

int helper(Grid<double> &distance,int startCity,Vector<int> &Visited,Vector<int> &cities, double cost, Vector<int> &result){
	int currCost = cost;
	
	if(Visited.size() == cities.size()) { // base case
		
		totalDistance = totalRouteDistance(distance, Visited) + distance[Visited.size()-1][startCity]; 
	
	return totalDistance;
		
		
		
	} else {
		for(i=0;i<cities.size();i++)
			if(!Visited.contains(i)) { // check the vector is element i is already seen
				Visited.add(i);
				int localcost = distance[startCity][i];
				localCost = helper(distance, i, visited, cities, currCost+localcost, result);
				if(localCost < currCost){
					currCost = localCost;
					result = Visted;
				}
				Visited.remove(Visited.size()-1);
			}
			
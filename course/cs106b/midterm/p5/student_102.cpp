Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> remaining;
	for (int i=0; i<distance.numRows(); i++){
		remaining.add(i);
	}
	Vector<int> route;
	int min=DBL_MAX;
	Vector<int> ans;
	for (int city : remaining){
		if (city!=startCity){
			Vector<int> bestRoute=bestRoute(distance, city, startCity, remaining, route);
			int bestDis=totalRouteDistance(bestRoute);
			if (bestDis+distance[startCity][city]<min){
				min=bestDis+distance[startCity][city];
				ans=bestRoute.insert(0,startCity);
			}
		}
	}
	return ans;
}
	

Vector<int> bestRoute(Grid<double> &distance, int startCity, int finalCity, Vector<int> remaining, Vector<int> route){
	if (remaining.size()==0){
		return route;
	}
	if (remaining.size()==1){
		return remaining[0];
	}else{
		int min = DBL_MAX;
		Vector<int> bestRoute;
		for (int i=0; i<remaining.size();i++){
			int city = remaining[i];
			route.insert(0,city);
			remaining.remove(i);
			Vector<int> best=bestRoute(distance, city, finalCity, remaining,route);
			int res = totalRouteDistance(distance,best);
			if (res+distance[startCity][city]<min){
				min=res+distance[startCity][city];
				bestRoute=best;
			}
			remaining.insert(i,city);						   
			route.remove(0);
		}
		return bestRoute;
	}
}


//this is a wrapper function that initializes the route and pases
//the route, city and an empty Set of used cities to the recursive function
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<int> usedCities;
	Vector<int> route;
	route = bestRoute(distance,startCity,usedCities);
	route.add(startCity);
	return route;
}


//this is the recursive function. It gets the distance grid as reference,
//the set of used cities as reference and the strat city
// the base case is when we have traveled to all cities, in which case it returns
// the city we are in
// the recursive case chooses a city, calls on the function again withut that city
//as an option and gets the distance of that pick. If the pick is optimal it returns that pick
Vector<int> bestRoute(Grid<double> &distance, int startCity, Set<int>& usedCities) {
	Vector<int> route;
	Vector<int> answer;
	double bestDistane = DBL_MAX;
	if(usedCities.size()==distance.nCols()-1){
		answer.add(startCity);
	} else {
		for(int i=0; i<distance.nCols(); i++{
			if(!usedCities.contains(i) && i != startCity){
				usedCities.add(i);
				route = bestRoute(distance,i,usedCities);
				route.add(i);
				if(totalRouteDistance(distance,route) < bestDistance){
					answer = route;
				}
				usedCities.remove(i);
			}
		}
		for (int i: answer){
			usedCities.add(i);
		}
	}
	return answer;
}
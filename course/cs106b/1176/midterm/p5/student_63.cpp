Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<int> citiesleft;
	Vector<int>itinerary;
	int distanceTraveled = 0;
	int currentCity = startCity;
	for (int i = 0; i<distance.size(); i++){
		citiesleft+=i;
	}
	return bestRouteHelper(distance,startCity,citiesleft,itinerary, currentCity, distanceTraveled);
}
			
		
			
			
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Set<int> citiesleft,Vector<int>itinerary, int distanceTraveled){
	if (currentCity == startCity && citiesleft.isEmpty()){
		return itinerary;
	}
	else{
		Vector<Vector<int>> comparisons;
		for (int i = 0; i<distance.size; i++){
			if ( i!=currentCity){
				citiesleft.remove(i);
				distance+=distance[currentCity][i];
				currentCity = i;
				comparisons.add(bestRouteHelper(distance, startCity, 							citiesleft, itinerary, distance traveled));
			}
		}
		for (Vector<int> vec : comparisons){
				//compare the distanceTraveled
			
		}
		return best
	}
}
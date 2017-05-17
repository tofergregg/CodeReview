Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int newValue = 0;
	int currentCity;
	Vector<int> route;
	return bestRoute(Grid<double> &distance, int startCity, int newValue;
					 int currentCity);
}
	
Vector<int>	bestRoute(Grid<double> &distance, int startCity, int newValue;
					 int currentCity, Vector<int> route){

	if (startCity == currentCity){
		route.add(currentCity);
		return route;
	} else {
		int newValue;
		for (int i = 0; i < distance.width(); i++) {
			int value = distance[currentCity][i];
			if (value != 0 and value < newValue and !pastCities.contains(i) {
				newValue == value;
				currentCity = i;
				pastCities.add(i);
				route.add(i);
				bestRoute(Grid<double> &distance, int startCity, 
						  int currentCity, int miles, Vector<int> route);
			}
				}
				


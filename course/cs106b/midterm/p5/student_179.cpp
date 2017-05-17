' Initialization of helper function
Vector<int> bestRoute(Grid<double> &distance, int startCity, int endCity, int &sum, Vector<int> &bestVect, double &bestDist, Set<int> &citiesChecked);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int sum;
	Vector<int> bestVect;
	Set<int> citiesChecked;
	citiesChecked.add(startCity);
	double bestDist = DBL_MAX;
	return bestRoute(distance, startCity, startCity, sum, bestVect, bestDist, citiesChecked);	
}

Vector<int> bestRoute(Grid<double> &distance, int startCity, int endCity, int &sum, Vector<int> &bestVect, double &bestDist, Set<int> &citiesChecked){
	' Base Case - All other cities checked - back to home and provide sum
	if(testVector.size() == distance.numRows()){
		testVector.add(startCity);
		sum = totalRouteDistance(distance, testVector);
		return testVector; 
	} else {
	' Recursive Case - Add another city to the test vector
		citiesChecked.add(i);
		for(int i = 0; i < distance.numRows(); i++){
			if(!citiesChecked.contains(i){
				Vector<int> test = bestRoute(distance, i, startCity, sum, bestVect, bestDist, citiesChecked);
				if(totalRouteDistance(test) < bestDist){
					bestDist = totalRouteDistance(test);
					bestVect = test;
				}
			}
		}
	}
	return bestVect;
	
}
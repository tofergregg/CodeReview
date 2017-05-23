

Vector<int> bestRouteHelper(int startCity, Vector<int>& soFar, Vector<int>& rest) {
	if (rest.size() == 0){
		soFar.insert(0, startCity);
		soFar.add(startCity);
		return soFar;
	} else {
		for (int i = 0; i < rest.size(); i++){
			int a = rest[i];
			rest.remove(i);
			soFar.add(a);
			return bestRouteHelper(startCity, soFar, rest);
		}
	}
}
			
			
		

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> soFar;
	Vector<int> rest;
	for(int i=0; i< distance.numRows();i++){
		if(i!=startCity){
			rest.add(i);
		}		
	}
	return bestRouteHelper(startCity, soFar, rest);
}
	

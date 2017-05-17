
Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, 
							int newCity, Vector<int> chosen){
	if(chosen[chosen.length()-1] == startCity){
		return chosen; // if the last element in the vector is the starting 
						//city, return the route
	}
	
	
	for(int r = newCity; r < distance.numRows(); r++){ 
		for(int c = 0; c< distance.numCols(); c++){
			if(c != newCity){
				chosen.add(c);
				double distance = totalRouteDistance(distance, chosen);
				bestRouteHelper(distance, startCity, c, chosen);
				chosen.remove(c);
			}
		}						  
	}
}
	
	
		
	

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> chosen;
	return bestRouteHelper(distance, startCity, startCity, chosen);
	
}

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	
return bestRouteHelper(missingCities, distance, startCity);
				
		
	
Vector<int> bestRouteHelper (vector<int>&missingCities, Grid<double> &distance, int startCity){
	if(distance.numCols() == 0 && distance.numRows == 0) {
		return;
	}
	else { 
		for(int r = 0; r < grid.numRows; r++) {
			for(int c = 0; c < grid.numCols; c++) {
				//find shortest path between city 0 and closest city
				//remove closest city from missingCities vector 
				//int startCity += number of second city
				//add first city to bestRoute vector
				//add closest city to bestRoute vector
				bestRoute(distance,  startCity + number of second closest city);
		


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	
	//populate a vector with cities 1 through n-1
	//we don't want 0 because that's the "start city"—we'll append it at the beginning and the end
	Vector<int> allCities;
	for(int i = 1; i < distance.numRows(); i++){
		allCities.add(i);
	}
	
	string soFar = "";
	//vector of all possible route vectors
	Vector<<Vector<int>> possibleRoutes;
	
	//gets all the possible routes
	getAllRoutes(allCities, soFar, possibleRoutes);
	
	//finds the minimum of all the routes
	double min = DBL_MAX;
	Vector<int> bestRoute;
	for(int i = 0; i < possibleRoutes.size(); i++){	
		if(totalRouteDistance(distance,possibleRoutes[i])<min){
			min = totalRouteDistance(distance,possibleRoutes[i]);
			bestRoute = possibleRoutes[i];
	}
	
	return bestRoute;
}

//recursive function to get all possible routes between the cities
void getAllRoutes(Vector<int> &allCities; string soFar; Vector<Vector<int>> &possibleRoutes{
	
	if(allCities.isEmpty()){ //base case
		//add a 0 at the beginning and the end (b/c that's the start and end point)
		string route = "";
		route = "0" + soFar + "0";
		
		Vector<int> routeVec;
		//convert into a Vector of integers
		for(int i = 0; i< route.length(); i++){
			routeVec.add(stringToInteger(route.substr(i, i+1)));
		}
		
		possibleRoutes.add(routeVec);
	}else{
		for(int i = 0; i < allCities.size(); i++){
			string currCity = integerToString(allCities[i]);
			allCities.remove(i); //choose
			getAllRoutes(allCities, soFar+currCity, possibleRoutes);
			allCities.insert(i, currCity); //unchoose
		}	
	}
}

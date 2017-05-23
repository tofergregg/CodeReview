Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double lowest = DBL_MAX;
	Set<int> citiesLeft;
	for(int i = 0; i < distance.numRows();i++){
		citiesLeft.add(i);
	}
	Vector<int> cityMap;
	cityMap.add(0);
	Vector<Vector<int>> paths;
	paths.add(recursion(distance,startCity,0,0,citiesLeft,cityMap);
	Map<<double>,Vector<int>> mapPath;
	for(Vector<int> go:paths){
		double distance = totalRouteDistance(distance,paths.get(go));
		if(distance < lowest){
			mapPath.put(distance,go);
		}
	}
	for(double finalDistance,mapPath){
		lowest = finalDistance;
		break;
	}
	return mapPath.get(lowest);
}
			  
			  
Vector<int> recursion(Grid<double> &distance,int startCity, int CurrentCity,Set<int> citiesLeft,Vector<int> cityMap){
	if(citiesLeft.isEmpty()){
		return cityMap;
	}
	else{
		for(int i : citiesLeft){
			citiesLeft.remove(i);
			cityMap.add(i);
			return 			       recursion(distance,startCity,i,citiesLeft,cityMap);
		}
	}
	
}
		
		
		


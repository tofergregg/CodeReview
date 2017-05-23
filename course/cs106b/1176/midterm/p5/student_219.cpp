Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int DBL_MAX;
	Vector<int> cities;
	for(int i=0;i<distance.numCols();i++){
		cities+=i;
	}
	Vector<int> chosen;
	chosen+=startCity;
	cities.remove(startCity);
	return bestRouteHelper(distance,startCity,DBL_MAX,cities,bestRoute,chosen);
	
}

Vector<int> bestRouteHleper(Grid<double> &distance, int startCity,int &bestDis, Vector<int> &cities, Vector<int> &bestRoute,Vector<int> & chosen){
	if(cities.isEmpty()){
		chosen+=startCity;		
		int currDis=totalDistance(distance,route);
		if(currDis<bestDis){
			bestDis=currDis;	
			bestRoute=chosen;		
		}
	}else{
		int city=cities[0];
		cities.remove(0);
		chosen+=city;
		bestRouteHelper(distance,startCity,bestDis,cities,bestRoute,chosen);
		cities.insert(0,city);
		chosen.remove(chosen.size()-1);
	}
	
	return bestRoute;
	
}



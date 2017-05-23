

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity,Vector<int> &cityToGo,Vector<int> &route,int &sum) {
	//base case
	if(cityToGo.isEmpty()){
		
		int lastCity = route[route.size()-1];
		
		sum += distance[lastCity][startCity];//add the distance from the last city back to startCity
		
		route+=startCity;//add start city as the end of the route
		
		return route;
		
	}else{						
			int curCity = route[route.size()-1];//get the current city we are in			
			int nextCity = cityToGo[0];//get the next city to go from our cityToGo list 	
			route += nextCity;//add the next city to our route
			cityToGo.remove(i);//remove the next city from our cityToGo list	
			
			//recursive cases
		    //case 1 choose to go this city
			Vector<int> goThisCity = bestRouteHelper(distance,startCity,cityToGo,route,sum + distance[curCity][nextCity]);
			
			//case 2 choose not to go this city
			route.remove(route.size()-1);//remove the city if choose not to go
			cityToGo += i;
		    Vector<int> notGoThisCity =             bestRouteHelper(distance,startCity,cityToGo,route,sum);
			return sum1:sum2? goThisCity:notGoThisCity;
			
		}
	}
}
		
	
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> route;
	Vector<int> cityToGo;
	
	route += startCity; //put start city in the route vec
	
	// store all the cities in the cityToGo vec 
	// except for the start city		
	for(int i=0;i<distance.numRows();i++){
		cityToGo += i;
	}
	cityToGo.remove(startCity);
			
	return bestRouteHelper(distance,startCity,cityToGo,route,0);
	
}
	









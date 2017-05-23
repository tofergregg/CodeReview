/** Method : bestRoute(.....................)
*----------------------
* This method is the helper overloaded function for the proble
* this method is recursive and will try each possibility of cities left to travel to
* and compare them to one another in order to get the lowest possible route
*
* Grid<double> distance : provided grid to calculate the 
* int StartCity : the startCity. needed because once the cities to travel to vector is empty, we need to return home
* vector<int> cities : this vector will hold the possible cities left to travel to. 
* vector<int> route : this vector will hold the choices we had made and will be compared to other routes in recursive steps
*/
Vector <int> bestRoute(Grid<double> &distance, int startCity, Vector<int> &cities, Vector<int> &route){
	// base case, only one city left to travel to
	if (cities.size() == 1){
		route.add(cities[0]);		// add in the only left city
		route.add(startCity);		// return back home
		return route;				// return our route
	} else {
		Vector <int> best;
		// go through each choice left in the cities vector
		Vector<int> copies = cities;			// copies is used because the cities vector will be manipulated
		for (ini i = 0; i < copies.size(); i++){				// go through each option we have left to travel to
			route.add(copies[i]);								// add the cities to the route
			int removed = cities[i];
			cities.remove(i);									// remove the city from optiosn to travel to
			Vector<int> thisWay = bestRoute(distance, startCity, cities, route);		// recursive call, will return a vector
			if (!best.isEmpty()){							// Make the comparison between our lowest route so far and out newly discovered route
				double dTried = totalRouteDistance (distance, thisWay);
				double dBest = totalRouteDistance (distance, best);					
				// if this route is short than what we've done before,
				if (dTried < dBest){
					best = thisWay;							// this way is better, replace the best with this
				}
			}else {	 // if this is first time through where the best one if the first one we have tried
				best = thisWay;
			}
			route.remove(route.size()-1);		    			// remove the last inserted element there for backtracking purposes
			cities.insert(i, removed);							// add the value back in our city for backtracking purposes
		}
		return best;
	}

}
/** Method : bestRoute(..........)
*-------------------------
* this method is the first to get called. It will call the overloaded recursive fucntion for the answer
* It begins by removing the start city from the list of cities to travel to and additing it to the beginning of the route
*
* Grid<double> distance : provided grid that will be used to calculate the distance of a Route
* int startCity : provided beginning city. Can be of value 0 - 3
*/
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	// Start off a cities vector 
	Vector <int> cities = {0, 1, 2, 3};
	// Start a route vector 
	Vector <int> route;
	route.add(startCity);	// add in first city
	cities.remove(startCity);		// remove from travel to cities vectors because we cannot go there until we come back. cities number matches index
	// helper function
	route = bestRoute(distance, startCity, cities, route);
	return route;					// this is the vector that made it through the recursion and must be the shortest one
}


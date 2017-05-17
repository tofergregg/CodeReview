
#include "grid.h"
#include "vector.h"

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int shortestDist = DBL_MAX;
	Vector<int> bestRoute;
	Vector<int> cities;
	for (int i = 0; i < distance.numCols()-1; i++){
		cities[i] = i;
	}
	
	cities.remove[startCity]; //So moving through startCity is not an option until the end of the trip
	
	for (int c = 1; c < cities.size(); c++){
		Vector<int> route;
		route[0] = startCity;
		int nextCity = c;
		route += cities[c-1];
		cities.remove(c-1);
		route += bestRoute(distance, cities);
		route += startCity
		double routeDist = totalRouteDistance(distance, route);
		if (routeDist < shortestDist){
			shortestDist = routeDist;
			bestRoute = route;
		}
		return bestRoute;
		
	}
	
	
Vector<int> bestRoute(Grid<double> const &distance, Vector<int> &cities) {
	
	int shortestDist = DBL_MAX;
	Vector<int> bestRoute;
	Vector<int> route;
	if (cities.size() == 1){
		return city[0];
	} else {
		int city = cities[0]
		route += city;
		cities.remove[0];
		route += bestRoute(distance, cities);
		double routeDist = totalRouteDistance(distance, route);
		if (routeDist < shortestDist){
			shortestDist = routeDist;
			bestRoute = route;
		}
		cities[0] = city;	
	}
	return bestRoute;
	}
		
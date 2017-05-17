//function prototype
void bestRouteH(Vector<int> & unvisited, Vector<int> & path, Grid<double> &distance, int startCity, double distanceCounter, double smallest, Vector<int> & smallestPath);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
Vector<int> path;
Vector<int> unvisited;
	for(int i = 0; i < distance.numCols(); i++){
		if(i != startCity){
		unvisited.add(i);
		}
	}

Vector<int> smallestPath;
bestRouteH(unvisited, path, distance, startCity, 0, DBL_MAX, smallestPath);
return smallestPath;
	
}

void bestRouteH(Vector<int> & unvisited, Vector<int> & path, Grid<double> &distance, int startCity, double distanceCounter, double smallest, Vector<int> & smallestPath){
//base case
	if(path.size() != 1 && path[path.size-1] == startCity){
		if(unvisited.size() == 0){
			if(distanceCounter < smallest) smallestPath = path; 
			return;
		}else{
		//backtrack
		//remove prev distance increment to distanceCounter
		//add prev city back to unvisited vector
		//remove last vector in oath
		}
	}

//recurse
	for(int i = 0; i < distance.numCols(); i++){
		int nextCity = i;
		path.add(nextCity);
		int prevCity = path[path.size()-1];
		for(int city : unvisited){
			if(unvisited[city] == nextCity) unvisited.remove[city];
		}
		
		
		int distance = distance[nextCity][prevCity];
		distanceCounter += distance;
		
		bestRouteH(unvisited, path, distance, startCity, distanceCounter, smallest, smallestPath);
	}
}


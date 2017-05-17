// In this program I took the the number of rows in the grid and created a string that contained every number except for the starting city. I then created a set that included all the permutations of the leftovercities. I then modified this set to add the starting city at the end and beginning of each string. After this, I transformed each string in the set to an integer and added each integer to a vector.



Vector<int> bestRoute(Grid<double> &distance int startCity) {
	Queue<int> temp;
	cities = distance.numCols();
	for( int x = 0; x< cities; x++) {
		if ( x != start) {
			temp.push(x);
		}
	}
	string str;
	while(!temp.isEmpty) {
	  str  += integerToString(temp.dequeue());
	}
	Set<string> set;
	string rest;
	permute(set,str,rest)
	set = completeSet(set, startCity)
	calculateBestTrip( set, distance)
}


Vector<int> calculateBestTrip( Set<string> set, Grid<double> &distance) {
	double maxDistance = DBL_MAX;
	Vector<int> bestRoute;
	for (string str : set) {
		Vector<int>temp;
		bool check;
		// checks if first value is zero
		if (str[0] == "0") check = true;
		int cities = stringToInteger(str);
		double sum = calculateSum(cities, temp, distance, check);
		if (sum < maxDistance) {
			bestRoute = temp;
		}
	}
	return bestRoute;
	
}

double calculateSum(int cities, Vector<int>& temp, Grid<double> &distance, bool check) {
	int num = cities;
	while (num > 9) {
		temp.add(num%10);
		num /= 10;
	} 
	if(check) temp.add(0,0);
	else temp.add(num);
	return totalRouteDistance(Grid<double> &distance, Vector<int> &temp);
}

Set<string> completeSet(Set<string> &set, int startCity) {
	Set<string> temp;
	for ( string str : set) {
		string city = integerToString(startCity) + str + startCity;
		temp.add(city)
	}
	return temp;
}


// this method permutes all possiblities for inner cities trips
permute(Set<string> &set, string str, string rest) {
	if (rest.lenght() == 0)
		set.add(str)
	else {
		for(int x =0; x< rest.length() x++) {
			string rem = rest.substr(0,x) + rest.substr(x+1);
			permute(set, str + rest[x], rest)
		}
}































}


Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> tmp;
	Vector<int> res;
	tmp.add(startCity);
	double minDis = DBL_MAX;
	helper(res, tmp, distance, minDis);
	return res;
}

void helper(Vector<int>& res, Vector<int> tmp, Grid<double> &dis, double& minDis) {
	if (tmp.size() == dis.numRows() + 1) {
		double curDis = totalRouteDistance(distance,tmp);
		if (curDis < minDis){
			res = tmp;
			minDis = curDis;
		}
	} else {
		for (int i = 0; i < dis.numRows(); i++) {
			if(used(tmp, i)) {
				coutinue;
			}
			//int c = tmp[tmp.size() -1 ]; // start
			//int r = i; // reach
			tmp.add(i);
			helper(res, tmp, distance, minDis);
			tmp.remove(tmp.size() - 1);
			
		
		}
		
	}
}


bool used(Vector<int>& tmp,int& i) {
	for (int t : tmp) {
		if (t == i) return true;
	}
	return false;
}
#include <iostream>
#include <vector>
#include <cmath>

// vector array (t, y) 
typedef std::vector<std::pair<double, double>> point_t;

const int N_SEMICIRCLE  = 4; 
const int CIRCLE_RADIUS = 5; 
const float TIME_DIFF   = 0.01;
const float TIME_FINAL  = 10;

point_t pathGenerator(float r, float dt, float finalTime);

int main(){
	point_t path_pt;
	path_pt = pathGenerator(CIRCLE_RADIUS, TIME_DIFF, 2 * CIRCLE_RADIUS);

    for (int repeat = 1; repeat < 3; repeat++){
		auto path_idx_end = path_pt.end();
		
		for(auto iter = path_pt.begin(); iter!= path_idx_end; iter++)
			path_pt.push_back(std::pair<double, double>(iter->first + 2 * repeat * CIRCLE_RADIUS, 
					-iter->second));
	}
	path_pt.push_back(std::pair<double, double>( TIME_FINAL * N_SEMICIRCLE , 0));

	// Print path_pt
	for(auto iter = path_pt.begin(); iter!= path_pt.end(); iter++){
		static int num = 0;
		std::cout << num++ << " ->";
		std::cout << "[" << iter->first << ", " << iter->second << "]" << std::endl;
	}
}

point_t pathGenerator(float r, float dt, float finalTime){

	point_t path_point;

	int timeIdx = finalTime / dt;
	float x = 0.0;
	float y = 0.0;

	for (int idx = 0; idx < timeIdx ; idx++){
		y =  sqrt(pow(r, 2) - pow(r - x, 2));
		path_point.push_back(std::pair<double, double>(x, y));
		x += dt;
	}

	return path_point;
}

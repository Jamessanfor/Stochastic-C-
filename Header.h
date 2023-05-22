#pragma once

#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>


#include <random>
#include <algorithm>

#define mapsize 100
//#define sens_MP 15
using namespace std;

class particles {
public:
	int x, y;
	int position;
	vector<vector<int>> sensor_dat;
	int weight = 0;
	particles(int a,int b, int direct) {
		x = a;
		y = b;
		position = direct;
		int sens_MP = 1;
		vector<int> temp(sens_MP);
		for (int i = 0; i < 8; i++) {

			sensor_dat.push_back(temp);
			sens_MP += 2;
			temp.resize(sens_MP);

			
		}
		weight = 50;
		temp.clear();
		//free(&temp);

	}
	void rotatecw() {//clockwise
		position++;
		position %= 4;
	}
	void rotateccw() {//counter clkwise
		if (position)
			position--;
		else
			position = 3;
	}
	

	void get_data(vector<vector<int>>& mp, int dir ) {
		if (dir == 0) {
			for (int i = 0; i < sensor_dat.size(); i++) {
				for (int j = 0; j < sensor_dat[i].size(); j++) {
					sensor_dat[i][j] = mp[x + i + 1][y + j - i];
				}
			}
		}
		else if (dir == 1) {
			for (int i = 0; i < sensor_dat.size(); i++) {
				for (int j = 0; j < sensor_dat[i].size(); j++) {
					sensor_dat[i][j] = mp[x - i - 1][y + j - i];
				}
			}
		}
		else if (dir == 2) {
			for (int i = 0; i < sensor_dat.size(); i++) {
				for (int j = 0; j < sensor_dat[i].size(); j++) {
					mp[x + i - j][y - j - 1] = 5;
					sensor_dat[i][j] = mp[x + i - j][y - j - 1];
				}
				reverse(sensor_dat[i].begin(), sensor_dat[i].end());
			}
		}
		else {
			for (int i = 0; i < sensor_dat.size(); i++) {
				for (int j = 0; j < sensor_dat[i].size(); j++) {
					sensor_dat[i][j] = mp[x + i - j][y - j + 1];
				}
			}
		}
	}

	void print_sensor_dat() {
		string spc = "       ";

		if (position == 0) {
			for (int i = 0; i < sensor_dat.size(); i++) {
				cout << spc;
				for (int j = 0; j < sensor_dat[i].size(); j++)
				{
					cout << sensor_dat[i][j];
				}
				if (spc.size())
					spc.pop_back();
				cout << "\n";
			}
		}
		else if (position == 1) {
			for (int i = sensor_dat.size()-1; i > -1; i--) {
				cout << spc.substr(0,sensor_dat.size()-i);
				for (int j = 0; j < sensor_dat[i].size(); j++)
				{
					cout << sensor_dat[i][j];
				}
				
				cout << "\n";
			}
		}
		else if (position == 2) {

			cout << sensor_dat[7][0] << "\n";
			cout << sensor_dat[7][1] << sensor_dat[6][0] << "\n";
			cout << sensor_dat[7][2] << sensor_dat[6][1] << sensor_dat[5][0] << "\n";
			cout << sensor_dat[7][3] << sensor_dat[6][2] << sensor_dat[5][1] << sensor_dat[4][0] << "\n";
			cout << sensor_dat[7][4] << sensor_dat[6][3] << sensor_dat[5][2] << sensor_dat[4][1] << sensor_dat[3][0] << "\n";
			cout << sensor_dat[7][5] << sensor_dat[6][4] << sensor_dat[5][3] << sensor_dat[4][2] << sensor_dat[3][1] << sensor_dat[2][0] << "\n";
			cout << sensor_dat[7][6] << sensor_dat[6][5] << sensor_dat[5][4] << sensor_dat[4][3] << sensor_dat[3][2] << sensor_dat[2][1] << sensor_dat[1][0] << "\n";
			cout << sensor_dat[7][7] << sensor_dat[6][6] << sensor_dat[5][5] << sensor_dat[4][4] << sensor_dat[3][3] << sensor_dat[2][2] << sensor_dat[1][1] << sensor_dat[0][0] << "\n";
			cout << sensor_dat[7][8] << sensor_dat[6][7] << sensor_dat[5][6] << sensor_dat[4][5] << sensor_dat[3][4] << sensor_dat[2][3] << sensor_dat[1][2] << "\n";
			cout << sensor_dat[7][9] << sensor_dat[6][8] << sensor_dat[5][7] << sensor_dat[4][6] << sensor_dat[3][5] << sensor_dat[2][4] << "\n";
			cout << sensor_dat[7][10] << sensor_dat[6][9] << sensor_dat[5][8] << sensor_dat[4][7] << sensor_dat[3][6] << "\n";
			cout << sensor_dat[7][11] << sensor_dat[6][10] << sensor_dat[5][9] << sensor_dat[4][8] << "\n";
			cout << sensor_dat[7][12] << sensor_dat[6][11] << sensor_dat[5][10] << "\n";
			cout << sensor_dat[7][13] << sensor_dat[6][12] << "\n";
			cout << sensor_dat[7][14] << "\n";

		}
		else if (position == 3) {
			
			cout << spc << sensor_dat[7][0] << "\n"; spc.pop_back();
			cout << spc <<sensor_dat[6][0] << sensor_dat[7][1] << "\n"; spc.pop_back();
			cout << spc << sensor_dat[5][0] << sensor_dat[6][1] << sensor_dat[7][2] << "\n"; spc.pop_back();
			cout << spc << sensor_dat[4][0] << sensor_dat[5][1] << sensor_dat[6][2] << sensor_dat[7][3] << "\n"; spc.pop_back();
			cout << spc << sensor_dat[3][0] << sensor_dat[4][1] << sensor_dat[5][2] << sensor_dat[6][3] << sensor_dat[7][4] << "\n"; spc.pop_back();
			cout << spc << sensor_dat[2][0] << sensor_dat[3][1] << sensor_dat[4][2] << sensor_dat[5][3] << sensor_dat[6][4] << sensor_dat[7][5] << "\n"; spc.pop_back();
			cout << spc << sensor_dat[1][0] << sensor_dat[2][1] << sensor_dat[3][2] << sensor_dat[4][3] << sensor_dat[5][4] << sensor_dat[6][5] << sensor_dat[7][6] << "\n"; spc.pop_back();
			cout << spc << sensor_dat[0][0] << sensor_dat[1][1] << sensor_dat[2][2] << sensor_dat[3][3] << sensor_dat[4][4] << sensor_dat[5][5] << sensor_dat[6][6] << sensor_dat[7][7] << "\n"; spc.push_back(' ');
			cout << spc << sensor_dat[1][2] << sensor_dat[2][3] << sensor_dat[3][4] << sensor_dat[4][5] << sensor_dat[5][6] << sensor_dat[6][7] << sensor_dat[7][8] << "\n"; spc.push_back(' ');
			cout << spc << sensor_dat[2][4] << sensor_dat[3][5] << sensor_dat[4][6] << sensor_dat[5][7] << sensor_dat[6][8] << sensor_dat[7][9] << "\n"; spc.push_back(' ');
			cout << spc << sensor_dat[3][6] << sensor_dat[4][7] << sensor_dat[5][8] << sensor_dat[6][9] << sensor_dat[7][10] << "\n"; spc.push_back(' ');
			cout << spc << sensor_dat[4][8] << sensor_dat[5][9] << sensor_dat[6][10] << sensor_dat[7][11] << "\n"; spc.push_back(' ');
			cout << spc << sensor_dat[5][10] << sensor_dat[6][11] << sensor_dat[7][12] << "\n"; spc.push_back(' ');
			cout << spc << sensor_dat[6][12] << sensor_dat[7][13] << "\n"; spc.push_back(' ');
			cout << spc << sensor_dat[7][14] << "\n";
		}
	
	}

};


class robo_map {
	public:
	vector<vector<int>> mp;
	//initalize map just a box
	robo_map() {

		
		vector<int> temp;
		for (int i = 0; i < mapsize; i++) {
			for (int j = 0; j < mapsize; j++) {
				if (i == 0 || j == 0) {
					temp.push_back(1);
				}
				else if (i == mapsize - 1 || j == mapsize - 1) {
					temp.push_back(1);
				}
				else {
					temp.push_back(0);
				}
			}
			mp.push_back(temp);
			temp.clear();
		}
	}
	//basic map change
	void basic_map() {
		for (int i = 0; i < mapsize; i++) {
			for (int j = 0; j < mapsize; j++) {
				if ((i > 50 && j == 1000) && (i < mapsize - 50 && j == 1000)) {
					mp[i][j] = 1;

				}
			}
		}

	}
	//medium map change
	void medium_map() {
		map_rest();
		for (int i = 0; i < mapsize; i++) {
			for (int j = 0; j < mapsize; j++) {
				if ((i >100 && j%10==0 )) {
					mp[i][j] = 1;

				}
			}
		}
	}
	void hard_map() {
		for (int i = 0; i < mapsize; i++) {
			for (int j = 0; j < mapsize; j++) {
				if ((i > 50 && j == 1000) && (i < mapsize - 50 && j == 1000)) {
					mp[i][j] = 1;

				}
			}
		}
	}

	void map_rest() {
		for (int i = 1; i < mapsize-1; i++) {
			for (int j = 1; j < mapsize-1; j++) {
				
					mp[i][j] = 0;

				
			}
		}
	
	
	}
	void mark_map(int x, int y) {
		mp[x][y] = 7;
	
	
	}
	void map_print() {
		for (int i = 0; i < mapsize;i++) {
			for (int j = 0; j < mapsize; j++) {
				cout << mp[i][j];

			}
			cout<< "\n";
		}
	
	
	}

};

double poission(void); 
double poission(int lambda, int x);





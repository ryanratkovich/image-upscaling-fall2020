/*
* Class: COP4531
* Assignment: 2
* Author: Ryan Ratkovich
* Date: 11/16/2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 	HELPER FUNCTIONS */

vector<vector<int>> create_matrix(ifstream & f){	// creates a 256 x 256 integer matrix that holds the input file data
	vector<string> lines;	// contains each line from input file
	string line;
	while(getline(f, line)){
		lines.push_back(line);
		line = "";
	}
	vector<vector<int>> m;
	vector<int> temp;
	for (const string & line : lines){
		string temp_string;
		for (int i = 0; i < line.length(); ++i){
			if (line[i] != ','){
				temp_string += line[i];
			} else {
				int num = stoi(temp_string);
				temp.push_back(num);
				temp_string = "";
			}
		}
		int num = stoi(temp_string);
		temp.push_back(num);
		m.push_back(temp);
		temp.clear();
	}
	return m;
}

vector<vector<int>> nearest_neighbor(const vector<vector<int>> & in){	// upscales a 256 x 256 image to 512 x 512 using NN algorithm
	vector<vector<int>> out;
	vector<int> temp;
	for (int i = 0; i < in.size(); ++i){
		for (int j = 0; j < in.size(); ++j){
			temp.push_back(in[i][j]);
			temp.push_back(in[i][j]);
		}
		out.push_back(temp);
		out.push_back(temp);
		temp.clear();
	}
	return out;
}

int calculate_L1(const vector<vector<int>> & a, const vector<vector<int>> & b){
	int sum = 0;
	for (int i = 0; i < 512; ++i){
		for (int j = 0; j < 512; ++j){
			sum += abs(a[i][j] - b[i][j]);
		}
	}
	return sum;
}

/* MAIN */

int main(int argc, char** argv) {

	ifstream file1, file2;	// open input file
	file1.open(argv[1]);
	file2.open("sample1_original_image.txt");

	vector<vector<int>> input_matrix = create_matrix(file1); // 256 x 256 vector of integers from input file

	vector<vector<int>> nearest_neighbor_matrix = nearest_neighbor(input_matrix); // 512 x 512 vector upscaling of input_matrix

	vector<vector<int>> original_matrix = create_matrix(file2);	// 512 x 512 vector of integers from original image file

	int L1_metric = calculate_L1(nearest_neighbor_matrix, original_matrix);

	cout << "L1 metric: " << L1_metric << endl;

	file1.close();
	file2.close();
	return 0;
}
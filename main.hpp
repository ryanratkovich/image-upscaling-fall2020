/*
* Class: COP4531
* Assignment: 2
* Author: Ryan Ratkovich
* Date: 11/23/2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 	HELPER FUNCTIONS */

void create_file(vector<vector<int>> m, string filename){	// creates output file with 512 x 512 matrix data in current working directory
	ofstream file;
	file.open(filename);
	for (int i = 0; i < m.size(); ++i){
		for (int j = 0; j < m.size() - 1; ++j){
			file << m[i][j] << ",";
		}
		file << m[i][m.size() - 1] << endl;
	}
	file.close();
}

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
	return m;	// returns a 256 x 256 matrix of integers
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

vector<vector<int>> bilinear(const vector<vector<int>> & in){	// upscales a 256 x 256 image to 512 x 512 using an attempt at the bilinear algorithm
	vector<vector<int>> out;
	vector<int> temp1;
	vector<int> temp2;	// vector holding only -1's 
	for (int i = 0; i < 512; ++i)
		temp2.push_back(-1);

	for (int i = 0; i < in.size(); ++i){		// creates the 512 x 512 matrix with empty spaces marked with -1's
		for (int j = 0; j < in.size(); ++j){
			temp1.push_back(in[i][j]);
			temp1.push_back(-1);
		}
		out.push_back(temp1);
		out.push_back(temp2);
		temp1.clear();
	}

	for (int i = 0; i < out.size(); i += 2){	// for every other row of the 512 rows
		for (int j = 1; j < out.size() - 1; j += 2){ // for every empty space (spaces with -1 as value)
			int avg = (out[i][j - 1] + out[i][j + 1]) / 2;	// set the value of the pixel to the average of the adjacent pixel values
			out[i][j] = avg;
		}
		out[i][511] = out[i][510];	// give the final pixel of every other row the same value as the pixel to it's left
	}

	for (int i = 1; i < out.size() - 1; i += 2){	// for every other row of the 512 rows
		for (int j = 0; j < out.size(); ++j){ // for every empty space (spaces with -1 as value)
			int avg = (out[i - 1][j] + out[i + 1][j]) / 2;	// set the value of the pixel to the average of the adjacent pixel values.
			out[i][j] = avg;
		}
	}
	for (int i = 0; i < out.size(); ++i){	// set all pixels of bottom row to pixels of top-adjacent row.
		out[511][i] = out[510][i];
	}

	return out;	// return 512 x 512 matrix
}

// int calculate_L1(const vector<vector<int>> & a, const vector<vector<int>> & b){	// calculates L1 metric
// 	int sum = 0;
// 	for (int i = 0; i < 512; ++i){
// 		for (int j = 0; j < 512; ++j){
// 			sum += abs(a[i][j] - b[i][j]);
// 		}
// 	}
// 	return sum;
// }

/* MAIN */

// int main(int argc, char** argv) {

// 	ifstream file1;	// open input file
// 	//ifstream file2;
// 	file1.open(argv[1]);
// 	//file2.open("sample1_original_image.txt");

// 	vector<vector<int>> input_matrix = create_matrix(file1); // 256 x 256 vector of integers from input file

// 	vector<vector<int>> nearest_neighbor_matrix = nearest_neighbor(input_matrix); // 512 x 512 vector upscaling of input_matrix using NN

// 	//vector<vector<int>> original_matrix = create_matrix(file2);	// 512 x 512 vector of integers from original image file

// 	vector<vector<int>> bilinear_matrix = bilinear(input_matrix); // 512 x 512 vector upscaling of input_matrix using attempted bilinear algorithm

// 	// int L1_metric = calculate_L1(nearest_neighbor_matrix, original_matrix);

// 	// int L1_metric2 = calculate_L1(bilinear_matrix, original_matrix);

// 	// cout << "L1 metric NN: " << L1_metric << endl;

// 	// cout << "L1 metric bilinear: " << L1_metric2 << endl;

// 	create_file(nearest_neighbor_matrix, argv[2]);	// creates output file

// 	//file2.close();
// 	file1.close();
// 	return 0;
// }
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

using namespace std;

/* 	HELPER FUNCTIONS */

vector<vector<int>> create_matrix(vector<string> lines){	// creates a 256 x 256 integer matrix that holds the input file data
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

/* MAIN */

int main() {

	ifstream file;	// open input file
	file.open("sample1_input_image.txt");

	vector<string> lines;	// contains each line from input file
	string line;
	while(getline(file, line)){
		lines.push_back(line);
		line = "";
	}
	file.close();

	vector<vector<int>> input_matrix = create_matrix(lines); // 256 x 256 vector of integers from input file



	// for(auto v : input_matrix){
	// 	for (int n : v){
	// 		cout << n << " ";
	// 	}
	// 	cout << "\n\n";
	// }

	return 0;
}
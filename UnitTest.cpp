/*
* Class: COP4531
* Assignment: 2
* Author: Ryan Ratkovich
* Date: 11/23/2020
*/

#include "./main.hpp"
#include "../../googletest/googletest/include/gtest/gtest.h"

using namespace std;

// TEST(CreateMatrixTest, HandlesInput){
// 	ifstream file;
// 	file.open("sample1_input_image.txt");
// 	EXPECT_NE(create_matrix(file), nullptr);
// 	file.close();
// }

TEST(NearestNeighborTest, HandlesInput){
	vector<vector<int>> vec;
	vector<int> row;
	for (int i = 0; i < 256; ++i){
		for (int j = 0; j < 256; +j){
			row.push_back(0);
		}
		vec.push_back(row);
		row.clear();
	}
	vector<vector<int>> test = nearest_neighbor(vec);
	EXPECT_EQ(test.size(), 512);
}

TEST(BilinearTest, HandlesInput){
	vector<vector<int>> vec;
	vector<int> row;
	for (int i = 0; i < 256; ++i){
		for (int j = 0; j < 256; +j){
			row.push_back(0);
		}
		vec.push_back(row);
		row.clear();
	}
	vector<vector<int>> test = bilinear(vec);
	EXPECT_EQ(test.size(), 512);
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
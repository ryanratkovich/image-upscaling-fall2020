# COP4531_Project2_Ratkovich

GENERAL:
This is the Gitlab repository for all files related to my solution to project 2 for COP4531 Fall 2020.

NOTE ON COMPILATION AND EXECUTION:
This program can be compiled using the makefile provided within this repository. Type "make" at the commandline.
To run this program: enter "main <input file>" at the commandline.

PROJECT DESCRIPTION:
This project aims to upscale an image by using the nearest neighbor and bilinear algorithms. This project accepts a file of size 262144 bytes and outputs an upscaled version of the file that is 1048576 bytes (2x larger). The goal of this project is to upscale the image in the best way possible, that is, to upscale the image and preserve the quality of the image to the best of the programs ability.

NOTE ON FUNCTIONS:
This program uses the following functions to accomplish this goal:

- create_matrix : produces a 2D vector from an input file containing rows and columns of values representing pixels in an image.

- nearest_neighbor : produces an upscaled 2D vector from an input 2D vector by implementing nearest neighbor interpolation on the matrix.

- calculate_L1 : calculates the difference between an upscaled image and the original image to measure the quality of upscaling.




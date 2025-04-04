/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 27, 2025.
Assignment: Lab8G

This program reads a PGM image from the file "inImage.pgm",
and outputs a modified image to "outImage.pgm" that implements
a Sobel kernel.
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(int image[MAX_H][MAX_W], int height, int width);
int fcn(int a, int b, int c, int d, int e, int f, int g, int h, int i);
void kernel(int image[MAX_H][MAX_W], int height, int width, int result[MAX_H][MAX_W]);


int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); 
    // read it from the file "inImage.pgm"
	// and the 2-dimesional array img contains the image data

	// we copy its contents into a new array
    int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = img[row][col];
		}
	}
    kernel(img, h, w, out);

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int fcn(int a, int b, int c, int d, int e, int f, int g, int h, int i){
    return (g + 2*h + i) - (a + 2*b + c);
}

void kernel(int image[MAX_H][MAX_W], int height, int width, int result[MAX_H][MAX_W]){
    int a, b, c, d, e, f, g, h, i;
    for (int row = 1; row < height - 1; row++){ //loop through every pixel except the borders
        for (int col = 1; col < width - 1; col++){
            a = image[row - 1][col - 1];
            b = image[row - 1][col];                                // a b c
            c = image[row - 1][col + 1];                            // d e f
            d = image[row][col - 1];                                // g h i
            e = image[row][col]; //current pixel
            f = image[row][col + 1];
            g = image[row + 1][col - 1];
            h = image[row + 1][col];
            i = image[row + 1][col + 1];
            int new_value = fcn(a, b, c, d, e, f, g, h, i);
            //make sure the result is in valid range.
            if (new_value < 0){
                result[row][col] = 0;
            }
            else if(new_value > 255){
                result[row][col] = 255;
            }
            else{
                result[row][col] = new_value;
            }
        }
    }

    //set all borders to black
    for (int row = 0; row < height; row++){
        result[row][0] = 0;
        result[row][width - 1] = 0;
    }
    for (int col = 0; col < width; col++){
        result[0][col] = 0;
        result[height - 1][col] = 0;
    }

}


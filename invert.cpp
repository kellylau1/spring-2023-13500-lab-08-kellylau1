#include <iostream>
#include "invert.h"
#include "imageio.h"
#include <cmath>

void invert_colors() {

    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 

    int out[MAX_H][MAX_W];
    int row, col;
    for(row = 0; row < h; row++) {
        for(col = 0; col < w; col++) {
        out[row][col] = img[row][col]; 

        }

    }

 
    for (row = 0; row < h; row++) {
        for (col = 0; col < w; col++) {
            out[row][col] = 255 - (out[row][col]); 
        }
    }

    writeImage("taskA.pgm",out, h, w);
}

void invert_half() {
    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 

    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
        out[row][col] = img[row][col]; 
        }

    }

    int row, col; 
    int half_point = round(w/2); 
    for(row = 0; row < h; row++) {
        for (col = half_point; col < w; col++) {
            out[row][col] = 255 - (out[row][col]); 
        }
    }

    writeImage("taskB.pgm",out, h, w);
}


void white_box() {

 std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);
    
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
        out[ row][col] = img[row][col]; 
        }
    }

    int row_starting = round(0.25*h); 
    int row_ending = round(0.75*h); 
    int col_starting = round(0.25*w); 
    int col_ending = round(0.75*w); 

    for(int row = row_starting; row < row_ending; row++) {
        for(int col = col_starting; col < col_ending; col++) {
            out[row][col] = 255; 
        }
    }
    writeImage("taskC.pgm",out, h, w);
}


void frame() {

 std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
        out[ row][col] = img[row][col]; 

        }

    }

    int row_starting = round(0.25*h); 
    int row_ending = round(0.75*h); 
    int col_starting = round(0.25*w); 
    int col_ending = round(0.75*w); 

    for(int row = row_starting; row <= row_ending; row++) {
        for(int col = col_starting; col <= col_ending; col++) {
            if (row == row_starting || row == row_ending || col == col_starting || col == col_ending) {
                out[row][col] = 255; 
            }
        }
    }
    writeImage("taskD.pgm",out, h, w);
}



void scale() {
    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    h = h*2; 
    w = w*2;
    readImage(input, img, h, w); 
  
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row+=2) {
        for(int col = 0; col < w; col+=2) {
            int pixel = img[row/2][col/2]; 
        
            out[row][col] = pixel; 
            out[row+1][col] = pixel; 
            out[row][col+1] = pixel; 
            out[row+1][col+1] = pixel; 
       }
   }

   writeImage("taskE.pgm", out, h, w);
}


void pixelate() {
std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 

    int out[MAX_H][MAX_W];

    int value = 0; 
    int average; 
    for(int row = 0; row < h; row+=2) {
        for(int col = 0; col < w; col+=2) {
                value= 0;

            value+= img[row][col]; 
            value+= img[row+1][col]; 
            value+= img[row][col+1]; 
            value+= img[row+1][col+1]; 

            average = value/4; 

            out[row][col] = average;  
            out[row+1][col] = average; 
            out[row][col+1] = average;
            out[row+1][col+1] = average;
        
        }
    }
    std::cout << "\n\n\n";
        for (int row = 0; row < h; row++) {
        for (int col=0; col<w; col++) {
            std::cout << out[row][col] << " ";
        }
        std::cout << "\n";
    }

   writeImage("taskF.pgm", out, h, w);

}




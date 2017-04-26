/*
example2.cpp

Using the function convolve
*/
#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

int main() {

// Declare a float image
  CImg<float> image;
// Load an image file into it
  image.load("lena.ppm");
  cout<<"Image loaded..."<<endl;

// Define a 5x5 convolution mask
  CImg<float> mask(5,5,1,1,1.);
  
// Print values of the mask
  cout<<"Values of the mask image : ["<<endl;
  for (int y=0;y<mask.height();y++) {
    cout<<"  ";
    for (int x=0;x<mask.width();x++) cout<<mask(x,y)<<" ";
    cout<<endl;
    }
  cout<<"]"<<endl;

// Convolve and normalize the image
  CImg<float> res = image.get_convolve(mask).normalize(0,255);

// Create an image list for side by side display
  CImgList<float> list(image,res);
  
// Declare a display and dispay the two images
  CImgDisplay disp(list,"Convolution by a 5x5 mean kernel");
  cout<<"<< Close the window to end the program >>"<<endl;
  
// Wait for the display window to close
  while (!disp.is_closed()) {
    disp.wait();
    }
    
  return 0;
}

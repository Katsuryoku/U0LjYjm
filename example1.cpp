#include "CImg.h"
using namespace cimg_library;

int main() {

// Declare an image
  CImg<unsigned char> image;
// Load an image file into it
  image.load("lena.ppm");
  
// Declare a display and dispay the image into it
  CImgDisplay disp(image,"Image");
  
// Wait for the display window to close
  while (!disp.is_closed()) {
    disp.wait();
    }
    
  return 0;
}

/**
 * @file filter2D_demo.cpp
 * @brief Sample code that shows how to implement your own linear filters by using filter2D function
 * @author OpenCV team
 */

//#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <stdio.h>
//#include <stdlib.h>

using namespace cv;
using namespace std;

/**
 * @function main
 */
int main ( int argc, char** argv )
{
    // Declare variables
    Mat src, dst;

    Mat kernel;
    Point anchor;
    double delta;
    int ddepth;
    int kernel_size;
    const char* window_name = "filter2D Demo";

    //![load]
    const char* imageName = argc >=2 ? argv[1] : "../LenaSjooblom1.png";

    // Loads an image
    src = imread( imageName, CV_LOAD_IMAGE_COLOR ); // Load an image

    if( src.empty() )
    {
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default lena.jpg] \n");
        return EXIT_FAILURE;
    }
    //![load]

    //![init_arguments]
    // Initialize arguments for the filter
    anchor = Point( -1, -1 );
    delta = 0;
    ddepth = -1;
    //![init_arguments]

    // Loop - Will filter the image with different kernel sizes each 0.5 seconds
    int ind = 0;
    for(;;)
    {
        //![update_kernel]
        // Update kernel size for a normalized box filter
        kernel_size = 3 + 2*( ind%5 );
        kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
        //![update_kernel]

        //![apply_filter]
        // Apply filter
        filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
        //![apply_filter]
        imshow( window_name, dst );

        char c = (char)waitKey(500);
        // Press 'ESC' to exit the program
        if( c == 27 )
        { break; }

        ind++;
    }

    return EXIT_SUCCESS;
}



/*
* para compilar: atenção usar acento grave em `pkg...`
* g++ main.cpp -o output `pkg-config --cflags --libs opencv`
*/

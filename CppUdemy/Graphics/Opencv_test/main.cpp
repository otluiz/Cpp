#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;

/*
* para compilar: atenção usar acento grave em `pkg...`
* g++ main.cpp -o output `pkg-config --cflags --libs opencv`
*/

int main(int argc, char** argv)
{
  cv::Mat image;
  image = cv::imread("sample.png", CV_LOAD_IMAGE_COLOR);

  if(!image.data){
    cout << "Não encontrei nenhuma imagem para abrir" << endl;
    return -1;
  }

  cv::namedWindow( "Dilplay windowes", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Display image window", image );

  cv::waitKey(0);
  
  return 0;
}

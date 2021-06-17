/*
 Função de kernel: filter2D já está implementada no C++ 
 K = 1/3² * [matriz de uns]
 */
/*
* para compilar: atenção usar acento grave em `pkg...`
* g++ [main.cpp] -o [output] `pkg-config --cflags --libs opencv`
*/

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/** @funciont main */
int main(int argc, char** argv)
{
  /// Declaração de variáveis
  Mat src, dst;

  Mat kernel;
  Point ancora;
  double delta;
  int tam_kernel;
  int ddepth;
  int c;
  const char* janela = "filter 2D Demo"; 
  ////  <cont char*> para tirar o Warning na compilação, pq char (em C++)
  ////   é uma constante, diferetemente do C que usava um array de char

  // Se não tem uma imagem (![load])
  const char* imageName = argc >=2 ? argv[1] : "LenaForsen.png";
  
  /// Carrega uma imagem (Loads an image)
  src = imread( imageName, CV_LOAD_IMAGE_COLOR ); // Load an image
  if ( !src.data ) {
    cout << "Error opening image \n";
    return -1;
  }

  /// Cria uma janeta
  namedWindow( janela, CV_WINDOW_AUTOSIZE );

  /// Inicializa argumentos para o filtro
  ancora = Point( -1, -1 ); // referência para iniciar: no alto à esquerda
  delta = 0;
  ddepth = -1;

  /// Laço principal - Irá filtrar a imagem com kernels de diferentes tamanho a cada 0.5s
  int ind = 0;
  while ( true) {
    c = waitKey( 500 );
    /// Se o cabra pressionar 'ESC' irá sair do programa.
    if ( (char)c == 27 ) { break; }

    /// Atualiza o tamanho do kernel para uma "caixa" normalizado
    tam_kernel = 3 + 2 * (ind % 5);
    kernel = Mat::ones(tam_kernel, tam_kernel, CV_32F) / (float)(tam_kernel * tam_kernel);

    /// Aplica o filtro (função kernel)
    filter2D(src, dst, ddepth, kernel, ancora, delta, BORDER_DEFAULT );
    imshow( janela, dst );
    ind++;
  }

  
  return 0;
}



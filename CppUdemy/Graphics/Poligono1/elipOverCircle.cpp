// para compilar g++ demo.c -o demo -lgraph -lstdc++
/*
 * Approach:
 * The idea is to decrease the angle(through which ellipse is going to slide) by an integral value and calculating the corresponding angle swiped by the circles radius using the ratio of their perimeters
 *
 * How to show the sliding on screen:
 * 1. Draw the Ellipse at calculated point using white color
 * 2. Introduce some delay in funcion(in ms).
 * 3. Erase the previous Ellipse by drawing the Ellipse at same point
 *    using black color
 * 4. Repeat from step 1
 *
 */

// C++ program to draw an Ellipse rotating
// over a Circle using graphics

#include <conio.h>
//#include <curses.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
//#include <graphics.h>
#include <vector>

using namespace std;


// Ellipse drawing funcion
void drawEllipse (int xc, int yc, int a, int b, float alpha, int color){

  float t = 3.14 / 180;
  alpha = 360 - alpha;
  //setcolor(color);
  textcolor(color);
  int theta;

  // Filling each pixel corresponding to every angle from 0 to 360
  for (int i = 0; i < 360; ++i) {
    theta = i;
    int x = a * cos(t * theta) * cos(t * alpha)
      + b * sin(t * theta) * sin(t * alpha);

    int y = b * sin(t * theta) * cos(t * alpha)
      - a * cos(t * theta) * sin(t * alpha);

    putpixel(xc + x, yc - y, color);
  }

  // Function to calculated the position
  // of ellipse after each rotation
  void slidePattern(int xc, int yc, int r, int a,
		    int alpha, float p, int color)
  {
    setcolor(color);
    float t = 3.14 / 180;
    float t1, t2, d;
    float angle = (p * alpha);

    // Calculation for center of Ellipse
    t1 = cos(t * fmod(angle, 360));
    t2 = sin(t * fmod(angle, 360));
    t1 *= t1;
    t2 *= t2;
    t1 = t1 / (a * a);
    t2 = t2 / (b * b);
    d = sqrt(t1 + t2);
    d = 1 / d;

    int draw_x = xc + (r + d) * cos(t * alpha);
    int draw_y = yc - (r + d) * sin(t * alpha);
    int draw_ang = angle + alpha;

    drawEllipse(draw_x, draw_y, a, b, draw_ang, color);
    
  }

  // Funcion to increment the angle of rotation
  void ellipeovercircle(int xc, int yc, int r, int a, int b){
    float theta = 0;
    double h, p1;

    // Calculating the ratio of perimeters of Ellipse and Circle
    h = (a * a) + (b * b);
    h /= 2;
    p1 = sqrt(h);
    p1 /= r;
    p1 = 1 / (p1);

    // by decrasing theta we can move Ellipe clockwise
    for (;; theta -= 1) {
      // Draw Ellipse at new location using White color
      slidePattern(xc, yc, r, a, b, theta, p1, WHITE);

      circle(xc, yc, r); // Drawing Circle
      delay(25); // Introducing delay

      // Erase the existing Ellipe
      slidePattern(xc, yc, r, a, b, theta, p1, BLACK);
    }
  }

  // Driver code
  int main()
  {
    // Initialize graphics funcion
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // maximum X-coordinate for the window
    int maxx = getmaxx();

    // maximum Y-coordinate for the window
    int maxy = getmaxy();

    // Start drawing from the mid of the screen
    ellipeovercircle(maxx/2, maxy/2, 100, 40, 28);

    closegraph();
    return 0;
  }

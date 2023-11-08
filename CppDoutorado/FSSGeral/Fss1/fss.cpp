#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <malloc.h>


//------------------FOR TEST FUNCTIONS------------------
#include <string.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
//#include "cec20_test_func.cpp"
double *OShift,*M,*y,*z,*x_bound;
int ini_flag=0,n_flag,func_flag,*SS;

using namespace std; 

class FSS {
	private:
        int func;
        int interactions;
        int terms;
        int fish;
        int dim;
        double alp;
        double i_step;
        double f_step;
        double position_max;
        double position_min;
        double current_step;
        double weight_difference;
        double step_v;
        double* positions;
        double* new_positions;
        double* fitness;
        double* new_fitness;
        double* weight;
        double* vector_I;
        double* barycenter;
        double* mean_fish_fitness;
        double* best_fish_positions;
        double* fitness_difference;
        double* displacement;
	public:
		double* best_fish_fitness;
        FSS(int function, int n_interactions, int n_terms, int n_fish, int dimension, double alpha, double initial_step, double final_step, int x, double step_variation);
        void initialize();
        void individual_movement();
        void calculate_fitness(bool new_or_old_positions);
        void update_step();
        void direction_I();
        void collective_instinctive_movement();
        void feeding();
        void calculate_barycenter();
        void collective_volitive_movement();
        void best_and_mean();
};

FSS::FSS(int function, int n_interactions, int n_terms, int n_fish, int dimension, double alpha,
                    double initial_step, double final_step, int x, double step_variation){

	//----------Initializing Parameters----------
    func = function;
    interactions = n_interactions;
    terms = n_terms;
    fish = n_fish;
    dim = dimension;
    alp = alpha;
	i_step = initial_step;
    f_step = final_step;
    step_v = step_variation;

	//----------Defining min and max positions and current step----------
    position_max = 100;
    position_min = -100;
    current_step = (position_max-position_min)*i_step;

	//----------For Random----------
	srand (time(NULL));

	//----------Allocating Pointers----------
	positions = (double *)malloc(dim * fish * sizeof(double));
    new_positions = (double *)malloc(dim * fish * sizeof(double));
	fitness = (double *)malloc(fish * sizeof(double));
	new_fitness = (double *)malloc(fish * sizeof(double));
	weight = (double *)malloc(fish * sizeof(double));
    barycenter = (double *)malloc(dim * sizeof(double));
	best_fish_fitness = (double *)malloc(sizeof(double));
	mean_fish_fitness = (double *)malloc(sizeof(double));
    best_fish_positions = (double *)malloc(dim * sizeof(double));
    fitness_difference = (double *)malloc(fish * sizeof(double));
    displacement = (double *)malloc(dim * fish * sizeof(double));
    vector_I = (double *)malloc(dim * sizeof(double));


    void FSS::initialize(){
      for(int i=0;i<fish;i++){weight[i] = 1.0;}
      best_fish_fitness[0] = 9999999999999;
      mean_fish_fitness[0] = 9999999999999;
      double pos_ini;
      for(int i=0;i<(fish*dim);i++){
	pos_ini = ((double)(rand() % 100000)/100000);
	pos_ini *= (position_max-position_min);
	pos_ini += position_min;
	positions[i] = pos_ini;
      }
    }


    void FSS::individual_movement(){
      int current_fitness = true;
      calculate_fitness(current_fitness);
      double best_weight = weight[0];
      double worst_weight = weight[0];
      for(int i=0;i<fish;i++){
        if( weight[i] > best_weight){
	  best_weight = weight[i];
        }else if(weight[i] < worst_weight){
	  worst_weight = weight[i];
        }
      }    

      for(int i=0;i<(fish*dim);i++){
        double step_adjustment = current_step;
        if((best_weight - worst_weight) != 0){
	  step_adjustment = (step_v - (step_v*(weight[i] - worst_weight)/(best_weight - worst_weight)))*current_step;
        }  
        if(step_adjustment < (current_step/step_v)){
	  step_adjustment = current_step/step_v;
        }    
        double direction = (double) rand() / (RAND_MAX/2);
        direction -= 1;
        new_positions[i] = positions[i] + direction*step_adjustment;
        if(new_positions[i] > position_max){ new_positions[i] = position_max; }
        else if(new_positions[i] < position_min){ new_positions[i] = position_min; }
      }

      current_fitness = false;
      calculate_fitness(current_fitness);
	
      for(int i=0;i<fish;i++){
        if(new_fitness[i] <= fitness[i]){
	  fitness_difference[i] = -1*(new_fitness[i] - fitness[i]);
	  fitness[i] = new_fitness[i];
	  for(int j=0;j<dim;j++){
	    displacement[i*dim + j] = new_positions[i*dim + j] - positions[i*dim + j];
	    positions[i*dim + j] = new_positions[i*dim + j];
	  }
        }else{
	  fitness_difference[i] = 0;
	  for(int j=0;j<dim;j++){
	    displacement[i*dim + j] = 0;
	  }
        }
	void FSS::individual_movement(){
	  int current_fitness = true;
	  calculate_fitness(current_fitness);
	  double best_weight = weight[0];
	  double worst_weight = weight[0];
	  for(int i=0;i<fish;i++){
	    if( weight[i] > best_weight){
	      best_weight = weight[i];
	    }else if(weight[i] < worst_weight){
	      worst_weight = weight[i];
	    }
	  }    

	  for(int i=0;i<(fish*dim);i++){
	    double step_adjustment = current_step;
	    // if((worst_fitness - best_fitness) != 0){
	    //     step_adjustment = (step_v - (step_v*(worst_fitness - fitness[i])/(worst_fitness - best_fitness)))*current_step;
	    // }
	    if((best_weight - worst_weight) != 0){
	      step_adjustment = (step_v - (step_v*(weight[i] - worst_weight)/(best_weight - worst_weight)))*current_step;
	    }  
	    if(step_adjustment < (current_step/step_v)){
	      step_adjustment = current_step/step_v;
	    }    
	    double direction = (double) rand() / (RAND_MAX/2);
	    direction -= 1;
	    new_positions[i] = positions[i] + direction*step_adjustment;
	    if(new_positions[i] > position_max){ new_positions[i] = position_max; }
	    else if(new_positions[i] < position_min){ new_positions[i] = position_min; }
	  }

	  current_fitness = false;
	  calculate_fitness(current_fitness);
	  
	  for(int i=0;i<fish;i++){
	    if(new_fitness[i] <= fitness[i]){
	      fitness_difference[i] = -1*(new_fitness[i] - fitness[i]);
	      fitness[i] = new_fitness[i];
	      for(int j=0;j<dim;j++){
                displacement[i*dim + j] = new_positions[i*dim + j] - positions[i*dim + j];
                positions[i*dim + j] = new_positions[i*dim + j];
	      }
	    }else{
	      fitness_difference[i] = 0;
	      for(int j=0;j<dim;j++){
                displacement[i*dim + j] = 0;
	      }
	    }
	  }
	}
      }
    }

    void FSS::best_and_mean(){
      double avg = 0;
      for(int i=0;i<fish;i++){
        avg += fitness[i];
        if(fitness[i] < best_fish_fitness[0]){
	  best_fish_fitness[0] = fitness[i];
	  for(int j=0;j<dim;j++){
	    best_fish_positions[j] = positions[i*dim + j];
	  }
        }
      }
      mean_fish_fitness[0] = avg/fish;
    }


    void FSS::calculate_fitness(bool new_or_old_positions){
      if(new_or_old_positions){
        cec20_test_func(positions, fitness, dim, fish, func);
        // for(int i=0;i<fish;i++){
        //     fitness[i] = 0.0;
        //     for(int j=0;j<dim;j++){
        //         fitness[i] += pow(positions[i*dim + j],2);
        //     }
        // }
      }else{
        cec20_test_func(new_positions, new_fitness, dim, fish, func);
        // for(int i=0;i<fish;i++){
        //     new_fitness[i] = 0.0;
        //     for(int j=0;j<dim;j++){
        //         new_fitness[i] += pow(new_positions[i*dim + j],2);
        //     }
        // }
      }
    }

    
    //int main() { 
 
 
    //return 0; 
} 

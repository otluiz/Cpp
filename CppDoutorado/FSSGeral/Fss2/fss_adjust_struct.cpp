/*
 * Nova versão do FSS, agora com ajustes no baricentro e operador de alimentação
 *
 */

#include <iostream>
#include <cmath>
#include <random>

const int populationSize = 100;  // size of the fish population
const int numberOfIterations = 1000; // number of iterations
const int numberOfDimensions = 10; // number of dimensions of the problem

struct Fish {
    double weight;
    double position[numberOfDimensions];
    double fitness;
};

// Sphere function
double objectiveFunction(const double x[], int n)
{
    // calculate the objective function
    double result = 0.0;
    for (int i = 0; i < n; i++)
        result += x[i] * x[i];
    return result;
}

void initializeSchool(Fish school[], double barycenter[])
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_real_distribution<double> distribution(-100.0, 100.0);

    /*
     * U   0+niformly distributed random numbers within a specified range
     */
    for (int i = 0; i < populationSize; i++)
    {
       // weight inicialily
      school[i].weight = 1.0;
      for (int j = 0; j < numberOfDimensions; j++)
	school[i].position[j] = distribution(engine);

        school[i].fitness = objectiveFunction(school[i].position, numberOfDimensions);
    }

    // Calculate the initial barycenter
    for (int j = 0; j < numberOfDimensions; j++)
    {
        barycenter[j] = 0.0;
        for (int i = 0; i < populationSize; i++)
            barycenter[j] += school[i].position[j] * school[i].weight;
        barycenter[j] /= populationSize;
    }
}

void feedingOperator(Fish school[], std::mt19937& engine)
{
    for (int i = 0; i < populationSize; i++)
    {
        double step = (distribution(engine) * 0.01) * (school[i].fitness - 1.0);
        for (int j = 0; j < numberOfDimensions; j++)
            school[i].position[j] += step;
        school[i].fitness = objectiveFunction(school[i].position, numberOfDimensions);
    }
}

void swimmingOperator(Fish school[], std::mt19937& engine, double barycenter[])
{
    for (int i = 0; i < populationSize; i++)
    {
        double step = (distribution(engine) * 0.01) * (school[i].fitness - 1.0);
        for (int j = 0; j < numberOfDimensions; j++)
        {
            double distanceToBarycenter = fabs(school[i].position[j] - barycenter[j]);
            double deltaPosition = distribution(engine) * distanceToBarycenter;
            school[i].position[j] += deltaPosition * step;
        }
        school[i].fitness = objectiveFunction(school[i].position, numberOfDimensions);
    }
}

int main()
{
    Fish school[populationSize];
    double barycenter[numberOfDimensions];
    std::random_device rd;
    std::mt19937 engine(rd());

    // Initialize the fish population
    initializeSchool(school, barycenter);

    // Main loop of Fish School Search
    for (int t = 0; t < numberOfIterations; t++)
    {
        // Feeding operator
        feedingOperator(school, engine);

        // Calculate the barycenter
        for (int j = 0; j < numberOfDimensions; j++)
        {
            barycenter[j] = 0.0;
           

#include <assert.h>
#include <math.h>
#include "uwnet.h"

// Run an activation function on each element in a matrix,
// modifies the matrix in place
// matrix m: Input to activation function
// ACTIVATION a: function to run
void activate_matrix(matrix m, ACTIVATION a)
{
    int i, j;
    for(i = 0; i < m.rows; ++i){
        double sum = 0;
        for(j = 0; j < m.cols; ++j){
            double x = m.data[i*m.cols + j];
            float x2 = 0.0;
            if(a == LOGISTIC){
                x2 = x*(1-x);
            } else if (a == RELU){
                x2 = max(0.0, x);
            } else if (a == LRELU){
                x2 = max(0.0, x);
            } else if (a == SOFTMAX){
                x2 = exp(-x)*exp(1-x);
            }
            sum += m.data[i*m.cols + j];

        }
        if (a == SOFTMAX) {

        }
        m.data[i*m.cos+j] = x2;
    }
}

// Calculates the gradient of an activation function and multiplies it into
// the delta for a layer
// matrix m: an activated layer output
// ACTIVATION a: activation function for a layer
// matrix d: delta before activation gradient
void gradient_matrix(matrix m, ACTIVATION a, matrix d)
{
    int i, j;
    for(i = 0; i < m.rows; ++i){
        for(j = 0; j < m.cols; ++j){
            double x = m.data[i*m.cols + j];
            m.data[i*m.cols+j] = d.data[((i==0)?i:(i-1))*m.cols+j)]-d.data[(i)*m.cols+j)];
            activate_matrix(m, a);
        }
    }
}

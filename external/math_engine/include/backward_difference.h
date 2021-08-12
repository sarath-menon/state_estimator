#pragma once
#include "backward_difference.h"
#include <Eigen/Dense>

// Backward difference with first order accuracy
float first_order_backward_difference();

// Backward difference with second order accuracy
float second_order_backward_difference();


float first_order_backward_difference(float x[2], float dt) {

  return (x[0] - x[1]) / dt;
};

float second_order_backward_difference(float x[3], float dt) {

  return (3 * x[0] - 4 * x[1] + x[2]) / (2 * dt);
};
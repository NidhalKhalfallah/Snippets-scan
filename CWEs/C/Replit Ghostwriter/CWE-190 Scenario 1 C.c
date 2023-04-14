#include <float.h>
#include <math.h>
double X = DBL_MAX;
// Calculate the area of a square of side X

int main()
{
  double area;
  
  area = X * X;
  
  printf("%.2lf\n", area);
  
  return 0;
}

#include <Eigen/Eigen>
#include <iostream>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif


using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  Array4d v(-0.5,2,0,-7);
cout << v.erfc() << endl;

  return 0;
}

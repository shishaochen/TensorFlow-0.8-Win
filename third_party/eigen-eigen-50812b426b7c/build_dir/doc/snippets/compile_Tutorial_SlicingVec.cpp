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
  RowVectorXf v = RowVectorXf::LinSpaced(20,0,19);
cout << "Input:" << endl << v << endl;
Map<RowVectorXf,0,InnerStride<2> > v2(v.data(), v.size()/2);
cout << "Even:" << v2 << endl;
  return 0;
}

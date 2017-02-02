#include <iostream>
#include <fstream>
#include <cmath>
#include <Eigen/Dense>

//this algorithm solves the potential equation using a simple multigrid method

using namespace std;

double restrict(int j, int l) { 
}

double prolong() {
}

int main() {

  int N = 5;
  int S = pow(2,N);

  Eigen::MatrixXd u(S,S);
  for (int j=0; j<S; j++) {
    for (int l=0; l<S; l++) {
      u(j,l) = 0;
    }
  }

  Eigen::Matrix3f Lh;
  Lh << 0,  1, 0,
       1, -4, 1,
       0,  1, 0;

  Eigen::Matrix3f P;
  P << 1/4., 1/2., 1/4.,
       1/4.,    1, 1/4.,
       1/4., 1/2., 1/4.;

  Eigen::Matrix3f R;
  R << 1/16., 1/8., 1/16.,
        1/8., 1/4.,  1/8.,
       1/16., 1/8., 1/16.;

  Eigen::MatrixXd d(S,S);
  for (int j=0; j<S; j++) {
    for (int l=0; l<S; l++) {
      d(j,l) = -4*u(j,l);
      if (j == 0) d(j,l) += u(j,l);
      else d(j,l) += u(j-1,l);
      if (j == S-1) d(j,l) += u(j,l);
      else d(j,l) += u(j+1,l);
      if (l == 0) d(j,l) += u(j,l);
      else d(j,l) += u(j,l-1);
      if (l == S-1) d(j,l) += u(j,l);
      else d(j,l) += u(j,l+1);
    }
  }

  int s = S/2.;
  int j,l;

  cout << s << endl;

  Eigen::MatrixXd dH(s,s);
  for (int J=0; J<s; J++) {
    j = 2*J;
    for (int L=0; L<s; L++) {
      l = 2*L;

      cout << J << "\t" << j << "\t\t" << L << "\t" << l << endl;

      if (J == 0) {
	if (L == 0) {
	  dH(J,L) = R(0,0)*d(j,l+1) + R(1,0)*d(j,l+1) + R(2,0)*d(j+1,l+1)
	          + R(0,1)*d(j,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j+1,l)
	          + R(0,2)*d(j,l)   + R(1,2)*d(j,l)   + R(2,2)*d(j+1,l);
	} else if (L == s-1) {
	  dH(J,L) = R(0,0)*d(j,l)   + R(1,0)*d(j,l)   + R(2,0)*d(j+1,l)
	          + R(0,1)*d(j,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j+1,l)
	          + R(0,2)*d(j,l-1) + R(1,2)*d(j,l-1) + R(2,2)*d(j+1,l-1);
	} else {
	  dH(J,L) = R(0,0)*d(j,l+1) + R(1,0)*d(j,l+1) + R(2,0)*d(j+1,l+1)
	          + R(0,1)*d(j,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j+1,l)
	          + R(0,2)*d(j,l-1) + R(1,2)*d(j,l-1) + R(2,2)*d(j+1,l-1);
	}
      } else if (J == s-1) {
	if (L == 0) {
	  dH(J,L) = R(0,0)*d(j-1,l+1) + R(1,0)*d(j,l+1) + R(2,0)*d(j,l+1)
   	          + R(0,1)*d(j-1,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j,l)
	          + R(0,2)*d(j-1,l)   + R(1,2)*d(j,l)   + R(2,2)*d(j,l);
	} else if (L == s-1) {
	  dH(J,L) = R(0,0)*d(j-1,l)   + R(1,0)*d(j,l)   + R(2,0)*d(j,l)
	          + R(0,1)*d(j-1,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j,l)
	          + R(0,2)*d(j-1,l-1) + R(1,2)*d(j,l-1) + R(2,2)*d(j,l-1);
	} else {
	  dH(J,L) = R(0,0)*d(j-1,l+1) + R(1,0)*d(j,l+1) + R(2,0)*d(j,l+1)
	          + R(0,1)*d(j-1,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j,l)
	          + R(0,2)*d(j-1,l-1) + R(1,2)*d(j,l-1) + R(2,2)*d(j,l-1);
	}
      } else {
	if (L == 0) {
	  dH(J,L) = R(0,0)*d(j-1,l+1) + R(1,0)*d(j,l+1) + R(2,0)*d(j+1,l+1)
	          + R(0,1)*d(j-1,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j+1,l)
	          + R(0,2)*d(j-1,l)   + R(1,2)*d(j,l)   + R(2,2)*d(j+1,l);
	} else if (L == s-1) {
	  dH(J,L) = R(0,0)*d(j-1,l)   + R(1,0)*d(j,l)   + R(2,0)*d(j+1,l)
	          + R(0,1)*d(j-1,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j+1,l)
	          + R(0,2)*d(j-1,l-1) + R(1,2)*d(j,l-1) + R(2,2)*d(j+1,l-1);
	} else {
	  dH(J,L) = R(0,0)*d(j-1,l+1) + R(1,0)*d(j,l+1) + R(2,0)*d(j+1,l+1)
	          + R(0,1)*d(j-1,l)   + R(1,1)*d(j,l)   + R(2,1)*d(j+1,l)
	          + R(0,2)*d(j-1,l-1) + R(1,2)*d(j,l-1) + R(2,2)*d(j+1,l-1);
	}
      }
    }
  }

  cout << "mark" << endl;
 
  Eigen::MatrixXd vH(s,s);
  //calculate vH, or nest more grids

  Eigen::MatrixXd v(S,S);
  float J,L,K,M;
  for(int j=0; j<S; j++) {
    J = j/2.;
    K = J-0.5;
    for(int l=0; l<S; l++) {
      L = l/2.;
      M = L-0.5;
     
      if ((j%2 == 0) && (l%2 == 0)) {
	v(j,l) = P(1,1)*vH(J,L);
      } else if ((j%2 != 0) && (l%2 != 0)) {
	v(j,l) = P(0,0)*vH(K,M) + P(2,0)*vH(K+1,M+1) + P(0,2)*vH(K,M+1) + P(2,2)*vH(K+1,M);
      } else if ((j%2 == 0) && (l%2 != 0)) {
	v(j,l) = P(1,0)*vH(J,M+1) + P(1,2)*vH(J,M);
      } else if ((j%2 != 0) && (l%2 == 0)) {
	v(j,l) = P(0,1)*vH(K,L) + P(2,1)*vH(K+1,L);
      }
    }
  }
  
  for (int j=0; j<S; j++) {
    for (int l=0; l<S; l++) {
      u(j,l) -= v(j,l);
    }
  }

  return 0;

}

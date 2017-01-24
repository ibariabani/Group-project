#include "Analytical2.h"

using namespace std;

void Analytical2(double& a, double& V0, double& d)
{
  double V = 0, x = 0, y = 0, r = 0, theta = 0;
  
  ofstream file;
  file.open("Analytical2.dat");

  for (x = -d/2; x <= d/2; x = x+0.01)
    {
            
      for (y = -d/2; y <= d/2; y = y+0.01)
	{
	  r = sqrt(pow(x,2)+pow(y,2));

	  if (x == 0)
	    {
	      V = V0;
	    }
	  
	  else if (x == d)
	    {
	      V = V0;
	    }

	  else if (a > r)
	    {
	      V = 0;
	    }
	  
	  else
	    {
	      V = -(V0)*(x/r)*(r - (pow(a,3)/pow(r,2)));
	      
	      file << x << "    " << y << "    " << V << endl;
	    }
	}
      file << "\n";
    }
  
  file.close();
  
}
  

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
  double x, y, V, b = 3, r, d = 1, theta, R = 0.5, V_0;
  
  cout << "Enter V_0:" << endl;
  cin >> V_0;
  
  ofstream file;
  file.open("Analytical2.dat");

  for (x = -1; x <= 1; x = x+0.01)
    {
            
      for (y = -1; y <= 1; y = y+0.01)
	{
	  r = sqrt(pow(x,2)+pow(y,2));
	 
	  if (x == 0)
	    {
	      V = V_0;
	    }
	
	  else if (x == 1)
	    {
	      V = V_0;
	    }

	  else if (R > r)
	    {
	      V = 0;
	    }
	  
	  else
	    {
	      V = -(V_0)*(x/r)*(r - (pow(R,3)/pow(r,2)));
	      
	      file << x << "    " << y << "    " << V << endl;
	    }
	}
      file << "\n";
    }
  
  file.close();
  
  return 0;
}
  

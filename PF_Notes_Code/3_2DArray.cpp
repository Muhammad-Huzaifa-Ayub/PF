#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   string timing[3] = {"Morning", "Noon", "Evening"};
   
   string city[6] = {"Multan","Layya","Kasur","Lahore","DG Khan","Gujrat"};
   
   float temp[3][6] = {
                        {34.4f, 54.3f, 65.6f, 34.4f, 43.2f, 55.6f},
                        {53.6f, 23.3f, 54.9f, 49.0f, 38.5f, 34.6f},
                        {35.2f, 54.4f, 40.4f, 54.6f, 76.3f, 65.2f}
                      };
   

   int j, k;

   // dumping temps
	cout << setw(10) << left << "Timing";
   
   j=0;
   while(j<6)
   {
      cout << setw(10) << right << city[j];
      j+=1;
   }
   cout << endl;
   
   j=0;
   while(j<3)
   {
         cout << setw(10) << left << timing[j];
         k=0;
         while(k<6)
         {
				cout << setw(10) << fixed << setprecision(2) << right << temp[j][k];
            k+=1;
         }
         j+=1;
         cout << endl;
   }

  
   // computation for average of DG Khan
   float dgkavg = 0.0f;
   j=0;
   while(j<3)
   {
         dgkavg += temp[j][4];
         j+=1;
   }
   dgkavg /= 3.0f;
   
   // computation for total of Noon
   float noontot = 0.0f;
   j=0;
   while(j<6)
   {
         noontot += temp[1][j];
         j+=1;
   }

   // computation for max of cities
   float mxtm[6];
   j=0;
   while(j<6)
   {
         mxtm[j] = temp[0][j];
         k=1;
         while(k<3)
         {
            if(temp[k][j] > mxtm[j])
            {
               mxtm[j] = temp[k][j];
            }
            k+=1;
         }
         j+=1;
   }
   
	// dumping statistics
   cout << endl << endl;
	cout << "Average for DG Khan " << fixed << setprecision(2) << dgkavg << endl;
	cout << "Total at noon " << fixed << setprecision(2) << noontot << endl ;
   cout << endl;
	cout << "  Max for cities" << endl ;
	cout << "==================" << endl ;
	cout << setw(10) << left << "City" << setw(8) << right << "Max" << endl;
	cout << "--------- --------" << endl;
   j=0;
   while(j<6)
   {
		cout << setw(10) << left << city[j] << setw(8) << right << mxtm[j] << endl;
      j+=1;
   }
}

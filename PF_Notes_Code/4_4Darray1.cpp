/* Consider a four dimensional array contains the percentage 
   marks for students
		first dimension is for program no (0,1,2 and 3)
		second dimension is for semester no (0,1,2,3,4,5,6 and 7)
		third  dimension is for subject no (0,1,2,3,4 and 5)
		fourth dimension is for student no (0,1,2,3,4,...,49)

   Write a function to compute and display the program wise average
   Write a function to compute and display the semester wise average
   Write a function to compute and display the subject wise average
   Write a function to compute and display the program (passed as parameter) + semester wise average
   Write a function to compute and display the result of student of a program, both passed as parameters
	Write some functions of your own choice
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int randmarks()
{
   int rv = rand()%70+40;
	return rv > 100 ? 100 - rand()%5 : rv ;
}

// Solution problem 3
// Write a function to compute and display the subject wise average
void SubWiseAvg(short int m[4][8][6][50])
{
	int swsum[6];
	for(int sub=0; sub<6; sub++)
	{
		swsum[sub] = 0;
		for(int prog=0; prog<4; prog++)
		{
			for(int sem=0; sem<8; sem++)
			{
				for(int stud=0; stud<50; stud++)
				{
					swsum[sub] += m[prog][sem][sub][stud];
				}
			}
			
		}
	}
	cout << "Subject Wise Average" << endl;
	for(int sub=0; sub<6; sub++)
	{
		cout << "Sub" << sub << " " << double(swsum[sub])/4.0/8.0/50.0 << endl;
	}
}

// Function for following task
// Write a function to compute and display the program 
// (passed as parameter) + semester wise average
void SemWiseAvg4Prog(short int m[4][8][6][50], int prog)
{
	
}

// Following is code to populate the array with 
// suitable random values and diplay them.
int main()
{
   short int data[4][8][6][50] ;

   int v,w,x,y;

	
	// input data with random marks
   v=0;
   while(v<4)
   {
      w=0;
      while(w<8)
      {
         x=0;
         while(x<6)
         {
            y=0;
            while(y<50)
            {
               data[v][w][x][y] = randmarks();
               y+=1;
            }
            x+=1;
         }
         w+=1;
      }
      v+=1;
   }

	SubWiseAvg(data);
	
	
	
	// Style 1: output data with random marks
	ofstream ofl;
	ofl.open("marks1.txt");
   v=0;
   while(v<4)
   {
      ofl << "Program " << v << endl;
		w=0;
      while(w<8)
      {
         ofl << "\tSemester " << w << endl;
			x=0;
         while(x<6)
         {
            ofl << "\t\tSubject " << x << endl;
				y=0;
            while(y<50)
            {
               ofl << "\t\t\tStudent " << y;
					ofl << " marks " << data[v][w][x][y] << endl;
               y+=1;
            }
            x+=1;
         }
         w+=1;
      }
      v+=1;
   }
	ofl.close();
	
	// Style 2: output data with random marks
	ofl.open("marks2.txt");
   v=0;
   while(v<4)
   {
      ofl << "Program " << v << endl;
		w=0;
      while(w<8)
      {
         ofl << "\tSemester " << w << endl;
			ofl << "\t\t" << setw(12) << left << "Student No.";

			x=0;
			while(x<6)
         {
            ofl << "Sub" << setw(3) << left << x;
				x+=1;
			}
			ofl << endl;
			y=0;
         while(y<50)
         {
				x=0;
				ofl << "\t\t" << setw(8) << left << "Student";
				ofl << setw(4) << left << y;
				while(x<6)
				{
					ofl << setw(4) << right << data[v][w][x][y] << "  ";
					x+=1;
				}
				ofl << endl;
            y+=1;
         }
         w+=1;
      }
      v+=1;
   }
	ofl.close();
	
	system("marks1.txt");
	system("marks2.txt");

	return 0;
}

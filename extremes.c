/* By Gregory Macri
   Programming Assignment 2

   In this program a .gra file is read in as input from the command line and is
opened. Then the program searches the file for the northernmost, southernmost, 
westernmost, and easternmost waypoints in the file and then prints the waypointname and coordinates to the screen. 
*/

#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
  FILE *source; //A file pointer
  source = fopen(argv[1],"r"); //A file from the input is opened

  char east[256];//Character strings to hold the names of the waypoints
  char south[256];//
  char north[256];//
  char west[256];//

  char tempLocation[256];//String to temporarily hold a waypoint name
  double tempLat, tempLong;//Doubles to temporarily hold two coordinates
  double extremesLat[4] = {-90.0,91.0,0.0,0.0};//Array to store latitude
  double extremesLong[4] = {0.0,0.0,-181.0,181.0};//Array to store longitude
  
  int i, rows, trash;

  fscanf(source,"%d \n",&rows);//Reads and stores number of lines in the file
  fscanf(source,"%d",&trash);//Used to read in a trash int from first line

  /* This loop goes line by line through the input file
     and reads in each line of input and stores the waypoint
     name and the two coordinates
  */
  for(i = 0; i < rows; ++i)
  {
    fscanf(source,"%s",tempLocation);//Gets waypoint name
    fscanf(source,"%lf",&tempLat);//Gets latitude
    fscanf(source,"%lf",&tempLong);//Gets longitude
    
    if(tempLat > extremesLat[0])//If input latitude is greater than stored lat 
    {
      strcpy(north,tempLocation);//Store the name in the north string
      extremesLat[0] = tempLat;//Store the input latitude in the array 
      extremesLong[0] = tempLong;//Store the input longitude in the array
    }
    else if(tempLat < extremesLat[1])//If input latitude is less than stored
    {
      strcpy(south,tempLocation);
      extremesLat[1] = tempLat;
      extremesLong[1] = tempLong;
    }
    
    if(tempLong > extremesLong[2])//If input longitude is greater than stored
    {
      strcpy(east,tempLocation);
      extremesLat[2] = tempLat;
      extremesLong[2] = tempLong;
    }
    else if(tempLong < extremesLong[3])//If input longitude is less than stored
    {
      strcpy(west,tempLocation);
      extremesLat[3] = tempLat;
      extremesLong[3] = tempLong;
    }

  }

  //Print the stored waypoint names and coordinates to the screen
  printf("Northernmost is %s at (%lf,%lf)\n",north,extremesLat[0],extremesLong[0]);
  printf("Southernmost is %s at (%lf,%lf)\n",south,extremesLat[1],extremesLong[1]);
  printf("Easternmost is %s at (%lf,%lf)\n",east, extremesLat[2],extremesLong[2]);
  printf("Westernmost is %s at (%lf,%lf)\n",west, extremesLat[3],extremesLong[3]);

  fclose(source);//Close the file
  

  return 0;
}

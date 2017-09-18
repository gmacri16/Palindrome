/*Gregory Macri

This program reads in the words dictionary and stores only lowercase non-numeric words into an array and then finds all palindromic words.
*/

#include <stdio.h>
#include <string.h>
#include "timer.h"

int lowerc(char w[]);//lowerc prototype method
void reverse(char rev[], char temp[]);//reverse prototype method

char words[355536][50];//Global array strings to store words

int main(int argc, char *argv[])
{
  char tempWord[50];//Stores a word temporarily while being verified
  char revWord[50];//Stores reverse of a word
  char alph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//Used with index
  int index[27];//Stores line numbers where different letters start
  int i,j,t,retval,count;//Creates loop int variables 
  struct timeval start;//Stores first time
  struct timeval stop;//Stores second time
  FILE *source;//Holds file from input
  source = fopen(argv[1],"r");//Opens file from input
  j = 0;
  t = 1;
  index[0]= 0;//First line number in index 
  index[26]=355536;//Last line number in index
  count = 0;
  //Goes through the entire dictionary 
  for(i = 0; i < 479623; ++i)
  {
      fscanf(source,"%s", tempWord);//Reads the word into the tempWord array
      retval = lowerc(tempWord);//Checks if word is all lowercase 

      if(retval == 1)//If word lowercase
      {
	//If word doesnt start with same letter
	if(tempWord[0] != words[j - 1][0] && j != 0)
	{
	  index[t] = j;//Store line number
	  ++t;//Move to next spot in index array
	}
	strcpy(words[j],tempWord);//Copy the word into words array
	++j;//Increase index for word array
      }
  }

  gettimeofday(&start, NULL);//Gets start time

  for(i = 0; i < 355536; ++i)//Goes through word array
  {
    reverse(words[i],revWord);//Reverse word and store in revWord
    for(t = 0; t < 26; ++t)
    {
      if(revWord[0] == alph[t])//If first character in revword same as alph c
	break;//Leave loop
    }
    for(j = index[t]; j < index[t + 1]; ++j)//Range of first letter in revWord
    {
      retval = strcmp(revWord,words[j]);//Compare words  
      if(retval == 0)//If a word matches
      {
	++count;//Increase count
	break;//Stop searching for this word
      }
    }
  }

  gettimeofday(&stop, NULL);//Gets end time
  
  //Prints difference of both times to the screen
  printf("Time Elapsed: %f seconds\n", diffgettime(start,stop));
  //Prints number of palindroms to the screen
  printf("Number of palindroms is %d\n", count);

  return 0;
}

//Checks to see if all characters in a string are lowercase letters only
int lowerc(char w[])
{
  int i = 0;
  //Goes through the string until it encounters non-lowercase character
  while(w[i] >= 'a' && w[i] <= 'z')
  {
    ++i;
  }

  if(w[i] == '\0')//If the non lowercase letter is null
    return 1;
  else
    return 0;
}

/*Takes in a word and reverses it while storing it in another string*/
void reverse(char w[],char temp[])
{
  int i,j,count;
  i = 0;
  while(w[i] != '\0')//Goes through string to get count
  {
    ++i;
  }
  count = i - 1;//Stores the position of the last non-null terminated char
  for(j = 0; j < i; ++j)//Puts the characters in the temp string in opposite 
  {
    temp[j] = w[count];
    --count;
  }
  temp[i] = '\0';//Puts null character at end of reversed string
}

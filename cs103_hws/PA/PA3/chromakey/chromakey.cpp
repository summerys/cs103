/*********************************************************************
 File: chromakey.cpp

 Author:  Summer Yeonhee Seo 

 Email address: summerys@usc.edu

 Usage: program_name in.bmp background.bmp dist_threshold out1.bmp out2.bmp

 Notes:

 This program performs the chroma key operation on an input 
 using two different methods.

 Method 1 Utilize a user-defined distance threshold from the
          chromakey value as a discriminator

 Method 2 Devise a method that to determine the chromakey mask
          that doesn't require a user-input threshold

********************************************************************/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmplib.h"

using namespace std;

// Prototypes
void method1(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE],
	     double threshold);

void method2(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE]);

void replace(bool mask[][SIZE],
	     unsigned char inImage[][SIZE][RGB],
	     unsigned char bgImage[][SIZE][RGB],
	     unsigned char outImage[][SIZE][RGB]);

int main(int argc, char *argv[])
{
  // Image data array
  static unsigned char inputImage[SIZE][SIZE][RGB];
  static unsigned char bgrndImage[SIZE][SIZE][RGB];
  static unsigned char outputImage[SIZE][SIZE][RGB];
  static bool chromaMask[SIZE][SIZE];

  double threshold;

  if (argc < 6) {
    cerr << "usage: program_name in.bmp background.bmp dist_threshold " 
         << "out1.bmp out2.bmp" << endl;
    return 0;
  }
	
  if (readRGBBMP(argv[1], inputImage)) {
    cerr << "Error reading file: " << argv[1] << endl;
    return 1;
  }

  if (readRGBBMP(argv[2], bgrndImage)) {
    cout << "Error reading file: " << argv[2] << endl;
    return 1;
  }
  
  //convert the threshold (argv[3]) from string format to a double and assign the 'threshold'
  threshold = atof(argv[3]);

  // Call Method 1 Function
  method1(inputImage,chromaMask,threshold);

  // Produce the output by calling replace()
  replace(chromaMask,inputImage,bgrndImage,outputImage);

  // Write the output image to a file using the filename argv[4]
  if (writeRGBBMP(argv[4], outputImage))  
  {
    cout << "Error writing file: " << argv[4] << endl;
    exit(1);
  }//if

  // Call Method 2 Function
  method2(inputImage,chromaMask); 

  // Produce the output by calling replace()
  replace(chromaMask,inputImage,bgrndImage,outputImage);

  // Write the output image to a file using the filename argv[5]
  if (writeRGBBMP(argv[5],outputImage)) {
    cout << "Error writing file: " << argv[5] << endl;
    exit(1);
  }	//if

  return 0;
}//main


/*===========================================================================

Method1 
:It is a function that creats mask array by comparing the user-provided 
threshold for chroma-key distance to the computed distance. 

Outcome:
If distance < threshold : mask = 0 (background)
If distance > threshold : mask = 1 (foreground)

=============================================================================*/

void method1(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE],
	     double threshold)

{
    /*------------------------------------------------------------------------

    Three for-loops of different parts of green backgrounds that overlaps
    of three images: stro.bmp, bird_gs.bmp and colbert_gs.bmp
    
    Purpose: to get the redSum, greenSum, blueSum that are needed to calculate 
    average red, green and blue sums. 

    -------------------------------------------------------------------------*/

    int redSum = 0;
    int greenSum = 0;
    int blueSum = 0;

    for(int i=0; i<65; i++)
    {
      for(int j=53; j<134; j++)
      {
        redSum += inImage[i][j][0];
        greenSum += inImage [i][j][1];
        blueSum += inImage [i][j][2];
      }//for
    }//for

    for(int i=216; i<255; i++)
    {
      for(int j=139; j<255; j++)
      {
        redSum += inImage[i][j][0];
        greenSum += inImage [i][j][1];
        blueSum += inImage [i][j][2];
      }//for
    }//for

    for(int i=0; i<50; i++)
    {
      for(int j=186; j<255; j++)
      {
        redSum += inImage[i][j][0];
        greenSum += inImage [i][j][1];
        blueSum += inImage [i][j][2];
      }//for
    }//for

    // Find average RGB by dividing total sum to number of pixels used

    int averageRedSum = redSum / 13174;
    int averageGreenSum = greenSum / 13174;
    int averageBlueSum = blueSum / 13174;
 
    /*--------------------------------------------------------------

    Double for-loops to assign '0' or '1' to mask array. 

    # Using for-loop that goes pixel by pixel of an entire image, 
      for each pixel, distance is calculated and compared to threshold. 

    # Distance : sqrt[(r1-r2)^2+(g1-g2)^2+(b1-b2)^2]

     ---------------------------------------------------------------*/   

  for(int i = 0; i < 255; i++)
  {
    for(int j = 0; j < 255; j++)
    {
      double distance = sqrt( pow( (inImage[i][j][0]-averageRedSum), 2 ) + 
        pow( (inImage[i][j][1]-averageGreenSum),2 ) + pow( (inImage[i][j][2]-averageBlueSum),2 ) );
      if(distance < threshold)
      {
        mask[i][j] = 0;
      }
      else
      {
        mask[i][j] = 1;
      }
    }//for 
  }//for

}//void



/*===========================================================================

Method2
:It is a function that creats mask array by comparing the computed distance
(between each pixels of RGB to pure green (0,255,0))
to the automatically calculated threshold.(instead of user-input threshold)

Outcome:
If distance < threshold : mask = 0 (background)
If distance > threshold : mask = 1 (foreground)


=============================================================================*/

void method2(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE])  
{
  /*------------------------------------------------------------------------

  for-loop that visits every single pixels to get the sum & average RGB values.
  And then compute threshold by using distance formula. 

  #Threshold = distance between average RGV value to pure green (0,255,0)
                and multiply scale factor of 1.059 

  -------------------------------------------------------------------------*/

    //Assigning integers of redSum, greenSum and blue Sum 

    int redSum = 0;
    int greenSum = 0;
    int blueSum = 0;

   // for loop that visits every single pixels of the image.
   // in each pixel, for loop gets the value of R, G, B and by multiplying
   // of each values, get sum of R, G, and B 

    for(int i = 0; i < 255; i++)
    {
      for(int j = 0; j < 255; j++)
      {
        redSum += inImage[i][j][0];
        greenSum += inImage [i][j][1];
        blueSum += inImage [i][j][2];
      }//for
    }//for

    //find the average R, G, B values of the the image dividing by 
    //entire pixels of image: 255 * 255

    int averageRedSum = redSum / 65025;
    int averageGreenSum = greenSum / 65025;
    int averageBlueSum = blueSum / 65025;

    //Calculating threshold using distance formula. 
    //comparing distance between average RGB value to pure green (0,255,0)
    //multiplying by scale factor of 1.059 (found the best value after trying 
    //multiple different values.  

    double threshold = 1.059*(sqrt( pow( (averageRedSum-0),2 )+pow( (averageGreenSum-255), 2 ) + pow( (averageBlueSum-0), 2) ));

    //for loop that visits each pixels and compare the threshold we computed above
    //to distance of each pixels (distance between each pixel's RGB to pure green (0,255,0)) 
    //and within for-loop, using if / else statement to assign mask array, either 0 or 1.
    //if distance < threshold, mask = 0, background
    //if distance > threshold, mask = 1, foreground 
      
    for(int i = 0; i < 255; i++)
    {
      for(int j = 0; j < 255; j++)
      {
        double distance = sqrt( pow( (inImage[i][j][0]-0), 2 ) + pow( (inImage[i][j][1]-255),2 ) + pow( (inImage[i][j][2]-0),2 ) );
        if(distance < threshold)
        {
          mask[i][j] = 0;
        }
        else
        {
          mask[i][j] = 1;
        }
      }//for 
    }//for

}//void


/*===========================================================================

Replace 
:Produce the output image using the mask array. 

If mask = 1 : input image pixel for the final output image
If mask = 0 : background image picxels for final output image. 

=============================================================================*/

void replace(
      bool mask[SIZE][SIZE],
	    unsigned char inImage[SIZE][SIZE][RGB],
	    unsigned char bgImage[SIZE][SIZE][RGB],
	    unsigned char outImage[SIZE][SIZE][RGB])
{

  /*------------------------------------------------------------------------

  Create the output image using the mask to determine
  whether to use the pixel from the Input or Background image

  -------------------------------------------------------------------------*/
   
  for(int i=0; i<255; i++)
  {
    for(int j=0; j<255; j++)
    { 
      if(mask[i][j] == 1)
      {
        outImage[i][j][0] = inImage[i][j][0];
        outImage[i][j][1] = inImage[i][j][1];
        outImage[i][j][2] = inImage[i][j][2];

      }//if
      else
      {
        outImage[i][j][0] = bgImage[i][j][0];
        outImage[i][j][1] = bgImage[i][j][1];
        outImage[i][j][2] = bgImage[i][j][2];
      }//else
    }//for
  }//for

}//void

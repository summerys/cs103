CSCI 103 Programming Assignment 2, Chroma Key, Fall 2014

Name:Summer Yeonhee Seo 

Email Address: summerys@usc.edu

NOTE: You can delete the questions, we only need your responses.

=============================== Prelab =======================================

Pixel                |    RGB Value     |  Distance from Chroma Key
-------------------------------------------------------------------
Top-left background  | ( 69, 138, 19   )  |  n/a
Arm                  | ( 254, 162, 111 )  |  208.00
Vest                 | ( 26,  31, 27   )  |  115.58
Shirt                | ( 253, 218, 250 )  |  305.96

================================== Review ===================================

Response 1:

[0,53] to [65,134]
[216 to 139] to [255,255]
[0, 186] to [50, 255]

If I choose more pixels than what I already have above, 
it wouldn't make much differences but If I choose fewer pixels, 
I was getting more of green backgrounds in ouput images.
Numbers of pixel did not make much differences,(at first I only chose
a big chunk of green pixels and I was not getting good outcomes) 
but extracting differnt parts of background pixels did make differences.  

Response 2:

  Image                  Min Threshold           Max Threshold
  Colbert range:  from        60           to         70
  Bird range:     from        30           to         65


Response 3:

Since method 2 needed to work with any input images, computing threshold
from the distance of average background RGB and average foreground RGB 
of the image would NOT work. (since you don't know which part would be 
background or foreground of the random image)
Instead, using method that getting average RGB of entire image and calculate
threshold comparing with pure green color. The reason why to compare with 
pure green color is that agerave RGB is going to be located closer to green
color since chroma key back ground is the largest part of the image. 
So that getting threshold as distacne between avg RGB and pure green would 
make it possible to sort out range of green and other colors.
Therefore, when the random image is assigned, threshold would be 
decided differently. Comparing calculated threshold and distance which is
between each pixel's RGB to pure green, the mask array will be decided. 


Before trying this method, I computed threshold the distance between
average of background color and average of foreground color. 
However this method only works with assigned images and it was no different 
than method 1. I was not getting right astronaut images no matter how many 
background, foreground pixels I was computing. 

The final method I used is more useful with unassigned images while 
method below is useful with assigned images. 
However, for method 2, it was hard to find the correct scale factor 
and I was not able to find the perfect scale factor that colbert2.bmp of 
the bird did not come as well compared with two other images. 

<<below is code for method 2+description>

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


================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

: 3 days

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

: Yes, I struggled in method 2 for long because I tried to compute
threshold by using average of background RGB and foreground RGB of each images. 

Do you have any other remarks?

:It was hard to understand the concept of RGB at first. 

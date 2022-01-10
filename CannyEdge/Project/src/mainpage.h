/*! \mainpage Iteration 1 Canny Edge detection
 *
 * \section Project Description
 *
 * This project is based around creating a canny edge detection filter
 *  we have created the multiple different filters that make it up
 *  then implented those into one final canny edge detection filter.
 *  This is where all of the filters are combined so it is able to take
 *  in a picture and the result is a final picture with the edge detection
 *  filter ran on it.
 *
 * \section Build and run
 *  The project can be built by being in the src folder and running
 * > make
 *  Then to run the program it can be done with the command where brackets are what you update
 * > ./image_processor data/[InputImage].png data/[OutputImage].png
 * 
 * \section Classes
 * 
 * Grayscale filter - 
 *  This takes an image and applies a grayscale filter to allow the other filters to work
 * 
 * Gaussian filter -
 *  Applies the gaussian blur filter which removes noise from the image
 * 
 * Sobel filter - 
 *  Applies the sobel gradient filter to produce 2 images, one with the intensity
 *  and the other with the edge direction
 * 
 * Non-maximum Supression filter - 
 *  Applies the non-max filter which thins the edges that have been created, this makes the edge
 *  detection more precise.
 * 
 * Double-threshold filter - 
 *  Applies the double threshold filter which takes an upper and lower intensity
 *  and categorizes each pixel as strong, weak, or non-relevant this allows the next
 *  filter to highlight the most important pixels
 * 
 * Hysteresis filter - 
 *  Applies the hysteresis filter which looks at each pixel and the ones surrounding it
 *  if the current filter is a weak pixel and there is a strong pixel near it, then it will become
 *  a strong pixel, but if there are none, then it becomes a non-relevant pixel. Strong and non-relevant
 *  pixels remain the same.
 * 
 * \section System Extension
 *  
 * It is quite simple to extend the system, all that needs to be done is to create a new .h and .cc file
 * for the filter that you want to create, implement the filters, then include the .h file in main.cc
 */
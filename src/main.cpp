#include <stdio.h>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

#define DEBUG 0

#define RGB 0

#define MIN_DISTANCE(var) (var).rows / 16
#define MIN_THRESHOLD 15
#define MAX_THRESHOLD 250
#define MIN_RADIUS 5
#define MAX_RADIUS 10

#define MEDIAN_BLUR_SIZE 11

int main(int argc, char **argv)
{
#if RGB
  Mat img = imread(string("data/rgb.png"), IMREAD_UNCHANGED);

  Mat gray;
  cvtColor(img, gray, COLOR_BGR2GRAY);

  medianBlur(gray, gray, MEDIAN_BLUR_SIZE);

  vector<Vec3f> circles;
  HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
               MIN_DISTANCE(gray),
               MAX_THRESHOLD, MIN_THRESHOLD, MIN_RADIUS, MAX_RADIUS
  );
#else
  Mat img = imread(string("data/gray.png"), IMREAD_UNCHANGED);

  medianBlur(img, img, MEDIAN_BLUR_SIZE);

  vector<Vec3f> circles;
  HoughCircles(img, circles, HOUGH_GRADIENT, 1,
               MIN_DISTANCE(img),
               MAX_THRESHOLD, MIN_THRESHOLD, MIN_RADIUS, MAX_RADIUS
  );
#endif

  fprintf(stderr, "Center coordinates (x, y) of circles found: \n");
  for( size_t i = 0; i < circles.size(); i++)
  {
    Vec3i c = circles[i];
    Point center = Point(c[0], c[1]);
    fprintf(stderr, "%d, %d px\n", c[0], c[1]);
    // circle center
    circle(img, center, 1, Scalar(0,100,100), 3, LINE_AA);
    // circle outline
    int radius = c[2];
    circle(img, center, radius, Scalar(255,0,255), 3, LINE_AA);
  }

#if DEBUG
  imshow("detected circles", img);
  waitKey();
#else
  vector<int> compression_params;
  compression_params.push_back(IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);

  bool result = imwrite("data/result.png", img, compression_params);

  if (result)
  {
    fprintf(stderr, "Saved PNG file successfully\n");
  }
  else
  {
    fprintf(stderr, "ERROR: Can't save PNG file\n");
  }

#endif

  return 0;
}

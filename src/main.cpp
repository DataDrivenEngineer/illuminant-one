#include <stdio.h>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  Mat img = imread(string("data/gray.png"), IMREAD_UNCHANGED);
  return 0;
}

#include <stdio.h>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  Mat img = imread(string("data/gray.png"), IMREAD_UNCHANGED);

  vector<int> compression_params;
  compression_params.push_back(IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);

  bool result = imwrite("data/gray_test.png", img, compression_params);

  if (result)
  {
    printf("Saved PNG file with alpha data.\n");
  }
  else
  {
    printf("ERROR: Can't save PNG file.\n");
  }

  return 0;
}

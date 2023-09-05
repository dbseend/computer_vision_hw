#include "opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat frame;
    VideoCapture cap;
    int fps;
    int delay;
    int current_frame;
    int total_frame;

    if (cap.open("background.mp4") == 0)
    {
        cout << "no such file!" << endl;
        waitKey(0);
    }

    fps = cap.get(CAP_PROP_FPS);
    delay = 1000 / fps;
    total_frame = cap.get(CAP_PROP_FRAME_COUNT);

    while (cap.get(CAP_PROP_POS_MSEC) <= 3000)
    {
        cap >> frame;
        current_frame = cap.get(CAP_PROP_POS_FRAMES);
        imshow("video", frame);
        waitKey(delay);

        cout << "frames: " << current_frame << " / " << total_frame << endl;
    }

    return 0;
}

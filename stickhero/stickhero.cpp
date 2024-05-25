#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp> // Include OpenCV library
#include <cstdlib> // Include the <cstdlib> header for system command execution
#include <chrono> // Include <chrono> for time-related operations
#include <thread> // Include <thread> for threading support

using namespace std;
using namespace cv;

int main() {
    // Define the row height to inspect
    int row_height = 1946;

    while (true) {
        try {
            // Capture the screen (execute ADB command to capture screen and save to file)
            system("adb shell screencap -p /sdcard/screen.png");
            system("adb pull /sdcard/screen.png");

            // Read the captured image
            Mat image = imread("screen.png");

            // Check if image is empty
            if (image.empty()) {
                cout << "Error: Cannot read image" << endl;
                continue;
            }

            // Print image dimensions
            cout << "Image dimensions: " << image.size() << endl;

            // Extract pixels from the specified row
            vector<Vec3b> pixels;
            for (int i = 0; i < image.cols; ++i) {
                pixels.push_back(image.at<Vec3b>(row_height, i));
            }

            // Debug: Print pixel values
            cout << "Pixel values at row " << row_height << ": ";
            for (int i = 0; i < 10; ++i) {
                cout << pixels[i] << ", ";
            }
            cout << "..." << endl;

            // Perform transition detection
            vector<int> transitions;
            bool ignore = true;
            bool black = true;

            for (int i = 0; i < pixels.size(); ++i) {
                Vec3b pixel = pixels[i];
                int r = pixel[0];
                int g = pixel[1];
                int b = pixel[2];

                if (ignore && (r + g + b) != 0) {
                    continue;
                }

                ignore = false;

                if (black && (r + g + b) != 0) {
                    black = !black;
                    transitions.push_back(i);
                    continue;
                }

                if (!black && (r + g + b) == 0) {
                    black = !black;
                    transitions.push_back(i);
                    continue;
                }
            }

            if (transitions.size() >= 3) {
                int start = transitions[0];
                int target1 = transitions[1];
                int target2 = transitions[2];
                int gap = target1 - start;
                int target = target2 - target1;
                double distance = (gap + target / 2) * 0.98;

                cout << "Transition points: ";
                for (int i : transitions) {
                    cout << i << " ";
                }
                cout << endl;

                cout << "Distance: " << distance << endl;

                // Execute ADB command for swipe gesture (adjust the coordinates and distance as needed)
                string adb_command = "adb shell input touchscreen swipe 500 500 500 500 " + to_string((int)distance);
                system(adb_command.c_str());
            }
            else {
                cout << "Not enough transition points detected" << endl;
            }


        }
        catch (const exception& e) {
            cout << "An error occurred: " << e.what() << endl;
        }

        // Wait for 5 seconds before the next iteration
        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}

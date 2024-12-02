/* This is the main execution file */
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

void displayPhotoAlbum(const std::vector<string>& imagePaths) {
  int currentImage = 0;
  cv::Mat image
  while (true) {
        // Load the current image
        image = cv::imread(imagePaths[currentIndex]);

        if (image.empty()) {
            std::cerr << "Error: Unable to load image at " << imagePaths[currentIndex] << "\n";
            break;
        }

        // Display the image
        cv::imshow("Photo Album", image);
        int key = cv::waitKey(0);

        // Handle keyboard input
        if (key == 27) { // ESC key to exit
            break;
        } else if (key == 81) { // Left arrow key
            currentIndex = (currentIndex - 1 + imagePaths.size()) % imagePaths.size();
        } else if (key == 83) { // Right arrow key
            currentIndex = (currentIndex + 1) % imagePaths.size();
        }
    }

    cv::destroyAllWindows();
}

  
}



int main() {
  std::string folderpath;
  std::cout << "Type in folderpath: " << std::endl;
  std::cin >> folderpath;
  
  // Load all image paths from the folder
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            imagePaths.push_back(entry.path().string());
        }
    }

    if (imagePaths.empty()) {
        std::cerr << "No images found in the specified folder.\n";
        return -1;
    }

    // Display the photo album
    displayPhotoAlbum(imagePaths);
  
  return 0;
}

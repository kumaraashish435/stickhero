# StickHero


https://github.com/kumaraashish435/stickhero/assets/103234896/7f1b6226-8a07-47dc-b98e-3974316c440b




Stick Hero Game Bot
This is a simple bot developed in C++ using Visual Studio to play the Stick Hero game automatically. The bot utilizes computer vision techniques to analyze the game screen, detect the gap between platforms, and perform the necessary actions to advance in the game.

# Features
Automatically captures the game screen using ADB commands.
Analyzes the captured image to detect the gap between platforms.
Calculates the optimal distance to stretch the stick.
Performs the necessary swipe gesture using ADB to extend the stick and land safely on the next platform.
Continuously runs in a loop to play the game indefinitely.
Requirements
Visual Studio: The project is developed and built using Visual Studio IDE.
OpenCV Library: Required for image processing and computer vision tasks.
Android Debug Bridge (ADB): Used to capture the game screen and send swipe gestures.
## Installation
Clone the repository to your local machine:

```bash
git clone https://github.com/kumaraashish435/stickhero.git
```
Open the project in Visual Studio.

Build the project to ensure all dependencies are resolved.

# OpenCV setup in visual studio 
visit this video for openCV setup
https://www.youtube.com/watch?v=trXs2r6xSnI

# Usage
Connect your Android device to your computer and enable USB debugging.

# Run this in windows terminal or cmd before running project
```bash
adb start-server
```

Run the Stick Hero game on your Android device.

Start the bot program in Visual Studio.

The bot will automatically start playing the game, analyzing the screen, and making moves to progress in the game.


# Run this command in terminal after finishing the programm
```bash
 adb kill-server
```


Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

License
This project is licensed under the MIT License.

Contact
For any inquiries or assistance, you can reach out to the project maintainer:

Name: [Your Name]
Email: [Your Email Address]
GitHub: [Your GitHub Profile]

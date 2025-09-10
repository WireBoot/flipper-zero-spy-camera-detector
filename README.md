# Flipper Zero Spy Camera Detector

This is a simple Flipper Zero application that uses the built-in infrared capabilities to detect spy cameras.

## Features

- Detects infrared signals from spy cameras.
- Displays signal strength and estimated distance.

## How to Build and Upload

1. Clone this repository.
2. Follow the [Flipper Zero firmware documentation](https://github.com/flipperdevices/flipperzero-firmware) to set up your development environment.
3. Place the `spy_camera_detector.c` and `CMakeLists.txt` files in the `applications_user` folder of the firmware.
4. Build the firmware and upload the compiled `.fap` file to your Flipper Zero using qFlipper.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

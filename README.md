# Spy Camera Detector (Flipper Zero App)

This app uses Flipper Zero's IR LED to help find hidden cameras by blinking the LED, which can reflect off camera lenses.

## Features

- Blinks IR LED for easy visual scanning.
- Simple interface: press BACK to exit.

## How to Build

1. **Clone Flipper Firmware** (if you haven't):
   ```
   git clone https://github.com/flipperdevices/flipperzero-firmware.git
   ```

2. **Clone this repo into `applications_user`**:
   ```
   git clone https://github.com/WireBoot/flipper-zero-spy-camera-detector.git \
     flipperzero-firmware/applications_user/spy_camera_detector
   ```

3. **Build:**
   ```
   cd flipperzero-firmware
   ./fbt fap_spy_camera_detector
   ```

4. **Upload to Flipper Zero:**
   - Copy the `.fap` from `dist/apps/spy_camera_detector.fap` to your Flipper (via qFlipper or SD card).

## Usage

1. Run the app on your Flipper Zero.
2. Slowly scan the room, looking for bright reflections from the blinking IR LED (camera lenses will reflect IR strongly).
3. Press BACK to exit.

## Note

- The app doesn't "auto-detect" cameras. It helps you visually spot them using IR reflection.

---

**Happy hunting!**

</> Giving credits to my project makes me really happy — and if this project brought you a smile or saved you time, I’d gratefully accept a donation. Every bit keeps the work going. 💙
USDT Address: TKY6kupcFnJqaYDkYWFzYyZf9Vc98dJyVx
Network: TRON(TRC20)





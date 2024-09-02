# SensiML Audio Keyword Recognition Example

## Summary

This Demo project uses the xG24 dev board and the onboard I2S microphone sensor for keyword spotting. This example project uses the Knowledge Pack created by SensiML along with the microphone component drivers running in a bare-metal configuration. The sensor data output is passed to the Machine Learning model created using SensiML's analytics studio, which is downloaded as a Knowledge Pack and incorporated into a Simplicity Studio V5 project to run inferences on the xG24 MVP AI Accelerator.

Software Components used: I2S Microphone, Simple LED, IO Stream: USART, Sleeptimer

## Gecko SDK version

v4.3.2
GCC 10.3.1

## Hardware Required

- One xG24 development kit
- One micro USB cable

## Hardware Setup

1. Open the Launcher tab in Simplicity Studio and check the status of the Adapter FW under General Information. The status should be Latest, if the status is Update then click the update link to download the latest version for the adapter firmware.
2. In the Console window select the Admin tab and type serial vcom config speed 921600 into the terminal input window and press Enter.
3. The example firmware in this guide uses a serial port connection. A debug VCOM port needs to be set up to use a serial connection. In the Debug Adapters window, Right + Click on the xG24 Dev Kit and select Launch Console… from the drop-down menu.
4. In the Console window select the Admin tab and type serial vcom config speed 921600 into the terminal input window and press Enter.

## UART Settings

The settings for the Serial Terminal are 912600 bps baud rate, 8N1 and no handshake.

## Setup

Import the included .sls file to Studio then build and flash the project to the SLTB004A development kit.
In Simplicity Studio select "File->Import" and navigate to the directory with the .sls project file.
The project is built with relative paths to the STUDIO_SDK_LOC variable which was defined as

C:\SiliconLabs\SimplicityStudio\v5\developer\sdks\gecko_sdk_suite\v4.3.2

## How the Project Works

This Project Has two modes, **Data Capture** and **Recognition**, that you can switch between using the `RUN_AUDIO_RECOGNITION_MODEL` flag in the `app_audio.h` header file.

When the Flag is set to

- `RUN_AUDIO_RECOGNITION_MODEL 0`: Microphone data is streamed out over the UART using the [SSI interface](https://sensiml.com/documentation/simple-streaming-specification/introduction.html). Which can be recorded using the SensiML Data Capture Lab.
- `RUN_AUDIO_RECOGNITION_MODEL 1`: Audio data is streamed into the Machine Learning model running on the device and the model classification output is sent over the UART.

The application uses the process-action bare-metal project configuration model. Running a Machine Learning model on an embedded device such as the xG24 dev board can be very broadly classified into three steps.

- Step 1: Data collection and labelling
- Step 2: Labelled data is used to train a machine learning model based on the end-goal (i.e., classify audio).
- Step 3: Convert the DSP pipeline and Machine Learning model to Embedded Code to run on the device.

For this project the DataSet is labeled using the SensiML Data Studio, The Machine Learning model is trained using SensiML's Analytics Studio. The Final model and pipeline is automatically converted to C code and downloaded as a `Knowledge Pack`. For more information, refer to SensiML's Analytics Studio Documentation - https://sensiml.com/documentation/guides/analytics-studio/index.html.

The Downloaded Knowledge Pack library is incorporated into the embedded application firmware and be flashed onto the device. The model will run on the xG24 dev board and can classify incoming voice data.

## .sls Projects Used

SensiML_SiliconLabs_XG24_Audio_ML.sls

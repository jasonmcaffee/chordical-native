# Chordical
Chordical Synthesizer implemented in C++ with JUCE framework.

Free synthesizer with VST, RU, AU, etc support for use in Digital Audio Workstations, or standalone.

## Dev Setup
### CLion
This project is configured with CMake and is setup to use the Intellij CLion IDE.

Using another IDE will require additional configuration.
### VST SDK
The JUCE framework requires vst sdk to be downloaded.

The zip can be found in the vendor directory (vstsdk369_01_03_2018_build_132.zip)

Extract the zip to a directory (e.g. ~/Documents/Dev/VSTSDK)

[Or Download VST SDK Here](https://www.steinberg.net/en/company/developers.html)
### Projucer
You'll need to install projucer, mainly so you can set vst sdk global path.

The installer for Mac can be found in the vendor directory (juce-huckleberry-osx.zip)

[Or Download Juce Here](https://juce.com/get-juce/download)

#### Setup Global Search Path
Click the Projucer menu -> Global Search Paths

Set the VST3 SDK directory to where you extracted the zip. (e.g. /Users/jason.mcaffee/Documents/dev/VST_SDK/VST3_SDK)

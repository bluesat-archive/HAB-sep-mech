# HAB-sep-mech

## Getting Started

### Prerequisites

#### Raspberry Pi Setup from scratch

This method will install an operating system, setup configuration files, install necessary software and create a startup script which runs the necessary software appropriately.

1. Navigate to https://www.raspberrypi.org/downloads/noobs/
2. Download the latest version of the NOOBS operating system installer.
3. Format SD card to FAT32 format
4. Extract the NOOBS .zip file. Place all the files from the unzipped NOOBS .zip file into the root of the SD card.
5. Insert SD card into Raspberry Pi and turn on the Raspberry Pi. Connect a keyboard and mouse to Raspberry Pi
6. Follow NOOBS installation instructions. Select Raspbian Operating System when prompted.
7. After installation of Raspbian, download files from HAB-sep-mech into the '''/home/pi''' folder. 
On a terminal window, enter:
'''
cd ~
git clone https://github.com/bluesat/HAB-sep-mech.git
'''
8. Now run the newInstallSetup program. On a terminal window, enter:
'''
cd ~/HAB-sep_mech/newInstallSetup
sudo ./install_script
'''
9. Monitor install and press 'y' when necessary.

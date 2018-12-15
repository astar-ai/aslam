# A\*SLAM Software

For more information see
[https://astar.ai](https://astar.ai).

The following steps have been tested and passed on Ubuntu 16.04.

### Note: A\*SLAM can run with ANY CaliCam stereo camera under the TRIAL mode.

In TRIAL mode, the map cannot be saved to or loaded from the hard drive.

### 1. Hardware Requirements

It is recommended to run A\*SLAM in a computer with 4-core, 8-thread CPU (i7-8550U or better) and 8G RAM.

### 2. OpenCV Installation

Follow the steps in [CaliCam@GitHub](https://github.com/astar-ai/calicam).

### 3. Download Image Data

Make sure the uncompressed files are under the directory  /home/USER_NAME/data/aslam_indoor

	cd
	mkdir data
	cd data
	wget http://astar.support/dotai/aslam_indoor.tar.gz
	tar xvf aslam_indoor.tar.gz

### 4. Download Program

	cd
	git clone https://github.com/astar-ai/aslam.git
	cd aslam
	chmod 777 ./aslam

### 5. Run

To run A\*SLAM program, you need to change the name of CaliCam stereo parameter file '##-YYMMDD-####.yml' to 'Stereo.yml' first.

	./aslam

### 6. Operation

Plese refer to the **Operation** part of [**A\*SLAM Manual**](https://drive.google.com/open?id=1T_PiYxxNShu9rh6vtca9-kar4itFgyLR0am5_G2h0-s).

### 7. A\*Localization

To run A\*SLAM program in the Monocular A\*Localization mode, you need to change the name of CaliCam monocular parameter file '##-YYMMDD-####.yml' to 'Mono.yml' first.

You also need to set the following parameters in the 'param.yml' file.

	slam_mode: 0
	model: Mono

### 8. Astar CES2019 Poster

<p align="center">
  <img src="http://astar.support/dotai/Astar_CES2019_Poster_1.png">
</p>


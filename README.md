# aslam: Astar SLAM Program

For more information see
[https://astar.ai](https://astar.ai).

The following steps are tested and passed in Ubuntu 16.04.

### 1. OpenCV Installation

Follow the steps in https://github.com/astar-ai/calicam.

### 2. Download Image Data

Make sure the uncompressed files are under the directory: /home/USER_NAME/data/astar_indoor

  cd
  mkdir data
  cd data
  wget http://astar.support/dotai/astar_indoor.tar.gz
  tar xvf astar_indoor.tar.gz

### 3. Download Program

	git clone https://github.com/astar-ai/aslam.git
	cd aslam
	chmod 777 ./aslam

# CSE-5349
Breathing Monitoring Using IMU(MPU-6050) with Arduino 
Instructions To Run:

1.	Install required software:
•	Arduino IDE: https://www.arduino.cc/en/software
•	Anaconda: https://www.anaconda.com/products/individual (Anaconda includes Jupyter Notebook and Python, as well as many pre-installed Python libraries)Python libraries: pip install numpy matplotlib pandas
2.	Connect hardware components:
•	IMU sensor board, microcontroller, breadboard, jumper wires,and  wearable device.
3.	Upload Arduino.ino sketch:
•	Open Arduino IDE, load sketch 'sketch_apr23d.ino' , connect microcontroller, select board and port, and click "Upload."
4.	Run Jupyter Notebook for data analysis and visualization:
Launch Jupyter Notebook by typing jupyter notebook in the command prompt or terminal and open the provided .ipynb file.
Modify the notebook to read the 'breathing_data.txt' dataset. Make sure 'breathing_data.txt' is in the same folder as visualizeMPU.ipynb file.
5.	Observe the output:
•	Python script generates plots and statistics for data analysis and visualization.

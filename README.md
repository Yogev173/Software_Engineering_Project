How to run:
1. we provide you a CMake file-"CMakeLists.txt", for building the project.
2. there are 3 part in this project, you should run each one in different terminals, by this order:
3. TCP server, command: "./build/server".
4. Client, command: "./build/client".




explanation about the project:<br />
In this project we created a server, that working on TCP protocol.
It present the client a CLI, with command to execute.
It main purpose is to classifie objects based on previos data, and display the counfusion matrix.

The server Classify data using KNN, the algorithm steps:
1. calculate the distance of all knowns objects, from the object that we want to classify (we call it a from now), and save it in a vector.
2. using select k algorithm, it find the k element in the vector (we call it b from now).
3. then find all the knowns objects that closer to a the the b, and save it in B.
4. return the most common type of objects in B.
<br />




our class hierarchy is:

the new server - client code is implamented with the following classes:
![](UMLs/UML%20ass2.png)

the classify code remains the same: <br />
![](UMLs/UML%20ass1.png)

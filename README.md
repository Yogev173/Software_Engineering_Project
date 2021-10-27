How to run:
1. we provide you a CMake file-"CMakeLists.txt", for building the project.
2. there are 3 part in this project, you should run each one in different terminals, by this order:
3. TCP server, command: "./build/tcpServer".
4. UDP server, command: "./build/udpServer".
5. Client, command: "./build/client".




explanation about the project:<br />
In this project we created 2 server, that working on diffrent protocol (TCP & UDP), they get data about Iruses and send back their types.
the servers is using the classic KNN implementation, with calculating the distance(Meric interface), saving the distance array, and doing a select(k) on the array. with doing that on every unclassified Iris and counting the KNN types we can classify the iris into his type.<br />




our class hierarchy is:

the new server - client code is implamented with the following classes:
![](../UMLs/UML%20ass2.png)

the classify code remains the same: <br />
![](../UMLs/UML%20ass1.png)

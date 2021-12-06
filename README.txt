#README for lab5

This is an implementation of Ford-Fulkerson algorithm for solving max flow determination problem

This program will work with 6 node graphs, if you want to change that - change the #define V statement to howmany nodes your graph has,
and change the graph array in main function such it has V subarrays with V elements each.

To input your graph you will need to input path values into graph array
Example of subarray(lets take the first subarray):

0, 2, 3, 0, 0 ,0 

which means from node 0 there are 2 path to node 1 and to node 2 with values 2 and 3 respectively

To start program you will have to input starting node and destination node like this:
 fordFulkerson(graph, int startnode, int destinationnode) 

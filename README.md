# Program summary

Written by Krista Parry, July 2017

Note: The email notifying me about the coding challenge was sent to my SPAM mailbox, so this is a late submission after approval from Cassie Stover on Wednesday. 

The code does not function properly to find and flag the anomolous purchases; File read-in/write-out are working properly and data structures are allocated.

I figured I would submit the code despite its shortcomings.  

-----The error comes from a problem in my linked list structure where I store the "friendships" of the users. The labels of each user are not passed 
to the linked list net->graph.edge, (or the linkages between each user are destroyed, breaking the linked list structure.Therefore I cannot perform 
the search algorithm on the list. The idea was to use breadth-first algorithm out to layer "D". Additionally, it cannot differentiate the purchases 
of friends within the desired network by timestamp. This functionally would have to be recorded in the linked list net->graph.node struct in an array. 



# Basic framework:

    - Allocate data structures
    - Read in batch_log file; 
        - read in parameters for degree of connectivity for each user to parse, and the purchase threshhold
        - for every new user, add vertex to "stack"
        - for every new friendship creater or destroyed, add "edge" to linked list data structure
        - track each users purchases in user struct
    - parse the network at some frequency to determine the mean and std. dev of purchase history for each user's friends within the network (within their "sphere of influence"). 
    - Use BFS algorithm 
    - read in batch file; if new purchase for given user is anomolous w.r.t purchase history of friends within sphere of influence then print to flagged 


#Directory Structure

    ├── README.md 
    ├── run.sh
    ├── src
    │   └── process_log.py
    ├── log_input
    │   └── batch_log.json
    │   └── stream_log.json
    ├── log_output
    |   └── flagged_purchases.json
    ├── insight_testsuite
        └── run_tests.sh
        └── tests
            └── test_1
            |   ├── log_input
            |   │   └── batch_log.json
            |   │   └── stream_log.json
            |   |__ log_output
            |   │   └── flagged_purchases.json
            ├── your-own-test
                ├── log_input
                │   └── your-own-log.txt
                |__ log_output
                    └── flagged_purchases.json

##### Code Summary

# Header File: 
	
structs.h:

    *network struct:
            -holds data that will span entire network (e.g. Input/Output files, or total number of Users)
            -contains substructs graph and an array of user structs
            - input parameters D, T read in from batch_log file to determine cutoff of social network connectivity and the number of purchases (T) to consider as part of the sphere of influence 

    *user struct:
            - holds data for the each user (e.g. number of friends, list of friends in network)
            - holds data for the purchases for each user
            - has flag for anomolous behavior


    * graph struct: 
            - holds data for the graph (social network) for all users
            - uses stack array to keep track of all of the users in the network
            - uses linked list to keep track of all of the "edges" of the network. Each node in the graph
                holds the label of each user
# Function files

main.c :

-main body of the code;
-calls all other functions from main.c


initialize.c:
    
-initializes the network and graph structs and the data structures contained within
-allows for dynamic memory allocation with each new user detected from the input file
-initialize user structs to zero

stack.c
- stack is array dynamically allocated to hold each vertix of the graph 


list.c:

- Create a linked list to hold the edges of all connected vertices; anytime a new friendship is created or destroyed, the appropriate edge is created or destroyed

read_files.c:

-has two functions to read the batch file and the stream file
-within the batch file: read in file, allocate the vertices and edges as you go;

user.c
-stores user information

analyze.c

-perform BFS algorithm on edge linked list
- determine if purchases read in from stream_log are anomolous; if so, print to flagged_purchases.json file





# InsightCodingChallenge
# InsightCodingChallenge
# InsightCodingChallenge
# InsightCodingChallenge
# InsightCodingChallenge

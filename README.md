# Lee-moore-maze-routing-algorithm

AIM: To implement a single layer Maze router using the Lee-Moore Algorithm. The
Router is responsible for finding the shortest paths between the given source and
destination, and also depicting the traverse path.

THEORY:
The Algorithm finds the shortest path from a source cell to destination cell
in a grid. It uses principles of Breadth first search.
The algorithm has two phases: Exploration and Retrace.
Initially the obstacles are identified and then the algorithm is announced.

INPUTS:
The input is a test file, which contains the grid size, address of obstruction
and the list of nets(i.e, source and destination).

Sample test file:
maze router testcase #1
=======================
	size 15
	obstruction 3 11
	obstruction 3 4
	obstruction 3 5
	obstruction 4 6
	obstruction 5 6
	obstruction 9 10
	obstruction 11 10
	obstruction 11 9
	obstruction 11 8
	obstruction 6 2
	obstruction 7 2
	obstruction 9 5
	obstruction 10 5
	obstruction 11 5
	net 3 12 12 5
	net 8 5 8 2
	net 3 3 3 10
	net 3 6 10 10
Here, the size depicts that, it is a (size x size) grid.

The obstruction line gives us the position of an obstacle,(the first integer depicts
row and the second one towards the column).

The net gives us the source address and the destination address.

PROCEDURE:
1. Initially, the grid size is to be acquired from the input file.
2. Then a size x size empty grid is created.
3. The Obstacles are then extracted from the input and are to be marked in
the grid. Obstacles are those which cannot be included in routing paths.
4. Initially, one of the nets is considered and corresponding source address
and destination address is locked.A counter initialized to 1 is considered.
5. Consider source address, and the counter is stored in all four immediate
horizontal and vertical cells.(Only if they are usable: I.e they are not
obstacles).
6. These neighbouring cells are locked and counter is incremented.
7. Repeat step 5,step 6 for each of these neighbouring cells.
8. Repeat step 7 and stop the flow as soon as the path touches the
destination.
9. Then, the path is retraced back from destination to source, and is saved.
    
DATA STRUCTURES AND FUNCTIONS:

1.VECTOR TUPLES
2.TUPLES
3.Void openinputFile() : The function is used to extract the name of the
input file and then to open it.
4.Stoi()
5.Array grid: int arr[][]
6.Int arr1[4]={0,-1,0,1}, int arr2[4]={-1,0,1,0}
These arrays are used to traverse from a node to its immediate vertical and horizontal neighbouring cells.
7. NOTE: In the grid, each value depicts each functionality.

	-1 -> Obstacle
	0 -> Can be used to route.
	-2 -> Source
	-3 -> Destination
 
PSEUDOCODE:

	initializing arrays
	int arr1[4]={0,-1,0,1};
	int arr2[4]={-1,0,1,0};
	ifstream inFile;
	openinputFile();
	while(!inFile.eof())
	{
	find(obstacles);
	find(nets);
	find(grid_size);
	}
	closefile();
	printing(initial_grid);
	Bool flag1=true;
	while(flag1)
	{
	current_source_address;
	current_destination_address;
	x1= x_position_of_current_source_address;
	y1= x_position_of_current_source_address;
	x2= x_position_of_current_dest_address;
	y2= x_position_of_current_dest_address;
	arr[x1][y1]=-2; arr[x2][y2]=-3;
	maze_counter=1;
	while(true)
	{
	/updation of neighbouring cells;
	repeat;
	if(path==destination)
	break;
	}
	printing(updated grid);
	traversing paths;
	cout<<maze_router_path;
	if(source_ad.size() ==0)
	{
	flag1=false;
	}
	}
 
Results:

For test file 1:

	Obstructions:
	(3,11),(3,4),(3,5),(4,6),(5,6),(9,10),(11,10),(11,9),(11,8),(6,2),(7,2),(9,5),
	(10,5),(11,5)
	Nets:
	Source Destination
	(3,12) (12,5)
	(8,5) (8,2)
	(3,3) (3,10)
	(3,6) (10,10)
 
Length and travel path:

	(3,12)->(12,5) = 16
	(12,5)->(12,6)->(12,7)->(12,8)->(12,9)->(12,10)->(12,11)->(11,11)->(10,11)->(9,11)->(8,11)->(7,11)->(6,11)->(5,11)->(4,11)->(4,12)->(3,12)
 
	(8,5) ->(8,2) = 3
	(8,2)->(8,3)->(8,4)->(8,5)
 
	(3,3) ->(3,10)= 9
	(3,10)->(3,9)->(3,8)->(2,8)->(2,7)->(2,6)->(2,5)->(2,4)->(2,3)->(3,3)
 
	(3,6) ->(10,10)= 11
	(10,10)->(10,9)->(10,8)->(10,7)->(9,7)->(8,7)->(7,7)->(6,7)->(5,7)->(4,7)->(3,7)->(3,6)
 
For testfile 2:

	Obstructions:
	(0,9), (1,9), (2,3), (2,4), (3,5), (5,13), (6,13). (8,13), (6,8), (7,8), (8,8), (6,9), (7,9), (8,9),
	(6,10), (7,10), (8,10), (11,3), (12,3), (11,4), (12,4), (11,5), (12,5), (12,9), (12,10), (12,11)
	Nets
	Source Destination
	(12,8) (12,12)
	(2,5) (6,1)
	(3,4) (10,3)
	(2,9) (10,5)
	(7,1) (7,13)
	(3,3) (10,4)
 
Length and travel path:

	(12,8)->(12,12)= 6
	(12,12)->(11,12)->(11,11)->(11,10)->(11,9)->(11,8)->(12,8)
 
	(2,5)->(6,1)= 10
	(6,1)->(5,1)->(4,1)->(3,1)->(2,1)->(1,1)->(1,2)->(1,3)->(1,4)->(1,5)->(2,5)
 
	(3,4)->(10,3)= 8
	(10,3)->(9,3)->(8,3)->(7,3)->(6,3)->(5,3)->(4,3)->(4,4)->(3,4)
 
	(2,9) ->(10,5)= 12
	(10,5)->(9,5)->(8,5)->(7,5)->(6,5)->(5,5)->(4,5)->(4,6)->(3,6)->(2,6)->(2,7)->(2,8)->(2,9)
 
	(7,1)->(7,13)= 24
	(7,13)->(7,12)->(7,11)->(8,11)->(9,11)->(9,10)->(9,9)->(9,8)->(9,7)->(9,6)->(10,6)->(11,6)->(12,6)->(13,6)->(13,5)->(13,4)->(13,3)->(13,2)->(13,1)->(12,1)->(11,1)->(10,1)->(9,1)->(8,1)->(7,1)
 
	(3,3) ->(10,4) is non routable
 
CONCLUSION:
The shortest path length and the traverse path are found to be successfully
and printed.

/* * Read the dimensions of a rectangular room and carpet
 and indicate whether the carpet fits the room 
 (user can enter in any order, 
 ex: larger first for the room and smaller first for 
 the carpet) */

#include <stdio.h>

int main()
{

	int x_room, y_room, x_carpet, y_carpet;

	int room_area, carpet_area;

	printf("enter the dimensions of the rectangular room:");
	scanf("%d %d", &x_room, &y_room);

	printf("enter the dimensions of the carpet:");
	scanf("%d %d", &x_carpet, &y_carpet);


	//printf("%d %d %d %d\n", x_room, y_room, x_carpet, y_carpet);

	room_area = x_room * y_room;
	carpet_area = x_carpet * y_carpet;

	if (room_area >= carpet_area)
		printf("carpet fits the room\n");
	else
		printf("carpet does not fit the room\n");


	return 0;
}




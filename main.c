#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my_mat.h"

#define MAX_COMMANDS 100
#define MAX_COMMAND_LEN 200
#define MAX_LINE_LEN 512

void parseInput(char *str, char *deli, char commands[][MAX_COMMANDS]);
void printCommands(char commands[][MAX_COMMANDS], char sequence[]);
void parseSequence(char str[], char *delimeters, char commandSequence[MAX_COMMANDS]);
void remove_spaces(char str[]);

int main()
{
	// variable decleration
	char str[MAX_LINE_LEN];
	// int mat[10][10];
	char commands[MAX_COMMAND_LEN][MAX_COMMANDS];
	char commandSequence[MAX_COMMANDS];
	char delimeters[] = {'A', 'B', 'C', 'D'};

	// get input from user
	fgets(str, sizeof(str), stdin);

	// delete all white space in the string
	remove_spaces(str);

	// get command sequence
	parseSequence(str, delimeters, commandSequence);

	// parse commands
	parseInput(str, ",", commands);

	// print all non empty commands
	printCommands(commands, commandSequence);
}

void parseInput(char *str, char *deli, char commands[MAX_COMMAND_LEN][MAX_COMMANDS])
{
	// init variables
	char *split;

	// init commands
	int com;
	for (com = 0; com < MAX_COMMANDS; ++com)
	{
		memset(commands[com], 0, strlen(commands[com]));
	}

	// split the user input
	split = strtok(str, deli);

	// add the new commands
	int i = 0;
	while (split != NULL)
	{
		strcat(commands[i], split);
		split = strtok(NULL, deli);
		i++;
	}
}

void printCommands(char commands[][MAX_COMMANDS], char sequence[])
{
	int command_index = 0;
	while (strcmp(commands[command_index], "") != 0)
	{
		printf("command %d: %c - %s\n", command_index, sequence[command_index], commands[command_index]);
		// printf("length: %ld\n", strlen(commands[command_index]));
		command_index++;
	}
}

void parseSequence(char str[], char delimeters[], char commandSequence[MAX_COMMANDS])
{
	// reset command sequence values

	// add the commands in their sequence
	int idx;
	int j = 0;
	for (idx = 0; idx < strlen(delimeters); ++idx) // for every letter in delimeters
	{
		char *pt = strchr(str, delimeters[idx]); // get the first letter that is equal to delimeters[i]
		while (pt != NULL)						 // while there are more of these letters in the string
		{
			commandSequence[j] = *pt;
			j++;
			*pt = ',';
			pt = strchr(str, delimeters[idx]);
		}
	}
}

void remove_spaces(char str[])
{
	size_t size = strlen(str);
	char out[size];
	int index = 0;
	char *ptr;
	ptr = &str[0];

	for (size_t i = 0; i < size; ++i)
	{
		if (*(ptr + i) != ' ')
		{
			out[index] = *(ptr + i);
			index++;
		}
	}

	strcpy(str, out);
}

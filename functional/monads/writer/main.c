#include "writer.h"

writer		add_one(int n)
{
	return (writer) {n + 1, "add 1 to "};//making this a linked list? NAHHHHHHH
}

writer		minus_one(int n)
{
	return (n - 1);
}

writer		wrap(int n)
{
	return (writer) {n, 0

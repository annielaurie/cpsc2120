#include "IntegerArrayQueue.h"
#include <string>
using testing::ElementsAreArray;
using namespace std;
int v[] = {1, 3, 6, 10, 15};
int f = 0;
int b = 4;
IntegerArrayQueue queue;
queue.enqueue(1);
queue.enqueue(3);
queue.enqueue(6);
queue.enqueue(10);
queue.enqueue(15);
// This can be an ofstream as well or any other ostream
stringstream buffer;
// Save cout's buffer here
streambuf *sbuf = cout.rdbuf();
// Redirect cout to our stringstream buffer or any other ostream
cout.rdbuf(buffer.rdbuf());
queue.printArrayQueue();
int vals[5];
int front, back;
string skip;
for (int i=0; i<5; i++)
{
  buffer >> vals[i];
}
for (int i=5; i<10; i++)
{
  buffer >> skip;
}
buffer >> skip;
buffer >> front;
buffer >> skip;
buffer >> back;
ASSERT_THAT(v, ElementsAreArray(vals));
ASSERT_EQ(f, front);
ASSERT_EQ(b, back);
// When done redirect cout to its old self
cout.rdbuf(sbuf);
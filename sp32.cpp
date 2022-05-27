#include <iostream>
#include <ctime>
using namespace std;
int main()
{
 srand(time(0));
long long n = 5;
long long array[n][n];
 cout<<"\tArray"<<endl;
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
  {
   array[i][j] = rand() % 9;
   cout<<array[i][j]<<" ";
  }
  cout<<endl;
 }
 long long *ptr = &array[0][n-1];
long long *begin = &array[0][0];
 long long *end = &array[n-1][n-1];

 asm(
 "mov %[ptr], %%rcx\n\t" 
 "mov %[end], %%rbx\n\t"
 "mov %%rbx, %[ptr]\n\t" 
 "mov $8, %%rax\n\t"
 "mulq %[n]\n\t" 
 "mov %%rcx, %%rbx\n\t"

 "p_start:\n\t"
 "push (%%rcx)\n\t"
 "cmp %%rbx, %[begin]\n\t" 
 "je second_cond\n\t"
 "jmp n_iter\n\t"

 "second_cond:\n\t"
 "cmp %%rcx, %[ptr]\n\t"
 "je p_end\n\t" 
 "jmp n_iter\n\t"

 "n_iter:\n\t"
 "cmp %%rcx, %[ptr]\n\t" 
 "je step\n\t" 
 "jmp next_elem\n\t" 

 "next_elem:\n\t"
 "add %%rax, %%rcx\n\t"
 "jmp p_start\n\t"

 "step:\n\t" 
 "sub $8, %%rbx\n\t" 
 "sub $8, %[ptr]\n\t" 
 "mov %%rbx, %%rcx\n\t" 
 "jmp p_start\n\t"

 "p_end:\n\t"
 "mov %[begin], %%rcx\n\t"
 "pop (%%rcx)\n\t"

 "loop_pop:\n\t"
 "cmp %%rcx, %[end]\n\t"
 "je end_asm\n\t"
 "add $8, %%rcx\n\t"
 "pop (%%rcx)\n\t"
 "jmp loop_pop\n\t"
 "end_asm:\n\t"
 :
 :[ptr]"m"(ptr), [begin]"m"(begin), [end]"m"(end), [n]"m"(n)
 :"%rax", "%rbx", "%rcx"
 );
 
 cout<<endl;
 cout<<"\tArray(New)"<<endl;
for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

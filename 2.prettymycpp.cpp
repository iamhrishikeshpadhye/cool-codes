#include <iostream>
#include <fstream>
using namespace std;

void indent(string fileName)	
{
	
	int pos = 0, count =0, lengthp = 0,j=0;
	string ch;
	ifstream file(fileName);
	while(file.good())
	{
		pos++;
		getline(file,ch);
	}
	lengthp=file.tellg();
	string* hold (nullptr);
	hold = new string[pos + 1];
	int* bracketcount(nullptr);
	bracketcount = new int[pos+1];
	file.clear();
	file.seekg(0);
	while(file.good())
	{
		getline(file,hold[count]);
		count++;
	}
	int endline = count;
	int p=0;
	while(p<=endline)
	{
		bracketcount[p]=0;
		p++;
	}
	count = 0;
	int len=0,i = 0, current=0;
	while(count<endline)
	{
		len = hold[count].length();
		i=0;
		while(i<=len)
		{
			if(hold[count][i] == '{')
			{
				current=count;
				while(current <endline)
				{
					current++;
					bracketcount[current]++;
				}
			}
			if(hold[count][i] == '}')
			{
				current=count;
				while(current <endline)
				{
					bracketcount[current]--;
					current++;
				}
			}
			i++;
		}
		count++;
	}
	file.close();
	ofstream file2("temp.txt");
	string* indents(nullptr);
	indents = new string[pos+1];
	p=0;
	while(p<endline)
	{
		count=0;
		while(hold[p][count]=='\t')
		{
			count++;
		}
		while(bracketcount[p]>0)
		{
			bracketcount[p]--;
			indents[p] +="\t";
		}
		if(count==0)
		{
			file2<<indents[p]<<hold[p]<<endl;
		}
		else if(count>0)
		{
			file2<<indents[p];
			len = hold[p].length();
			i=0;
			while(i<len-count)
			{
				file2<<hold[p][i+count];
				i++;
			}
			file2<<endl;
		}
		p++;
	}
	file2.close();
	delete [] hold;
	delete [] bracketcount;
	delete [] indents;
}

int main(int argc, char const *argv[])
{
	indent(argv[1]);
	return 0;
}

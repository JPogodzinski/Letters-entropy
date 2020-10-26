#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <math.h>

using namespace std;
double entropy_fun(double p)
{
    double entropy;
    entropy=(p*log2(p))+((1-p)*log2(1-p));
    return entropy;
}

void fun(string filename)
{
    string plaintext;
	map <char, double> counter;
    map <char, double> entropy;
	ifstream plaintext_file;
    ofstream result;
	string line;
	plaintext_file.open(filename);
	if (plaintext_file.is_open())
	{
		while (getline(plaintext_file, line))
		{
			plaintext += line;
		}
		plaintext_file.close();
	}
	int length = plaintext.length();
	for (int i = 0; i < length; i++)
	{
		counter[plaintext[i]]++;
        entropy[plaintext[i]]++;
	}
	for (std::map<char, double>::iterator it = counter.begin(); it != counter.end(); ++it)
		it->second=it->second / length;
    for (std::map<char, double>::iterator it = entropy.begin(); it != entropy.end(); ++it)
    {	it->second=it->second / length;
        it->second=entropy_fun(it->second);
    }
    string output_name;
    output_name="result_";
    output_name.append(filename);
    result.open(output_name);
    for (std::map<char, double>::iterator it = counter.begin(); it != counter.end(); ++it)
		result << it->first << ";" << it->second << '\n';
    result <<"Entropy"<< '\n';
    for (std::map<char, double>::iterator it = entropy.begin(); it != entropy.end(); ++it)
		result << it->first << ";" << it->second << '\n';
    result.close();
}

int main()
{
    fun("kamizelka.txt");
    fun("it.txt");
    fun("macbeth.txt");
}


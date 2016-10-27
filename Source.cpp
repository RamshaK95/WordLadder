#include <iostream>
#include<vector>
#include <fstream>
#include<string>
#include<algorithm>
using namespace std;
bool canChange(string  strA, string strB)
{
	string letter;
	int dif = 0;
	int position = 0;
	int currentSize = (int)strA.size();
	if (currentSize != (int)strB.size())
	{
		return false;
	}
	for (int i = 0; i < currentSize; ++i)
	{
		if (strA[i] != strB[i])
		{
			dif++;
			position = i;
			if (dif > 1)
			{
				return false;
			}
		}
	}
	if (dif == 1)
	{
		letter = strA[position];
		return true;
	}
	else return false;
}
void main()
{
	vector < vector<string>> records;
	fstream file;
	file.open("sample.txt");
	string data;
	int line_count = 0;
	int even = 0;
	int total = 0;
	int length;
	vector<string> words;
	string prev_word;
	string str;
	size_t found;
	size_t found1;
	string str4;
	if (file.is_open())
	{

		while (file.good())
		{
			getline(file, data);

			int count = 0;
			for (int i = 0; i < data.length(); i++)
			{
				int c = data[i];
				if ((c >= 65 && c <= 90) || (c == 45) || (c == 59 || c == 32)) //allows for all capitalzed words including hyphens and accounts for more than one word seperated by a "; "
				{
					count += 1;
				}

			}
			if (count == data.length() && data.length() != 0)
			{
				//cout << data << endl;
				str = data;
				found = str.find("; ", 0, 2);

				str4 = str.substr(0, found);
				if (found == std::string::npos)
				{
					//cout << data;
					if (data != prev_word && data[0] >= prev_word[0])
					{
						words.push_back(data);
						total = total + 1;
					}
					//cout << total << endl;
				}
				else {
					//cout << str4 << '\n';
					if (str4 != prev_word)
					{
						words.push_back(str4);
						total++;

					}
					while (found != std::string::npos)
					{
						found1 = str.find("; ", found + 1, 2);
						//std::cout << "First individual word found at: " << found << '\n';
						std::string str4 = str.substr(found + 2, found1 - 2);
						found = found1;
						int f1 = str4.find(";");
						if (f1 != std::string::npos)
						{
							str4.erase(f1, 1);
						}
						if (str4 != prev_word)
						{
							//std::cout << str4 << '\n';
							words.push_back(str4);

							total = total + 1;
							//cout << total << endl;
						}
					}
				}
				prev_word = words.back();
				//cout << words.back() << endl;

				//cout << total << endl;

			}
			else
			{

				even++;//cout << "The word contains " << count << " lowercase characters" << endl;
			}
		}
		//file.close();
		cout << total;


	}
	else
	{
		cout << "Couldn't open file.\n";
	}
	for (int i = 0; i < words.size(); i++)
	{
		length = words[i].length();
		vector<string> temp;
		for (int j = 0; j < words.size(); j++)
		{
			if (length == words[j].length())
			{
				
				if (canChange(words[i],words[j]) == true)
				{
					temp.push_back(words[j]);
				}

			}


		}
		records.push_back(temp);

	}



	int x = words.size();
	cout << words.size();

	for (int i = 0; i < x; i++)
	{
		cout << i << " : " << words[i] << endl;

	}

	for (int i = 0;i< records.size(); i++)
		
		for (int j = 0; j < records[j].size(); j++)
			cout << records[i][j] << " _______________";
	cin >> line_count;

	return;
}
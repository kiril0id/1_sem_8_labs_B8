/////////////////////////////////////////////////////////////////////////////////////
//В8 Имеется список участников спортивных соревнований.Каждый эдемент списка содержит
//следующую информайию : названия команды, фамилия спортсмена, уго возраст, рост вес.
//Вывести в алфавитном порядке фамилии спортсменов, возраст которых младше 18 лет.
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

struct participant
{
	string team_name;
	string surname;
	int  age;
	int weight;
	int growth;
};

int main()
{
	int N;
    cout << "Please enter the number of participants " << endl;

	cin >> N;
	while (N<=0)
	{
		
			cout << "Sorry, but the number must be greater than 0. Try again.." << endl;
			cin >> N;
	}
	participant *par = new participant[N];
	cout << "Number of participants is " << N << "\n Please fill in the data: \n \n";
	
	for (int i = 0; i < N; i++)
	{

		cout << i + 1 << " participants: \n";
		cout << "Team name:\t ";  cin >> par[i].team_name;
		cout << "Surname:\t "; cin>> par[i].surname;
		cout << "Age:\t "; cin >> par[i].age;
		cout << "Weight:\t"; cin >> par[i].weight;
		cout << "Growth: \t"; cin >> par[i].growth;
	}

	 //
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (par[j].surname[0] > par[j + 1].surname[0])
			{
				participant temp;
				temp = par[j];
				par[j] = par[j + 1];
				par[j + 1] = temp;
			}
			else if (par[j].surname[0] == par[j + 1].surname[0])
			{
				int k = 1;
				bool whil = true;
				while (whil)
				{
					if (!(par[j].surname[k] == par[j + 1].surname[k]))
					{
						if (par[j].surname[k] > par[j + 1].surname[k])
						{
							participant temp;
							temp = par[j];
							par[j] = par[j + 1];
							par[j + 1] = temp;
						}
					}
					else k++;
				}
			}
		}
	}
	 //
		for (int i = 0; i < N; i++)
		{
			if (par[i].age< 18)
			{
				
				cout << par[i].team_name << endl;
				cout << par[i].surname << endl;
				cout <<  par[i].age<<endl;
				cout << par[i].weight<<endl;
				cout <<  par[i].growth<<endl;
			
			}
		}

	delete[] par;
	system("pause");
	return 0;
}


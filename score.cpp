#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
using namespace std;

typedef struct student
{
        string name;
        string sex;
        double score;
        bool operator<(const student &a) const
        {
            return (score>a.score)||((score==a.score)&&(name<a.name));
        }
}Stu;


double average(const vector<Stu> &stu)
{
	double ans=0;
	for(auto i:stu)
	{
		ans+=i.score;
	}
	return ans/double(stu.size());
}

vector<student> stu,male,female;
int main()
{
        
        ifstream fin("score.csv");
        string Score;
		string head;
	int flag=1;
        while(!fin.eof())
        {
              if(flag)
             {
                getline(fin,head);
                flag=0;
             }
             else
             {
                Stu tmp;
                string name;
                string sex;
                string score;
                getline(fin,name,',');
                tmp.name=name;
				fin.ignore(1);
                getline(fin,sex,',');
                tmp.sex=sex;
				fin.ignore(1);
                getline(fin,score,'\n');
                stringstream ss;
                ss<<score;
                ss>>tmp.score;
                
				if(sex=="Female")
				{	female.push_back(tmp);
                                        stu.push_back(tmp);
                                 }
				if(sex=="Male")
				{	male.push_back(tmp);
                                        stu.push_back(tmp);
                                }
               }
        }
        
		cout<<fixed<<setprecision(1)<<average(stu)<<endl<<average(male)<<endl<<average(female)<<endl;	 
          sort(stu.begin(),stu.end());
	for (auto x:stu)
	{
		cout<<x.name<<" "<<x.sex<<" "<<x.score<<endl;
	}
	return 0;
}


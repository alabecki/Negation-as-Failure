#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <algorithm>

#define ATOM_SIZE 10

using namespace std;


int nextLine(string s, unsigned int p){
	while(s[p] != '\n' && p < s.size()){
		p++;
	}
	return p;
}

int main (){

	string file_name;
	cout << "Please enter the name of the KB file to be read (be sure to include '.txt' at the end) " << endl;
	getline(cin, file_name);

	//load file content into a string

	ifstream t(file_name.c_str());
	string test((std::istreambuf_iterator<char>(t)),
    istreambuf_iterator<char>());


	/*ifstream in(file_name.c_str());
    stringstream buffer;
    buffer << in.rdbuf();
    string test = buffer.str();				//string copied into */
	cout << endl << test << endl << endl; 

	
	int num_clauses = 1;

	unsigned int aux = 0; 
	//cout << "string size " << test.size() << endl;
	while( aux < test.size()){
		//cout << "char count" << aux << endl;
		aux++;
		if(test[aux] == '\n'){
				num_clauses++;
			}
	}
	
//cout << num_clauses << endl;

string heads [num_clauses] [1];
string p_bodies [num_clauses][25];
string n_bodies [num_clauses][25];

int p_count[num_clauses];
int n_count[num_clauses];

vector<string> c;
int c_size = 0;

vector<string> nc;
int nc_size = 0;

vector<string> atoms;

for(int i = 0; i < num_clauses; i++){
	p_count[i] = 0;
}

for(int i= 0; i < num_clauses; i++){
	n_count[i] = 0;
}

	int clause = 0;
	aux = 0;

	while(aux < test.size()){
		if(test[aux] == '#'){
			while(test[aux] != '\n'){
				aux++;
			}
		}
			while(isalpha(test[aux]) == false){
			aux++;}
	
		int atom = 0;
		
			while(test[aux] != '['){
				string temp;
				while(test[aux]!= ' ' && test[aux]!= '[' ){
					temp.append(1, test[aux]);
					aux++;
				}

			heads[clause][atom] = temp;								///////////
			if((find(atoms.begin(), atoms.end(), temp) != atoms.end()) == false){
				atoms.push_back(temp);}
			atom++;
			aux++;
		}		

		while(test[aux] == ' '){
			aux++;
		}
		aux++;
	
		atom = 0;
		while(test[aux] == ' ' || test[aux] == '['){
			aux++;
		}
		while(test[aux] != ']' && aux < test.size()){
			
			if(test[aux] == ']'){
				break;
			} 
			string temp;
			while(test[aux]!= ' ' && test[aux]!= ']' && aux < test.size()){
				//cout<< "n " << test[aux] << endl;
				temp.append(1, test[aux]);
				aux++;
			}
			while(test[aux] == ' '){
				aux++;
			}
			p_bodies[clause][atom] = temp;								///////////
			if((find(atoms.begin(), atoms.end(), temp) != atoms.end()) == false){
				atoms.push_back(temp);}
			atom++;
			p_count[clause] = p_count[clause] +1;

			while(test[aux] == ' '){
				aux++;
			}
		}
		while(test[aux] == ' '){
			aux++;
		}
		aux++;
		while(test[aux] == ' '){
			aux++;
		}
		aux++;

			atom = 0;
		while(test[aux] == ' ' || test[aux] == '['){
			aux++;
		}
		while(test[aux] != ']' && aux < test.size()){
			
			if(test[aux] == ']'){
				break;
			} 
			string temp;
			while(test[aux]!= ' ' && test[aux]!= ']' && aux < test.size()){
				//cout<< "n " << test[aux] << endl;
				temp.append(1, test[aux]);
				aux++;
			}
			while(test[aux] == ' '){
				aux++;
			}
			n_bodies[clause][atom] = temp;								///////////
			if((find(atoms.begin(), atoms.end(), temp) != atoms.end()) == false){
				atoms.push_back(temp);}
			atom++;
			n_count[clause] = n_count[clause] +1;
		}
	while(test[aux] == ' ' || test[aux] == '[' || test[aux] == ']'){
			aux++;
		}
	if(test[aux] == '#'){
			while(test[aux] != '\n' && aux < test.size()){
				aux++;
			}
		}
	clause++;	
	
	}

	cout << "Implications:" << endl;

	//gather all of the bodyless clauses

	for(int i = 0; i < num_clauses; i++){
		if(p_bodies[i][0] == "\0" && n_bodies[i][0] == "\0"){
			c.push_back(heads[i][0]);
			cout << heads[i][0] << " because it is given in a bodyless clause (i.e., it is given as a fact)" << endl;
			c_size++;
		}
	}

	//gather all atoms not occuring in a head
	for(unsigned int i = 0; i < atoms.size(); i++){
		int flag = 0;
		for(int j = 0; j < num_clauses; j++){
			if(atoms[i] == heads[j][0]){
				flag = 1;
			}
		}
		if(flag == 0){
			nc.push_back(atoms[i]);
			cout << "not-" << atoms[i] <<  " because it is not present in a head, and so cannot be derived." << endl;
			nc_size++;
		}
	}
	

	for(int x = 0; x < 3; x++){

	//look for instances when all conditions for a head are satisified


for(int i = 0; i < num_clauses; i++){
	int flag = 1;
	if(p_count[i] > 0){
		for(int j = 0; j < p_count[i]; j++){
			if((find(c.begin(), c.end(), p_bodies[i][j]) != c.end()) == false){
				flag = 0;
			}
		}	
	}
	if(n_count[i] > 0){
		for(int j = 0; j < n_count[i]; j++){
			if((find(nc.begin(), nc.end(), n_bodies[i][j]) != nc.end()) == false){
				flag = 0;
			}
		}	
	}
	if (flag == 1){
			if((find(c.begin(), c.end(), heads[i][0]) != c.end()) == false){
				c.push_back(heads[i][0]);
				cout << heads[i][0] << " because both its positive and negative conditions are satisified." << endl;
				c_size++;
				}
			}
	} 

//look for cases in which a negative condition is not satisified because the atom is known to be true	
 
for(int i = 0; i < c_size; i++){
	for(int j = 0; j < num_clauses; j++){
		for(int k = 0; k < n_count[j]; k++){
			if(c[i] == n_bodies[j][k]){
				if((find(nc.begin(), nc.end(), heads[j][0]) != nc.end()) == false){
					nc.push_back(heads[j][0]);
					cout << "not-" << heads[j][0] << " because not-" << n_bodies[j][k] << " is a condition for " << heads[j][0] << " but " << c[i] << " is true." << endl;
					nc_size++;
				}
			}
		}
	}
}

	for(int i = 0; i < nc_size; i++){
		for(int j = 0; j < num_clauses; j++){
			for(int k = 0; k < p_count[j]; k++){
				if(nc[i] == p_bodies[j][k]){
					if(((find(nc.begin(), nc.end(), heads[j][0]) != nc.end()) == false) && ((find(c.begin(), c.end(), heads[j][0]) != c.end()) == false)){
						nc.push_back(heads[j][0]);
						cout << "not-" << heads[j][0] << " because " << p_bodies[j][k] << " is a condition for " << heads[j][0] << " but " << nc[i] << " is false." << endl;
						nc_size++;
				}
			}
		}
	}
}


//from nc

/*for(int i = 0; i < num_clauses; i++){
	int flag = 1;
	if(n_count > 0){
		for(int j = 0; j < p_count[i]; j++){
			if((find(nc.begin(), nc.end(), n_bodies[i][j]) != nc.end()) == false){
				flag = 0;
			}
		if (flag == 1){
			if(((find(nc.begin(), nc.end(), heads[j][0]) != nc.end()) == false) && ((find(c.begin(), c.end(), heads[j][0]) != c.end()) == false)){
				nc.push_back(heads[i][0]);
				nc_size++;
				cout << "redundant?" << endl;
				}
			}
		}	
	}
} */

} 


for(int i = 0; i < nc_size; i++){
	for(int j = 0; j < c_size; j++){
		if(nc[i] == c[j]){
			 nc.erase(nc.begin() +i);
			 nc.shrink_to_fit();
			 nc_size--;
		} 
	}
}

cout << endl;

cout << "If a propositon has been reported as both true and true, then it is true, becuase one of its conditions" << endl;
cout << "conditions failed but another one of its conditions susceeded." << endl;

cout << "The following is the ultimate list of atoms implicated by the KB: " << endl << endl;
cout << " { "; 
for(int i = 0; i < c_size; i++){
		cout << c[i] << " ";
	}
for(int i = 0; i < nc_size; i++){
		cout << "not-" << nc[i] << " ";
	}
cout << "}"<< endl << endl;


return 0;

}	

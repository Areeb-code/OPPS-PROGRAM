#include<iostream>
#include<string>
#include<vector>
using namespace std;

const string BOLD ="\033[1m";
const string UNDERLINE ="\033[4m";
const string ITALIC ="\033[3m";
const string RESET="\033[0m";
char choice;

class Todo {
private:
    string todo_name;
    vector<string> tasks;
    vector<string> distraction;

public:
    Todo(string todo_name, string distraction) {
        this->todo_name = todo_name;
        this->distraction.push_back(distraction);
    }

    Todo() {
        todo_name = "UNTITLED";
        distraction.push_back("NONE");
    }

    void info() {
        int task_count;
        cout << BOLD << ITALIC << "ENTER HOW MANY TASK YOU WANT TO DO : " << RESET << endl;
        cin >> task_count;
        cin.ignore();
        for (int i = 0; i < task_count; i++) {
            string task;
            cout << "PLEASE ENTER YOUR TASK " << i + 1 << ": ";
            getline(cin, task);
            tasks.push_back(task);
        }
    }

    void display_info() {
      label: cout << BOLD << ITALIC << "YOUR TASKS:" << RESET << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
        cout << endl;

        for (int i = 0; i < tasks.size(); i++) {
            bool taskCompleted = false;
            while (!taskCompleted) {
               cout << BOLD << "TASK " << i + 1 << ": " << RESET << tasks[i] << endl;
                cout << "Type 'N' when completed or 'D' if you face any distraction: ";
                
                cin >> choice;
                cin.ignore();

                if (choice == 'n' || choice == 'N') {
                    taskCompleted = true;
                }
                else if (choice == 'd' || choice == 'D') {
                    string distract;
                    cout << BOLD << UNDERLINE << "ENTER DISTRACTION: " << RESET << endl;
                    getline(cin, distract);
                    distraction.push_back(distract);
                }
                else {
                    cout << "Invalid choice. Please type 'N' or 'D'." << endl;
                    system("cls");
                    goto label;
                }
            }
        }
    }
   
};


int main(){
	system("cls");
	string name;
	cout<<BOLD<<"WHAT IS YOUR NAME : "<<RESET;
	getline(cin,name);
	system("cls");
	cout<<BOLD<<UNDERLINE<<name<<"'s TODO LIST"<<RESET<<endl;
	Todo task;
	task.info();
	system("cls");
	task.display_info();
	system("cls");
	cout<<BOLD<<UNDERLINE<<name<<"'s TODO LIST"<<RESET<<endl;
	cout<<BOLD<<UNDERLINE<<"Congratulation ! YOU HAVE COMPLETED ALL TASK"<<RESET<<endl;
	cout<<"TO YOU WANT TO SEE Distraction BETWEEN YOUR TASKS. IF YES TYPE 'Y' OR ELSE 'E'";
	if(choice=='Y'|| choice=='y'){
		for(int i=0;i<ditstraction.size();i++){
			cout<<BOLD<<i+1<<<<":-] "<<UNDERLINE<<ditstraction.push_back(i)<<RESET<<endl;
		}
	}
	
	return 0;
	
}

SOURCE CODE:
#include<iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
class Quiz {
private:
string Ques;
string Ans1, Ans2, Ans3, Ans4;
int Right_Answer; // 1..4
int marks; // marks for this question
public:
// set values (like your VALUES)
void VALUES(const string& q,
const string&
a1, const
string& a2,
const string&
a3, const
string& a4, int
correct,
int pts)
{
Ques = q;
Ans1 =
a1;
Ans2 =
a2;
Ans3 =
a3;
Ans4 =
a4;
Right_Answer = correct;
marks = pts;
}
// ask the question and return marks
earned int ASK() const {
cout << "\n" << Ques << "\n";
cout << "1. " << Ans1 <<
"\n"; cout << "2. " << Ans2
<< "\n"; cout << "3. " <
Ans3 << "\n"; cout << "4. "
<< Ans4 << "\n";
int choice = 0
while (true) {
cout << "Your answer (enter 1-4): ";
if (!(cin >> choice)) {
// clear bad input
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Invalid input. Please enter a number 1-4.\n";
continue;
}
if (choice >= 1 && choice <= 4) break;
cout << "Please enter a number between 1 and 4.\n";
}
if (choice == Right_Answer) {
cout << "Correct! You scored " << marks << " marks for this question.\n";
return marks;
} else {
cout << "Wrong. Correct answer: option " << Right_Answer << ".\n";
cout << "You scored 0 for this question.\n";
return 0;
}
}
};
int main() {
cout << "\n\t\t\tQUIZ ZONE - C++ (OOP Concepts)\n";
cout << "Press Enter to start...";
cin.ignore(numeric_limits<streamsize>::max(), '\n');
string Name;
cout << "Enter your name: ";
getline(cin, Name);
int Age;
cout << "Enter your age: ";
while (!(cin >> Age)) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),
'\n'); cout << "Please enter a valid integer for age:
";
}
cout << "\nReady for the Quiz, " << Name << "? (type yes to continue): ";
string Respond;
cin >> Respond;
if (Respond != "yes" && Respond != "Yes") {
cout << "Okay. Exiting. Goodbye!\n";
return 0;
}
cout << "Best of Luck, " << Name << "!\n";
// create 10 OOP questions (each 10 marks)
vector<Quiz> bank(10);
bank[0].VALUES(
(OOP)?",
4, 10);
"Q1: Which of the following is NOT a pillar of Object Oriented Programming
"Encapsulation", "Abstraction", "Polymorphism", "Recursion",
bank[1].VALUES(
"Q2: Which access specifier allows members to be accessible only within the
class and its friends?",
"public", "protected", "private", "internal",
3, 10);
bank[2].VALUES(
"Q3: What does 'polymorphism' allow in C++?",
"Objects of different types to be treated as objects of a common base type",
"Only function overloading",
"Hiding of implementation details",
"Preventing inheritance",
1, 10);
bank[3].VALUES(
"Q4: Which C++ feature allows a derived class to replace a base class method
implementation and ensures the correct method is called via base-class pointer?",
"Function overloading", "Virtual functions", "Templates", "Macros",
2, 10);
bank[4].VALUES(
"Q5: What is the correct term for binding data and functions together in a single
unit?",
"Polymorphism", "Encapsulation", "Inheritance", "Compilation",
2, 10);
bank[5].VALUES(
"Q6: Which keyword is used in C++ to inherit publicly from a base class?",
"implements", "inherits", "public", "private",
3, 10);
bank[6].VALUES(
"Q7: What is constructor overloading?",
"Having multiple constructors with different parameter lists",
"Defining constructor inside another constructor",
"Having only one default constructor",
"Using constructors and destructors together",
1, 10);
bank[7].VALUES(
"Q8: Which of the following allows compile-time polymorphism in C++?",
"Virtual functions", "Function overriding", "Operator overloading /
function
overloading",
"RTTI", 3, 10);
bank[8].VALUES(
"Q9: What is a pure virtual function in C++?",
"A function defined with inline keyword",
"A virtual function with implementation",
"A virtual function declared with = 0 and no implementation",
"A static member function",
3, 10);
bank[9].VALUES(
"Q10: Inheritance type where derived class inherits privately from base (class
Derived : private Base) makes base's public members:",
"public in derived", "protected in derived", "private in derived", "inaccessible",
3, 10);
int Sum = 0;
// ask all questions
for (size_t i = 0; i < bank.size(); ++i) {
Sum += bank[i].ASK();
}
cout << "\nTotal score = " << Sum << " out of 100\n";
if (Sum >= 70) {
cout << "CONGRATULATIONS!!! You have passed the quiz!\n";
} else {
cout << "SORRY! You failed the quiz.\nBetter luck next time.\n";
}
return 0;
}
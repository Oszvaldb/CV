#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDie();
//using std::cout;

void print_counter (int credit){
  cout << "credit : " << credit << endl;
}

void print_slots(int die1, int die2, int die3) {
	cout << " | " << die1 << " | " << die2 << " | " << die3 << " | " << endl;
}

int play (int* setcredit) {
	  char again = 0;
	  cout << "Let's roll! y / n" << endl;
	  cin >> again;
	  if (again = 'y') {
		 *setcredit -= 1;
	  }
	    else if (again = 'n'){
	    	*setcredit = 0;
	    }
	  return 0;
}

int check_slots(int die1, int die2, int die3, int* setcredit, int credit){
	if (die1 == die2 && die2 == die3) {
	  cout << "win!!!" << endl;
	  cout << endl;
	  cout << endl;
	  *setcredit += 10;
	}
	  else {
		cout << "next time" << endl;
		cout << "remaining credit : " << credit << endl;
		cout << endl;
		cout << endl;
	}
	return 0;
}

int gameover(int credit, int* setcredit) {
  if (credit <= 0) {
	  char again = 0;
	  cout << "game over" << endl;
	  cout << "play again? y / n" << endl;
	  cin >> again;
	  if (again = 'y') {
		 *setcredit += 20;
	  }
  }
  return 0;
}

int main (){
  int credit = 20;
  int* setcredit = &credit;
  do {
	  print_counter(credit);
	  play(setcredit);
	  srand((unsigned)time(0));
	  int die1;
	  int die2;
	  int die3;
	  die1 = rollDie();
	  die2 = rollDie();
	  die3 = rollDie();
	  print_slots(die1, die2, die3);
	  check_slots(die1, die2, die3, setcredit, credit);
	  gameover(credit, setcredit);
  } while (credit > 0);

  return 0;
}

int rollDie(){
    return (rand()%6)+1;
}


#include <iostream>
#include "HD.h"

using namespace std;


// ======================
//     main function
// ======================
int main()
{
	 int count;
	 HotDogStand* sList;
	 cout << "Stand count(3개~10개) : ";
	 cin >> count;
	 sList = new HotDogStand[count];
	 for (int i = 0; i < count; i++) {
	  sList[i].SetID(i);
	 }
	 char input;
	 while (true)
	 {
	  cout << "ID : ";
	  cin >> input;
	  if (input == 'q' || input == 'Q')
	   break;
	  int id = input - '0';
	  if(id >= 0 && id < count) // 인덱스 범위 안에 들면
	   sList[id].JustSold();
	 }

	 for (int i = 0; i < count; i++) {
	  cout << "Stand " << sList[i].GetID();
	  cout << " sold " << sList[i].GetNumSold() << endl;
	 }

	 cout << "Total sold = " << HotDogStand::GetTotalSold() << endl;

	 if (sList)
	  delete[] sList;
	 sList = NULL;

  //// Test our code with three hot dog stands
  //HotDogStand s1(1,0),s2(2,0),s3(3,0);
  //
  //// Sold at stand 1, 2
  //s1.JustSold();
  //s2.JustSold();
  //s1.JustSold();

  //cout << "Stand " << s1.GetID() << " sold " << s1.GetNumSold() << endl;
  //cout << "Stand " << s2.GetID() << " sold " << s2.GetNumSold() << endl;
  //cout << "Stand " << s3.GetID() << " sold " << s3.GetNumSold() << endl;
  //cout << "Total sold = " << HotDogStand::GetTotalSold() << endl;
  //cout << "Total sold = " << s1.GetTotalSold() << endl;
  //cout << endl;

  //// Sold some more
  //s3.JustSold();
  //s1.JustSold();

  //cout << "Stand " << s1.GetID() << " sold " << s1.GetNumSold() << endl;
  //cout << "Stand " << s2.GetID() << " sold " << s2.GetNumSold() << endl;
  //cout << "Stand " << s3.GetID() << " sold " << s3.GetNumSold() << endl;
  //cout << "Total sold = " << HotDogStand::GetTotalSold() << endl;
  //cout << "Total sold = " << s1.GetTotalSold() << endl;
  //cout << endl;
  return 0;
}


#include<iostream>
#include <math.h>
#include<stdlib.h>
#include<sstream>
#include <boost/dynamic_bitset.hpp>
#include<cmath>
#include<bitset>
#include<string>

using namespace std;
using namespace boost;
int btod(int);
string gtob(string);
string btog(string);
int main(int argc, char ** argv) {
	int numofbulb;
	cout << "enter number of switches[1-10] :";
	cin >> numofbulb;
	string input;
	dynamic_bitset < > inputtemp(numofbulb, 0);
	to_string(inputtemp, input);
	//input="000101"; //you can change initial value of switches here
	string result;
	string grey1 = btog(input);
	string grey2;
	ostringstream str1;
	dynamic_bitset < > grey2temp(numofbulb, (btod(stoi(input)) + 1));
	to_string(grey2temp, grey2);
	grey2 = btog(grey2);
	int count = 0;
	string bin1 = input;
	string bin2;
	string result2;
	dynamic_bitset < > result2temp(numofbulb, pow(2, numofbulb) - 1);
	to_string(result2temp, result2);
	dynamic_bitset < > bin2temp(numofbulb, (btod(stoi(input)) + 1));
	to_string(bin2temp, bin2);
	cout << endl << "Push button in following sequence(right-0,left-N) : " << endl<<endl;
	while (bin1 != result2) {

		count++;
		int xoring = btod(stoll(grey1)) ^ btod(stoll(grey2));
		int bitpos = log2(xoring) + 1;
		bin1 = bin2;
		dynamic_bitset < > bin2temp(numofbulb, (btod(stoll(bin1)) + 1));
		to_string(bin2temp, bin2);
		cout << bitpos << " ";
		grey1 = btog(bin1);
		grey2 = btog(bin2);
		if (input[numofbulb - bitpos] == '1')
		input[numofbulb - bitpos] = '0';
		else
		input[numofbulb - bitpos] = '1';
		result = input;
	}

	cout << endl<<endl<<"..............................................."<<endl;
	cout<<"It will take "<<count<<" push to turn on the bulb"<<endl;
}
char xor_c(char a, char b) {
	return (a == b) ? '0' : '1';
}
char flip(char c) {
	return (c == '0') ? '1' : '0';
}
string btog(string binary) {
	string gray = "";

	gray += binary[0];

	for (int i = 1; i < binary.length(); i++) {
		gray += xor_c(binary[i - 1], binary[i]);
	}

	return gray;
}
string gtob(string gray) {
	string binary = "";

	binary += gray[0];

	for (int i = 1; i < gray.length(); i++) {
		if (gray[i] == '0')
		binary += binary[i - 1];

		else
		binary += flip(binary[i - 1]);
	}

	return binary;
}
int btod(int n) {
	int num = n;
	int dec_value = 0;

	int base = 1;

	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}

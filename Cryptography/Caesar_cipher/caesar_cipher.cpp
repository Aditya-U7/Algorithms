/*

Author: Aditya Upadhye

A program for implementing the Caesar cipher. Works for both positive and negative values of the shift-key.

*/


#include <iostream>
#include <map>


void display_textmap(std::map<char, char>& txtmap)
{

	std::cout << "Digits:" << std::endl;

	for (char digit = '0'; digit < 58; digit++)
	{
		std::cout << digit << " <—> " << txtmap[digit] << "   "; 
	}

	std::cout << "\n\n";
	std::cout << "Letters:" << std::endl;

	for (char letter = 'a'; letter < 123; letter++)
	{

		std::cout << letter << " <—> " << txtmap[letter] << "   "; 
		if (letter % 8 == 0)
			std::cout << "\n";

	}

	std::cout << "\n\n";

}


std::map<char, char> generate_the_textmap(const int& key)
{

	int shift_value = key % 26;                  //(key >= 0? key % 26: -(abs(key) % 26));
	int shift_value_n = key % 10;                //(key >= 0? key % 10: -(abs(key) % 10));

	std::map<char, char> text_map {{'a', 'a'}, {'b', 'b'}, {'c', 'c'}, {'d', 'd'}, {'e', 'e'}, {'f', 'f'},
                                       {'g', 'g'}, {'h', 'h'}, {'i', 'i'}, {'j', 'j'}, {'k', 'k'}, {'l', 'l'},
                                       {'m', 'm'}, {'n', 'n'}, {'o', 'o'}, {'p', 'p'}, {'q', 'q'}, {'r', 'r'}, 
                                       {'s', 's'}, {'t', 't'}, {'u', 'u'}, {'v', 'v'}, {'w', 'w'}, {'x', 'x'},
                                       {'y', 'y'}, {'z', 'z'}, {'0', '0'}, {'1', '1'}, {'2', '2'}, {'3', '3'},
                                       {'4', '4'}, {'5', '5'}, {'6', '6'}, {'7', '7'}, {'8', '8'}, {'9', '9'}};
        
	std::cout << "\nMapping of the characters using the given key (shift) value:\n\n";                        
	
	for (auto& character: text_map)
	{
		if (character.second >= 97 && character.second < 123)
		{

			if ((character.second + shift_value) > 122)
				character.second = ((shift_value - (123 - character.second))) + 97; 
			else if ((character.second + shift_value < 97))
				character.second = 123 - (abs(shift_value) - (character.second - 97));
			else
				character.second = character.second + shift_value;
		}
		else 
		{
			if ((character.second + shift_value_n) > 57)
				character.second = (shift_value_n - (58 - character.second)) + 48; 
			else if ((character.second + shift_value_n) < 48)
				character.second = ((character.second - 48) + shift_value_n) + 58;
			else 
				character.second = character.second + shift_value_n;

		}  
		     
	}

	return text_map;

}


std::string caesar_cipher(const std::string& user_input, const int& key)
{

	std::string text = "";

	std::map<char, char> text_map = generate_the_textmap(key);

	for (auto& character: user_input)
	{

		if (text_map[character])
			text += text_map[character];
		else if(text_map[character + 32])
		        text += (text_map[character + 32] - 32);
		else
			text += character;

	}

	display_textmap(text_map);
	std::cout << "After applying the shift: \n\n";
	return text;
}


int main()
{

	std::string user_input = "";
	int key;
	std::cout << "Enter the text below:\n\n";
	std::getline(std::cin, user_input); 
	std::cout << "\nPlease enter the key value (negative: left shift, positive: right shift):\n\n";
	std::cin >> key;
	std::cout << caesar_cipher(user_input, key) << std::endl;

	return 0;

}

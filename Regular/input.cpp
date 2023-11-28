#include "bits/stdc++.h"
#include <fstream>

using namespace std;

#define int long long
#define endl "\n"

int getRandomNumber(int min, int max)
{
    random_device rd;                             // Obtain a random seed from the hardware
    mt19937 gen(rd());                            // Seed the random number engine
    uniform_int_distribution<int> dist(min, max); // Define the range

    return dist(gen); // Generate a random number within the range
}

string generateRandomWord(int minLen, int maxLen)
{
    static const string characters = "abcdefghijklmnopqrstuvwxyz";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    uniform_int_distribution<int> lenDist(minLen, maxLen);
    uniform_int_distribution<int> charDist(0, characters.size() - 1);

    int length = lenDist(gen);
    string word;
    for (int i = 0; i < length; i++)
    {
        word += characters[charDist(gen)];
    }

    return word;
}

int32_t main()
{
    ofstream file("june-g-5.txt"); // Open the file for writing
    const int t = 30;
    const int i_mn = 1;
    const int i_mx = 16;
    const int j_mn = 1;
    const int j_mx = 20;

    if (file.is_open())
    { // Check if the file was successfully opened
        file << t << endl;
        for (int i = 1; i <= t; i++) {
            file << getRandomNumber(i_mn, i_mx) << " " << getRandomNumber(j_mn, j_mx) << " " << getRandomNumber(i_mn, i_mx) << " " << getRandomNumber(j_mn, j_mx) << endl;
        }
        file.close(); // Close the file
        cout << "File created successfully.\n";
    }
    else
    {
        cout << "Failed to create the file.\n";
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int n, vector<int> digits)
{
    int product = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        product *= digits[i];
        sum += digits[i];
    }
    return product == sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        digits[i] = i + 1;
    }

    int count = 0;
    string least_number = "";
    while (true)
    {
        if (is_valid(n, digits))
        {
            count++;
            if (least_number == "" || digits < least_number)
            {
                least_number = to_string(digits[0]);
                for (int i = 1; i < n; i++)
                {
                    least_number += to_string(digits[i]);
                }
            }
        }
        else
        {
            break;
        }

        int i = n - 1;
        while (i >= 0 && digits[i] == 9)
        {
            digits[i] = 0;
            i--;
        }

        if (i < 0)
        {
            break;
        }

        digits[i]++;
        for (int j = i + 1; j < n; j++)
        {
            digits[j] = 1;
        }
    }

    if (count == 0)
    {
        cout << endl;
    }
    else
    {
        cout << "Number of N-digit numbers: " << count << endl;
        cout << "Least N-digit number: " << least_number << endl;
    }

    return 0;
}

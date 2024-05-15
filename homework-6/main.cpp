#include <iostream>
#include <sstream>
using namespace std;

int num{};

template <typename  T>
void consoleInput(T& a) {
    cin >> a;
}

void getConsoleLineString (string& str) {
    getline(cin, str);
}

vector<int> split(const string &s, char delimiter) {
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}



namespace Problem1 {
    void execute() {
        int num;
        consoleInput(::num);
        consoleInput(num);

        cout << (::num % num) << endl;
    }
}

namespace Problem2 {
    int count (string& a, char c) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == c) count++;
        }
        return count;
    }

    int func(string& a, string& b, char c, int& status) {
        int firstStringAppears = count(a, c);
        int secondStringAppears = count(b, c);

        if (firstStringAppears == 0 && secondStringAppears == 0) {
            status = -1;
            return 0;
        } else if (firstStringAppears == secondStringAppears) {
            status = 0;
            return firstStringAppears;
        } else if (firstStringAppears > secondStringAppears) {
            status = 1;
            return firstStringAppears;
        } else {
            status = 2;
            return secondStringAppears;
        }
    }

    void execute () {
        string fisrtStr = "";
        string secondStr = "";
        char c;
        consoleInput(fisrtStr);
        consoleInput(secondStr);
        consoleInput(c);

        int status;

        int appearances = func(fisrtStr, secondStr, c, status);

        switch (status) {
            case -1:
                cout << "Not found" << endl;
            break;
            case 0:
                cout << "String " << fisrtStr << " and " << secondStr << " contain the character " << c << " same times ( " << appearances << " )" << endl;
            break;
            case 1:
                cout << "String "<< fisrtStr << " contains the character "<< c << " most times ( " << appearances << " times )" << endl;
            break;
            case 2:
                cout << "String "<< secondStr << " contains the character "<< c << " most times ( " << appearances << " times )" << endl;
            break;
        }
    }


}

namespace Problem3 {
    void func (string& a, int& sumDigits) {
        for (int i = 0; i < a.size(); i++) {
            if (isdigit(a[i])) {
                ++sumDigits;
            } else if (isupper(a[i])) {
                a[i] = tolower(a[i]);
            } else if (islower(a[i])) {
                a[i] =toupper(a[i]);
            }
        }
    }
    void execute () {
        string str = "";
        int sumDigits{};

        while (str[str.size() - 1] != 'x') {
            consoleInput(str);
        }
        func (str, sumDigits);
        cout << str << " contains " << sumDigits << " digits." << endl;
    }
}

namespace Problem4 {
    template <typename T>
    T func (T a, T b, T c ) {
        return max(max(a + b, b + c), a + c);
    }

    template <typename T>
    void func (vector<T> array, T& min, T& max ) {
        for (int i= 1; i< array.size(); i++) {
            if (array[i] > max) max = array[i];
            if (array[i] < min) min = array[i];
        }
    }

    void execute () {
        int channel;
        consoleInput(channel);

        switch (channel) {
            case 1:
                int a, b, c;
                consoleInput(a);
                consoleInput(b);
                consoleInput(c);
                cout << func(a, b, c) << endl;
            break;
            case 2:
                string str ="";
                cin.ignore(256, '\n');
                getConsoleLineString(str);
                vector<int> res = split(str, ' ');
                int min {res[0]};
                int max {res[0]};
                func (res, min, max);
                cout << "Min: " << min << " Max: " << max << endl;

        }
    }
}

namespace Problem5 {
    template <typename T>
    T& func(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
        return (a > b ? a : b);
    }
    template <typename T>
    void func(vector<T>& arr1, vector<T>& arr2) {
       swap(arr1, arr2);
    }

    void execute () {
        string str ="";
        getConsoleLineString(str);
        vector<int> res = split(str, ' ');
        if (res.size() == 2) {
            cout << func(res[0], res[1]);
        } else {
            string str2;
            getConsoleLineString(str2);
            vector<int> res2 = split(str2, ' ');
            func(res, res2);
            for (int i=0; i < res.size(); i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
            for (int j = 0; j < res2.size(); j++) {
                cout << res2[j] << " ";
            }
            cout << endl;
        }
    }

}

int main() {
    Problem1::execute();
    Problem2::execute();
    Problem3::execute();
    Problem4::execute();
    Problem5::execute();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

// Function to calculate factorial
long double factorial(int n) {
    long double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
        if((int)result>=1e18/(i+1)) return result;
    }
    return result;
}

// Problem 1
void p1() {
    cout<<"Give the terms you wanna add : ";
    long double term1,term2;
    cin>>term1>>term2;
    long double sum = term1 + term2;
    //normalize the result to scientific notation
    double normalized_sum = sum / 1e4;
    //rounded to five significant digits
    long double rounded_sum = round(normalized_sum * 1e5) / 1e5;
    //absolute error
    long double absolute_error = fabs(sum - rounded_sum * 1e4);
    //relative error
    long double relative_error = absolute_error / fabs(sum);
    cout << "Exact sum: " << sum << " or " << normalized_sum << " * 10^4" << endl;
    cout << "Rounded sum: " << rounded_sum << " * 10^4" << endl;
    cout << "Absolute error: " << absolute_error << endl;
    cout << "Relative error: " << relative_error << endl;
    cout << endl;
}

// Problem 2
void p2() {
    long double result = exp(M_PI * sqrt(163));
    cout << "Problem 2:" << endl;
    cout << "e^(pi*sqrt(163)) = " << setprecision(30) << result << endl;
    cout << "Difference from 262537412640768744: " << fabs(result - 262537412640768744.0) << endl;
    cout << endl;
}

// Function for problem 3 calculations with specified precision
void p3() {
    vector<long double> exact_values = {133 + 0.921, 122 - 0.499, (121 - 0.327) - 119, (121 - 119) - 0.327,
                                   13.0 / 14 - 3.0 / (4 * 2 * exp(1) - 5.4), M_PI - 22.0 / 7 * 1.0 / 17};

    vector<string> descriptions = {
        "133 + 0.921",
        "122 - 0.499",
        "(121 - 0.327) - 119",
        "(121 - 119) - 0.327",
        "13/14 - 3/(4*2*e - 5.4)",
        "pi - 22/7 * 1/17"
    };

    vector<long double> rounded_3digit = {134.0, 122.0, 2.0, 1.67, 0.74, 2.95};
    vector<long double> rounded_4digit = {133.9, 121.5, 1.67, 1.673, 0.745, 2.956};

    cout << "Problem 3:" << endl;
    for (size_t i = 0; i < exact_values.size(); ++i) {
        long double abs_error_3digit = fabs(exact_values[i] - rounded_3digit[i]);
        long double rel_error_3digit = abs_error_3digit / fabs(exact_values[i]);
        long double abs_error_4digit = fabs(exact_values[i] - rounded_4digit[i]);
        long double rel_error_4digit = abs_error_4digit / fabs(exact_values[i]);

        cout << descriptions[i] << endl;
        cout << "  Exact: " << exact_values[i] << endl;
        cout << "  3-digit rounding: " << rounded_3digit[i] << ", Abs error: " << abs_error_3digit << ", Rel error: " << rel_error_3digit << endl;
        cout << "  4-digit chopping: " << rounded_4digit[i] << ", Abs error: " << abs_error_4digit << ", Rel error: " << rel_error_4digit << endl;
    }
    cout << endl;
}

// Maclaurin series for atan
long double atan_series(double x, int terms) {
    long double sum = 0;
    for (int n = 0; n < terms; ++n) {
        double term = pow(-1, n) * pow(x, 2*n + 1) / (2*n + 1);
        sum += term;
    }
    return sum;
}

// Problem 4 (a, b)
void p4() {
    long double pi_approx1 = 4 * (atan_series(0.5, 5) + atan_series(0.33333333333, 5));
    long double pi_approx2 = 16 * atan_series(0.2, 5) - 4 * atan_series(0.0041841, 5);

    cout << "Problem 4:" << endl;
    cout << "Approximation 1 for pi: " << pi_approx1 << endl;
    cout << "Approximation 2 for pi: " << pi_approx2 << endl;
    cout << "Exact pi: " << M_PI << endl;
    cout << "Absolute error 1: " << fabs(M_PI - pi_approx1) << endl;
    cout << "Relative error 1: " << fabs((M_PI - pi_approx1) / M_PI) << endl;
    cout << "Absolute error 2: " << fabs(M_PI - pi_approx2) << endl;
    cout << "Relative error 2: " << fabs((M_PI - pi_approx2) / M_PI) << endl;
    cout << endl;
}

// Problem 5
void p5() {
    double x = 2;
    double sin_approx2 = x - pow(x, 3) / factorial(3);

    cout << "Problem 5:" << endl;
    cout << "sin(2) approximation (2 terms): " << sin_approx2 << endl;
    cout << "Exact sin(2): " << sin(2) << endl;
    cout << "Absolute error: " << fabs(sin(2) - sin_approx2) << endl;
    cout << "Relative error: " << fabs((sin(2) - sin_approx2) / sin(2)) << endl;
    cout << endl;
}

// Problem 6
void p6() {
    long double e_approx_5 = 0;
    long double e_approx_10 = 0;
    long double e_approx_1000 = 0;
    for (int i = 0; i <= 5; ++i) e_approx_5 += 1 / factorial(i);
    for (int i = 0; i <= 10; ++i) e_approx_10 += 1 / factorial(i);
    for (int i = 0; i <= 1000; ++i) e_approx_1000 += 1 / factorial(i);

    cout << "Problem 6:" << endl;
    cout << "e approximation(5 terms): " << e_approx_5 << endl;
    cout << "e approximation(10 terms): " << e_approx_10 << endl;
    cout << "e approximation(1000 terms): " << e_approx_1000 << endl;
    cout << "Exact e: " << exp(1) << endl;
    cout << "Absolute error(5 terms): " << fabs(exp(1) - e_approx_5) << endl;
    cout << "Relative error(5 terms): " << fabs((exp(1) - e_approx_5) / exp(1)) << endl;
    cout << "Absolute error(10 terms): " << fabs(exp(1) - e_approx_10) << endl;
    cout << "Relative error(10 terms): " << fabs((exp(1) - e_approx_10) / exp(1)) << endl;
    cout << "Absolute error(1000 terms): " << fabs(exp(1) - e_approx_1000) << endl;
    cout << "Relative error(1000 terms): " << fabs((exp(1) - e_approx_1000) / exp(1)) << endl;
    cout << endl;
}
void solve(int cnt){
    if(cnt==1) p1();
    else if(cnt==2) p2();
    else if(cnt==3) p3();
    else if(cnt==4) p4();
    else if(cnt==5) p5();
    else if(cnt==6) p6();
    else cout<<"Invalid Number"<<endl;
    cout<<"Do You wanna solve another question?(Y/N) "<<endl;
    string s;
    cin>>s;
    if(s[0]=="Y"){
        cout<<"Which Problem do you wanna solve? "<<endl;
        cin>>cnt;
        solve(cnt);
    }
    return;
}

int main() {
    cout << fixed << setprecision(10);
    int cnt=0;
    cout<<"Which Problem do you wanna solve? "<<endl;
    cin>>cnt;
    solve(cnt);
    return 0;
}

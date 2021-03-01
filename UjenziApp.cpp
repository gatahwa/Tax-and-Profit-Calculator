#include <iostream>

using namespace std;

//FUNCTION PROTOTYPE - we are simply defining the function but the body function is in another file
int taxCalculator(int qnty, int s_px);
int profitCalculator(int unit_selling_price, int quantity, int unit_buying_price, int tax);

int total_brands = 0;
//MAIN FUNCTION TO CALL THE TWO FUNCTIONS
int main()
{

    //Welcome Note below, can be omitted if not required
    cout << "WELCOME TO UJENZI GENERAL SUPPLIES" << endl;
    cout << "TAX AND PROFIT CALCULATOR" << endl;

    //Accept input variables
    cout << "Enter number of cement types that you have: " << endl;
    cin >> total_brands;

    //Define input variables
    int quantity[total_brands];
    int unit_buying_price[total_brands];
    int unit_selling_price[total_brands];
    string brand[total_brands];

    //Define output variables
    int tax[total_brands];
    int profit[total_brands];

    for (int i = 0; i < total_brands; i++) {

        //accepting cement types
        cout << "Enter cement type name " << (i + 1) << ": " << endl;
        cin >> brand[i];
        //for each cement type, we are accepting prices
        cout << "Enter the quantity of " << brand[i] << ": " << endl;
        cin >> quantity[i];
        //for each cement type, we are accepting prices
        cout << "Enter unit buying price of " << brand[i] << ": " << endl;
        cin >> unit_buying_price[i];
        //for each cement type, we are accepting prices
        cout << "Enter unit selling price of " << brand[i] << ": " << endl;
        cin >> unit_selling_price[i];

        //call the two functions
        tax[i] = taxCalculator(quantity[i], unit_selling_price[i]);
        profit[i] = profitCalculator(unit_selling_price[i], quantity[i], unit_buying_price[i], tax[i]);
    }

    //WRITING HEADERS
    cout << "SN "
         << "CEMENT TYPE"
         << " "
         << "PURCHASING PRICE/BAG"
         << " "
         << "SELLING PRICE/BAG"
         << " "
         << "QUANTITY SOLD"
         << " "
         << "TAX"
         << " "
         << "PROFIT" << endl;

    //WRITING DATA COMPUTED
    for (int i = 0; i < total_brands; i++) {
        cout << i + 1 << " " << brand[i] << " " << unit_buying_price[i] << " " << unit_selling_price[i] << " " << quantity[i] << " " << tax[i] << " " << profit[i] << endl;
    }

    return 0;
};

//Function to calculate tax
int taxCalculator(int qnty, int s_px)
{
    int tax;
    int i = 0;

    if (qnty < 1500) {
        tax = 0.15 * qnty * s_px;
    }
    else if (qnty >= 1500 && qnty < 3000) {
        tax = 0.20 * qnty * s_px;
    }
    else if (qnty >= 3000) {
        tax = 0.25 * qnty * s_px;
    }

    return tax;
};

//Function to calculate profit
int profitCalculator(int unit_selling_price, int quantity, int unit_buying_price, int tax)
{
    int i;
    int profit = (unit_selling_price * quantity) - tax - (unit_buying_price * quantity);
    return profit;
}



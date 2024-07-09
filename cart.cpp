using namespace std;
#include <iostream>
#include "datamodel.h"
#include <vector>

vector<Product> allProducts = {
    Product(1, "Apple", 50),
    Product(2, "Mango", 150),
    Product(3, "Guava", 20),
    Product(4, "Banana", 4),
    Product(5, "Strawberry", 15),
    Product(6, "Pineapple", 90),
};

Product *chooseProduct()
{
    string productList;
    cout << "Available Products" << endl;
    for (auto product : allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;
    cout << "-----------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product not found!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if (cart.isEmpty())
        return false;
    int total = cart.getTotal();
    cout << "Pay in Cash!";

    int paid;
    cin >> paid;

    if (paid >= total)
    {
        cout << "Change : " << paid - total << endl;
        cout << "Successfully Paid. Thank you for shopping!" << endl;
        return true;
    }
    else
    {
        cout << "NOt enough cash!" << endl;
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;
        if (action == 'a')
        {
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the Cart :" << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            cout << "---------------------" << endl;
            cout << cart.viewCart();
            cout << "---------------------" << endl;
        }
        else
        {
            cart.viewCart();
            if (checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}
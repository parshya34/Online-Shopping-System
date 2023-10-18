#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a product
typedef struct {
    int id;
    char name[100];
    double price;
} Product;

// Define a structure for the shopping cart
typedef struct {
    int productId;
    int quantity;
} CartItem;

int main() {
    // Define some sample products
    Product products[] = {
        {1, "Product A", 10.99},
        {2, "Product B", 15.99},
        {3, "Product C", 5.49},
    };
    int numProducts = sizeof(products) / sizeof(products[0]);

    // Initialize the shopping cart
    CartItem cart[100];
    int cartSize = 0;

    int choice;
    double totalCost = 0;

    printf("Welcome to the Online Shopping and Payment System\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Proceed to Payment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Available Products:\n");
                printf("ID\tName\t\tPrice\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("%d\t%s\t\t$%.2lf\n", products[i].id, products[i].name, products[i].price);
                }
                break;
            case 2:
                int productId, quantity;
                printf("Enter the product ID to add to cart: ");
                scanf("%d", &productId);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);

                int found = 0;
                for (int i = 0; i < numProducts; i++) {
                    if (products[i].id == productId) {
                        cart[cartSize].productId = productId;
                        cart[cartSize].quantity = quantity;
                        cartSize++;
                        totalCost += products[i].price * quantity;
                        found = 1;
                        printf("Added to cart.\n");
                        break;
                    }
                }

                if (!found) {
                    printf("Product not found. Please enter a valid product ID.\n");
                } break;
            case 3:
                printf("Shopping Cart:\n");
                printf("ID\tName\t\tPrice\tQuantity\n");
                for (int i = 0; i < cartSize; i++) {
                    int productId = cart[i].productId;
                    int quantity = cart[i].quantity;

                    for (int j = 0; j < numProducts; j++) {
                        if (products[j].id == productId) {
                            printf("%d\t%s\t\t$%.2lf\t%d\n", products[j].id, products[j].name, products[j].price, quantity);
                            break;
                        }
                    }
                }
                printf("Total Cost: $%.2lf\n", totalCost);
                break;
            case 4:
                if (cartSize > 0) {
                    printf("Total Cost: $%.2lf\n", totalCost);
                    printf("Enter your payment information (credit card, etc.): ");
                    char paymentInfo[100];
                    scanf("%s", paymentInfo);
                    printf("Payment successful! Thank you for your purchase.\n");
                    cartSize = 0;
                    totalCost = 0;
                } else {
                    printf("Your cart is empty. Please add items to your cart before proceeding to payment.\n");
                }
                break;
            case 5:
                printf("Thank you for using our Online Shopping and Payment System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
